
#include "jogo.h"
#include "cartaimagem.h"

#include <QApplication>

using namespace p3;

class Window : public QWidget {
    //Q_OBJECT

public:

    explicit Window(QWidget *parent = 0) : QWidget(parent){
        
        auto imagens = cria_imagem(200, 100);

        Carta c(3, Carta::Naipe::Espadas, true);

        imagens->addimagem(c, "Imagens/espadas.png");

        int y = 0;
        
        for(auto& image : ims){
            
            image = CartaImagem(c, imagens, this);
            
            image.y(y);
            
            image.display();
            
            y += 40;
        }
        
    }
    
private:
    
    CartaImagem ims[5];

};

int main(int argc, char **argv){
    
    QApplication app(argc, argv);
    
    Window window;
    
    window.setFixedSize(500, 500);

    window.show();

    return app.exec();
    
}
