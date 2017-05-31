	

#ifndef CARTAIMAGEM_H_
#define CARTAIMAGEM_H_

#include "imagem.h"

namespace p3{

template<class CARTA>
class CartaImagemBasica : public QLabel{

public:

	CartaImagemBasica(const CartaImagemBasica& im);
	CartaImagemBasica(CARTA c = CARTA(0, (typename CARTA::Naipe) 0), std::shared_ptr<ImagemBasica<CARTA> > images = nullptr, 
					  QWidget *parent = nullptr);

	const CARTA carta() const;

	void x(std::size_t value);
	std::size_t x() const;

	void y(std::size_t value);
	std::size_t y() const;
	

	void parent(QWidget *parent);

private:

	std::shared_ptr<ImagemBasica<CARTA> > _images;
	CARTA _carta;
};

template<class CARTA> CartaImagemBasica<CARTA>::CartaImagemBasica(const CartaImagemBasica& im) : QLabel(im.parent()), 
																									_images(im._images), _carta(im._carta){ 

}


template<class CARTA> CartaImagemBasica<CARTA>::CartaImagemBasica(CARTA c, std::shared_ptr<ImagemBasica<CARTA> > images, QWidget *parent) : 
																			QLabel(parent), _images(images), _carta(c){
	

	QLabel::setPixmap((*_images)[_carta]);

	QLabel::setGeometry(0, 0, _images->width(), _images->height());
}

template<class CARTA> const CARTA CartaImagemBasica<CARTA>::carta() const {
	
	return _carta;
}

template<class CARTA> void CartaImagemBasica<CARTA>::x(std::size_t value) {

	auto r = QLabel::geometry();

	r.setX(value);

	r.setWidth(r.width() + value);

	QLabel::setGeometry(r);

}

template<class CARTA> void CartaImagemBasica<CARTA>::y(std::size_t value) {

	auto r = QLabel::geometry();

	r.setY(value);

	r.setHeight(r.height() + value);

	QLabel::setGeometry(r);
}


using CartaImagem = CartaImagemBasica<Carta>;

} /* namespace p3 */

#endif /* CARTAIMAGEM_H_ */
