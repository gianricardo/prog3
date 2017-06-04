
//#include <QApplication>
//#include "window.h"
#include <jogo.h>

#include "rules.h"
#include "cards.h"

using namespace p3;

int main(){
    
    Jogo j(new Rules(), {"player"});
    
    Baralho b(52);
    
    b.vira_topo();
    b.vira_baixo();
    
    auto vec = b.mostra_baralho();
    
    for(auto pair : vec){
        
        std::cout << std::boolalpha << pair.first << "//" << pair.second.numero() << std::endl;
    }
    
    return 0;
    
}
