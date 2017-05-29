
#ifndef CARTAIMAGEM_H_
#define CARTAIMAGEM_H_

#include "imagem.h"

namespace p3{

template<class CARTA>
class CartaImagemBasica{

public:

	CartaImagemBasica(const CartaImagemBasica& im);
	CartaImagemBasica(CARTA c = CARTA(0, (typename CARTA::Naipe) 0), std::shared_ptr<ImagemBasica<CARTA> > images = nullptr, 
					  QWidget *parent = nullptr);
	
	~CartaImagemBasica();

	const CartaImagemBasica<CARTA>& operator=(const CartaImagemBasica<CARTA>& im);

	const CARTA carta() const;

	void x(std::size_t value);
	std::size_t x() const;

	void y(std::size_t value);
	std::size_t y() const;

	void display();

	void undisplay();

	void parent(QWidget *parent);

private:

	QLabel *_im;
	std::shared_ptr<ImagemBasica<CARTA> > _images;
	std::size_t _x, _y;
	CARTA _carta;
	QWidget *_parent;
};

template<class CARTA> CartaImagemBasica<CARTA>::CartaImagemBasica(const CartaImagemBasica& im) : _im(im._im), _images(im._images), 
																  _x(im._x), _y(im._y), _carta(im._carta), _parent(im._parent){
	
}

template<class CARTA> const CartaImagemBasica<CARTA>& CartaImagemBasica<CARTA>::operator=(const CartaImagemBasica<CARTA>& im){
	
	_im = im._im;
	_images = im._images;
	_x = im._x;
	_y = im._y;
	_carta = im._carta;
	_parent = im._parent;

	return *this;
}

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

template<class CARTA> void CartaImagemBasica<CARTA>::x(std::size_t value) {
	
	_x = value;

	if(_im != nullptr){

		auto r = _im->geometry();

		r.setY(_x);

		_im->setGeometry(r);
	}
}

template<class CARTA> void CartaImagemBasica<CARTA>::y(std::size_t value) {
	
	_y = value;

	if(_im != nullptr){

		auto r = _im->geometry();

		r.setY(_y);

		_im->setGeometry(r);
	}
}


using CartaImagem = CartaImagemBasica<Carta>;

} /* namespace p3 */

#endif /* CARTAIMAGEM_H_ */
