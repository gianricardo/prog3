/*
 * regratrunfo.h
 *
 *  Created on: 24 de mai de 2017
 *      Author: breno
 */

#ifndef REGRATRUNFO_H_
#define REGRATRUNFO_H_

#include "carta.h"

class Carta_trunfo : p3::Carta {
public:

	enum class Naipe{A, B, C, D};

	Carta_trunfo(	int numero,
					int naipe,
					bool frente = false,
					int participacao_gps,
					int titulos_mundiais_construtores,
					int vitorias,
					int pole_positions,
					int gps_com_podios );

	int participacao_gps();
	int titulos_mundiais_construtores();
	int vitorias();
	int pole_positions();
	int gps_com_podios();
private:

	int _participacao_gps;
	int _titulos_mundiais_construtores;
	int _vitorias;
	int _pole_positions;
	int _gps_com_podios;

};

#endif /* REGRATRUNFO_H_ */
