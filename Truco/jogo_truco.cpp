/*
 * jogo_truco.cpp
 *
 *  Created on: 30 de mai de 2017
 *      Author: bruno
 */

#include "jogo_truco.h"

namespace p4 {

Jogo_Truco::Jogo_Truco(p3::Regra *regra, std::vector<std::string> nomes):Jogo(regra, nomes){
}

Jogo_Truco::~Jogo_Truco() {
	// TODO Auto-generated destructor stub
}
/* Method could not be resolved

int Jogo_Truco::compara(std::size_t pos_jog,p3::Carta c1,p3::Carta c2,p3::Carta _vira){
	return _regra->compara(pos_jog, c1, c2, _vira);
}

void Jogo_Truco::truco(p3::Jogador j1){
	_regra->truco(j1);
}

bool Jogo_Truco::truco(){
	return _regra->truco();
}

int Jogo_Truco::valor_pontuacao(){
	return _regra->valor_pontuacao();
}

std::size_t Jogo_Truco::joga_turno(std::size_t j_posicao, int comparou){
	return _regra->joga_turno(j_posicao, comparou);
}
*/

} /* namespace p4 */
