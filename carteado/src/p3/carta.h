/*
 * carta.h
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#ifndef CARTA_H_
#define CARTA_H_
#include <string>

namespace p3 {

class Carta {
public:
	enum class Naipe{Espadas,Copas,Paus,Ouros};

	static const int n_naipes = 4;

	Carta(int num, Naipe np, bool f = false);
	virtual ~Carta();
	int numero() const;
	Naipe naipe() const;
	void vira();
	bool mostra() const;

	bool operator==(const Carta& c) const;
	bool operator!=(const Carta& c) const;

private:
	int _numero;
	Naipe _naipe;
	bool _frente;
};

} /* namespace p3 */

#endif /* CARTA_H_ */
