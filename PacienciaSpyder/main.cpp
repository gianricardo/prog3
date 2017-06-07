
//#include <QApplication>
//#include "window.h"

#include "game.h"

using namespace p3;

int main(){
    
    OneSuitGame game("player");
    
    game.show();
    
    char a;
    
    std::cin >> a;
    
    game.next_turn();
    
    game.show();
    
    std::cin >> a;
    
    game.next_turn();
    
    game.show();
    std::cin >> a;
    
    game.next_turn();
    
    game.show();
    
    std::cin >> a;
    
    game.next_turn();
    
    game.show();
    
    return 0;
    
}
