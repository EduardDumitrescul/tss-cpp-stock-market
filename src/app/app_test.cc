//
// Created by Alexco on 08.05.2025.
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


        // Initialize the stock market

        // Register traders
        app.getStockMarket()->registerTrader(std::const_pointer_cast<Trader>(app.getTraderManager()->getTraders()[0]));
        app.getStockMarket()->registerTrader(std::const_pointer_cast<Trader>(app.getTraderManager()->getTraders()[1]));
        app.getStockMarket()->registerTrader(std::const_pointer_cast<Trader>(app.getTraderManager()->getTraders()[2]));

        // Register stocks
        app.getStockMarket()->registerStock(Stock(Name("Apple"), Symbol("APPL")));
        app.getStockMarket()->registerStock(Stock(Name("Nvidia"), Symbol("NVDA")));
        app.getStockMarket()->registerStock(Stock(Name("Microsoft"), Symbol("MSFT")));
        app.getStockMarket()->registerStock(Stock(Name("Tesla"), Symbol("TSLA")));
        app.getStockMarket()->registerStock(Stock(Name("Google"), Symbol("GOOGL")));
        app.getStockMarket()->registerStock(Stock(Name("Amazon"), Symbol("AMZN")));
        app.getStockMarket()->registerStock(Stock(Name("Meta"), Symbol("META")));
        app.getStockMarket()->registerStock(Stock(Name("Netflix"), Symbol("NFLX")));
        app.getStockMarket()->registerStock(Stock(Name("Adobe"), Symbol("ADBE")));
        app.getStockMarket()->registerStock(Stock(Name("Salesforce"), Symbol("CRM")));
        app.getStockMarket()->registerStock(Stock(Name("IBM"), Symbol("IBM")));
        app.getStockMarket()->registerStock(Stock(Name("Intel"), Symbol("INTC")));
        app.getStockMarket()->registerStock(Stock(Name("AMD"), Symbol("AMD")));

    }

};

// End2EndTest for the app which simulates a real environment in which a user Alexco wants to use the app
TEST_F(AppTest, End2EndTest) {
    // Test the setup of the app

    // Check if the traders are correctly initialized
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getName().toString(), "Alexco");
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getName().toString(), "Edi");
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getName().toString(), "GFA");

    // Check if the funds are correctly registered
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getFunds().getValue(), 1500);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getFunds().getValue(), 1000);
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getFunds().getValue(), 1200);

    // Check if the stocks for portofolios are correctly registered for each trader
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(100)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(50)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(150)), false);

    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Google"), Symbol("GOOGL")), Quantity(105)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Google"), Symbol("GOOGL")), Quantity(95)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Google"), Symbol("GOOGL")), Quantity(300)), false);

    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getPortfolio()->hasStock(Stock(Name("AMD"), Symbol("AMD")), Quantity(10)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getPortfolio()->hasStock(Stock(Name("AMD"), Symbol("AMD")), Quantity(1)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getPortfolio()->hasStock(Stock(Name("AMD"), Symbol("AMD")), Quantity(400)), false);


    // Check if the portofolios are correctly registered among the traders and the stock market
    EXPECT_EQ(app.getStockMarket()->getPortfolio(app.getTraderManager()->getTraders()[0]->getId()), app.getTraderManager()->getTraders()[0]->getPortfolio());
    EXPECT_EQ(app.getStockMarket()->getPortfolio(app.getTraderManager()->getTraders()[1]->getId()), app.getTraderManager()->getTraders()[1]->getPortfolio());
    EXPECT_EQ(app.getStockMarket()->getPortfolio(app.getTraderManager()->getTraders()[2]->getId()), app.getTraderManager()->getTraders()[2]->getPortfolio());

    // Check if the stocks are correctly registered in the stock market
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Apple"), Symbol("APPL")))->getBuyOrders().size(), 0);
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Apple"), Symbol("APPL")))->getSellOrders().size(), 0);
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Nvidia"), Symbol("NVDA")))->getBuyOrders().size(), 0);
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Nvidia"), Symbol("NVDA")))->getSellOrders().size(), 0);
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Microsoft"), Symbol("MSFT")))->getBuyOrders().size(), 0);
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Microsoft"), Symbol("MSFT")))->getSellOrders().size(), 0);


    // Simulation of a real user interacting with the app (Alexco is the main character of this simulation)

    // Setup of actual existing sell orders
    // Edi is selling 25 stocks of Apple at 10, he has 55 stocks in portofolio
    app.getStockMarket()->placeSellOrder(Order(
        app.getTraderManager()->getTraders()[1],
        Stock(Name("Apple"), Symbol("APPL")),
        Quantity(25),
        Price(10)
    ));

    // GFA is selling 100 stocks of Microsoft at 20, he has 150 stocks in portofolio
    app.getStockMarket()->placeSellOrder(Order(
    app.getTraderManager()->getTraders()[2],
    Stock(Name("Microsoft"), Symbol("MSFT")),
    Quantity(100),
    Price(20)
    ));

    // Check if the order is correctly placed
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Apple"), Symbol("APPL")))->getSellOrders().size(), 1);
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Microsoft"), Symbol("MSFT")))->getSellOrders().size(), 1);


    // Alexco is placing a buy order for 10 stocks of Apple at 10
    app.getStockMarket()->placeBuyOrder(Order(
        app.getTraderManager()->getTraders()[0],
        Stock(Name("Apple"), Symbol("APPL")),
        Quantity(10),
        Price(10)
    ));

    // Check if the result of the order has been processed for the buyer
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(110)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getFunds(), Funds(1500 - 10 * 10));

    // Check if the result of the order has been processed for the seller
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(55)), false);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(45)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getFunds(), Funds(1000 + 10 * 10));

    // Alexco is placing a buy order for 20 stocks of Microsoft at 25
    app.getStockMarket()->placeBuyOrder(Order(
        app.getTraderManager()->getTraders()[0],
        Stock(Name("Microsoft"), Symbol("MSFT")),
        Quantity(20),
        Price(25)
    ));

    // Check if the result of the order has been processed for the buyer
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Microsoft"), Symbol("MSFT")), Quantity(70)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getFunds(), Funds(1500 - 10 * 10 - 20 * 20));

    // Check if the result of the order has been processed for the seller
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getPortfolio()->hasStock(Stock(Name("Microsoft"), Symbol("MSFT")), Quantity(150)), false);
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getPortfolio()->hasStock(Stock(Name("Microsoft"), Symbol("MSFT")), Quantity(125)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getFunds(), Funds(1200 + 20 * 20));

    // GFA wants to withdraw some funds
    app.getTraderManager()->getTraders()[2]->withdrawFunds(Funds(100));
    EXPECT_EQ(app.getTraderManager()->getTraders()[2]->getFunds(), Funds(1200 + 20 * 20 - 100));

    // Alexco wants to buy more stocks of Apple (30 stocks at 10)
    app.getStockMarket()->placeBuyOrder(Order(
        app.getTraderManager()->getTraders()[0],
        Stock(Name("Apple"), Symbol("APPL")),
        Quantity(30),
        Price(10)
    ));

    // Check if the result of the order has been processed for the buyer
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(125)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(140)), false);
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getFunds(), Funds(1500 - 10 * 10 - 20 * 20 - 15 * 10));
    // Check if the result of the order has been processed for the seller
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(45)), false);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getPortfolio()->hasStock(Stock(Name("Apple"), Symbol("APPL")), Quantity(30)), true);
    EXPECT_EQ(app.getTraderManager()->getTraders()[1]->getFunds(), Funds(1000 + 10 * 10 + 15 * 10));

    // Check if the remaining 15 stocks of Apple are still in the order book since Edi had only 15 out of 30 stocks that Alexco wanted
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Apple"), Symbol("APPL")))->getBuyOrders().size(), 1);
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Apple"), Symbol("APPL")))->getBuyOrders()[0].getQuantity(), Quantity(15));
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("Apple"), Symbol("APPL")))->getBuyOrders()[0].getPrice(), Price(10));

    // Alexco wants to deposit some funds
    app.getTraderManager()->getTraders()[0]->depositFunds(Funds(1000));
    EXPECT_EQ(app.getTraderManager()->getTraders()[0]->getFunds(), Funds(1500 - 10 * 10 - 20 * 20 - 15 * 10 + 1000));

    // Alexco wants to sell some stocks of AMD (10 stocks at 10000)
    app.getStockMarket()->placeSellOrder(Order(
        app.getTraderManager()->getTraders()[0],
        Stock(Name("AMD"), Symbol("AMD")),
        Quantity(10),
        Price(10000)
    ));

    // Check if the sell order is correctly placed
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("AMD"), Symbol("AMD")))->getSellOrders().size(), 1);
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("AMD"), Symbol("AMD")))->getSellOrders()[0].getQuantity(), Quantity(10));
    EXPECT_EQ(app.getStockMarket()->getOrderBook(Stock(Name("AMD"), Symbol("AMD")))->getSellOrders()[0].getPrice(), Price(10000));

    // Now Alexco has done everything he wanted on the app for the moment so he leaves the app


}
