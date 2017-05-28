
#ifndef CARTAIMAGEM_H_
#define CARTAIMAGEM_H_

#include "imagem.h"

namespace p3{

template<class CARTA>
class CartaImagemBasica{

public:

	CartaImagemBasica(CARTA c = CARTA(0, (typename CARTA::Naipe) 0), std::shared_ptr<ImagemBasica<CARTA> > images = nullptr, 
					  QWidget *parent = nullptr);
	~CartaImagemBasica();

	const CARTA carta() const;

	void x(std::size_t);
	std::size_t x() const;

	void y(std::size_t);
	std::size_t y() const;

	void display();

	void undisplay();

	void parent(QWidget *parent);

private:

	QLabel *_im;
	std::shared_ptr<ImagemBasica<CARTA> > _images;
	std::size_t _x, _y;
	const CARTA _carta;
	QWidget *_parent;
};

template<class CARTA> CartaImagemBasica<CARTA>::CartaImagemBasica(CARTA c, std::shared_ptr<ImagemBasica<CARTA> > images, 
																  QWidget *parent) : _im(nullptr), _images(images), 
																  _x(0), _y(0), _carta(c), _parent(parent){
	
}

template<class CARTA> CartaImagemBasica<CARTA>::~CartaImagemBasica(){
	
	if(_im != nullptr) delete _im;
}

template<class CARTA> const CARTA CartaImagemBasica<CARTA>::carta() const {
	
	return _carta;
}

template<class CARTA> void CartaImagemBasica<CARTA>::display() {
	
	_im = new QLabel(_parent);

	_im->setPixmap((*_images)[_carta]);

	_im->setGeometry(_x, _y, _images->width(), _images->height());

	_im->show();
}


using CartaImagem = CartaImagemBasica<Carta>;

} /* namespace p3 */

#endif /* CARTAIMAGEM_H_ */
