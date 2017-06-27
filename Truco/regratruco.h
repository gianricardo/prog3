
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
#include <stdexcept>
#include "../carteado/src/p3/regra.h"
#include "../carteado/src/p3/carta.h"
#include "../carteado/src/p3/jogador.h"


namespace p4{

class Regra_Truco final: public p3::Regra{
public:
	enum class Compara{Maior, Menor, Igual};
	Regra_Truco(std::size_t numero_de_jogadores,
			  int cartas_jogadores,
			  int rodadas,
			  int pontuacao_max,
			  int menor_pontuacao,
			  int cartas_inicial);

	virtual ~Regra_Truco();

	bool checa_fim_rodada(std::size_t pos) override;

	void jogador_ganhou_rodada(std::size_t jogador,std::size_t rodada) override;

	std::size_t jogador_ganhou_turno() override;

	void recomeca_turno() override;

	bool fim_turno(std::size_t rodada, std::size_t ganhou) override;

	int valor_pontuacao(bool cond,int valor) override;

	int compara(p3::Carta c1, p3::Carta c2, p3::Carta _vira) override;

	std::size_t jogador_comeca() override;

	void jogador_comeca(std::size_t n_pos) override;

	std::size_t jogador_termina() override;

	void jogador_termina(std::size_t n_pos) override;

	std::size_t jogador_comeca_turno() override;

	void jogador_comeca_turno(std::size_t n_pos) override;


private:
	//Compara a forca das manilhas de acordo com o truco
	bool compara_naipe(p3::Carta c1,p3::Carta c2);
	//Compara manilha se o _vira = 12
	int compara_vira_12(p3::Carta c1,p3::Carta c2);
	//Compara o valor numerico das cartas
	int compara_valor(p3::Carta c1 , p3::Carta c2);

	std::size_t _jogador_comeca;
	std::size_t _jogador_termina;
	std::size_t _jogador_comeca_turno;
	std::vector<std::size_t> _jogadores_ganharam;
};
 /* namespace p3 */

}
#endif /* REGRATRUCO_H_ */
