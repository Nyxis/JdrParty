#ifndef JDR_CARDSADAPTER_H
#define JDR_CARDSADAPTER_H
#include <iostream>


class CardsAdapter {
public:
    static std::string cardsAdapter(int cardType, int cardNumber);
    static std::string getCardType(int type);
    static std::string getCard(int card);
    virtual ~CardsAdapter();
};


#endif //JDR_CARDSADAPTER_H
