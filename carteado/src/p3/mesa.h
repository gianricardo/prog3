/*
 * mesa.h
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#ifndef MESA_H_
#define MESA_H_

#include "baralho.h"

namespace p3 {

class Mesa {
public:
	Mesa();
	virtual ~Mesa();

	void distribuir(unsigned int qtd_cartas, bool cima); //distribui uma quantidade de cartas

	void add_jogador(std::string name = ""); //adiciona jogador
	void rem_jogador(std::size_t pos); //remove jogador


	Carta pega_topo(std::size_t monte = 0); //pega carta do topo do monte passado
	Carta pega_baixo(std::size_t monte = 0); //pega carta de baixo do monte passado

private:
	Baralho _monte; //monte principal
	std::vector<Baralho> _outros_montes;

	std::vector<Jogador> _jogadores;
};

} /* namespace p3 */

#endif /* MESA_H_ */
