
#ifndef GAME_H
#define GAME_H

#include <jogo.h>

#include "rules.h"
#include "cards.h"

class OneSuitGame : private p3::JogoBasico<OneSuitCard> {

public:
    
    OneSuitGame(std::string player);
    
    void next_turn();
    
    void show();
    
    bool move(std::size_t deck1, std::size_t deck2, std::size_t n_cards);
    
    std::size_t turn() const;
    
private:
    
    void _distribute(int start = 0, int end = 9);
    
    void _turn_all();
    
    int _verify_sequence(const std::vector<std::pair<bool, OneSuitCard> >& deck, std::size_t n_cards);
};

#endif
