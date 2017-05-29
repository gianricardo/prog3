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

    //Cria um jogador com o nome "name"
	JogadorBasico(std::string name = "");
	virtual ~JogadorBasico();

    //Retorna o nome do jogador
	std::string nome() const;

    //Acrescenta uma carta a mao do jogador
	void recebe_carta(CARTA card);

    //Retira uma carta da mao do jogador, retorna false caso a carta nao esteja na mao
	bool tira_carta(CARTA card, bool cmp_face = false);

    //Retorna a pontuacao atual do jogador
	int pontuacao() const;

    //Atribui um valor a pontuacao atual do jogador
	void pontuacao(int p);
    
    // jogadores aptos viram espectadores, e espectadores viram jogadores aptos
	void muda_aptidao();
    
    // informa se jogador esta apto
	bool esta_apto() const;

    //Retorna um vetor das cartas contidas na mao do jogador
	const std::vector<CARTA> mostra_mao() const;

	//Esvazia o vetor de cartas
	void esvazia_mao();

private:
	std::vector<CARTA> _mao;
	std::string _nome;
	int _pontuacao;
	bool _apto_para_jogar;
};

/* Recebe o nome no construtor */
template<class CARTA> JogadorBasico<CARTA>::JogadorBasico(std::string name/* = "" */) : _nome{name}, _pontuacao{0}, _apto_para_jogar{true}{
}

template<class CARTA> JogadorBasico<CARTA>::~JogadorBasico() {

}

template<class CARTA> std::string JogadorBasico<CARTA>::nome() const {

	return _nome;
}

/* Recebe uma carta como argumento e insere no final
 * do vector _mao. */
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

using Jogador = JogadorBasico<Carta>;

} /* namespace p3 */

#endif /* JOGADOR_H_ */
