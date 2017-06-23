
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include <QApplication>
#include "window.h"

#include "game.h"

using namespace p3;

class jogador : public Jogador{
    
    using Jogador::Jogador;
    
};

class mesa : public MesaBasica<Carta, jogador>{
    
    using MesaBasica<Carta, jogador>::MesaBasica;
};

class jogo : public JogoBasico<Carta, mesa>{
    
    using JogoBasico<Carta, mesa>::JogoBasico;
};


int main(int argc, char **argv){
    /*
    jogo j(new Regra(0, 0), {});

    OneSuitGame game("player");
    
    game.show();
    
    while(1){
        
        int source, dest, num;
        char quest;
        
        std::cout << "source: ";
        std::cin >> source;
        
        std::cin.ignore();
        
        game.show();
        
        std::cout << "destine: ";
        std::cin >> dest;
        
        std::cin.ignore();
        
        game.show();
        
        std::cout << "number of cards: ";
        std::cin >> num;
        
        std::cin.ignore();

        game.move(source, dest, num);
        
        game.show();
        
        std::cout << "distribute cards?(y/n)";
        std::cin >> quest;
        
        std::cin.ignore();
        
        game.show();
        
        if(quest >= 'A' && quest <= 'Z') quest += 'a' - 'A';
        
        if((quest == 'y' || quest == 's') && game.turn() != 6){
            
            game.next_turn();
            game.show();
        }
    }
    return 0;*/

    QApplication a(argc, argv);

    Window w;
    w.show();

    return a.exec();

}
