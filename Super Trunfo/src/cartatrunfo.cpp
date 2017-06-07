/*
 * regratrunfo.cpp
 *
 *  Created on: 24 de mai de 2017
 *      Author: breno
 */

#include "cartatrunfo.h"

Carta_trunfo::Carta_trunfo(	int numero,
							int naipe,
							bool frente = false,
							int participacao_gps,
							int titulos_mundiais_construtores,
							int vitorias,
							int pole_positions,
							int gps_com_podios ) :

					_numero{numero}, _naipe{naipe}, _frente{frente},_participacao_gps{participacao_gps},
					_titulos_mundiais_construtores{titulos_mundiais_construtores}, _vitorias{vitorias},
					_pole_positions{pole_positions}, _gps_com_podios{gps_com_podios}
{ }

int Carta_trunfo::gps_com_podios()
{
	return _gps_com_podios;
}

int Carta_trunfo::participacao_gps()
{
	return _participacao_gps;
}

int Carta_trunfo::pole_positions()
{
	return _pole_positions;
}

int Carta_trunfo::titulos_mundiais_construtores()
{
	return _titulos_mundiais_construtores;
}

int Carta_trunfo::vitorias()
{
	return _vitorias;
}
