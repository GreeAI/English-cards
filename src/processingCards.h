#ifndef PROCESSINGCARDS_H
#define PROCESSINGCARDS_H

#include "cards.h"
#include "nlohmann/json.hpp"

#include <vector>

using json = nlohmann::json;

class CardsProcessingLEG {
public:
    CardsProcessingLEG(std::string& nameDeck);

    void saveCardsInDeck(const Card& card);

    //void removeCardFromId(const uint16_t id);

    std::vector<Card> startRepeat();

    void updateDeckAfterRepeat(std::vector<Card>& cards);
private:
    size_t count_id_ = 0;
    std::vector<Card> cards_for_repeat_;
    std::string pathDeck_;

    json loadCard();

    void saveDeckInJsonConst(const json& deck);
    void saveDeckInJson(json& deck);

    size_t CountId(const json& deck);

    void reloadCardTimeFromId(const std::vector<Card>& cards, json& deck);
};

#endif // PROCESSINGCARDS_H
