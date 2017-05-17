/*
 * mesa.cpp
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#include "mesa.h"

namespace p3 {

Mesa::Mesa() {
	// TODO Auto-generated constructor stub

}

Mesa::~Mesa() {
	// TODO Auto-generated destructor stub
}

void Mesa::distribuir(unsigned int qtd_cartas,
		bool cima=true){

	if(qtd_cartas*_jogadores.size()>_numerocartas){
		std::cout<<"Erro";
		return;
	}
	if(cima){
		for(auto k=qtd_cartas;k>0;k--){
			for(auto i=_jogadores.size();i>0;i--){
				_jogadores[i].recebe_carta(_monte.pega_topo());
			}
		}
	}else{
		for(auto k=qtd_cartas;k>0;k--){
			for(auto i=_jogadores.size();i>0;i--){
				_jogadores[i].recebe_carta(_monte.pega_baixo());
			}
		}
	}
}

void Mesa::add_jogador(std::string name){

	_jogadores.emplace_back(name);
}

void Mesa::rem_jogador(std::size_t pos){ // seta jogador para não apto

	if ( _jogadores[pos-1].esta_apto())_jogadores[pos-1].muda_aptidao();
}

Carta Mesa::pega_topo(std::size_t monte){

	if(monte == 0) return _monte.pega_topo();

	return _outros_montes[monte-1].pega_topo();
}

Carta Mesa::pega_baixo(std::size_t monte){

	if(monte == 0) return _monte.pega_baixo();

	return _outros_montes[monte-1].pega_baixo();
}



} /* namespace p3 */
