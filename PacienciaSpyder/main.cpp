
//#include <QApplication>
//#include "window.h"

#include "game.h"

using namespace p3;

int main(){
    
    OneSuitGame game("player");
    
    game.next_turn();
    
    return 0;
    
}
