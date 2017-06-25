
#ifndef GAME_H
#define GAME_H

#include <jogo.h>

#include "rules.h"
#include "table.h"
#include "cardimage.h"

class OneSuitGame : public CardImageMouseEventHandler, private p3::JogoBasico<OneSuitCard, OneSuitTable>{

public:

    static const std::size_t number_of_rows = 10;
    
    OneSuitGame(std::string player, QGraphicsScene *scene = nullptr);

    ~OneSuitGame();
    
    void next_turn();

    void draw();
    
    void show_ascii();
    
    bool move(std::size_t deck1, std::size_t deck2, std::size_t n_cards);

    std::size_t turn() const;

    void click_event(int n_deck, int n_position){

        std::cout << "clicked" << std::endl;

        if(n_deck == -2){

            next_turn();

            draw();
        }
    }

    void release_event(int, int){


    }

private:
    
    void _distribute(int start = 0, int end = 9);
    
    void _turn_all();
    
    int _verify_sequence(const std::vector<std::pair<bool, OneSuitCard> >& deck, std::size_t n_cards);

    QGraphicsScene *_scene;

    std::vector<CardImage *> _images;

    CardImage *stack_image;
};

#endif
