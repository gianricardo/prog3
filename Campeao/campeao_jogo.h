#ifndef CAMPEAO_JOGO_H_
#define CAMPEAO_JOGO_H_

#include <iostream>
#include "../carteado/src/p3/jogo.h"
#include "../carteado/src/p3/carta.h"
#include "campeao_regra.h"
#include <chrono>
#include <random>

using namespace p3;


class Jogo_Campeao: public JogoBasico<Carta>{
	public:
	Jogo_Campeao(Camp_regra * regra, std::string jogador_um); // criador:
	//cria o jogo recebendo o nome do jogador, e um ponteiro do tipo "Camp_regra"
    	~Jogo_Campeao(){}; // desconstrutor

	void joga(int dificuldade); // jogo acontece como um todo 
   	void turno (std::vector<Carta> mao_atual, std::vector<Carta> mao_outro); // turno em que o jogo acontece 
    	void inicializacao(std::vector<Carta> mao_atual, std::vector<Carta> mao_outro, int dificuldade); // inicializa o jogo, distribuindo as cartas aos jogadores  	
	//void turno (); // realiza as acoes de um turno 
	int seleciona_aposta();  // jogador seleciona aposta
	bool resultado_aposta(int aposta, std::vector<Carta> mao_atual, std::vector<Carta> mao_outro); // calcula resultado da aposta
	void movimenta_mesa ( bool  res_aposta,  std::vector<Carta> mao_atual, std::vector<Carta> mao_outro) ; // movimenta a mesa de acordo com a aposta
	int decisao_IA(std::vector<Carta> mao_jogador2 ); // IA em maiusculo por fim de abreviacao, funciona como o seleciona_aposta, mas utilizando um sistema de escolha 

private:
	 int memoria; // corresponde à memoria da IA, 0 corresponde a um jogador desmemoriado, 1 a um jogador com memória convencional ( lembra-se das últimas cartas vistas), e -1 a um jogador burro  
	};


#endif 
