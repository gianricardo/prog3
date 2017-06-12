
#include "game.h"

OneSuitGame::OneSuitGame(std::string player) : JogoBasico<OneSuitCard>(new Rules(), std::vector<std::string>(1, player)) {
    
    for(int i = 0; i < 10; i++) JogoBasico<OneSuitCard>::novo_monte();
    
    for(int i = 0; i < 5; i++) _distribute(0, 9);
    
    _distribute(0, 3);
    
    _turn_all();
}

void OneSuitGame::next_turn(){
    
    _distribute();
    
    _turn_all();
    
    JogoBasico<OneSuitCard>::fim_jogada();
}

void OneSuitGame::show(){
    
    std::vector<std::pair<bool, OneSuitCard> > cards[10];
    
    for(int i = 0; i < 10; i++){
        
        cards[i] = JogoBasico<OneSuitCard>::mostra_monte(i+1);
    }
    
    int i = 0;
    
    bool _continue;
    
    std::cout << '\n';
    
    do{
        
        _continue = false;
        
        for(int j = 0; j < 10; j++){
            
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
    
    std::cout << JogoBasico<OneSuitCard>::mostra_monte(0).size()/10;
    
    std::cout << '\n';
    
    for(int i = 0; i < 9; i++) std::cout << '\t';
    
    auto str = std::to_string(JogoBasico<OneSuitCard>::pontuacao_jogador_atual());
    
    for(int i = str.size(); i < 9; i++) std::cout << ' ';
    
    std::cout << str; 
    
    std::cout << std::endl;
}

bool OneSuitGame::move(std::size_t deck1, std::size_t deck2, std::size_t n_cards){
    
    if(deck1 >= 10) return false;
    if(deck2 >= 10) return false;
    
    auto d1 = JogoBasico<OneSuitCard>::mostra_monte(deck1 + 1);
    auto d2 = JogoBasico<OneSuitCard>::mostra_monte(deck2 + 1);
    
    int aux = _verify_sequence(d1, n_cards);
    
    if(aux == -1) return false;
    
    if(d2.size() > 0) if(d1[aux].second.numero() != d2.back().second.numero() - 1) return false;
    
    for(std::size_t i = 0; i < n_cards; i++) move_carta_mj(deck1+1, 0, false);
    
    auto vet = mostra_mao_jogador_atual();
    
    for(auto it = vet.rbegin(); it != vet.rend(); it++) move_carta_jm(*it, 0, deck2+1, false);
    
    if(aux != 0) if(!d1[aux-1].first) JogoBasico<OneSuitCard>::vira_carta_monte(deck1+1, false);
    
    JogoBasico<OneSuitCard>::jogador_subtrai_pontos(1);
    
    if(_verify_sequence(d2, 13) != -1){
        
        std::cout << "APARECEU AQUI" << std::endl;
        
        for(std::size_t i = 0; i < n_cards; i++) move_carta_mj(deck2, 0, false);
        
        if(JogoBasico<OneSuitCard>::mostra_mao_jogador_atual().size() == 0) next_turn();
    }
    
    return true;
}

std::size_t OneSuitGame::turn() const {
    
    return JogoBasico<OneSuitCard>::rodada();
}

void OneSuitGame::_distribute(int start, int end){
    
    start++;
    end += 2;
    
    for(int i = start; i < end; i++) JogoBasico<OneSuitCard>::move_carta_m(i, true, false);
}

void OneSuitGame::_turn_all(){
    
    for(int i = 1; i < 11; i++) JogoBasico<OneSuitCard>::vira_carta_monte(i, false);
}

int OneSuitGame::_verify_sequence(std::vector<std::pair<bool, OneSuitCard> >& deck, std::size_t n_cards){
 
    if(n_cards > deck.size()) return -1;
    
    std::size_t aux = deck.size() - n_cards;
    
    if(!deck[aux].first) return -1;
    
    for(std::size_t i = aux + 1; i < deck.size(); i++){
        
        if(deck[i].second.numero() != deck[i-1].second.numero() - 1) return -1;
    }
        
    return aux;
}




