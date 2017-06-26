/*
 * interface.h
 *
 *  Created on: 23 de jun de 2017
 *      Author: adolfo
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
#include <vector>
#include <string>
#include "carta.h"

using namespace p3;

class Interface {
public:
	void show_hand(std::vector<Carta>);
	std::string get_playername();
	void show_winner(int);
	void show_status(int,int);
	int get_play();
	void show_pontuation(int,int);
};

#endif /* INTERFACE_H_ */
