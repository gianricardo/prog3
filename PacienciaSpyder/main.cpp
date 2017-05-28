
#include "jogo.h"
#include "cartaimagem.h"

#include <QApplication>
#include <QPushButton>

using namespace p3;

class Window : public QWidget {
    //Q_OBJECT

public:

    explicit Window(QWidget *parent = 0) : QWidget(parent){
        
        auto imagens = cria_imagem(200, 100);

        Carta c(2, Carta::Naipe::Espadas, true);

        imagens->addimagem(c, "Imagens/espadas.png");

        im = std::make_unique<CartaImagem>(c, imagens, this);
        
        im->display();
        
        minus_button = new QPushButton("-", this);
        
        minus_button->setGeometry(100, 100, 30, 30);
    }
    
private:
    
    QPushButton *minus_button;
    std::unique_ptr<CartaImagem> im;

};

int main(int argc, char **argv){
    
    QApplication app(argc, argv);
    
    Window window;
    
    window.setFixedSize(500, 500);

    window.show();

    return app.exec();
    
}
