#include "processingCards.h"
#include "SR.h"

#include <fstream>
#include <iostream>

using json = nlohmann::json;
const uint8_t InitialValueSR = 1;
const time_t SecondOneDay = 86400; // second in one day

CardsProcessingLEG::CardsProcessingLEG(std::string &nameDeck) {
    pathDeck_ = "../../decks/";
    pathDeck_ += nameDeck;
    pathDeck_ += ".json";

    std::cout << pathDeck_;
}

void CardsProcessingLEG::saveCardsInDeck(const Card& card) {
    json data = loadCard();
    count_id_ = CountId(data);
    count_id_++;

    time_t now = time(nullptr);
    json card_data;
    card_data["id"] = count_id_;
    card_data["en"] = card.en;
    card_data["ru"] = card.ru;
    card_data["sr"] = InitialValueSR;
    card_data["nextReview"] = now;

    data.emplace_back(card_data);

    saveDeckInJson(data);
}

void CardsProcessingLEG::saveDeckInJsonConst(const json& deck) {
    std::ofstream file(pathDeck_, std::ios::trunc);
    if(file.is_open()) {
        file << deck.dump(4);
    } else {
        throw std::runtime_error("Failed to open file for writing");
    }
}

void CardsProcessingLEG::saveDeckInJson(json& deck) {
    std::ofstream file(pathDeck_, std::ios::trunc);
    if(file.is_open()) {
        file << deck.dump(4);
    } else {
        throw std::runtime_error("Failed to open file for writing");
    }
}

json CardsProcessingLEG::loadCard() {
    std::ifstream file(pathDeck_);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open deck.json for reading");
    }
    json arr;
    if (file.peek() != std::ifstream::traits_type::eof()) {
        file >> arr;
        return arr;
    }

    return arr;
}

void CardsProcessingLEG::removeCardFromId(const uint16_t id) {
    std::fstream file(pathDeck_);
    json deck = loadCard();

    auto it = std::find_if(deck.begin(), deck.end(),
                           [id](const json& card) {
                               return card["id"] == id;
                           });

    if (it != deck.end()) {
        deck.erase(it);
    }
    saveDeckInJson(deck);
}

// bool CardsProcessingLEG::checkSameID(const json& deck, const uint16_t id) {
//     for (const auto card : deck) {
//         if (card["id"] == id) {
//             return true;
//         }
//     }
//     return false;
// }

size_t CardsProcessingLEG::CountId(const json& deck) {
    return deck.size();
}

void CardsProcessingLEG::reloadCardTimeFromId(const std::vector<Card> &cards, json& deck) {
    for(auto& card_ : cards) {
        int id = card_.id;
        auto it = std::find_if(deck.begin(), deck.end(),
                        [id](const json& card) {
                            return card["id"] == id;
                        });

        if (it != deck.end()) {
            deck.erase(it);
        }
    }

    json card_data;
    for(const Card& card: cards) {
        card_data["id"] = card.id;
        card_data["en"] = card.en;
        card_data["ru"] = card.ru;
        card_data["sr"] = card.sr;
        card_data["nextReview"] = SRLEG::processingDate(card.sr);

        deck.emplace_back(card_data);
    }

    saveDeckInJson(deck);
}

std::vector<Card> CardsProcessingLEG::startRepeat() {
    time_t now = time(nullptr);

    json deck = loadCard();
    std::vector<Card> cards;

    for(const auto& card: deck) {
        Card card_add;
        if(card["nextReview"] <= now) {
            card_add.en = card["en"].get<std::string>();
            card_add.id = card["id"].get<uint16_t>();
            card_add.ru = card["ru"].get<std::string>();
            card_add.sr = card["sr"].get<uint8_t>();
            card_add.nextReview = card["nextReview"].get<time_t>();;

            cards.push_back(card_add);
        }
    }

    return cards;
}

void CardsProcessingLEG::updateDeckAfterRepeat(std::vector<Card>& cards) {
    json deck = loadCard();
    reloadCardTimeFromId(cards, deck);
}


