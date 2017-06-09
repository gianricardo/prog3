/*
 * jogopresidente.h
 *
 *  Created on: 8 de jun de 2017
 *      Author: adolfo
 */

#ifndef JOGOPRESIDENTE_H_
#define JOGOPRESIDENTE_H_

#include <vector>
#include <string>
#include "jogo.h"

using namespace p3;

class JogoPresidente : public p3::Jogo{
public:
	JogoPresidente(p3::Regra *r,std::vector<std::string> p);
	virtual ~JogoPresidente();
	int acha_carta_jogavel(std::vector<Carta>,int,int);
	int how_many_in_the_hand(std::vector<Carta>,int);
	void joga_cartas(int,int);
	void fim_jogada();
	void add_position(int jogador);
	void pass_card(std::vector<int> v, int pos1, int pos2);
	std::vector<int> find_highest(int);
	std::vector<int> find_lowest(int);
	int retorna_bobo();
	int retorna_vicebobo();
	int retorna_vicepres();
	int retorna_pres();
private:
	std::vector<int> _positions;
};
#endif /* JOGOPRESIDENTE_H_ */
