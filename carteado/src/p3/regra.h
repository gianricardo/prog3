/*
 * regra.h
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#ifndef REGRA_H_
#define REGRA_H_

namespace p3 {

class Regra {
public:
	Regra(int numero_de_jogadores,	int cartas_inicial,
			int cartas_jogadores,	int montes, int rodadas , int pontuacao_max);
	virtual ~Regra();
	virtual bool condicao_de_vitoria(/*TODO*/);
	int numero_de_jogadores();
	int cartas_inicial(); //retorna numero de cartas do monte
	int cartas_jogadores(); //retorna cartas iniciais por jogadores
	int montes(); // retorna numero de montes
	int rodadas(); //retorna numero maximo de rodadas
	int pontuacao_max(); //retorna numero de pontos para termino
protected:
	int _numero_de_jogadores;
	int _cartas_inicial; // numero de cartas do monte
	int _cartas_jogadores; // cartas iniciais por jogadores
	int _montes; // numero de montes
	int _rodadas; // numero maximo de rodadas
	int _pontuacao_max; // numero de pontos para termino

};

} /* namespace p3 */

#endif /* REGRA_H_ */
