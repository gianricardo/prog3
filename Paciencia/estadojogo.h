/*
 * estadojogo.h
 *
 *  Created on: 19 de jun de 2017
 *      Author: lucas
 */

//Verifica o estado de inicio e fim de jogo

#ifndef ESTADOJOGO_H_
#define ESTADOJOGO_H_

#include <jogo.h>
#include "r_paciencia.h"

namespace p3 {

class Estado_jogo : private p3::Jogo {
public:
	Estado_jogo(std::string nome);
	virtual ~Estado_jogo();

	//static bool inicia_jogo(std::string nome);
	bool realiza_jogada(int p_m1, int p_m2);
	bool fim_jogo();

	bool distribuir();
	//int pontuacao();

	int pontuacao_jogador();
	std::string nome_jogador();

	void restaura_monte_inicial(); //override;

	Carta* _pega_monte_v(std::size_t m);

	int verifica_sequencia(int m1);


private:
	
	R_Paciencia _r_paciencia;
};

} /* namespace p3 */

#endif /* ESTADOJOGO_H_ */
