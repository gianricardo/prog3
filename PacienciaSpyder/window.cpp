
#include "window.h"

Window::Window(QWidget *parent /* = nullptr */) : QWidget(parent){
        
    auto imagens = p3::cria_imagem(150, 75);

    p3::Carta c(3, p3::Carta::Naipe::Espadas, true);

    imagens->addimagem(c, "Imagens/espadas.png");

    int y = 0;
    
    for(auto& image : ims){
        
        image = p3::CartaImagem(c, imagens, this);
        
        image.y(y);
        
        image.display();
        
        y += 25;
    }
}

