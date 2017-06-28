#include "campeao_regra.h"
using namespace p3;


Camp_regra::Camp_regra() :  Regra(2,26,100,52,-1,52, // dois jogadores, baralho de 52 cartas distribuido entre eles 
	(Regra::modo_fim::pontuacao),
	(Regra::condicao_vitoria::padrao),
	(Regra::condicao_derrota::zero_pontos)
	){    
}

