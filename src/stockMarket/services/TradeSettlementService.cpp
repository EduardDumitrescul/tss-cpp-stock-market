//
// Created by gfa on 5/6/25.
//

#include "TradeSettlementService.h"

void TradeSettlementService::applyTrades(const std::vector<Trade> &trades) {
    for (const Trade& trade : trades) {
        if (!settleTrade(trade)) {
            throw std::runtime_error("Trade settlement failed");
        }
    }
}


bool TradeSettlementService::settleTrade(const Trade &trade) {
    const auto tradeFunds = trade.getTotalFunds();

    auto buyer = trade.getBuyer();
    auto seller = trade.getSeller();
    auto stock = trade.getStock();
    auto quantity = trade.getQuantity();

    auto buyerPortfolio = buyer->getPortfolio();
    auto sellerPortfolio = seller->getPortfolio();

    if (!sellerPortfolio->hasStock(stock, quantity)) return false;
    if (!buyerPortfolio->hasFunds(tradeFunds)) return false;

    buyer->withdrawFunds(tradeFunds);
    seller->depositFunds(tradeFunds);

    sellerPortfolio->removeStock(stock, quantity);
    buyerPortfolio->addStock(stock, quantity);

    return true;
}

