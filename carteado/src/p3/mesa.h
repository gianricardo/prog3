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

template <class CARTA>
class MesaBasica {
public:


    //Constroi uma mesa com um baralho principal com "main_deck_size" numero de cartas
	MesaBasica(std::size_t main_deck_size = 0);

	virtual ~MesaBasica();

	//Distribui "qtd_cartas" cartas do monte principal para todos os jogadores, se cima for true retira as cartas
	//de cima do monte principal
	void distribuir(unsigned int qtd_cartas, bool cima = true);
    
    //Adiciona um jogador a mesa passando o nome dele como parametro
	void add_jogador(std::string name = "");
	
	 //Torna um jogador da mesa inapto de jogar passando sua posicao na mesa
	void rem_jogador(std::size_t pos);
	
	 //Pega uma carta do topo de um monte de cartas especificado
	CARTA pega_topo(std::size_t monte = 0);

    //Pega uma carta de baixo de um monte de cartas especificado
	CARTA pega_baixo(std::size_t monte = 0);

	 //Coloca uma carta no topo de um monte de cartas especificado
	void coloca_topo(CARTA c, std::size_t i = 0);
    
	 //Coloca uma carta em baixo de um monte de cartas especificado
	void coloca_baixo(CARTA c, std::size_t i = 0);

    //Retorna o tamanho de um monte especificado
	std::size_t tamanho_monte(std::size_t monte = 0) const;

    //Retorna o numero de jogadores
	std::size_t numero_jogadores() const;

	//Retorna o numero de jogadores aptos
	std::size_t numero_jogadores_aptos() const;

    //Retorna um jogador especificado
    JogadorBasico<CARTA> ver_jogador(std::size_t i = 0) const;

    //Acrescenta pontos a um jogador "i"
	void jogador_soma_pontos(int valor, std::size_t i = 0);

    //Tira uma carta "c" de um jogador "i", caso ele nao tenha retorna false
	bool jogador_tira_carta(CARTA c, std::size_t i = 0);

    //Acrescenta uma carta "c" a mao do jogador "i"
	void jogador_recebe_carta(CARTA c, std::size_t i = 0);

    //Pega uma carta do topo de um monte de cartas especificado
	void novo_monte();
    
    //Limpa o monte
	void deleta_monte(std::size_t i);

	//Mostra o monte da mesa
	BaralhoBasico<CARTA> monte_mesa() const;

	//retorna o numero de montes que a mesa contem
	std::size_t n_montes() const;
    
    // vira uma carta de um monte
	//
	// "m" - Indice do monte que tera uma de suas cartas virada
	// "m_cima" - Caso true a carta sera tira do topo do monte, caso contrario, de baixo
	//
	// nao retorna nada
	//
	// ex: mesa.vira_carta_monte(2, false);
	//
    void vira_carta_monte(std::size_t m = 0, bool m_cima = true);

    // vira uma carta de um jogador
	//
	// "pos_carta" - Posicao da carta a ser virada na mao do jogador
	// "j" - indice do jogador que tera uma de suas cartas virada
	//
	// nao retorna nada
	//
	// ex: mesa.vira_carta_jogador(2);
	//
    void vira_carta_jogador(std::size_t pos_carta, std::size_t j);

    // vira uma carta de um jogador
	//
	// "carta" - Carta que vai ser procurada dentro da mao do jogador, vira a primeira que encontrar
	// "j" - indice do jogador que tera uma de suas cartas virada
	//
	// retorna true caso consiga achar a carta dentro da mao do jogador, retorna false caso contrario
	//
	// ex: mesa.vira_carta_jogador_c(Carta(7, Carta::Naipe::Paus), 3);
	//
    bool vira_carta_jogador_c(CARTA carta, std::size_t j);

private:
    //monte principal
    BaralhoBasico<CARTA> _monte;

	//vetor de baralhos que representam os montes na mesa diferentes do deck principal
	std::vector<BaralhoBasico<CARTA> > _outros_montes;

	//vetor de jogadores contido na mesa
	std::vector<JogadorBasico<CARTA>> _jogadores;
};


template <class CARTA> MesaBasica<CARTA>::MesaBasica(std::size_t main_deck_size) : _monte(main_deck_size) {
	_monte.embaralhar();
}

template <class CARTA> MesaBasica<CARTA>::~MesaBasica() {
}

template <class CARTA> void MesaBasica<CARTA>::distribuir(unsigned int qtd_cartas, bool cima/* = true */){

	if(qtd_cartas * _jogadores.size() > _monte.size()){
		std::cout<<"Erro\n";
		return;
	}

	for(auto k=qtd_cartas;k>0;k--){
		for(std::size_t i = 0; i < _jogadores.size(); i++){

			_jogadores[i].recebe_carta(cima ? _monte.pega_topo() : _monte.pega_baixo());
		}
	}
}

template <class CARTA> void MesaBasica<CARTA>::add_jogador(std::string name){

	_jogadores.emplace_back(name);
}

template <class CARTA> void MesaBasica<CARTA>::rem_jogador(std::size_t pos){ // seta jogador para não apto

	if ( _jogadores[pos-1].esta_apto())_jogadores[pos-1].muda_aptidao();
}

template <class CARTA> CARTA MesaBasica<CARTA>::pega_topo(std::size_t monte/* = 0 */){

	if(monte == 0) return _monte.pega_topo();

	return _outros_montes[monte-1].pega_topo();
}

template <class CARTA> CARTA MesaBasica<CARTA>::pega_baixo(std::size_t monte/* = 0 */){

	if(monte == 0) return _monte.pega_baixo();

	return _outros_montes[monte-1].pega_baixo();
}

template <class CARTA> void MesaBasica<CARTA>::coloca_topo(CARTA c, std::size_t i /* = 0 */){
	
	if(i == 0) _monte.coloca_topo(c);
	else _outros_montes[i-1].coloca_topo(c);
}

template <class CARTA> void MesaBasica<CARTA>::coloca_baixo(CARTA c, std::size_t i /* = 0 */){
	
	if(i == 0) _monte.coloca_baixo(c);
	else _outros_montes[i-1].coloca_baixo(c);
}

template <class CARTA> std::size_t MesaBasica<CARTA>::tamanho_monte(std::size_t monte/* = 0 */) const {

	if(monte == 0) return _monte.size();

	return _outros_montes[monte - 1].size();
}

template <class CARTA> std::size_t MesaBasica<CARTA>::numero_jogadores() const {

	return _jogadores.size();
}

template <class CARTA> std::size_t MesaBasica<CARTA>::numero_jogadores_aptos() const {

	std::size_t jogadores_aptos = 0;

	for(std::size_t pos_jogador = 0; pos_jogador < numero_jogadores(); pos_jogador++)
	{
		if(ver_jogador(pos_jogador).esta_apto())
		{
			jogadores_aptos++;
		}
	}

	return jogadores_aptos;

}

template <class CARTA> JogadorBasico<CARTA> MesaBasica<CARTA>::ver_jogador(std::size_t i) const {

	return _jogadores[i];
}

template <class CARTA> void MesaBasica<CARTA>::jogador_soma_pontos(int valor, std::size_t i){

	_jogadores[i].pontuacao(_jogadores[i].pontuacao() + valor);
}

template <class CARTA> bool MesaBasica<CARTA>::jogador_tira_carta(CARTA c, std::size_t i){

	return _jogadores[i].tira_carta(c);
}

template <class CARTA> void MesaBasica<CARTA>::jogador_recebe_carta(CARTA c, std::size_t i){

	_jogadores[i].recebe_carta(c);
}

template <class CARTA> void MesaBasica<CARTA>::novo_monte(){

	_outros_montes.emplace_back();
}

template <class CARTA> void MesaBasica<CARTA>::deleta_monte(std::size_t i){

	if(i == 0) std::cerr << "Mesa::deleta_monte -- Nao pode deletar o monte principal\n";

	_outros_montes.erase(_outros_montes.begin() + i - 1);
}

template <class CARTA> BaralhoBasico<CARTA> MesaBasica<CARTA>::monte_mesa() const{

	return _monte;
}

template <class CARTA> std::size_t MesaBasica<CARTA>::n_montes() const {

	return 1 + _outros_montes.size();
}
    
template <class CARTA> void MesaBasica<CARTA>::vira_carta_monte(std::size_t m /* = 0 */, bool m_cima /* = true */){
    
	BaralhoBasico<CARTA>& monte = (m == 0) ? _monte : _outros_montes[m-1];

	if(m_cima) monte.vira_topo();
	else monte.vira_baixo();
}

template <class CARTA> void MesaBasica<CARTA>::vira_carta_jogador(std::size_t pos_carta, std::size_t j){
    
	_jogadores[j].vira_carta_pos(pos_carta);
}

template <class CARTA> bool MesaBasica<CARTA>::vira_carta_jogador_c(CARTA carta, std::size_t j){
    
	return _jogadores[j].vira_carta(carta);
}

using Mesa = MesaBasica<Carta>;

} /* namespace p3 */

#endif /* MESA_H_ */
