//
// Created by alexco on 08.05.2025.
//

#include <gtest/gtest.h>

#include "App.h"
#include "../order/Order.h"

class AppTest: public testing::Test {
protected:
    App app;

    void SetUp() override {

        // Initialize the app with traders
        app.getTraderManager()->insert(Name("GFA"));
        app.getTraderManager()->insert(Name("Edi"));
        app.getTraderManager()->insert(Name("Alexco"));

        // Adding initial funds to traders
        app.getTraderManager()->getTraders()[0]->depositFunds(Funds(1500)); // Alexco
        app.getTraderManager()->getTraders()[1]->depositFunds(Funds(1000)); // EDI
        app.getTraderManager()->getTraders()[2]->depositFunds(Funds(1200)); // GFA

        // Adding stocks to traders' portfolios
        // Alexco
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(100));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Nvidia"), Symbol("NVDA")), Quantity(200));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Microsoft"), Symbol("MSFT")), Quantity(50));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Tesla"), Symbol("TSLA")), Quantity(60));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Google"), Symbol("GOOGL")), Quantity(45));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Amazon"), Symbol("AMZN")), Quantity(190));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Meta"), Symbol("META")), Quantity(450));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Netflix"), Symbol("NFLX")), Quantity(300));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Adobe"), Symbol("ADBE")), Quantity(205));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Salesforce"), Symbol("CRM")), Quantity(25));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("IBM"), Symbol("IBM")), Quantity(5));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("Intel"), Symbol("INTC")), Quantity(15));
        app.getTraderManager()->getTraders()[0]->getPortfolio()->addStock(Stock(Name("AMD"), Symbol("AMD")), Quantity(10));

        // EDI
        app.getTraderManager()->getTraders()[1]->getPortfolio()->addStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(55));
        app.getTraderManager()->getTraders()[1]->getPortfolio()->addStock(Stock(Name("Google"), Symbol("GOOGL")), Quantity(105));
        app.getTraderManager()->getTraders()[1]->getPortfolio()->addStock(Stock(Name("Amazon"), Symbol("AMZN")), Quantity(75));
        app.getTraderManager()->getTraders()[1]->getPortfolio()->addStock(Stock(Name("Meta"), Symbol("META")), Quantity(100));
        app.getTraderManager()->getTraders()[1]->getPortfolio()->addStock(Stock(Name("Netflix"), Symbol("NFLX")), Quantity(110));
        app.getTraderManager()->getTraders()[1]->getPortfolio()->addStock(Stock(Name("Adobe"), Symbol("ADBE")), Quantity(210));
        app.getTraderManager()->getTraders()[1]->getPortfolio()->addStock(Stock(Name("Salesforce"), Symbol("CRM")), Quantity(310));
        app.getTraderManager()->getTraders()[1]->getPortfolio()->addStock(Stock(Name("Intel"), Symbol("INTC")), Quantity(500));

        // GFA
        app.getTraderManager()->getTraders()[2]->getPortfolio()->addStock(Stock(Name("Microsoft"), Symbol("MSFT")), Quantity(150));
        app.getTraderManager()->getTraders()[2]->getPortfolio()->addStock(Stock(Name("Tesla"), Symbol("TSLA")), Quantity(135));
        app.getTraderManager()->getTraders()[2]->getPortfolio()->addStock(Stock(Name("Google"), Symbol("GOOGL")), Quantity(100));
        app.getTraderManager()->getTraders()[2]->getPortfolio()->addStock(Stock(Name("Amazon"), Symbol("AMZN")), Quantity(85));
        app.getTraderManager()->getTraders()[2]->getPortfolio()->addStock(Stock(Name("Meta"), Symbol("META")), Quantity(90));
        app.getTraderManager()->getTraders()[2]->getPortfolio()->addStock(Stock(Name("Netflix"), Symbol("NFLX")), Quantity(300));
        app.getTraderManager()->getTraders()[2]->getPortfolio()->addStock(Stock(Name("IBM"), Symbol("IBM")), Quantity(15));
        app.getTraderManager()->getTraders()[2]->getPortfolio()->addStock(Stock(Name("AMD"), Symbol("AMD")), Quantity(10));






        std::cout << "Traders: " << app.getTraderManager()->getTraders()[2]->getName().toString() << std::endl;
        std::cout << "Has Apple Stock? " << app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(100)) << std::endl;


    }

};

TEST_F(AppTest, End2EndTest) {

    // Test the setup of the app
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getName().toString(), "Alexco");
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getName().toString(), "Edi");
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getName().toString(), "GFA");


    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getFunds().getValue(), 1500);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getFunds().getValue(), 1000);
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getFunds().getValue(), 1200);


    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(100)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(50)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(150)), false);

    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Google"), Symbol("GOOGL")), Quantity(105)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Google"), Symbol("GOOGL")), Quantity(95)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Google"), Symbol("GOOGL")), Quantity(300)), false);

    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getPortfolio()->hasStock(Stock(Name("AMD"), Symbol("AMD")), Quantity(10)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getPortfolio()->hasStock(Stock(Name("AMD"), Symbol("AMD")), Quantity(1)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getPortfolio()->hasStock(Stock(Name("AMD"), Symbol("AMD")), Quantity(400)), false);






}
