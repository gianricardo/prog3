/*
 * jogada.h
 *
 *  Created on: 7 de jun de 2017
 *      Author: breno
 */

#ifndef SRC_JOGADA_H_
#define SRC_JOGADA_H_

class Jogada {
public:
	enum class Atributos{participacao_gps, titulos_mundiais_construtores, vitorias, pole_positions, gps_com_podios};

	Jogada(Jogada::Atributos atributo_escolhido);
	Jogada::Atributos atributo_escolhido();

private:
	Jogada::Atributos _atributo_escolhido;

};

#endif /* SRC_JOGADA_H_ */
