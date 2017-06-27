
#include "game.h"

OneSuitGame::OneSuitGame(std::string player, QGraphicsScene *scene /*= nullptr */) :
    JogoBasico<OneSuitCard, OneSuitTable>(new Rules(), std::vector<std::string>(1, player)), _scene(scene),
    _selected(-1, -1), _handler(nullptr) {
    
    for(std::size_t i = 0; i < number_of_rows; i++) JogoBasico<OneSuitCard, OneSuitTable>::novo_monte();
    
    for(int i = 0; i < 5; i++) _distribute(0, 9);
    
    _distribute(0, 3);
    
    _turn_all();

    if(_scene != nullptr){

        stack_image = new CardImage();

        stack_image->setX(315);
        stack_image->setY(180);

        _scene->addItem(stack_image);

        stack_image->setDeck(-2);

        stack_image->setMouseHandler(this);
    }
}

OneSuitGame::~OneSuitGame(){

    if(stack_image != nullptr) delete stack_image;

    for(auto images : _card_images){

        for(auto image : images){

            delete image;
        }
    }
}

void OneSuitGame::next_turn(){

    if(!JogoBasico<OneSuitCard, OneSuitTable>::fim_jogada()) return;

    if(turn() == 6){

        if(stack_image != nullptr){

            delete stack_image;

            stack_image = nullptr;
        }
    }
    
    _distribute();
    
    _turn_all();
}

void OneSuitGame::show_ascii(){
    
    std::vector<std::pair<bool, OneSuitCard> > cards[number_of_rows];
    
    for(std::size_t i = 0; i < number_of_rows; i++){
        
        cards[i] = JogoBasico<OneSuitCard, OneSuitTable>::mostra_monte(i+1);
    }
    
    int i = 0;
    
    bool _continue;
    
    std::cout << '\n';
    
    do{
        
        _continue = false;
        
        for(std::size_t j = 0; j < number_of_rows; j++){
            
            if(cards[j].size() > (std::size_t) i){
                
                if(!cards[j][i].first) std::cout << " ?";
                else{
                    
                    auto card = cards[j][i].second;
                    
                    if(card.numero() == 1) std::cout << " A";
                    else if(card.numero() == 10) std::cout << "10";
                    else if(card.numero() == 11) std::cout << " J";
                    else if(card.numero() == 12) std::cout << " Q";
                    else if(card.numero() == 13) std::cout << " K";
                    else std::cout << ' ' << char('0' + card.numero());
                }
                
                _continue = true;
            }
            else std::cout << "  ";
            
            for(int i = 0; i < 6; i++) std::cout << ' ';
        }
        
        std::cout << '\n';
        
        i++;
        
    }while(_continue);
    
    for(int j = i; j < 22; j++) std::cout << '\n';
    
    for(int i = 0; i < 10; i++) std::cout << '\t';
    
    std::cout << JogoBasico<OneSuitCard, OneSuitTable>::mostra_monte(0).size()/10;
    
    std::cout << '\n';
    
    for(int i = 0; i < 9; i++) std::cout << '\t';
    
    auto str = std::to_string(JogoBasico<OneSuitCard, OneSuitTable>::pontuacao_jogador_atual());
    
    for(int i = str.size(); i < 9; i++) std::cout << ' ';
    
    std::cout << str; 
    
    std::cout << std::endl;
}

bool OneSuitGame::move(std::size_t deck1, std::size_t deck2, std::size_t n_cards){

    if(deck1 >= number_of_rows) return false;
    if(deck2 >= number_of_rows) return false;
    
    auto d1 = JogoBasico<OneSuitCard, OneSuitTable>::mostra_monte(deck1 + 1);
    auto d2 = JogoBasico<OneSuitCard, OneSuitTable>::mostra_monte(deck2 + 1);
    
    int aux = _verify_sequence(d1, n_cards);
    
    if(aux == -1) return false;
    
    if(d2.size() > 0) if(d1[aux].second.numero() != d2.back().second.numero() - 1) return false;
    
    for(std::size_t i = 0; i < n_cards; i++) move_carta_mj(deck1+1, 0, false);
    
    auto vet = mostra_mao_jogador_atual();
    
    auto rend = vet.rbegin() + n_cards;
    
    for(auto it = vet.rbegin(); it != rend; it++) move_carta_jm(*it, 0, deck2+1, false);

    if(_scene != nullptr) _move_images(deck1, deck2, n_cards);
    
    if(aux != 0) if(!d1[aux-1].first){

        JogoBasico<OneSuitCard, OneSuitTable>::vira_carta_monte(deck1+1, false);

        if(_scene != nullptr) _turn_card_image(deck1);
    }
    
    JogoBasico<OneSuitCard, OneSuitTable>::jogador_subtrai_pontos(1);
    
    if(_verify_sequence(JogoBasico<OneSuitCard, OneSuitTable>::mostra_monte(deck2 + 1), 13) != -1){

        for(std::size_t i = 0; i < 13; i++) move_carta_mj(deck2+1, 0, false);

        if(_scene != nullptr){

            for(auto it = _card_images[deck2].end() - 13; it != _card_images[deck2].end(); it++) delete *it;

            _card_images[deck2].erase(_card_images[deck2].end() - 13,  _card_images[deck2].end());
        }

        if(this->_mesa.tamanho_monte(deck2 + 1) == 0){

            _gen_blank_image(deck2);
        }
        else if(this->_mesa.bottom_card(deck2 + 1).numero() == 0) {

            this->vira_carta_monte(deck2 + 1, false);

            if(_scene != nullptr) _turn_card_image(deck2);
        }


        if(this->mostra_mao_jogador_atual().size() >= (std::size_t) this->cartas_inicial()){

            if(_handler != nullptr) _handler->gameover_event(true);
        }
    }
    
    //show_ascii();

    return true;
}

std::size_t OneSuitGame::turn() const {
    
    return JogoBasico<OneSuitCard, OneSuitTable>::rodada();
}

void OneSuitGame::click_event(int n_deck, int n_position) {

    //std::cout << "clicked: " <<  n_deck << ", " << n_position << std::endl;

    select(n_deck, n_position);

    if(n_deck == -2) next_turn();
}

void OneSuitGame::select(int n_deck, int n_position){

    if(_selected.first >= 0) unglow(_selected.first, _selected.second);

    if(_selected.first == n_deck && _selected.second == n_position){

        _selected.first = -1;

        return;
    }

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

void OneSuitGame::setEventHandler(GameEventHandler *handler){

    _handler = handler;
}

void OneSuitGame::_distribute(int start, int end){
    
    end++;

    if(_scene != nullptr){

        for(int i = start; i < end; i++){

            CardImage *img = new CardImage();

            img->setX(35*i);
            img->setY(10*this->_mesa.tamanho_monte(i+1));
            img->setZValue(this->_mesa.tamanho_monte(i+1));

            img->setDeck(i);
            img->setDeckPosition(this->_mesa.tamanho_monte(i+1));

            img->setMouseHandler(this);

            _scene->addItem(img);

            _card_images[i].push_back(img);
        }
    }

    start++;
    end++;
    
    for(int i = start; i < end; i++) JogoBasico<OneSuitCard, OneSuitTable>::move_carta_m(i, true, false);
}

void OneSuitGame::_turn_all(){
    
    for(std::size_t i = 1; i < number_of_rows + 1; i++){

        JogoBasico<OneSuitCard, OneSuitTable>::vira_carta_monte(i, false);
    }

    if(_scene != nullptr){

        for(std::size_t i = 0; i < number_of_rows; i++){

            _turn_card_image(i);
        }
    }

    //show_ascii();
}

int OneSuitGame::_verify_sequence(const std::vector<std::pair<bool, OneSuitCard> >& deck, std::size_t n_cards){
 
    if(n_cards > deck.size()) return -1;
    
    std::size_t aux = deck.size() - n_cards;
    
    if(!deck[aux].first) return -1;
    
    for(std::size_t i = aux + 1; i < deck.size(); i++){
        
        if(deck[i].second.numero() != deck[i-1].second.numero() - 1) return -1;
    }
        
    return aux;
}

void OneSuitGame::glow(int n_deck, int n_position){

    auto start = _card_images[n_deck].begin() + n_position;
    auto end = _card_images[n_deck].end();

    for(auto it = start; it != end; it++){

        (*it)->setTransparent(true);
    }
}

void OneSuitGame::unglow(int n_deck, int n_position){

    auto start = _card_images[n_deck].begin() + n_position;
    auto end = _card_images[n_deck].end();

    for(auto it = start; it != end; it++){

        (*it)->setTransparent(false);
    }
}

void OneSuitGame::_move_images(std::size_t deck1, std::size_t deck2, int n_cards){

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

void OneSuitGame::_turn_card_image(int deck){

    if(_scene != nullptr){

        CardImage *img = _card_images[deck].back();
        OneSuitCard card = this->_mesa.bottom_card(deck+1);

        img->setCard(card.numero(), (int) card.naipe());

        img->setUp(true);

        img->update();
    }
}

void OneSuitGame::_gen_blank_image(int deck){

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
