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

	/*
	 *	Cria um jogador com o nome "name"
	 */
	Jogador(std::string name = "");
	virtual ~Jogador();

	/*
	 *	Retorna o nome do jogador
	 */
	std::string nome() const;

	/*
	 * Acrescenta uma carta a mao do jogador
	 */
	void recebe_carta(Carta card);

	/*
	 * Retira uma carta da mao do jogador, retorna false caso a carta nao esteja na mao
	 */
	bool tira_carta(Carta card, bool cmp_face = false);

	/*
	 * Retorna a pontuacao atual do jogador
	 */
	int pontuacao() const;

	/*
	 * Atribui um valor a pontuacao atual do jogador
	 */
	void pontuacao(int p);

	void muda_aptidao(); // jogadores aptos viram espectadores, e espectadores viram jogadores aptos
	bool esta_apto() const; // informa se jogador esta apto

	/*
	 *	Retorna um vetor das cartas contidas na mao do jogador
	 */
	const std::vector<Carta> mostra_mao() const ;

private:
	std::vector<Carta> _mao;
	std::string _nome;
	int _pontuacao;
	bool _apto_para_jogar;
};

} /* namespace p3 */

#endif /* JOGADOR_H_ */
