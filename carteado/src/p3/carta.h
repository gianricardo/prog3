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

	static const int n_naipes = 4; // numero de naipes

	//Cria uma carta recebendo o valor do numero, naipe e um booleano indicando se a carta esta virada para cima
	Carta(int num, Naipe np, bool f = false);
	virtual ~Carta();

	//Retorna o valor da carta
	int numero() const;

	// Retorna o naipe da carta
	Naipe naipe() const;

	//Vira a carta
	void vira();

	//Indica se a face da carta esta virada para cima
	bool mostra() const;

	//Retorna true se a carta for igual a "c"
	bool operator==(const Carta& c) const;

	//Retorna true se a carta for diferente de "c"
	bool operator!=(const Carta& c) const;

private:
	int _numero;
	Naipe _naipe;
	bool _frente;
};

} /* namespace p3 */

#endif /* CARTA_H_ */
