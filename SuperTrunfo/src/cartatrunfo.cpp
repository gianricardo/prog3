/*
 * regratrunfo.cpp
 *
 *  Created on: 24 de mai de 2017
 *      Author: breno
 */

#include "cartatrunfo.h"

Carta_trunfo::Carta_trunfo(	int numero, Carta::Naipe naipe, bool frente ) :
							Carta(numero,naipe,frente)
{
	//Pegar o indice da lista de atributos baseado no numero e naipe
	int index_lista = (numero * (numero_naipe() + 1)) - 1;
	set_atributos(lista_atributos[index_lista]);
}

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

void Carta_trunfo::set_atributos(Atributos attr)
{
	_participacao_gps = attr[0];
	_titulos_mundiais_construtores = attr[1];
	_vitorias = attr[2];
	_pole_positions = attr[3];
	_gps_com_podios = attr[4];
}

int Carta_trunfo::numero_naipe()
{
	int num;

	switch(naipe())
	{
	case p3::Carta::Naipe::Espadas 	:	num = 0;
	break;

	case p3::Carta::Naipe::Copas 	:	num = 1;
	break;

	case p3::Carta::Naipe::Paus  	:	num = 2;
	break;

	case p3::Carta::Naipe::Ouros 	:	num = 3;
	break;
	}

	return num;
}



