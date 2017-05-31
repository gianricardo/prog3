/*
 * jogo.cpp
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#include "jogo.h"

namespace p3 {

Jogo::Jogo(Regra *regra, std::vector<std::string> nomes) : _regra{regra}, _mesa{ (unsigned int) regra->cartas_inicial() },
										 _jog_atual{0}, _rodada{1}, _jogando{true} {

	if(nomes.size() != numero_de_jogadores()) std::cerr << "Jogo::Jogo -- Numero incorreto de nomes passado\n";

	auto it = nomes.begin();

	for(std::size_t i = 0; i < numero_de_jogadores(); i++){

		_mesa.add_jogador((it != nomes.end()) ? *it : "");

		it++;
	}

	_mesa.distribuir(cartas_jogadores());

}

Jogo::~Jogo() {}

std::size_t Jogo::numero_de_jogadores() const {
	return _regra->numero_de_jogadores();
}

int Jogo::cartas_inicial() const {
	return _regra->cartas_inicial();
}

int Jogo::cartas_jogadores() const {
	return _regra->cartas_jogadores();
}

int Jogo::max_rodadas() const {
	return _regra->max_rodadas();
}

int Jogo::pontuacao_max() const {
	return _regra->pontuacao_max();
}

void Jogo::reiniciar(){

	_rodada = 1;
	_jog_atual = 0;
	_jogando = true;

	//Reseta pontuacao, limpa a mao e muda aptidao se nao for apto
	for(std::size_t pos_jogador=0; pos_jogador < numero_de_jogadores(); pos_jogador++)
	{
		_mesa.ver_jogador(pos_jogador).pontuacao(0);
		_mesa.ver_jogador(pos_jogador).esvazia_mao();
		if(!_mesa.ver_jogador(pos_jogador).esta_apto())
			_mesa.ver_jogador(pos_jogador).muda_aptidao();
	}

	//Restaura o monte da mesa e resdistribui as cartas para os jogadores
	_mesa.monte_mesa().restaurar();
	_mesa.distribuir(cartas_jogadores());
}

void Jogo::fim_jogada(){

	if(!_jogando) return;

	while(!_mesa.ver_jogador(++_jog_atual).esta_apto()){

		if(_jog_atual == numero_de_jogadores()){

			_jog_atual = 0;

			_rodada++;

			verifica_jogadores_derrotados();
			verifica_fim_de_jogo();
			verifica_vitoria();
		}
	}
}

bool Jogo::jogando() const {

	return _jogando;
}

std::size_t Jogo::rodada() const {

	return _rodada;
}

std::size_t Jogo::posicao_jogador_atual() const {

	return _jog_atual;
}

std::string Jogo::nome_jogador_atual() const {

	return _mesa.ver_jogador(_jog_atual).nome();
}

std::vector<Carta> Jogo::mostra_mao_jogador_atual() const {

	return _mesa.ver_jogador(_jog_atual).mostra_mao();
}

int Jogo::pontuacao_jogador_atual() const {

	return _mesa.ver_jogador(_jog_atual).pontuacao();
}

void Jogo::jogador_soma_pontos(int pontos){

	_mesa.jogador_soma_pontos(pontos, _jog_atual);
}

void Jogo::jogador_subtrai_pontos(int pontos){

	jogador_soma_pontos(-pontos);
}

bool Jogo::move_carta_j(Carta carta, std::size_t j){

	return move_carta_jj(carta, jogador_atual, j);
}

bool Jogo::move_carta_m(std::size_t m, bool p_cima /* = true */, bool m_cima /* = true */){

	return move_carta_mm(0, m, p_cima, m_cima);
}

bool Jogo::move_carta_jj(Carta carta, std::size_t j1, std::size_t j2 /* = jogador_atual */){

	if(j1 == jogador_atual) j1 = _jog_atual;
	if(j2 == jogador_atual) j2 = _jog_atual;

	if(_mesa.jogador_tira_carta(carta, j1)){

		_mesa.jogador_recebe_carta(carta, j2);

		return true;
	}

	return false;
}

bool Jogo::move_carta_jm(Carta carta, std::size_t j /* = jogador_atual */, std::size_t m /* = 0 */, bool m_cima /* = true */){

	if(j == jogador_atual) j = _jog_atual;

	if(!_mesa.jogador_tira_carta(carta, j)) return false;

	_coloca_monte(carta, m, m_cima);

	return true;
}

bool Jogo::move_carta_mj(std::size_t m /* = 0 */, std::size_t j /* =  jogador_atual */, bool m_cima /* = true */){

	if(_mesa.tamanho_monte(m) == 0) return 0;

	if(j == jogador_atual) j = _jog_atual;

	_mesa.jogador_recebe_carta(_pega_monte(m, m_cima), j);

	return true;
}

bool Jogo::move_carta_mm(std::size_t m1, std::size_t m2 /* = 0 */, bool m1_cima /* = true */, bool m2_cima /* = true */){

	if(_mesa.tamanho_monte(m1) == 0) return false;

	_coloca_monte(_pega_monte(m1, m1_cima), m2, m2_cima);

	return true;
}

void Jogo::novo_monte(){

	_mesa.novo_monte();
}

void Jogo::deleta_monte(std::size_t i){

	_mesa.deleta_monte(i);
}

void Jogo::verifica_fim_de_jogo()
{
	switch(_regra->fim())
	{
	case (Regra::modo_fim::padrao) :		//caso de um jogador restante
		if(numero_jogadores_aptos() == 1) declara_fim_de_jogo();
		break;

	case (Regra::modo_fim::pontuacao) :	//caso de um jogador ter atingido pontuacao maxima
		for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
		{
			if(_mesa.ver_jogador(pos_jogador).esta_apto() && _mesa.ver_jogador(pos_jogador).pontuacao() == _regra->pontuacao_max())
				declara_fim_de_jogo();
		}
		break;

	case (Regra::modo_fim::rodadas) : 	//caso atingido numero maximo de rodadas
		if((int)rodada() > _regra->max_rodadas())
			declara_fim_de_jogo();
		break;

	case (Regra::modo_fim::zero_cartas) :
		bool condicao = true;	//condicao para checar se todos possuem zero cartas

		for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
		{
			if(_mesa.ver_jogador(pos_jogador).esta_apto() && _mesa.ver_jogador(pos_jogador).mostra_mao().size() != 0)	condicao = false;;
		}
		if(condicao) declara_fim_de_jogo();
		break;

	}

}

void Jogo::verifica_vitoria() {

	if(!_jogando) return;

	if(todos_jogadores_derrotados()) return;
    
	switch(_regra->cond_vit())
	{
	case Regra::condicao_vitoria::padrao :
		verifica_jogador_unico();
		break;

	case Regra::condicao_vitoria::maior_pontuacao :
		verifica_jogador_pontuacao_maxima();
		break;

	case Regra::condicao_vitoria::menor_pontuacao :
		verifica_jogador_pontuacao_minima();
		break;

	case Regra::condicao_vitoria::mais_cartas :
		verifica_jogador_mais_cartas();
		break;

	case Regra::condicao_vitoria::menos_cartas :
		verifica_jogador_menos_cartas();
		break;

	}
}

void Jogo::verifica_jogadores_derrotados()
{
	if(!jogando()) return;

	if(!todos_jogadores_derrotados()) return;

	switch(_regra->cond_der())
	{
	case Regra::condicao_derrota::estoura_pontuacao :
		for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
		{
			if(_mesa.ver_jogador(pos_jogador).esta_apto() && _mesa.ver_jogador(pos_jogador).pontuacao() > _regra->pontuacao_max())
				_mesa.ver_jogador(pos_jogador).muda_aptidao();
		}
		break;

	case Regra::condicao_derrota::zero_cartas :
		for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
		{
			if(_mesa.ver_jogador(pos_jogador).esta_apto() && _mesa.ver_jogador(pos_jogador).mostra_mao().size() == 0)
				_mesa.ver_jogador(pos_jogador).muda_aptidao();
		}
		break;

	case Regra::condicao_derrota::zero_pontos :
		for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
		{
			if(_mesa.ver_jogador(pos_jogador).esta_apto() && _mesa.ver_jogador(pos_jogador).pontuacao() == 0)
				_mesa.ver_jogador(pos_jogador).muda_aptidao();
		}
		break;

	case Regra::condicao_derrota::nenhuma :
		break;
	}
}

bool Jogo::todos_jogadores_derrotados() {

	if(numero_jogadores_aptos() == 0){
		declara_fim_de_jogo();
		return true;
	}
	return false;
}


void Jogo::verifica_fim_zero_cartas(){

	for(std::size_t i = 0; i < numero_de_jogadores(); i++){

		if(_mesa.ver_jogador(i).mostra_mao().size() == 0){

			declara_fim_de_jogo();
		}
	}
}

void Jogo::verifica_jogador_unico(){

	std::size_t jog_aptos = 0;
	std::size_t last = _jog_atual;

	for(std::size_t i = 0; i < _mesa.numero_jogadores(); i++){

		if(_mesa.ver_jogador(i).esta_apto()){
		
			jog_aptos++;

			last = i;
		}
	}

	if(jog_aptos > 1) return;

	declara_vencedor(last);
}

std::size_t Jogo::numero_jogadores_aptos(){

	return _mesa.numero_jogadores_aptos();
}

void Jogo::verifica_jogador_pontuacao_maxima(){

	int maior_pontuacao = 0;
	int jogador_vencedor;

	for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
	{
		if(_mesa.ver_jogador().esta_apto() && _mesa.ver_jogador(pos_jogador).pontuacao() > maior_pontuacao)
		{
			maior_pontuacao = _mesa.ver_jogador(pos_jogador).pontuacao();
			jogador_vencedor = (int)pos_jogador;
		}
	}

	declara_vencedor(jogador_vencedor);
}

void Jogo::verifica_jogador_pontuacao_minima(){

	int menor_pontuacao = 999999;
	int jogador_vencedor;

	for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
	{
		if(_mesa.ver_jogador().esta_apto() && _mesa.ver_jogador(pos_jogador).pontuacao() < menor_pontuacao)
		{
			menor_pontuacao = _mesa.ver_jogador(pos_jogador).pontuacao();
			jogador_vencedor = (int)pos_jogador;
		}
	}

	declara_vencedor(jogador_vencedor);
}

void Jogo::verifica_jogador_mais_cartas(){

	std::size_t maior_numero_cartas = -999999;
	std::size_t jogador_vencedor;

	for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
	{
		if(_mesa.ver_jogador().esta_apto() && _mesa.ver_jogador(pos_jogador).mostra_mao().size() > maior_numero_cartas)
		{
			maior_numero_cartas = _mesa.ver_jogador(pos_jogador).mostra_mao().size();
			jogador_vencedor = pos_jogador;
		}
	}

	declara_vencedor(jogador_vencedor);
}

void Jogo::verifica_jogador_menos_cartas(){

	std::size_t menor_numero_cartas = 999999;
	std::size_t jogador_vencedor;

	for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
	{
		if(_mesa.ver_jogador().esta_apto() && _mesa.ver_jogador(pos_jogador).mostra_mao().size() < menor_numero_cartas)
		{
			menor_numero_cartas = _mesa.ver_jogador(pos_jogador).mostra_mao().size();
			jogador_vencedor = pos_jogador;
		}
	}

	declara_vencedor(jogador_vencedor);
}

void Jogo::declara_fim_de_jogo(){

	_jogando = false;
}

void Jogo::declara_vencedor(std::size_t j){

	_jog_atual = j;

	_jogando = false;
}

void Jogo::_coloca_monte(Carta c, std::size_t m, bool topo){

	if(topo) _mesa.coloca_topo(c, m);
	else _mesa.coloca_baixo(c, m);
}

Carta Jogo::_pega_monte(std::size_t m, bool topo){

	if(topo) return _mesa.pega_topo(m);
	else return _mesa.pega_baixo(m);
}
        
bool Jogo::vira_cara(p3::Carta c){
    return _mesa.vira_carta(c);
    
}

} /* namespace p3 */




