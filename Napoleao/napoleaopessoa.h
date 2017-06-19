/*
 * napoleaopessoa.h
 *
 *  Created on: 12 de jun de 2017
 *      Author: vitorrussi
 */

#ifndef NAPOLEAOPESSOA_H_
#define NAPOLEAOPESSOA_H_
#include "jogadornapoleao.h"

class NapoleaoPessoa : public JogadorNapoleao{
public:
	NapoleaoPessoa(std::string nome);
	int jogador_pergunta_turnos();
	int jogador_jogada();
	std::string nome();
	int escolhe_trunfo();
	virtual ~NapoleaoPessoa();
private:
	std::string _nome;
	int resposta();
};

#endif /* NAPOLEAOPESSOA_H_ */
