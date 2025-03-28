#include <gtest/gtest.h>

#include "Symbol.h"

TEST(SymbolTest, LengthAtLeast2) {
    EXPECT_NO_THROW({
            Symbol symbol("AB");
        }
    );
    EXPECT_THROW({
            Symbol symbol("A");
        },
        std::invalid_argument
    );
}

TEST(SymbolTest, LengthAtMost5) {
    EXPECT_NO_THROW({
            Symbol symbol("ABCDE");
        }
    );
    EXPECT_THROW({
            Symbol symbol("ABCDEF");
        },
        std::invalid_argument
    );
}

TEST(SymbolTest, UppercaseAlpha) {
    EXPECT_NO_THROW({
            Symbol symbol("APPL");
        }
    );
    EXPECT_THROW({
            Symbol symbol("appl");
        },
        std::invalid_argument
    );
    EXPECT_THROW({
            Symbol symbol("A123");
        },
        std::invalid_argument
    );
}