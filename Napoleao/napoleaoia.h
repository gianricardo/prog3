/*
 * napoleaoia.h
 *
 *  Created on: 12 de jun de 2017
 *      Author: vitorrussi
 */

#ifndef NAPOLEAOIA_H_
#define NAPOLEAOIA_H_
#include "jogadornapoleao.h"
class NapoleaoIA : public JogadorNapoleao{
public:
	NapoleaoIA(std::string nome);
	int jogador_pergunta_turnos();
	int jogador_jogada();
	std::string nome();
	int escolhe_trunfo();
	virtual ~NapoleaoIA();
private:
	int decisao_aleatoria(int min,int max);
	std::string _nome;
	int _contador = 4;
};

#endif /* NAPOLEAOIA_H_ */



