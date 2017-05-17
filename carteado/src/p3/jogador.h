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

class Jogador {
public:
	Jogador(std::string name, int posicao);
	virtual ~Jogador();
	void recebe_carta(Carta card);
	Carta joga_carta();
	int pontuacao();
	void soma_pontuacao(int soma);
	void muda_aptidao(); // jogadores aptos viram espectadores, e espectadores viram jogadores aptos
	bool esta_apto(); // informa se jogador esta apto
	//bool operator==(const Jogador& jog) const;


private:
	std::vector<Carta> _mao;
	std::string _nome;
	int seleciona_carta();
	int _pontuacao = 0;
	bool _apto_para_jogar;
};

} /* namespace p3 */

#endif /* JOGADOR_H_ */
