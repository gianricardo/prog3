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

	//representa os naipes existentes para criar uma carta
	enum class Naipe{Espadas,Copas,Paus,Ouros};

	// numero de naipes
	static const int n_naipes = 4;

	//Cria uma carta
	//recebe o valor do numero, naipe e um booleano indicando se a carta esta virada para cima
	Carta(int num, Naipe np, bool f = false);

	//Destrutor
	virtual ~Carta();

	//Retorna o valor da carta
	int numero() const;

	//Retorna o naipe da carta
	Naipe naipe() const;

	//Vira a carta
	void vira();

	//Indica se a face da carta esta virada para cima
	bool mostra() const;

	//Retorna true se a carta for igual a "c"
	bool operator==(const Carta& c) const;

	//Retorna true se a carta for diferente de "c"
	bool operator!=(const Carta& c) const;

	//retorna true se a carta for menor que "c"
	bool operator<(const Carta& c) const;

	//retorna true se a carta for maior que "c"
	bool operator>(const Carta& c) const;

	//retorna true se a carta for menor ou igual a "c"
	bool operator<=(const Carta& c) const;

	//retorna true se a carta for maior ou igual a "c"
	bool operator>=(const Carta& c) const;

protected:

	//guarda o numero da carta nao necessariamente representando seu valor
	int _numero;

	//guarda o naipe da carta
	Naipe _naipe;

	//guarda se a carta esta virada para cima(true)
	bool _frente;
};

} /* namespace p3 */

#endif /* CARTA_H_ */
