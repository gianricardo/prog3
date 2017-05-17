/*
 * jogo.h
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#ifndef JOGO_H_
#define JOGO_H_

#include <memory>
#include "mesa.h"
#include "regra.h"

namespace p3 {

class Jogo {
public:
	Jogo(std::unique_ptr<Regra> regra);
	virtual ~Jogo();

	void distribuir(unsigned int qtd_cartas, bool cima);
	void add_jogador(std::string name = "");
	void rem_jogador(std::size_t pos);
	Carta pega_topo(std::size_t monte = 0);
	Carta pega_baixo(std::size_t monte = 0);

	int numero_de_jogadores(); //retorna numero de jogares
	int cartas_inicial(); //retorna numero de cartas do monte
	int cartas_jogadores(); //retorna cartas iniciais por jogadores
	int montes(); // retorna numero de montes
	int rodadas(); //retorna numero maximo de rodadas
	int pontuacao_max(); //retorna numero de pontos para termino

private:
	std::unique_ptr<Regra> _regra;
	Mesa _mesa;

};

} /* namespace p3 */

#endif /* JOGO_H_ */
