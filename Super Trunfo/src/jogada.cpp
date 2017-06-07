/*
 * jogada.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: breno
 */

#include "jogada.h"

Jogada::Jogada(Jogada::Atributos atributo_escolhido) :
	_atributo_escolhido{atributo_escolhido}
{ }

Jogada::Atributos Jogada::atributo_escolhido()
{
	return _atributo_escolhido;
}
