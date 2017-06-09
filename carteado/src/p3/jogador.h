/*
 * jogador.h
 *
 *  Created on: 15 de mai de 2017
 *      Author: aluno
 */

#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <vector>
#include "carta.h"

namespace p3 {

template<class CARTA>
class JogadorBasico {
public:

    //Cria um jogador
	//o parametro passado é o nome do jogador, se nao for passado o nome será vazio
	//o jogador criado inicia com pontuacao 0 e apto para jogar
	JogadorBasico(std::string name = "");

	//Destrutor
	virtual ~JogadorBasico();

    //Retorna o nome do jogador
	std::string nome() const;

    //Acrescenta uma carta a mao do jogador
	//a carta passada como parametro é acrescentada ao final do vetor de cartas _mao
	void recebe_carta(CARTA card);

    //Retira uma carta da mao do jogador
	//passa como parametro a carta que deve ser retirada e um booleano se diz se deve ou nao comparar a face da carta
	//retorna false caso a carta nao esteja na mao
	bool tira_carta(CARTA card, bool cmp_face = false);

    //Retorna a pontuacao atual do jogador
	int pontuacao() const;

    //Atribui um valor a pontuacao atual do jogador
	//o valor passado como parametro SUBSTITUI a pontuacao atual
	void pontuacao(int p);
    
    //jogadores aptos viram espectadores, e espectadores viram jogadores aptos
	void muda_aptidao();
    
    //informa se jogador esta apto
	bool esta_apto() const;

    //Retorna um vetor das cartas contidas na mao do jogador que nao pode ser alterado
	const std::vector<CARTA> mostra_mao() const;

	//Esvazia o vetor de cartas
	void esvazia_mao();

	// vira uma carta da mao do jogador
	//
	// "c" - Carta que sera virada(caso o jogador tenha duas cartas iguais, so a primeira sera virada)
	//
	// retorna um booleano indicando se "carta" foi encontrada na mao do jogador
	//
	// ex: jogador.vira_carta(Carta(3, Carta::Naipe::copas));
	//
	bool vira_carta(CARTA c);

	// vira uma carta da mao do jogador
	//
	// "posicao" - Posicao na mao do jogador da carta que sera virada
	//
	// nao retorna nada
	//
	// ex: jogador.vira_carta(4); ou jogador.vira_carta_pos(4);
	//
	void vira_carta(std::size_t posicao);

	void vira_carta_pos(std::size_t posicao);

private:

	//vetor de cartas que representa a mao do jogador
	std::vector<CARTA> _mao;

	//guarda o nome do jogador
	std::string _nome;

	//guarda a pontuacao do jogador
	int _pontuacao;

	//guarda se jogador esta apto(true) para jogar
	bool _apto_para_jogar;
};

template<class CARTA> JogadorBasico<CARTA>::JogadorBasico(std::string name/* = "" */) :
		_nome{name}, _pontuacao{0}, _apto_para_jogar{true}{
}

template<class CARTA> JogadorBasico<CARTA>::~JogadorBasico() {

}

template<class CARTA> std::string JogadorBasico<CARTA>::nome() const {
	return _nome;
}

template<class CARTA> void JogadorBasico<CARTA>::recebe_carta(CARTA card){
	_mao.push_back(card);
}

template<class CARTA> bool JogadorBasico<CARTA>::tira_carta(CARTA card, bool cmp_face /* = false */){
	for(auto it = _mao.begin(); it != _mao.end(); it++){
		if(*it == card){
			if(cmp_face) if(it->mostra() != card.mostra()) continue;
			_mao.erase(it);
			return true;
		}
	}
	return false;
}

template<class CARTA> int JogadorBasico<CARTA>::pontuacao() const {
	return _pontuacao;
}

template<class CARTA> void JogadorBasico<CARTA>::pontuacao(int p){
	_pontuacao = p;
}

template<class CARTA> void JogadorBasico<CARTA>::muda_aptidao(){
	 _apto_para_jogar = !( _apto_para_jogar);
}

template<class CARTA> bool JogadorBasico<CARTA>::esta_apto() const {
	return _apto_para_jogar;
}


template<class CARTA> const std::vector<CARTA> JogadorBasico<CARTA>::mostra_mao() const {
	return _mao;
}

template<class CARTA> void JogadorBasico<CARTA>::esvazia_mao(){
	_mao.clear();
}

template<class CARTA> bool JogadorBasico<CARTA>::vira_carta(CARTA c){
	
	for(auto& carta : _mao){

		if(carta == c) {

			carta.vira();

			return true;
		}
	}

	return false;
}

template<class CARTA> void JogadorBasico<CARTA>::vira_carta(std::size_t posicao){
	
	vira_carta_pos(posicao);
}

template<class CARTA> void JogadorBasico<CARTA>::vira_carta_pos(std::size_t posicao){
	
	_mao[posicao].vira();
}

using Jogador = JogadorBasico<Carta>;

} /* namespace p3 */

#endif /* JOGADOR_H_ */
