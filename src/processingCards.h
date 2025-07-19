#ifndef PROCESSINGCARDS_H
#define PROCESSINGCARDS_H

#include "cards.h"
#include "nlohmann/json.hpp"

#include <vector>

using json = nlohmann::json;

class CardsProcessingLEG {
public:

    CardsProcessingLEG();

    void saveCardsInDeck(const Card& card);
    json loadCard();

    void saveDeckInJsonConst(const json& deck);
    void saveDeckInJson(json& deck);

    void removeCardFromId(const uint16_t id);

    //bool checkSameID(const json& deck, const uint16_t id);

    size_t CountId(const json& deck);

    void reloadCardTimeFromId(const std::vector<Card> &cards, json& deck);

    std::vector<Card> startRepeat();

    void updateDeckAfterRepeat(std::vector<Card>& cards);
private:
    size_t count_id_ = 0;
    std::vector<Card> cards_for_repeat_;
};

#endif // PROCESSINGCARDS_H
