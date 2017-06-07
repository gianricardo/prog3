
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
                
                for(int i = 0; i < 6; i++) std::cout << ' ';
                
                _continue = true;
            }
        }
        
        std::cout << '\n';
        
        i++;
        
    }while(_continue);
    
    for(int j = i; j < 23; j++) std::cout << '\n';
    
    for(int i = 0; i < 10; i++) std::cout << '\t';
    
    std::cout << JogoBasico<OneSuitCard>::mostra_monte(0).size()/10;
        
    std::cout << std::endl;
}

void OneSuitGame::_distribute(int start, int end){
    
    start++;
    end += 2;
    
    for(int i = start; i < end; i++) JogoBasico<OneSuitCard>::move_carta_m(i, true, false);
}

void OneSuitGame::_turn_all(){
    
    for(int i = 1; i < 11; i++) JogoBasico<OneSuitCard>::vira_carta_monte(i, false);
}



