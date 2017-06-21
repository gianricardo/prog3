/*
 * jogotrunfo.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: breno
 */

#include "jogotrunfo.h"

Jogo_trunfo::Jogo_trunfo(p3::Regra *regra, std::vector<std::string> nomes) :
	JogoBasico(regra, nomes),
	carta_super_trunfo(1, (p3::Carta::Naipe)2)
{
	novo_monte(); 	//monte de empate
}

Jogada Jogo_trunfo::recebe_jogada()
{
	if(!jogando()) return Jogada(Jogada::Atributos::INVALIDA);

	Carta_trunfo carta = mostra_mao_jogador_atual()[0];

	std::cout 	<< "Escolha o atributo a ser comparado\n"
				<< "1-Participacao em gps: " 				<< carta.participacao_gps() 				<< std::endl
				<< "2-Titulos muntiais de construtores: "	<< carta.titulos_mundiais_construtores()	<< std::endl
				<< "3-Vitorias: "							<< carta.vitorias()							<< std::endl
				<< "4-Pole positions: "						<< carta.pole_positions()					<< std::endl
				<< "5-Gps com podios: "						<< carta.gps_com_podios()					<< std::endl;

	int jogada;

	do{
	std::cin >> jogada;
	if(jogada < 1 || jogada > 5) std::cout << "Jogada invalida!\n";
	} while (jogada < 1 || jogada > 5);

	return Jogada((Jogada::Atributos)jogada);
}

void Jogo_trunfo::realiza_jogada(Jogada jogada)
{
	if(!jogando()) return;

	//Caso uma das cartas seja o super trunfo
	if(checa_super_trunfo() != -1)
	{
		size_t j_comparar = !checa_super_trunfo();
		//Checa se a outra carta é uma XA
		if((mostra_mao_jogador_consulta(j_comparar)[0]).naipe() == (p3::Carta::Naipe)0){
			move_carta_jogador_vencedor(j_comparar);
		} else	{
			move_carta_jogador_vencedor(!j_comparar);
		}

		return;
	}

	switch(jogada.atributo_escolhido())
	{
	case Jogada::Atributos::participacao_gps :
		//Jogador atual vencedor
		if	(	mostra_mao_jogador_consulta(posicao_jogador_atual())[0].participacao_gps() >
				mostra_mao_jogador_consulta(jogador_oponente())[0].participacao_gps())
			move_carta_jogador_vencedor(posicao_jogador_atual());

		//Empate
		else if(mostra_mao_jogador_consulta(posicao_jogador_atual())[0].participacao_gps() ==
				mostra_mao_jogador_consulta(jogador_oponente())[0].participacao_gps())
		{
			move_carta_empate();
			realiza_jogada(jogada);	//Chama a funcao novamente em caso de empate
		}

		//Jogador oponente vencedor
		else
			move_carta_jogador_vencedor(jogador_oponente());
		break;

	case Jogada::Atributos::titulos_mundiais_construtores :
		if	(	mostra_mao_jogador_consulta(posicao_jogador_atual())[0].titulos_mundiais_construtores() >
				mostra_mao_jogador_consulta(jogador_oponente())[0].titulos_mundiais_construtores())
			move_carta_jogador_vencedor(posicao_jogador_atual());

		else if(mostra_mao_jogador_consulta(posicao_jogador_atual())[0].titulos_mundiais_construtores() ==
				mostra_mao_jogador_consulta(jogador_oponente())[0].titulos_mundiais_construtores())
		{
			move_carta_empate();
			realiza_jogada(jogada);
		}

		else
			move_carta_jogador_vencedor(jogador_oponente());
		break;

	case Jogada::Atributos::vitorias :
		if	(	mostra_mao_jogador_consulta(posicao_jogador_atual())[0].vitorias() >
				mostra_mao_jogador_consulta(jogador_oponente())[0].vitorias())
			move_carta_jogador_vencedor(posicao_jogador_atual());

		else if(mostra_mao_jogador_consulta(posicao_jogador_atual())[0].vitorias() ==
				mostra_mao_jogador_consulta(jogador_oponente())[0].vitorias())
		{
			move_carta_empate();
			realiza_jogada(jogada);
		}

		else
			move_carta_jogador_vencedor(jogador_oponente());
		break;

	case Jogada::Atributos::pole_positions :
		if	(	mostra_mao_jogador_consulta(posicao_jogador_atual())[0].pole_positions() >
				mostra_mao_jogador_consulta(jogador_oponente())[0].pole_positions())
			move_carta_jogador_vencedor(posicao_jogador_atual());

		else if(mostra_mao_jogador_consulta(posicao_jogador_atual())[0].pole_positions() ==
				mostra_mao_jogador_consulta(jogador_oponente())[0].pole_positions())
		{
			move_carta_empate();
			realiza_jogada(jogada);
		}

		else
			move_carta_jogador_vencedor(jogador_oponente());
		break;

	case Jogada::Atributos::gps_com_podios :
		if	(	mostra_mao_jogador_consulta(posicao_jogador_atual())[0].gps_com_podios() >
				mostra_mao_jogador_consulta(jogador_oponente())[0].gps_com_podios())
			move_carta_jogador_vencedor(posicao_jogador_atual());

		else if(mostra_mao_jogador_consulta(posicao_jogador_atual())[0].gps_com_podios() ==
				mostra_mao_jogador_consulta(jogador_oponente())[0].gps_com_podios())
		{
			move_carta_empate();
			realiza_jogada(jogada);
		}

		else
			move_carta_jogador_vencedor(jogador_oponente());
		break;

	}
}

void Jogo_trunfo::move_carta_jogador_vencedor(size_t jogador_vencedor)
{
	std::cout << _mesa.ver_jogador(jogador_vencedor).nome() << " venceu esta rodada!\n";

	size_t jogador_perdedor = !jogador_vencedor;

	move_carta_jj(mostra_mao_jogador_consulta(jogador_perdedor)[0], jogador_perdedor, jogador_vencedor);

	//Caso houve cartas no monte de empate
	while(mostra_monte(1).size() != 0)
	{
		move_carta_mj(1, jogador_vencedor);
	}
}

size_t Jogo_trunfo::jogador_oponente()
{
	return !posicao_jogador_atual();
}

void Jogo_trunfo::move_carta_empate()
{
	std::cout << "Empatou!\n";

	if(mostra_mao_jogador_consulta(0).size() != 1)
	move_carta_jm(mostra_mao_jogador_consulta(0)[0], 1);

	if(mostra_mao_jogador_consulta(1).size() != 1)
	move_carta_jm(mostra_mao_jogador_consulta(1)[0], 1);
}

int Jogo_trunfo::checa_super_trunfo()
{
	if(mostra_mao_jogador_consulta(0)[0] == carta_super_trunfo)	return 0;
	if(mostra_mao_jogador_consulta(1)[0] == carta_super_trunfo)	return 1;
	return -1;
}
















