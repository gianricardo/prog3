/*
 * estadojogo.cpp
 *
 *  Created on: 19 de jun de 2017
 *      Author: lucas
 */

#include "estadojogo.h"

namespace p3 {

Estado_jogo::Estado_jogo(std::string nome) : Jogo(new R_Paciencia(), std::vector<std::string>(1, nome)){

	for(int i = 0; i < 12; i++){
		Jogo::novo_monte();
	}

	Estado_jogo::distribuir();
}

Estado_jogo::~Estado_jogo() {

}


bool Estado_jogo::realiza_jogada(int p_m1, int p_m2){

	//std::cout << "Chegou aqui" << p_m1 << " " << p_m2 << std::endl;

	if(p_m1 == 0){

		if(_mesa.tamanho_monte(0) == 0)
			Estado_jogo::restaura_monte_inicial();

		Jogo::vira_carta_monte(p_m1, true);
		Jogo::move_carta_mm(0, 1, true, true);

		return true;
	}
	else if (((p_m1 >= 6 && p_m1 <= 12) || p_m1 == 1 ) && p_m2 >= 2 ){

		Carta *c1, *c2;

		c1 = Estado_jogo::_pega_monte_v(p_m1);
		c2 = Estado_jogo::_pega_monte_v(p_m2);

		if(p_m2 <=5){

			if( (int) _mesa.tamanho_monte(p_m2) > 0){

				if(!(_r_paciencia.verifica_ordem(c1->numero(), c2->numero(),1) && _r_paciencia.verifica_naipe(c1->naipe(), c2->naipe(), 1)))
					
					return false;
			}else if(c1->numero() == 1){

				Jogo::move_carta_mm(p_m1, p_m2);
				if(!(Estado_jogo::_pega_monte_v(p_m1)->mostra()))
					Jogo::vira_carta_monte(p_m1, true);
				Jogo::jogador_soma_pontos(1, 0);

				Jogo::verifica_fim_de_jogo();

				return true;
			}			

		}
		else if(c1->numero() == 13 && c2->numero() == 0){

			Jogo::move_carta_mm(p_m1, p_m2);
		}
		else {

			int seq, i;

			seq = Estado_jogo::verifica_sequencia(p_m1);

			if(seq == 1 || p_m1 == 1){

				 if(_r_paciencia.verifica_naipe(c1->naipe(), c2->naipe(), 2) && _r_paciencia.verifica_ordem(c1->numero(), c2->numero(),2)){

					Jogo::move_carta_mm(p_m1, p_m2);
					if(!(Estado_jogo::_pega_monte_v(p_m1)->mostra()))
						Jogo::vira_carta_monte(p_m1, true);

					return true;
				}
			}
			else{

				int dif = c2->numero() - c1->numero();

				if(seq >= dif){

					Baralho b;

					if(((c1->numero() + dif) == 13 && c2->numero() == 0) || (dif % 2 == 0 && _r_paciencia.verifica_naipe(c1->naipe(), c2->naipe(), 1)) || (dif % 2 == 1 && _r_paciencia.verifica_naipe(c1->naipe(), c2->naipe(), 2))){

						for(i = 0; i < dif; i++)
							b.coloca_topo(Jogo::_pega_monte(p_m1, true));

						for(i = 0; i < dif; i++)
							Jogo::_coloca_monte(b.pega_topo(), p_m2, true);

						if(!(Estado_jogo::_pega_monte_v(p_m1)->mostra()))
							Jogo::vira_carta_monte(p_m1, true);

						return true;
					}
				}
			}
		}
	}

	return false;
}


bool Estado_jogo::fim_jogo(){

	if(Jogo::_jogando == false)
		return true;

	return false;
}



bool Estado_jogo::distribuir(){

	int k = 1;
	bool a = true;

	for(std::size_t i = 6; i <= 12; i++){

		for(int j = 0; j < k;j++){

			if(Jogo::move_carta_mm((std::size_t) 0, i) == false){

				a = false;
			}
		}

		Jogo::vira_carta_monte(i, true);

		k++;
	}

	return a;
}

int Estado_jogo::pontuacao_jogador(){

	return Jogo::pontuacao_jogador_atual();
}

std::string Estado_jogo::nome_jogador(){

	return Jogo::nome_jogador_atual();
}

void Estado_jogo::restaura_monte_inicial(){

	unsigned long int tam = _mesa.tamanho_monte((unsigned long int)1), i;

	for(i = 0; i < tam; i++){
		
		Jogo::vira_carta_monte(1, true);
		Jogo::move_carta_mm((std::size_t) 1, (std::size_t) 0);
	}
}

Carta* Estado_jogo::_pega_monte_v(std::size_t m){

	return Jogo::_mesa.verifica_topo(m); //verificar
}

int Estado_jogo::verifica_sequencia(int m1){

	int a = 1, i;

	std::vector<std::pair<bool, Carta> > b1;

	b1 = _mesa.mostra_monte(m1);

	for(i = 0; i < ((int)_mesa.tamanho_monte(m1)); i++){

		if(i + 1 < ((int)_mesa.tamanho_monte(m1)) && b1[i].second.mostra()){
			if(_r_paciencia.verifica_naipe(b1[i].second.naipe(), b1[i+1].second.naipe(), 2) && _r_paciencia.verifica_ordem(b1[i].second.numero(), b1[i+1].second.numero(), 2))
				a++;
		}
		else
			break;
	}

	return a;
}




} /* namespace p3 */
