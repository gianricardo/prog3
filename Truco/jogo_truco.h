/*
 * jogo_truco.h
 *
 *  Created on: 30 de mai de 2017
 *      Author: bruno
 */

#ifndef JOGO_TRUCO_H_
#define JOGO_TRUCO_H_


#include "jogo.h"
#include "regra.h"
#include "jogador.h"

namespace p4 {

class Jogo_Truco final:public p3::Jogo{
public:
	enum class Compara{Maior, Menor, Igual};

	void fim_jogo();

	Jogo_Truco(p3::Regra *regra, std::vector<std::string> nomes);
	virtual ~Jogo_Truco();

	bool checa_fim_rodada();

	void fim_rodada(std::size_t _jogador_ganhou);

	//O jogador j1 pede truco
	void truco(std::size_t j1);
	//Retorna true se a rodada estiver valendo truco
	bool truco();

	int valor_truco();

	int valor_pontuacao();

	std::size_t jogador_comeca();

	std::vector<p3::Carta> mostra_mao_jogador(std::size_t _jogador);

	int compara(p3::Carta c1,p3::Carta c2,p3::Carta _vira);

	void jogador_ganhou_rodada(std::size_t _jogador);

	bool fim_turno();

	std::size_t jogador_ganhou_turno();

	void comeca_novo_turno();

	void incrementa_jog_atual();

	int pontuacao(std::size_t _jogador);

	void jogador_soma_pontos(std::size_t _jogador, int pontos);

	bool verifica_truco(std::size_t _jogador_trucou);

	int checa_mao_de_11();

	void mao_de_11();

	bool ia_aceita_mao_11();

private:
	//Compara a forca das manilhas de acordo com o truco
	bool compara_naipe(p3::Carta c1,p3::Carta c2);
	//Compara manilha se o _vira = 12
	int compara_vira_12(p3::Carta c1,p3::Carta c2);
	//Compara o valor numerico das cartas
	int compara_valor(p3::Carta c1 , p3::Carta c2);

	bool _truco;									//turno vale truco ou nao
	int _valor_truco;								//quantidade de pontos que o truco vale
	std::vector<std::size_t> _jogadores_ganharam;
	std::size_t _jogador_comeca;
	std::size_t _jogador_termina;
	std::size_t _jogador_comeca_turno;
};

} /* namespace p4 */

#endif /* JOGO_TRUCO_H_ */
