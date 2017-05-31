
#include "window.h"

Window::Window(QWidget *parent /* = nullptr */) : QWidget(parent){
        
    auto imagens = p3::cria_imagem(150, 75);

    p3::Carta c(3, p3::Carta::Naipe::Espadas, true);

    imagens->addimagem(c, "Imagens/espadas.png");

    img = new p3::CartaImagem(c, imagens, this);
    
    img->x(200);
    img->y(200);
    
    QObject::connect(img, SIGNAL (linkHovered(const QString&)), img, SLOT (setText(const QString&)));
    
    int y = 0;
    
    for(auto& image : ims){
    
        image = new p3::CartaImagem(c, imagens, this);
        
        image->y(y);
        
        image->show();
        
        y += 25;
    }
    
}

