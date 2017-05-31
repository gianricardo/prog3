/*
 *regratruco.h
 *
 *  Created on: 24 de mai de 2017
 *      Author: bruno
 */

#ifndef REGRATRUCO_H_
#define REGRATRUCO_H_

#include <deque>
#include <random>
#include <algorithm>
#include "regra.h"
#include "carta.h"
#include "jogador.h"


namespace p4{

class Regra_Truco final: public p3::Regra{
public:
	enum class Compara{Maior, Menor, Igual};
	Regra_Truco(std::size_t numero_de_jogadores,
			  int cartas_jogadores,
			  int rodadas,
			  int pontuacao_max,
			  int cartas_inicial);

	virtual ~Regra_Truco();
	//O jogador j1 pede truco
	void truco(p3::Jogador j1);
	//Retorna true se a rodada estiver valendo truco
	bool truco();
	//Compara a forca das cartas de acordo com as regras do truco, retorna um inteiro de acordo com a enum class Compara
	int compara(std::size_t pos_jog,p3::Carta c1,p3::Carta c2,p3::Carta _vira);
	//Retorna o valor da rodada(caso truco o valor é multiplicado por um fator)
	int valor_pontuacao();
	//Retorna a posicao do jogador que ganhou o turno(ganhou 2 rodadas), comparou diz se houve um empate nas cartas ou nao
	std::size_t joga_turno(std::size_t j_posicao, int comparou);
	// "_carta_ganhando" recebe "n_carta"
	void carta_ganhando(p3::Carta n_carta);
	//Retorna a carta que esta ganhando
	p3::Carta carta_ganhando();
	//Retorna o numero da rodada atual
	int rodada();

	void pos_rodada_comeca(std::size_t n_posicao);

	std::size_t pos_rodada_comeca();

	std::size_t pos_turno_comeca();


private:
	//Compara a forca das manilhas de acordo com o truco
	bool compara_naipe(std::size_t pos_jog,p3::Carta c1,p3::Carta c2);
	//Compara manilha se o _vira = 12
	int compara_vira_12(std::size_t,p3::Carta c1,p3::Carta c2);
	//Compara o valor numerico das cartas
	int compara_valor(std::size_t,p3::Carta c1 , p3::Carta c2);
	//Retorna true se o turno acabou
	bool fim_turno();
	//Retorna a posicao do vencedor do turno
	std::size_t vencedor_turno();

	bool _truco;									//turno vale truco ou nao
	int _valor_truco;								//quantidade de pontos que o truco vale
	int _valor_pontuacao;							//valor de pontos padrao de um turno
	int _rodada;									//Guarda o valor da rodada (2 ou 3 rodadas = 1 turno)
	//Guarda a posicao do jogador que levou a respectiva rodada
	std::size_t _rodadas_ganhas[3];
	std::size_t _pos_rodada_comeca;
	std::size_t _pos_turno_comeca;
	p3::Carta _carta_ganhando;
};
 /* namespace p3 */

#endif /* REGRATRUCO_H_ */
}
