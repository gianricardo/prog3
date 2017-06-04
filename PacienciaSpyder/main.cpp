
//#include <QApplication>
//#include "window.h"
#include "jogo.h"

using namespace p3;

int main(){
    
    Jogo j(new Regra(2, 4, -1, -1, -1, 12), {"j1", "j2"});
    
    j.vira_carta_monte(0, true); // vira a carte de cima do primeiro baralho
    
    j.vira_carta_jogador(1); // vira a segunda carta do jogador atual
    
    return 0;
    
}
