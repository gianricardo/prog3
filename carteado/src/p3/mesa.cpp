/*
 * mesa.cpp
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#include "mesa.h"

namespace p3 {

Mesa::Mesa(std::size_t main_deck_size) : _monte(main_deck_size) {
	// TODO Auto-generated constructor stub
	_monte.embaralhar();
}

Mesa::~Mesa() {
	// TODO Auto-generated destructor stub
}

void Mesa::distribuir(unsigned int qtd_cartas, bool cima/* = true */){

	if(qtd_cartas * _jogadores.size() > _monte.size()){
		std::cout<<"Erro";
		return;
	}

	for(auto k=qtd_cartas;k>0;k--){
		for(std::size_t i = 0; i < _jogadores.size(); i++){

			_jogadores[i].recebe_carta(cima ? _monte.pega_topo() : _monte.pega_baixo());
		}
	}
}

void Mesa::add_jogador(std::string name){

	_jogadores.emplace_back(name);
}

void Mesa::rem_jogador(std::size_t pos){ // seta jogador para não apto

	if ( _jogadores[pos-1].esta_apto())_jogadores[pos-1].muda_aptidao();
}

Carta Mesa::pega_topo(std::size_t monte/* = 0 */){

	if(monte == 0) return _monte.pega_topo();

	return _outros_montes[monte-1].pega_topo();
}

Carta Mesa::pega_baixo(std::size_t monte/* = 0 */){

	if(monte == 0) return _monte.pega_baixo();

	return _outros_montes[monte-1].pega_baixo();
}

void Mesa::coloca_topo(Carta c, std::size_t i /* = 0 */){
	
	if(i == 0) _monte.coloca_topo(c);
	else _outros_montes[i-1].coloca_topo(c);
}

void Mesa::coloca_baixo(Carta c, std::size_t i /* = 0 */){
	
	if(i == 0) _monte.coloca_baixo(c);
	else _outros_montes[i-1].coloca_baixo(c);
}

std::size_t Mesa::tamanho_monte(std::size_t monte/* = 0 */) const {

	if(monte == 0) return _monte.size();

	return _outros_montes[monte - 1].size();
}

std::size_t Mesa::numero_jogadores() const {

	return _jogadores.size();
}

Jogador Mesa::ver_jogador(std::size_t i) const {

	return _jogadores[i];
}

void Mesa::jogador_soma_pontos(int valor, std::size_t i){

	_jogadores[i].pontuacao(_jogadores[i].pontuacao() + valor);
}

bool Mesa::jogador_tira_carta(Carta c, std::size_t i){

	return _jogadores[i].tira_carta(c);
}

void Mesa::jogador_recebe_carta(Carta c, std::size_t i){

	_jogadores[i].recebe_carta(c);
}

void Mesa::novo_monte(){

	_outros_montes.emplace_back();
}

void Mesa::deleta_monte(std::size_t i){

	if(i == 0) std::cerr << "Mesa::deleta_monte -- Nao pode deletar o monte principal\n";

	_outros_montes.erase(_outros_montes.begin() + i - 1);
}

std::size_t Mesa::n_montes() const {

	return 1 + _outros_montes.size();
}



} /* namespace p3 */



