
#ifndef IMAGEM_H_
#define IMAGEM_H_

#include <iostream>

#include <map>
#include <memory>
#include <QImage>
#include <QLabel>

#include "carta.h"

namespace p3{

template<class CARTA>
class ImagemBasica{

public:

	static const std::size_t normal_size = std::numeric_limits<std::size_t>::max();

	ImagemBasica(std::size_t height = normal_size, std::size_t width = normal_size);
	ImagemBasica(const ImagemBasica<CARTA>& im);

	void addimagem(const CARTA& carta, std::string path);

	void addimagem_virada(std::string path);

	QPixmap imagem(const CARTA& carta) const;

	QPixmap operator[](const CARTA& carta) const;

	std::size_t height() const;
	std::size_t width() const;

private:

	std::map<CARTA, QPixmap> _imagens;
	QPixmap _imagem_carta_virada;
	
	const std::size_t _height, _width;
};

template<class CARTA> ImagemBasica<CARTA>::ImagemBasica(std::size_t height, std::size_t width) : _height{height}, _width{width} {
	

}

template<class CARTA> ImagemBasica<CARTA>::ImagemBasica(const ImagemBasica<CARTA>& im) : _imagens{im._imagens}, 
														_imagem_carta_virada{im._imagem_carta_virada},
														_height{im._height}, _width{im.width} {


}

template<class CARTA> void ImagemBasica<CARTA>::addimagem(const CARTA& carta, std::string path){
	
	CARTA c = carta;

	if(!c.mostra()) c.vira();

	QImage im;

	std::cout << im.load(QString::fromStdString(path)) << std::endl;

	_imagens[c] = QPixmap::fromImage(im.scaled((_width == normal_size) ? im.width() : _width, 
											   (_height == normal_size) ? im.height() : _height));
}

template<class CARTA> void ImagemBasica<CARTA>::addimagem_virada(std::string path){
	
	QImage im;

	im.load(QString::fromStdString(path));

	_imagem_carta_virada = QPixmap::fromImage(im.scaled((_width == normal_size) ? im.width() : _width, 
														(_height == normal_size) ? im.height() : _height));
}

template<class CARTA> QPixmap ImagemBasica<CARTA>::imagem(const CARTA& carta) const {
	
	return (*this)[carta];
}


template<class CARTA> QPixmap ImagemBasica<CARTA>::operator[](const CARTA& carta) const {

	if(carta.mostra()){

		auto it = _imagens.find(carta);

		if(it == _imagens.end()) return QPixmap();

		return it->second;
	}

	return _imagem_carta_virada;
}


template<class CARTA> std::size_t ImagemBasica<CARTA>::height() const {
	
	return _height;
}


template<class CARTA> std::size_t ImagemBasica<CARTA>::width() const {
	
	return _width;
}


template<class CARTA, typename... Args> std::shared_ptr<ImagemBasica<CARTA> > cria_imagembasica(Args... args){
	
	return std::make_shared<ImagemBasica<CARTA> >(args...);
}


using Imagem = ImagemBasica<Carta>;


template<typename... Args> std::shared_ptr<Imagem> cria_imagem(Args... args){
	
	return std::make_shared<Imagem>(args...);
}

} /* namespace p3 */

#endif /* IMAGEM_H_ */



