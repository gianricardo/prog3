/*
 * iInteligenciaartificial.cpp
 *
 *  Created on: 20 de jun de 2017
 *      Author: breno
 */

#include "inteligenciaartificial.h"

Jogada Inteligencia_artificial::escolhe_jogada()
{
	auto const seed = std::random_device()();
	std::mt19937 rg(seed);
	std::uniform_int_distribution<> dist(1, 5);

	return Jogada((Jogada::Atributos)dist(rg));
}
