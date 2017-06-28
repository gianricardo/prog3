/*
 * paciencia.h
 *
 *  Created on: 7 de jun de 2017
 *      Author: lucas
 */

//Jogadas e verificacao de jogadas

#ifndef PACIENCIA_H_
#define PACIENCIA_H_

#include <string>
#include <sstream>
#include <stdlib.h>
#include "estadojogo.h"
#include "tela.h"

namespace p3 {

class Paciencia {
public:
	Paciencia();
	virtual ~Paciencia();

    bool verifica_jogada(int m1, int m2);
	void fim();
	std::string nome_jogador();
	std::string pontuacao();	
	std::string jogada_atual();
	void nome_jogador(std::string nome);

	Estado_jogo *get_jogo();

private:

	std::string _nome_jogador = "Jogador";
	std::string _jogada;
	Tela _tela;
	Estado_jogo *_estado_jogo;
};

} /* namespace p3 */

#endif /* PACIENCIA_H_ */
