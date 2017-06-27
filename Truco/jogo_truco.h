/*
 * jogo_truco.h
 *
 *  Created on: 30 de mai de 2017
 *      Author: bruno
 */

#ifndef JOGO_TRUCO_H_
#define JOGO_TRUCO_H_


#include "../carteado/src/p3/jogo.h"
#include "../carteado/src/p3/regra.h"
#include "regratruco.h"
#include "../carteado/src/p3/jogador.h"
#include "../carteado/src/p3/mesa.h"
#include "qjogo.h"
#include <memory>

namespace p4 {

class Jogo_Truco :public p3::Jogo{
public:
	enum class Compara{Maior, Menor, Igual};

	void fim_jogo();

    Jogo_Truco(p3::Regra *regra, std::vector<std::string> nomes, Qjogo *_interface);
	virtual ~Jogo_Truco();

	void jogar();

	bool checa_fim_rodada();
	//Retorna true se a rodada estiver valendo truco
	bool truco();

	int valor_truco();

	int valor_pontuacao();

	std::size_t jogador_comeca();

	int compara(p3::Carta c1,p3::Carta c2,p3::Carta _vira);

	bool fim_turno();

	std::size_t jogador_ganhou_turno();

	int pontuacao(std::size_t _jogador);

	bool verifica_truco(std::size_t _jogador_trucou);

	int checa_mao_de_11();

	bool ia_aceita_mao_11();


protected:
    unsigned int jogador_vencedor();

    void joga_jogador_posicao0_11();

    void rodada_as_cegas();

    void joga_jogador_comeca();

    void joga_carta_cima(unsigned int _carta);

	void jogador_ganhou_rodada(std::size_t _jogador);

	std::vector<p3::Carta> mostra_mao_jogador_pos(std::size_t _jogador);

	void comeca_novo_turno();

	void incrementa_jog_atual();

	void jogador_soma_pontos(std::size_t _jogador, int pontos);

    bool mao_de_11();

	void fim_rodada(std::size_t _jogador_ganhou);

	//O jogador j1 pede truco
	void pede_truco(std::size_t j1);

	void joga_jogador_posicao_0();
	void ia_joga();

	bool _turno;
	bool _cond_rodada;
	bool _truco;									//turno vale truco ou nao
	int _valor_truco;								//quantidade de pontos que o truco vale
	std::vector<std::size_t> _jogadores_ganharam;
	std::size_t carta_ganhando;
	std::size_t jogador_ganhando;


private:
    std::unique_ptr<Qjogo> interface;
};

} /* namespace p4 */

#endif /* JOGO_TRUCO_H_ */
