/*
 * regrapresidente.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: adolfo
 */

#include "regrapresidente.h"
#include "regra.h"

RegraPresidente::RegraPresidente(std::size_t numero_de_jogadores,int cartas_jogadores,int rodadas,int pontuacao_max,
		  int menor_pontuacao,int cartas_inicial,modo_fim fim,condicao_vitoria vit,condicao_derrota der) :
		  Regra(numero_de_jogadores,cartas_jogadores,rodadas,pontuacao_max,menor_pontuacao,cartas_inicial,fim,vit,der) {

}

RegraPresidente::~RegraPresidente() {
}

