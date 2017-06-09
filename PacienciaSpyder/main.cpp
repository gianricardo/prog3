
//#include <QApplication>
//#include "window.h"

#include "game.h"

using namespace p3;

int main(){
    
    OneSuitGame game("player");
    
    game.show();
    
    while(1){
        
        int source, dest, num;
        char quest;
        
        std::cout << "source: ";
        std::cin >> source;
        
        std::cin.ignore();
        
        std::cout << "destine: ";
        std::cin >> dest;
        
        std::cin.ignore();
        
        std::cout << "cards number: ";
        std::cin >> num;
        
        std::cin.ignore();

        game.move(source, dest, num);
        
        game.show();
        
        std::cout << "distribute cards?(y/n)";
        std::cin >> quest;
        
        std::cin.ignore();
        
        if(quest >= 'A' && quest <= 'Z') quest += 'a' - 'A';
        
        if((quest == 'y' || quest == 's') && game.turn() != 6){
            
            game.next_turn();
            game.show();
        }
    }
    
    return 0;
}
