/*
 * iInteligenciaartificial.cpp
 *
 *  Created on: 20 de jun de 2017
 *      Author: breno
 */

#include "inteligenciaartificial.h"
#include <QDebug>
#include <QtCore>

Jogada Inteligencia_artificial::escolhe_jogada()
{
	auto const seed = std::random_device()();
	std::mt19937 rg(seed);
    std::uniform_int_distribution<> dist(0, 4);

    int jogada = dist(rg);

    return Jogada((Jogada::Atributos)jogada);
}
