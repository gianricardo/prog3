
#ifndef GAME_H
#define GAME_H

#include <jogo.h>

#include "rules.h"
#include "table.h"
#include "cardimage.h"

class GameEventHandler{

public:

    virtual void gameover_event(bool won) = 0;
};

class OneSuitGame : public CardImageMouseEventHandler, private p3::JogoBasico<OneSuitCard, OneSuitTable>{

public:

    static const std::size_t number_of_rows = 10;
    
    OneSuitGame(std::string player, QGraphicsScene *scene = nullptr);

    ~OneSuitGame();
    
    void next_turn();
    
    void show_ascii();
    
    bool move(std::size_t deck1, std::size_t deck2, std::size_t n_cards);

    std::size_t turn() const;

    void click_event(int n_deck, int n_position) override ;

    void select(int n_deck, int n_position);

    void setEventHandler(GameEventHandler *handler);

private:
    
    void _distribute(int start = 0, int end = 9);
    
    void _turn_all();
    
    int _verify_sequence(const std::vector<std::pair<bool, OneSuitCard> >& deck, std::size_t n_cards);

    void glow(int n_deck, int n_position);

    void unglow(int n_deck, int n_position);

    void _move_images(std::size_t deck1, std::size_t deck2, int n_cards);

    void _turn_card_image(int deck);

    void _gen_blank_image(int deck);

    QGraphicsScene *_scene;

    std::vector<CardImage *> _card_images[number_of_rows];
    CardImage *stack_image;

    std::pair<int, int> _selected;

    GameEventHandler *_handler;
};

#endif
