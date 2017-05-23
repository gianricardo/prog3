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
	Mesa(std::size_t main_deck_size = 0);
	virtual ~Mesa();

	void distribuir(unsigned int qtd_cartas, bool cima = true); //distribui uma quantidade de cartas

	void add_jogador(std::string name = ""); //adiciona jogador
	void rem_jogador(std::size_t pos); //remove jogador

	Carta pega_topo(std::size_t monte = 0); //pega carta do topo do monte passado
	Carta pega_baixo(std::size_t monte = 0); //pega carta de baixo do monte passado

	void coloca_topo(Carta c, std::size_t i = 0);
	void coloca_baixo(Carta c, std::size_t i = 0);

	std::size_t tamanho_monte(std::size_t monte = 0) const;
	std::size_t numero_jogadores() const;

	Jogador ver_jogador(std::size_t i = 0) const;

	void jogador_soma_pontos(int valor, std::size_t i = 0);

	bool jogador_tira_carta(Carta c, std::size_t i = 0);

	void jogador_recebe_carta(Carta c, std::size_t i = 0);

	void novo_monte();

	void deleta_monte(std::size_t i);

	std::size_t n_montes() const;

private:
	Baralho _monte; //monte principal
	std::vector<Baralho> _outros_montes;

	std::vector<Jogador> _jogadores;
};

} /* namespace p3 */

#endif /* MESA_H_ */
