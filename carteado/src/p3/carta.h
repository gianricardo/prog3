/*
 * carta.h
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#ifndef CARTA_H_
#define CARTA_H_

namespace p3 {

class Carta {
public:
	enum class Naipe{Espadas,Copas,Paus,Ouros};
	Carta(int num, Naipe np,bool f);
	virtual ~Carta();
	int numero();
	Naipe naipe();
	void vira();
	bool mostra();
private:
	int _numero;
	Naipe _naipe;
	bool _frente;
};

} /* namespace p3 */

#endif /* CARTA_H_ */
