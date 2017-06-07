
#include "game.h"

OneSuitGame::OneSuitGame(std::string player) : JogoBasico<OneSuitCard>(new Rules(), std::vector<std::string>(1, player)) {
    
    for(int i = 0; i < 8; i++) JogoBasico<OneSuitCard>::novo_monte();
}

void OneSuitGame::fim_jogada(){
    
    next_turn();
}

void OneSuitGame::next_turn(){
    
    for(int i = 1; i < 9; i++) JogoBasico<OneSuitCard>::move_carta_m(i);
    
    JogoBasico<OneSuitCard>::fim_jogada();
}
