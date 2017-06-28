/*
 * jogopresidente.cpp
 *
 *  Created on: 8 de jun de 2017
 *      Author: adolfo
 */

#include "jogopresidente.h"

JogoPresidente::JogoPresidente(Regra *r, std::vector<std::string> p, TelaPresidente &ui) : Jogo(r,p){
	ordena_mao_jogador();
    _ui=&ui;
}

JogoPresidente::~JogoPresidente() {
}

int JogoPresidente::acha_carta_jogavel(std::vector<Carta> v,int numerocartas,int valor){
	int jogavel=0;
	for(auto k:v){
		if(k.numero()>valor && how_many_in_the_hand(v,k.numero())>=numerocartas){
			jogavel=k.numero();
			break;
		}
	}
	return jogavel;
}

void JogoPresidente::joga_cartas(int carta,int numerocartas){
	//retirar as primeiras numerocartas cartas com numero igual a carta
	int i=0;
	while(i!=numerocartas){
		for(int j=0;j<4;j++){
			if(move_carta_jm(p3::Carta(carta,(Carta::Naipe)j),_jog_atual,i+1,true)){
                vira_carta_monte(i+1,true);
				i++;
				break;
			}
		}
	}
}

int JogoPresidente::how_many_in_the_hand(std::vector<Carta> v,int valor){
	int count=0;
	for(auto c : v){
		if(c.numero()==valor) count++;
	}
	return count;
}

bool JogoPresidente::fim_jogada(){
    if(!_jogando) return false;
	if(numero_jogadores_aptos()==0){
		jogador_soma_pontos(3,_positions[0]);
		jogador_soma_pontos(2,_positions[1]);
        jogador_soma_pontos(1,_positions[2]);
		limpa_outros_montes();
		restaurar_monte_inicial();
		embaralhar_monte_principal();
        distribuir();
		muda_aptidao(0);
		muda_aptidao(1);
		muda_aptidao(2);
        muda_aptidao(3);
        pass_card(find_highest(2,retorna_bobo()),retorna_bobo(),retorna_pres());
		pass_card(find_lowest(2,retorna_pres()),retorna_pres(),retorna_bobo());
		pass_card(find_highest(1,retorna_vicebobo()),retorna_vicebobo(),retorna_vicepres());
        pass_card(find_lowest(1,retorna_vicepres()),retorna_vicepres(),retorna_vicebobo());
        ordena_mao_jogador();
        for(std::size_t i=0;i<13;i++){
            vira_carta_jogador(i,0);
        }
        std::vector<int> pts;
        for(int i=0;i<4;i++){
            muda_jogador_atual(i);
            pts.push_back(pontuacao_jogador_atual());
        }
        _ui->show_position(_positions);
        _ui->show_pontuation(pts);
        verifica_fim_de_jogo();
        _rodada++;
		muda_jogador_atual(retorna_pres());
        _positions.clear();
        return true;
	}
	return false;
}

void JogoPresidente::add_position(int jogador){
	_positions.push_back(jogador);
}

int JogoPresidente::retorna_bobo(){
	return _positions[3];
}

int JogoPresidente::retorna_pres(){
	return _positions[0];
}

int JogoPresidente::retorna_vicebobo(){
	return _positions[2];
}

int JogoPresidente::retorna_vicepres(){
	return _positions[1];
}

std::vector<int> JogoPresidente::find_highest(int numbercards,std::size_t player){
	std::vector<int> cards;
	int maior=0;
	int maior2=0;
	for(auto c : mostra_mao_jogador_consulta(player)){
		if(c.numero() >= maior && c.numero()>=maior2){
			maior2=maior;
			maior=c.numero();
		}else if(c.numero()>=maior2){
			maior2=c.numero();
		}
	}
	cards.push_back(maior);
	if(numbercards>1) cards.push_back(maior2);
	return cards;
}

std::vector<int> JogoPresidente::find_lowest(int numbercards,std::size_t player){
	std::vector<int> cards;
	int menor=14;
	int menor2=14;
	for(auto c : mostra_mao_jogador_consulta(player)){
		if(c.numero() <= menor && c.numero()<=menor2){
			menor2=menor;
			menor=c.numero();
		}else if(c.numero()<=menor2){
			menor2=c.numero();
		}
	}
	cards.push_back(menor);
	if(numbercards>1) cards.push_back(menor2);
	return cards;
}

void JogoPresidente::pass_card(std::vector<int> v,int pos1,int pos2){
	unsigned int i=0;
	while(i!=v.size()){
		for(int j=0;j<4;j++){
			if(move_carta_jj(p3::Carta(v[i],(Carta::Naipe)j),pos1,pos2)){
				i++;
				break;
			}
		}
	}
}

void JogoPresidente::verifica_fim_de_jogo(){
	if((int)max_rodadas()== (int)rodada()){
		declara_fim_de_jogo();
		verifica_vitoria();
	}
}

void JogoPresidente::verifica_vitoria(){
	verifica_jogador_pontuacao_maxima();
}

void JogoPresidente::verifica_jogador_pontuacao_maxima(){
	int maior_pontuacao = 0;
	int jogador_vencedor = 0;
	for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
	{
		if(_mesa.ver_jogador(pos_jogador).pontuacao() > maior_pontuacao)
		{
			maior_pontuacao = _mesa.ver_jogador(pos_jogador).pontuacao();
			jogador_vencedor = (int)pos_jogador;
		}
	}
	declara_vencedor(jogador_vencedor);
}

void JogoPresidente::declara_vencedor(std::size_t j){
    _ui->show_winner(j);
}

void JogoPresidente::verifica_jogador_unico(){
    int jog_aptos = 0;
    int last = 0;
    for(unsigned int i = 0; i < _mesa.numero_jogadores(); i++){
        if(_mesa.ver_jogador(i).esta_apto()){
            jog_aptos++;
            last = i;
        }
    }
    if(jog_aptos > 1) return;
    std::vector<Carta> cards = mostra_mao_jogador_consulta(last);
    for(auto c : cards){
        _mesa.jogador_tira_carta(c,last);
    }
    add_position(last);
    muda_aptidao(last);
}

void JogoPresidente::ordena_mao_jogador(){
	std::vector<Carta> hand;
	for(auto c : mostra_mao_jogador_consulta(0)){
		hand.push_back(c);
		_mesa.jogador_tira_carta(c,0);
	}
	auto compara=[](Carta a, Carta b){
		return b.numero() > a.numero();
	};
	std::sort(hand.begin(), hand.end(), compara);
	for(int k=0;k<13;k++){
		_mesa.jogador_recebe_carta(hand[k],0);
	}
}

void JogoPresidente::play(){
	std::vector<Carta> playing,montes;
	novo_monte();
	novo_monte();
	novo_monte();
	novo_monte();
    int card=0;
	int last_played_card=-1;
	int number_of_cards_played=0;
    int wining=0;
	int count;
    int players=0;
    int time_wait=500;
	unsigned int pass_count=0;
	for(std::size_t i=0;i<13;i++){
		vira_carta_jogador(i,0);
	}
    while(!_ui->tela_inicio()){}
	while(jogando()){
        players=numero_jogadores_aptos();
        for(int i=1;i<=number_of_cards_played;i++) montes.push_back(_pega_monte(i,true));
        _ui->show_hand(mostra_mao_jogador_consulta(0),mostra_mao_jogador_consulta(1),mostra_mao_jogador_consulta(2),mostra_mao_jogador_consulta(3));
        _ui->show_montes(montes);
        int i=1;
        for(auto m : montes){ _coloca_monte(m,i,true); i++;}
        montes.clear();
		playing=mostra_mao_jogador_consulta(posicao_jogador_atual());
		if(posicao_jogador_atual()==0 && esta_apto(0)){
            card=playing[_ui->get_play()-1].numero();
            if(card>last_played_card && how_many_in_the_hand(playing,card)>=number_of_cards_played){
				wining=posicao_jogador_atual();
				count=how_many_in_the_hand(playing,card);
				joga_cartas(card,number_of_cards_played!=0?number_of_cards_played:count);
				last_played_card=card;
				number_of_cards_played = number_of_cards_played!=0?number_of_cards_played:count;
				if(mostra_mao_jogador_consulta(posicao_jogador_atual()).size()==0 && esta_apto((int)posicao_jogador_atual())==true){
					muda_aptidao((int)posicao_jogador_atual());
					add_position((int)posicao_jogador_atual());
                    time_wait=1;
				}
				pass_count=0;
			}else pass_count++;
		}else if(esta_apto((int)posicao_jogador_atual())){
			card=acha_carta_jogavel(playing,number_of_cards_played,last_played_card);
			if(card!=0){
				wining=posicao_jogador_atual();
				count=how_many_in_the_hand(playing,card);
				joga_cartas(card,number_of_cards_played!=0?number_of_cards_played:count);
				last_played_card=card;
				number_of_cards_played = number_of_cards_played!=0?number_of_cards_played:count;
				if(mostra_mao_jogador_consulta(posicao_jogador_atual()).size()==0 && esta_apto((int)posicao_jogador_atual())){
					muda_aptidao((int)posicao_jogador_atual());
					add_position((int)posicao_jogador_atual());
				}
				pass_count=0;
			}else pass_count++;
		}
        for(int i=1;i<=number_of_cards_played;i++) montes.push_back(_pega_monte(i,true));
        verifica_jogador_unico();
        _ui->show_hand(mostra_mao_jogador_consulta(0),mostra_mao_jogador_consulta(1),mostra_mao_jogador_consulta(2),mostra_mao_jogador_consulta(3));
        _ui->show_montes(montes);
        i=1;
        for(auto m : montes){ _coloca_monte(m,i,true); i++;}
        montes.clear();
        QEventLoop espera;
        QTimer::singleShot(time_wait,&espera,SLOT(quit()));
        espera.exec();
        if(last_played_card==13 || (int)pass_count==(players-1)){
            if(esta_apto(wining))	muda_jogador_atual(wining);
            limpa_outros_montes();
			last_played_card=-1;
			number_of_cards_played=0;
		}
		if(last_played_card!=-1 || !esta_apto(posicao_jogador_atual())){
			if(posicao_jogador_atual()==3) muda_jogador_atual(0);
			else muda_jogador_atual(posicao_jogador_atual()+1);
		}
		if(numero_jogadores_aptos()==0){
			last_played_card=-1;
			number_of_cards_played=0;
		}
        if(fim_jogada()) time_wait=500;
	}
}
