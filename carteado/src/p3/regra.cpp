/*
 * regra.cpp
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#include "regra.h"

namespace p3 {

Regra::Regra(int numero_de_jogadores,	int cartas_inicial,
		int cartas_jogadores,	int montes, int rodadas, int pontuacao_max ) {
	_numero_de_jogadores =  numero_de_jogadores;
	_cartas_inicial =  cartas_inicial;
	_cartas_jogadores =cartas_jogadores;
	_montes = montes;
	_rodadas = rodadas;
	_pontuacao_max =pontuacao_max;

}

Regra::~Regra() {
	// TODO Auto-generated destructor stub
}

bool Regra::condicao_de_vitoria(){
	//TODO
}

int Regra::numero_de_jogadores(){
	return _numero_de_jogadores;
}
int Regra::cartas_inicial(){//retorna numero de cartas do monte
	return _cartas_inicial;
}
int Regra::cartas_jogadores(){ //retorna cartas iniciais por jogadores
	return  _cartas_jogadores;
}
int Regra::montes(){// retorna numero de montes
	return _montes;
}
int Regra::rodadas(){//retorna numero maximo de rodadas
	return _rodadas;
}
int Regra::pontuacao_max(){//retorna numero de pontos para termino
	return _pontuacao_max;
}
} /* namespace p3 */
