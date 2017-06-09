/*
 * jogo.h
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#ifndef JOGO_H_
#define JOGO_H_

#include <memory>
#include <limits>
#include "mesa.h"
#include "regra.h"

namespace p3 {

template<class CARTA>
class JogoBasico {
public:

    //Construtor
	//recebe um ponteiro da classe regra e um vetor de nomes de jogadores
	//inicializa os atributos rodada com 1, jogador atual como 0 e jogando como true
    //cria a mesa e distribui o numero de cartas inicial para a mao dos jogadores
    JogoBasico(Regra *regra, std::vector<std::string> nomes);
	
	virtual ~JogoBasico();

	std::size_t numero_de_jogadores() const; //retorna numero de jogares
	int cartas_inicial() const; //retorna numero de cartas iniciais monte
	int cartas_jogadores() const; //retorna cartas iniciais por jogadores
	int max_rodadas() const; //retorna numero maximo de rodadas
	int pontuacao_max() const; //retorna numero de pontos para termino

	//reinicia o jogo como se o objeto JogoBasico fosse recem criado
	void reiniciar();

	 //Termina a jogada do jogador atual, caso ele seja o ultimo jogador, muda a rodada
	void fim_jogada();

    //Retorna se o jogo esta em andamento
	bool jogando() const;

	//Retorna numero da rodada atual
	std::size_t rodada() const;

    //Retorna o nome do jogador atual
	std::string nome_jogador_atual() const;

    //Retorna a posicao na mesa do jogador atual
	std::size_t posicao_jogador_atual() const;

    //Retorna um vetor contendo as cartas do jogador atual
	std::vector<CARTA> mostra_mao_jogador_atual() const;

    //Retorna um vetor contendo as cartas do jogador na posi pos
    std::vector<CARTA> mostra_mao_jogador(std::size_t pos) const;
    
    //Retorna a pontucao do jogador atual
	int pontuacao_jogador_atual() const;

	 //Aumenta a pontucao do jogador atual em "pontos" pontos
	void jogador_soma_pontos(int pontos);

    //Diminui a pontucao do jogador atual em "pontos" pontos
	void jogador_subtrai_pontos(int pontos);

	 // move carta do jogador atual para outro jogador
	bool move_carta_j(CARTA carta, std::size_t j);
	
	 // move carta do monte principal para outro monte
	bool move_carta_m(std::size_t m, bool p_cima = true, bool m_cima = true);

    //altera a posicao do jogador atual
    //recebe como parametro a nova posicao do jogador atual sendo '0' a primeira e 'numero de jogadores -1' a ultima
    void muda_jog_atual(int novapos);
	
	// move carta entre jogadores
	//
	// "carta" - Carta que será retirada de um jogador para ser passado a outro(usa o comparador padrao da carta)
	// "j1" - indice do jogador que entregara a carta ao outro
	// "j2" - indice do jogador que recebera a carta
	//
	// retorna um booleano indicando se "carta" foi encontrada na mao de "j1" podendo executar a troca
	//
	// ex: jogo.move_carta_jj(Carta(3, Carta::Naipe::copas), jogador_atual, 3);
	//
	bool move_carta_jj(CARTA carta, std::size_t j1, std::size_t j2 = jogador_atual);
	
	// move carta de um jogador para um monte
	//
	// "carta" - Carta que será retirada de um jogador para ser passado a um monte(usa o comparador padrao da carta)
	// "j" - indice do jogador que entregara a carta ao monte
	// "m" - indice do monte
	// "m_cima" - caso true a carta sera colocada na parte de cima do baralho, caso false em baixo
	//
	// retorna um booleano indicando se "carta" foi encontrada na mao de "j" podendo executar a troca
	//
	// ex: jogo.move_carta_jm(Carta(3, Carta::Naipe::copas), 2, 0, false);
	//
	bool move_carta_jm(CARTA carta, std::size_t j = jogador_atual, std::size_t m = 0, bool m_cima = true);
	
	// move carta de um monte para um jogador
	//
	// "m" - indice do jogador que entregara a carta ao outro
	// "j" - indice do jogador que recebera a carta
	// "m_cima" - caso true a carta sera tirada da parte de cima do baralho, caso falso de baixo
	//
	// retorna um booleano se "m" nao esta vazio, dessa forma, podendo fazer a troca
	//
	// ex: jogo.move_carta_mj(3, jogador_atual, true);
	//
	bool move_carta_mj(std::size_t m = 0, std::size_t j = jogador_atual, bool m_cima = true);
	
	// move carta entre montes
	//
	// "m1" - indice do monte que entregara a carta ao outro
	// "m2" - indice do monte que recebera a carta
	// "m1_cima" - caso true a carta sera tirada da parte de cima do baralho "m1", caso falso de baixo
	// "m2_cima" - caso true a carta sera colocada na parte de cima do baralho "m2', caso false em baixo
	//
	// retorna um booleano se "m1" nao esta vazio, dessa forma, podendo fazer a troca
	//
	// ex: jogo.move_carta_mm(0, 1, true, true);
	//
	bool move_carta_mm(std::size_t m1, std::size_t m2 = 0, bool m1_cima = true, bool m2_cima = true);

	
    //Cria um novo monte na mesa
	void novo_monte();

    //Deleta um monte da mesa especificada em "i"
	void deleta_monte(std::size_t i);

	//Mostra um monte dado que está na mesa (monte 0 é o monte principal da mesa)
	std::vector<std::pair<bool, CARTA> > mostra_monte(std::size_t pos_monte) const;

    // vira uma carta de um monte
	//
	// "m" - Indice do monte que tera uma de suas cartas virada
	// "m_cima" - Caso true a carta sera tira do topo do monte, caso contrario, de baixo
	//
	// nao retorna nada
	//
	// ex: jogo.vira_carta_monte(2, false);
	//
    void vira_carta_monte(std::size_t m = 0, bool m_cima = true);

    // vira uma carta de um jogador
	//
	// "pos_carta" - Posicao da carta a ser virada na mao do jogador
	// "j" - indice do jogador que tera uma de suas cartas virada
	//
	// nao retorna nada
	//
	// ex: jogo.vira_carta_jogador(2);
	//
    void vira_carta_jogador(std::size_t pos_carta, std::size_t j = jogador_atual);

    // Distribui as cartas para os jogadores. O metodo apenas chama o metodo ja feito na mesa.h.
    // o numero de cartas distribuidas vai ser o mesmo numero de cartas escolhidas na regra.
    //
    // nao retorna nada

    // ex: jogo.distribuir;
    void distribuir();    

private:

	static const std::size_t jogador_atual = std::numeric_limits<std::size_t>::max();

	void verifica_fim_de_jogo();

	void verifica_vitoria();					//checa se algum jogador ja ganhou

	void verifica_jogadores_derrotados();		//checa se algum jogador perdeu

	bool todos_jogadores_derrotados();			//retorna se todos os jogadores perderam

	void verifica_fim_zero_cartas();			//ultizado na condicao de fim de todos com zero cartas

	void verifica_jogador_pontuacao_maxima();	//utilizado para condicao de vitoria de maior pontuacao

	void verifica_jogador_pontuacao_minima();	//utilizado para condicao de vitoria de menor pontuacao

	void verifica_jogador_mais_cartas();		//ultizado para condicao de vitoria de mais cartas

	void verifica_jogador_menos_cartas();		//ultizado para condicao de vitoria de menos cartas

	void verifica_jogador_unico();				//utilizado na condicao de vitoria de ultimo jogador

	std::size_t numero_jogadores_aptos();		//retorna o numero de jogadores aptos restante no jogo

	void declara_fim_de_jogo();					//troca o estado da variavel que declara se o jogo esta rodando

	void declara_vencedor(std::size_t j);		//declara o jogador j como vencedor e encerra o jogo

	void _coloca_monte(CARTA c, std::size_t m, bool topo);	//coloca a carta c no topo(se for true) do monte m

	CARTA _pega_monte(std::size_t m, bool topo);	//pega uma carta do topo(se for true) do monte m

	std::unique_ptr<Regra> _regra;		//ponteiro para a regra do jogo
	MesaBasica<CARTA> _mesa;			//objeto da classe mesa que representa a mesa do jogo
	std::size_t _jog_atual;				//guarda a posicao do jogador atual
	std::size_t _rodada;				//guarda a rodada do jogo
	bool _jogando;   					//se for true o jogo esta rodando

};



template<class CARTA> JogoBasico<CARTA>::JogoBasico(Regra *regra, std::vector<std::string> nomes) : _regra{regra}, _mesa{ (unsigned int) regra->cartas_inicial() },
										 _jog_atual{0}, _rodada{1}, _jogando{true} {

	if(nomes.size() != numero_de_jogadores()) std::cerr << "Jogo::Jogo -- Numero incorreto de nomes passado\n";

	auto it = nomes.begin();

	for(std::size_t i = 0; i < numero_de_jogadores(); i++){

		_mesa.add_jogador((it != nomes.end()) ? *it : "");

		it++;
	}

	_mesa.distribuir(cartas_jogadores());

}

template<class CARTA> JogoBasico<CARTA>::~JogoBasico() {}

template<class CARTA> std::size_t JogoBasico<CARTA>::numero_de_jogadores() const {
	return _regra->numero_de_jogadores();
}

template<class CARTA> int JogoBasico<CARTA>::cartas_inicial() const {
	return _regra->cartas_inicial();
}

template<class CARTA> int JogoBasico<CARTA>::cartas_jogadores() const {
	return _regra->cartas_jogadores();
}

template<class CARTA> int JogoBasico<CARTA>::max_rodadas() const {
	return _regra->max_rodadas();
}

template<class CARTA> int JogoBasico<CARTA>::pontuacao_max() const {
	return _regra->pontuacao_max();
}

template<class CARTA> void JogoBasico<CARTA>::reiniciar(){

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
    _mesa.limpa_outros_montes();
	_mesa.distribuir(cartas_jogadores());
}

template<class CARTA> void JogoBasico<CARTA>::fim_jogada(){

	if(!_jogando) return;

	while(1){

		if(++_jog_atual == numero_de_jogadores()){

			_jog_atual = 0;

			_rodada++;

			verifica_jogadores_derrotados();
			verifica_fim_de_jogo();
			verifica_vitoria();
		}
		
		if(_mesa.ver_jogador(_jog_atual).esta_apto()) break;
	}
}

template<class CARTA> bool JogoBasico<CARTA>::jogando() const {

	return _jogando;
}

template<class CARTA> std::size_t JogoBasico<CARTA>::rodada() const {

	return _rodada;
}

template<class CARTA> std::size_t JogoBasico<CARTA>::posicao_jogador_atual() const {

	return _jog_atual;
}

template<class CARTA> std::string JogoBasico<CARTA>::nome_jogador_atual() const {

	return _mesa.ver_jogador(_jog_atual).nome();
}

template<class CARTA> std::vector<CARTA> JogoBasico<CARTA>::mostra_mao_jogador_atual() const {

	return _mesa.ver_jogador(_jog_atual).mostra_mao();
}
        
        
template<class CARTA> std::vector<CARTA> JogoBasico<CARTA>::mostra_mao_jogador(std::size_t pos) const{
            
    auto vet = _mesa.ver_jogador(pos).mostra_mao();
    
    return vet;
    std::vector<CARTA> aux;
    
    aux.reserve(vet.size());
    
    std::cout << "size: " << vet.size();
    
    for(auto carta : vet){
        
        if(carta.mostra()) aux.push_back(carta);
        else aux.emplace_back(0, (typename CARTA::Naipe) 0);
        
        std::cout << "passou aqui" << std::endl;
    }
    
    return aux;
}
        
        
        

template<class CARTA> int JogoBasico<CARTA>::pontuacao_jogador_atual() const {

	return _mesa.ver_jogador(_jog_atual).pontuacao();
}

template<class CARTA> void JogoBasico<CARTA>::jogador_soma_pontos(int pontos){

	_mesa.jogador_soma_pontos(pontos, _jog_atual);
}

template<class CARTA> void JogoBasico<CARTA>::jogador_subtrai_pontos(int pontos){

	jogador_soma_pontos(-pontos);
}

template<class CARTA> bool JogoBasico<CARTA>::move_carta_j(CARTA carta, std::size_t j){

	return move_carta_jj(carta, jogador_atual, j);
}

template<class CARTA> bool JogoBasico<CARTA>::move_carta_m(std::size_t m, bool p_cima /* = true */, bool m_cima /* = true */){

	return move_carta_mm(0, m, p_cima, m_cima);
}

template<class CARTA> bool JogoBasico<CARTA>::move_carta_jj(CARTA carta, std::size_t j1, std::size_t j2 /* = jogador_atual */){

	if(j1 == jogador_atual) j1 = _jog_atual;
	if(j2 == jogador_atual) j2 = _jog_atual;

	if(_mesa.jogador_tira_carta(carta, j1)){

		_mesa.jogador_recebe_carta(carta, j2);

		return true;
	}

	return false;
}

template<class CARTA> bool JogoBasico<CARTA>::move_carta_jm(CARTA carta, std::size_t j /* = jogador_atual */, std::size_t m /* = 0 */, bool m_cima /* = true */){

	if(j == jogador_atual) j = _jog_atual;

	if(!_mesa.jogador_tira_carta(carta, j)) return false;

	_coloca_monte(carta, m, m_cima);

	return true;
}

template<class CARTA> bool JogoBasico<CARTA>::move_carta_mj(std::size_t m /* = 0 */, std::size_t j /* =  jogador_atual */, bool m_cima /* = true */){

	if(_mesa.tamanho_monte(m) == 0) return false;

	if(j == jogador_atual) j = _jog_atual;

	_mesa.jogador_recebe_carta(_pega_monte(m, m_cima), j);

	return true;
}

template<class CARTA> bool JogoBasico<CARTA>::move_carta_mm(std::size_t m1, std::size_t m2 /* = 0 */, bool m1_cima /* = true */, bool m2_cima /* = true */){

	if(_mesa.tamanho_monte(m1) == 0) return false;

	_coloca_monte(_pega_monte(m1, m1_cima), m2, m2_cima);

	return true;
}

template<class CARTA> void JogoBasico<CARTA>::novo_monte(){

	_mesa.novo_monte();
}

template<class CARTA> void JogoBasico<CARTA>::deleta_monte(std::size_t i){

	_mesa.deleta_monte(i);
}

template<class CARTA> std::vector<std::pair<bool, CARTA> > JogoBasico<CARTA>::mostra_monte(std::size_t pos_monte) const{

	return _mesa.mostra_monte(pos_monte);
}

template<class CARTA> void JogoBasico<CARTA>::verifica_fim_de_jogo()
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
	{
		bool condicao = true;	//condicao para checar se todos possuem zero cartas

		for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
		{
			if(_mesa.ver_jogador(pos_jogador).esta_apto() && _mesa.ver_jogador(pos_jogador).mostra_mao().size() != 0)	condicao = false;;
		}
		if(condicao) declara_fim_de_jogo();
		break;
	}

	case (Regra::modo_fim::zero_jogadores) :
		if(numero_jogadores_aptos() == 0)
			declara_fim_de_jogo();
		break;

	}

}

template<class CARTA> void JogoBasico<CARTA>::verifica_vitoria() {

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

template<class CARTA> void JogoBasico<CARTA>::verifica_jogadores_derrotados()
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

template<class CARTA> bool JogoBasico<CARTA>::todos_jogadores_derrotados() {

	if(numero_jogadores_aptos() == 0){
		declara_fim_de_jogo();
		return true;
	}
	return false;
}


template<class CARTA> void JogoBasico<CARTA>::verifica_fim_zero_cartas(){

	for(std::size_t i = 0; i < numero_de_jogadores(); i++){

		if(_mesa.ver_jogador(i).mostra_mao().size() == 0){

			declara_fim_de_jogo();
		}
	}
}

template<class CARTA> void JogoBasico<CARTA>::verifica_jogador_unico(){

	if(todos_jogadores_derrotados()) return;

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

template<class CARTA> std::size_t JogoBasico<CARTA>::numero_jogadores_aptos(){

	return _mesa.numero_jogadores_aptos();
}

template<class CARTA> void JogoBasico<CARTA>::verifica_jogador_pontuacao_maxima(){

	if(todos_jogadores_derrotados()) return;

	int maior_pontuacao = 0;
	int jogador_vencedor = 0;

	//checa todos os jogadores aptos e ve qual tem mais pontos
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

template<class CARTA> void JogoBasico<CARTA>::verifica_jogador_pontuacao_minima(){

	if(todos_jogadores_derrotados()) return;

	int menor_pontuacao = 999999;
	int jogador_vencedor = 0;

	//checa todos os jogadores aptos e ve qual tem menos pontos
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

template<class CARTA> void JogoBasico<CARTA>::verifica_jogador_mais_cartas(){

	if(todos_jogadores_derrotados()) return;

	std::size_t maior_numero_cartas = -999999;
	std::size_t jogador_vencedor = 0;

	//checa todos os jogadores aptos e ve qual tem mais cartas
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

template<class CARTA> void JogoBasico<CARTA>::verifica_jogador_menos_cartas(){

	if(todos_jogadores_derrotados()) return;

	std::size_t menor_numero_cartas = 999999;
	std::size_t jogador_vencedor = 0;

	//checa todos os jogadores aptos e ve qual tem menos cartas
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

template<class CARTA> void JogoBasico<CARTA>::declara_fim_de_jogo(){

	_jogando = false;
}

template<class CARTA> void JogoBasico<CARTA>::declara_vencedor(std::size_t j){

	_jog_atual = j;

	_jogando = false;
}

template<class CARTA> void JogoBasico<CARTA>::_coloca_monte(CARTA c, std::size_t m, bool topo){

	if(topo) _mesa.coloca_topo(c, m);
	else _mesa.coloca_baixo(c, m);
}

template<class CARTA> CARTA JogoBasico<CARTA>::_pega_monte(std::size_t m, bool topo){

	if(topo) return _mesa.pega_topo(m);
	else return _mesa.pega_baixo(m);
}
    
template <class CARTA> void JogoBasico<CARTA>::vira_carta_monte(std::size_t m /* = 0 */, bool m_cima /* = true */){

	_mesa.vira_carta_monte(m, m_cima);
}

template <class CARTA> void JogoBasico<CARTA>::vira_carta_jogador(std::size_t pos_carta, std::size_t j /* = jogador_atual */){
    
	if(j == jogador_atual) j = _jog_atual;

	_mesa.vira_carta_jogador(pos_carta, j);
}

template <class CARTA> void JogoBasico<CARTA>::muda_jog_atual(int novapos){
	_jog_atual = novapos;
}

template<class CARTA> void JogoBasico<CARTA>::distribuir(){

	_mesa.distribuir(cartas_jogadores());
}


using Jogo = JogoBasico<Carta>;

} /* namespace p3 */

#endif /* JOGO_H_ */
