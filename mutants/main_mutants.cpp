//
// Created by Alexco on 5/10/2025.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <filesystem>
#include <unordered_map>
#include <regex>

// Configurable variables
const std::string path = "../src/orderBook/OrderBook.cpp"; // path to the file that will be mutated
const std::string backup_path = "backup.txt"; // backup path of the original file
const int MODE = 0; // 1 = mutate, 0 = restore

// Operators that can be mutated
std::vector<std::string> arithmetic_ops = {"+", "-", "*", "/"};
std::vector<std::string> relational_ops = {">", "<", "==", "!=", ">=", "<="};

// Function to get a different random operator
std::string getDifferentRandomOperator(const std::string& currentOp, const std::vector<std::string>& ops) {
    std::vector<std::string> altOps;
    for (const auto& op : ops) {
        if (op != currentOp) altOps.push_back(op);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, altOps.size() - 1);
    return altOps[dis(gen)];
}

int main() {
    std::ifstream infile(path);
    if (!infile.is_open()) {
        std::cerr << "Failed to open source file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> lines;

    while (std::getline(infile, line)) {
        lines.push_back(line);
    }
    infile.close();

    if (MODE == 1) {
        // MUTATE
        // Create backup first
        std::ofstream backup_out(backup_path);
        for (const auto& l : lines) {
            backup_out << l << "\n";
        }
        backup_out.close();

        // Perform mutation
        std::ofstream outfile(path);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> flip(0, 1); // 0 = don't change, 1 = mutate

        std::vector<std::pair<std::string, std::vector<std::string>>> mutation_sets = {
            {"arithmetic", arithmetic_ops},
            {"relational", relational_ops}
        };

        for (auto& l : lines) {
            for (const auto& [type, ops] : mutation_sets) {
                for (const auto& op : ops) {
                    std::string escaped_op = std::regex_replace(op, std::regex(R"([\^\$\.\|\?\*\+\(\)\[\]\{\}])"), R"(\$&)" );
                    std::regex re("(\\s)" + escaped_op + "(\\s)"); // search for operator with spaces around it
                    std::smatch match;
                    std::string temp_line = l;
                    std::string result;
                    size_t search_start = 0;

                    while (std::regex_search(temp_line, match, re)) {
                        result += match.prefix().str();
                        if (flip(gen) == 1) {
                            std::string new_op = getDifferentRandomOperator(op, ops);
                            result += match.str(1) + new_op + match.str(2);
                        } else {
                            result += match.str();
                        }
                        temp_line = match.suffix().str();
                    }
                    result += temp_line;
                    l = result;
                }
            }
            outfile << l << "\n";
        }
        outfile.close();
        std::cout << "Mutation complete. Backup saved to: " << backup_path << std::endl;

    } else if (MODE == 0) {
        // RESTORE
        std::ifstream backup_in(backup_path);
        if (!backup_in.is_open()) {
            std::cerr << "Failed to open backup file." << std::endl;
            return 1;
        }
        std::ofstream restore_out(path);
        while (std::getline(backup_in, line)) {
            restore_out << line << "\n";
        }
        backup_in.close();
        restore_out.close();
        std::cout << "Restore complete. Original file restored from backup." << std::endl;
    }

    return 0;
}
