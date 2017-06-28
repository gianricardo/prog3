/*
 * jogotrunfo.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: breno
 */

#include <QDebug>
#include <QtCore>
#include "jogotrunfo.h"

Jogo_trunfo::Jogo_trunfo(p3::Regra *regra, std::vector<std::string> nomes, TrunfoUI *ui) :
	JogoBasico(regra, nomes),
    carta_super_trunfo(1, (p3::Carta::Naipe)2),
    _ui{ui}
{
    novo_monte(); 	//monte de empate
}

Jogo_trunfo::~Jogo_trunfo()
{
    delete _ui;
}

void Jogo_trunfo::jogar()
{
    _ui->show();
    Jogada jogada(Jogada::Atributos::INVALIDA);

    _ui->wait_for_game_start();
    if(!_ui->window_closed())
    {
        _ui->set_cards(carta_jogador_0_index(), carta_jogador_1_index());
        _ui->wait(1);
    }

    while(jogando() && !_ui->window_closed())
    {
        _ui->set_cards(carta_jogador_0_index(), carta_jogador_1_index());
        _ui->print_cards_amount(mostra_mao_jogador_consulta(0).size(),
                                mostra_mao_jogador_consulta(1).size());

        if(posicao_jogador_atual() == 1)
        {
            _ui->wait(1.5);
            jogada = Inteligencia_artificial::escolhe_jogada();
        }
        else {
            jogada = recebe_jogada();
        }

        _ui->print_attributes_label((int)jogada.atributo_escolhido() + 1);

        realiza_jogada(jogada);
        _ui->show_both_cards();

        _ui->wait(4);
        _ui->reset_shown();
        _ui->reset_round_winner();  //Reseta label atributos e vencedor

        fim_jogada();
        if (_jogando) _ui->set_cards(carta_jogador_0_index(), carta_jogador_1_index());
    }

    if(!_jogando && !_ui->window_closed())
    {
        _ui->print_game_winner(nome_jogador_atual());
        _ui->close();
    }
}

Jogada Jogo_trunfo::recebe_jogada()
{
	if(!jogando()) return Jogada(Jogada::Atributos::INVALIDA);

	int jogada;

    jogada = _ui->get_play();

	jogada--;

	return Jogada((Jogada::Atributos)jogada);
}

void Jogo_trunfo::realiza_jogada(Jogada jogada)
{
    if(!jogando()) return;

    Carta_trunfo carta_jog_0    (mostra_mao_jogador_consulta(0)[0].numero(),
                                 mostra_mao_jogador_consulta(0)[0].naipe());
    Carta_trunfo carta_jog_1    (mostra_mao_jogador_consulta(1)[0].numero(),
                                 mostra_mao_jogador_consulta(1)[0].naipe());

    //Caso uma das cartas seja o super trunfo
    if(checa_super_trunfo() != -1)
    {
        size_t j_comparar = !checa_super_trunfo();
        //Checa se a outra carta é uma XA
        if((mostra_mao_jogador_consulta(j_comparar)[0]).naipe() == (p3::Carta::Naipe)0){
            determina_acao_jogador_vencedor(j_comparar);
        } else	{
            determina_acao_jogador_vencedor(!j_comparar);
        }

        return;
    }

    switch(jogada.atributo_escolhido())
    {
    case Jogada::Atributos::participacao_gps :
        //Jogador atual vencedor
        if	(	carta_jog_0.participacao_gps() >
                carta_jog_1.participacao_gps())
            determina_acao_jogador_vencedor(0);

        //Empate
        else if(carta_jog_0.participacao_gps() ==
                carta_jog_1.participacao_gps())
        {
            determina_acao_jogador_vencedor(2);
        }

        //Jogador oponente vencedor
        else
            determina_acao_jogador_vencedor(1);

        break;

    case Jogada::Atributos::titulos_mundiais_construtores :
        if	(	carta_jog_0.titulos_mundiais_construtores() >
                carta_jog_1.titulos_mundiais_construtores())
            determina_acao_jogador_vencedor(0);

        else if(carta_jog_0.titulos_mundiais_construtores() ==
                carta_jog_1.titulos_mundiais_construtores())
        {
            determina_acao_jogador_vencedor(2);
        }

        else
            determina_acao_jogador_vencedor(1);
        break;

    case Jogada::Atributos::vitorias :
        if	(	carta_jog_0.vitorias() >
                carta_jog_1.vitorias())
            determina_acao_jogador_vencedor(0);

        else if(carta_jog_0.vitorias() ==
                carta_jog_1.vitorias())
        {
            determina_acao_jogador_vencedor(2);
        }

        else
            determina_acao_jogador_vencedor(1);
        break;

    case Jogada::Atributos::pole_positions :
        if	(	carta_jog_0.pole_positions() >
                carta_jog_1.pole_positions())
            determina_acao_jogador_vencedor(0);

        else if(carta_jog_0.pole_positions() ==
                carta_jog_1.pole_positions())
        {
            determina_acao_jogador_vencedor(2);
        }

        else
            determina_acao_jogador_vencedor(1);
        break;

    case Jogada::Atributos::gps_com_podios :
        if	(	carta_jog_0.gps_com_podios() >
                carta_jog_1.gps_com_podios())
            determina_acao_jogador_vencedor(0);

        else if(carta_jog_0.gps_com_podios() ==
                carta_jog_1.gps_com_podios())
        {
            determina_acao_jogador_vencedor(2);
        }

        else
            determina_acao_jogador_vencedor(1);
        break;

    case Jogada::Atributos::INVALIDA :
        break;

    }
}

void Jogo_trunfo::move_carta_jogador_vencedor(const size_t jogador_vencedor)
{
	size_t jogador_perdedor = !jogador_vencedor;

	move_carta_jj(mostra_mao_jogador_consulta(jogador_perdedor)[0], jogador_perdedor, jogador_vencedor);

	//Coloca a primeira carta no fim do baralho
	_mesa.jogador_recebe_carta(mostra_mao_jogador_consulta(jogador_vencedor)[0], jogador_vencedor);
	_mesa.jogador_tira_carta(mostra_mao_jogador_consulta(jogador_vencedor)[0], jogador_vencedor);

	//Caso houve cartas no monte de empate
    while(_mesa.tamanho_monte(0) != 0)
	{
        move_carta_mj(0, jogador_vencedor);
	}

    _ui->print_round_winner(_mesa.ver_jogador(jogador_vencedor).nome());

	_ultimo_jogador_vencedor = jogador_vencedor;
}

size_t Jogo_trunfo::jogador_oponente()
{
	return !posicao_jogador_atual();
}

void Jogo_trunfo::determina_acao_jogador_vencedor(const size_t jogador_vencedor)
{

	if(jogador_vencedor != 2)
	move_carta_jogador_vencedor(jogador_vencedor);

	else
	move_carta_empate();
}

bool Jogo_trunfo::fim_jogada()
{
    if(!_jogando) return false;

	_jog_atual = ultimo_jogador_vencedor();

	_rodada++;

    verifica_jogadores_derrotados();
	verifica_fim_de_jogo();

    return true;
}

int Jogo_trunfo::ultimo_jogador_vencedor()
{
	return _ultimo_jogador_vencedor;
}

void Jogo_trunfo::imprime_numero_cartas()
{
	std::cout 	<< _mesa.ver_jogador(0).nome() << " - numero de cartas: "
				<< mostra_mao_jogador_consulta(0).size() << std::endl
				<< _mesa.ver_jogador(1).nome() << " - numero de cartas: "
                << mostra_mao_jogador_consulta(1).size() << std::endl;
}

void Jogo_trunfo::verifica_jogadores_derrotados()
{
    if(_mesa.ver_jogador(0).mostra_mao().size() == 0) muda_aptidao(0);
    if(_mesa.ver_jogador(1).mostra_mao().size() == 0) muda_aptidao(0);
}

void Jogo_trunfo::move_carta_empate()
{
	if(mostra_mao_jogador_consulta(0).size() != 1)
    move_carta_jm(mostra_mao_jogador_consulta(0)[0], 0);

	if(mostra_mao_jogador_consulta(1).size() != 1)
    move_carta_jm(mostra_mao_jogador_consulta(1)[0], 1);

    _ui->print_round_draw();
}

int Jogo_trunfo::checa_super_trunfo()
{
	if(mostra_mao_jogador_consulta(0)[0] == carta_super_trunfo)	return 0;
	if(mostra_mao_jogador_consulta(1)[0] == carta_super_trunfo)	return 1;
	return -1;
}

void Jogo_trunfo::imprime_atributo_escolhido(Jogada jogada)
{
	size_t jogador_1 = 0;
	size_t jogador_2 = 1;

	switch(jogada.atributo_escolhido())
	{
	case Jogada::Atributos::participacao_gps :
		std::cout 	<< "Atributo escolhido: participacao em gps\n"
					<< _mesa.ver_jogador(jogador_1).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_1)[0].participacao_gps() 			<< std::endl
					<< _mesa.ver_jogador(jogador_2).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_2)[0].participacao_gps() 			<< std::endl;
		break;

	case Jogada::Atributos::titulos_mundiais_construtores :
		std::cout 	<< "Atributo escolhido: titulos mundiais de construtores\n"
					<< _mesa.ver_jogador(jogador_1).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_1)[0].titulos_mundiais_construtores() << std::endl
					<< _mesa.ver_jogador(jogador_2).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_2)[0].titulos_mundiais_construtores() << std::endl;
		break;

	case Jogada::Atributos::vitorias :
		std::cout 	<< "Atributo escolhido: vitorias\n"
					<< _mesa.ver_jogador(jogador_1).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_1)[0].vitorias() 	<< std::endl
					<< _mesa.ver_jogador(jogador_2).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_2)[0].vitorias() 	<< std::endl;
		break;

	case Jogada::Atributos::pole_positions :
		std::cout 	<< "Atributo escolhido: pole positions\n"
					<< _mesa.ver_jogador(jogador_1).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_1)[0].pole_positions() 	<< std::endl
					<< _mesa.ver_jogador(jogador_2).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_2)[0].pole_positions() 	<< std::endl;
		break;

	case Jogada::Atributos::gps_com_podios :
		std::cout 	<< "Atributo escolhido: participacao em gps\n"
					<< _mesa.ver_jogador(jogador_1).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_1)[0].gps_com_podios() 	<< std::endl
					<< _mesa.ver_jogador(jogador_2).nome() << ": "
					<< mostra_mao_jogador_consulta(jogador_2)[0].gps_com_podios() 	<< std::endl;
		break;

	case Jogada::Atributos::INVALIDA :
		std::cout << "Jogada invalida erro\n";
		break;

    }
}

int Jogo_trunfo::carta_jogador_0_index()
{
    return (mostra_mao_jogador_consulta(0))[0].index();
}

int Jogo_trunfo::carta_jogador_1_index()
{
    return (mostra_mao_jogador_consulta(1))[0].index();
}
