/*
 * jogadornapoleao.h
 *
 *  Created on: 12 de jun de 2017
 *      Author: vitorrussi
 */

#ifndef JOGADORNAPOLEAO_H_
#define JOGADORNAPOLEAO_H_
#include <string>
class JogadorNapoleao {
public:
	JogadorNapoleao();
	virtual int jogador_pergunta_turnos() = 0;
	virtual int jogador_jogada() = 0;
	virtual std::string nome() = 0;
	virtual int escolhe_trunfo() = 0;
	virtual ~JogadorNapoleao();
};

#endif /* JOGADORNAPOLEAO_H_ */
