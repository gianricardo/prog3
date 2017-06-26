
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
    
    void show_ascii();
    
    bool move(std::size_t deck1, std::size_t deck2, std::size_t n_cards);

    std::size_t turn() const;

    void click_event(int n_deck, int n_position){

        Q_UNUSED(n_position);

        std::cout << "clicked: " <<  n_deck << ", " << n_position << std::endl;

        select(n_deck, n_position);

        if(n_deck == -2) next_turn();
    }

    void release_event(int, int){


    }

    void select(int n_deck, int n_position){

        if(_selected.first >= 0) unglow(_selected.first, _selected.second);

        if(n_deck < 0 || n_position < -1 || (std::size_t)n_deck >= number_of_rows) return;

        if(n_position == -1 && _selected.first == -1) return;

        int n_cards = this->_mesa.tamanho_monte(n_deck + 1) - n_position;

        if(n_cards <= 0 && _selected.first == -1) return;

        if(_selected.first >= 0 && n_deck != _selected.first){

            if(std::size_t(n_position + 1) == this->_mesa.tamanho_monte(n_deck + 1)) {

                move(_selected.first, n_deck,
                     this->_mesa.tamanho_monte(_selected.first + 1) - _selected.second);
            }

            _selected.first = -1;
        }
        else if(_verify_sequence(this->mostra_monte(n_deck + 1), n_cards) != -1){

            _selected.first = n_deck;
            _selected.second = n_position;

            glow(n_deck, n_position);
        }
        else{

            _selected.first = -1;
        }
    }

private:
    
    void _distribute(int start = 0, int end = 9);
    
    void _turn_all();
    
    int _verify_sequence(const std::vector<std::pair<bool, OneSuitCard> >& deck, std::size_t n_cards);

    void glow(int n_deck, int n_position){

        auto start = _card_images[n_deck].begin() + n_position;
        auto end = _card_images[n_deck].end();

        for(auto it = start; it != end; it++){

            (*it)->setTransparent(true);
        }
    }

    void unglow(int n_deck, int n_position){

        auto start = _card_images[n_deck].begin() + n_position;
        auto end = _card_images[n_deck].end();

        for(auto it = start; it != end; it++){

            (*it)->setTransparent(false);
        }
    }

    void _move_images(std::size_t deck1, std::size_t deck2, int n_cards){

        auto& deck1_images = _card_images[deck1];
        auto& deck2_images = _card_images[deck2];

        if(deck2_images.size() == 1){

            if(deck2_images[0]->deckPosition() == -1){

                delete deck2_images[0];

                deck2_images.clear();
            }
        }

        int i = deck2_images.size(), aux_x = 35*deck2;

        std::vector<CardImage *>::iterator start_it = deck1_images.end() - n_cards,
                end_it = deck1_images.end();

        deck2_images.insert(deck2_images.end(), start_it, end_it);

        for(auto it = deck1_images.end() - n_cards; it != deck1_images.end(); it++){

            (*it)->setX(aux_x);
            (*it)->setY(10*i);
            (*it)->setDeck(deck2);
            (*it)->setDeckPosition(i);
            (*it)->setZValue(i);

            i++;
        }

        deck1_images.erase(start_it, end_it);

        if(deck1_images.size() == 0) _gen_blank_image(deck1);
    }

    void _turn_card_image(int deck){

        if(_scene != nullptr){

            CardImage *img = _card_images[deck].back();
            OneSuitCard card = this->_mesa.bottom_card(deck+1);

            img->setCard(card.numero(), (int) card.naipe());

            img->setUp(true);

            img->update();
        }
    }

    void _gen_blank_image(int deck){

        CardImage *img = new BlankCardImage();

        img->setX(35*deck);
        img->setY(0);
        img->setDeck(deck);
        img->setDeckPosition(-1);
        img->setZValue(0);

        img->setMouseHandler(this);

        _card_images[deck].push_back(img);

        _scene->addItem(img);
    }

    QGraphicsScene *_scene;

    std::vector<CardImage *> _card_images[number_of_rows];
    CardImage *stack_image;

    std::pair<int, int> _selected;
};

#endif
