/*
 * main.cpp

 *
 *  Created on: 24 de mai de 2017
 *      Author: bruno
 */

#include "jogo_truco.h"
#include "mesa.h"
#include "baralho.h"
#include "regratruco.h"

int main(){
	std::string nome;
	std::size_t numero_jogadores = 0;
	std::size_t j_rodada = 0;
	std::size_t carta = 0;
	std::size_t jogador_ganhando = 0, carta_ganhando = 0;
	char resposta;
	char truco;

	std::cout << "Escolha o numero de jogadores (2/4): ";
	std::cin >> numero_jogadores;

	std::vector<std::string> _jogadores;

	std::cout << "Escolha o nome do seu jogador: ";
	std::cin >> nome;

	_jogadores.push_back(nome);
	switch(numero_jogadores){
	case 2:
		_jogadores.push_back("Computer");
		break;
	case 4:
		_jogadores.push_back("Computer1");
		_jogadores.push_back("Computer2");
		_jogadores.push_back("Computer3");
		break;
	default:
		break;
	}

	p4::Regra_Truco r1(numero_jogadores,3,3,12,0,40);
	p4::Regra_Truco *r1_ptr = &r1;
	p4::Jogo_Truco j1(r1_ptr,_jogadores);


	while(j1.jogando()){

		std::cout<< "\n Pontuacao dos jogadores: " << std::endl;
		for(auto i = 0; i < (int)j1.numero_de_jogadores(); i++){
			std::cout<< "\n Posicao Jogador: " << i << std::endl;
			std::cout<< "Pontuacao: " << j1.pontuacao(i) << std::endl;
		}
		//Cria o monte em que vai ficar o vira
		std::cout<< "Novo Turno" << std::endl;
		j1.novo_monte();
		//Cria o monte em que as cartas serão jogadas
		j1.novo_monte();
		//move uma carta do monte principal para o monte 1 que sera o vira
		j1.move_carta_mm(0,1,true,true);
		//vira a carta que sera o vira
		j1.vira_carta_monte(1,true);

		j_rodada = 0;

		//Termino de um Turno:
		while(!j1.fim_turno()){
			//Termino da rodada:
			std::cout << "Nova rodada" << std::endl;
			carta_ganhando = 0;
			jogador_ganhando = 0;
			do{

				std::cout<< "\n" ;
				std::cout << "Posicao jogador atual: " << j1.posicao_jogador_atual() << std::endl;
				std::cout<< "Jogador: "<< j1.nome_jogador_atual() << std::endl;
				std::cout << "O vira eh: " << j1.mostra_monte(1)[0].second.numero() << std::endl;
				//Jogador escolhe suas acoes:
				if(j1.posicao_jogador_atual() == 0){
					std::cout<< "\n" ;
					//mostra as cartas na mao do jogador
					for(int i = 0; i < (int)j1.mostra_mao_jogador_atual().size() ; i++){
						std::cout<< "Suas cartas: ";
						std::cout<< " " << (j1.mostra_mao_jogador_atual())[i].numero();
						std::cout<< "\n";
					}
					//Pergunta se o jogador deseja pedir truco caso nao esteja em um
					if(j1.truco() == false){
						std::cout<< "Deseja Pedir Truco ? (s/n): ";
						std::cin >> truco;
						std::cout<< "\n";
					}
					//Pergunta se o jogador deseja aumentar o truco atual
					else if(j1.truco() == true){
						std::cout<< "Deseja aumentar pedir " << j1.valor_truco() +3 << "? (s/n): ";
						std::cin >> truco;
						std::cout<< "\n";
					}

					//Caso todos aceitem a rodada prossegue
					if(truco == 's' && j1.verifica_truco(j1.posicao_jogador_atual()) == true){
						j1.truco(j1.posicao_jogador_atual());

						//O jogador que pediu o truco escolhe uma carta para jogar
						std::cout << "Escolha a Carta (1 a "<< j1.mostra_mao_jogador_atual().size() <<" )";
						std::cin >> carta;
						std::cout<< "\n";

						if(carta < 1 || carta > j1.mostra_mao_jogador_atual().size()){
							std::cout<< "Invalid Argument, a primeira carta sera escolhida" << std::endl;
							carta = 1;
						}

						//Se o jogador atual nao for o que comeca, este pode escolher esconder a carta
						if(j1.posicao_jogador_atual() != j1.jogador_comeca()){
							std::cout << "Deseja esconder a carta (s/n) ?";
							std::cin >> resposta;
							std::cout<< "\n";
						}

						//Caso o jogador escolha nao esconder a carta
						if(resposta == 'n' || j1.posicao_jogador_atual() == j1.jogador_comeca()){
							j1.vira_carta_jogador(carta - 1, j1.posicao_jogador_atual());
							if(j1.mostra_monte(2).empty()){
								carta_ganhando = 0;
								jogador_ganhando = j1.posicao_jogador_atual();
							}
							else{
								if(j1.compara(j1.mostra_mao_jogador_atual()[carta -1],j1.mostra_monte(2)[carta_ganhando].second,
										j1.mostra_monte(1)[0].second)==(int) p4::Jogo_Truco::Compara::Maior){

									carta_ganhando = 0;
									jogador_ganhando = j1.posicao_jogador_atual();
								}
								else if(j1.compara(j1.mostra_mao_jogador_atual()[carta -1], j1.mostra_monte(2)[carta_ganhando].second,
										j1.mostra_monte(1)[0].second) == (int)p4::Jogo_Truco::Compara::Igual){

									jogador_ganhando = j1.numero_de_jogadores();
								}
								else{
									carta_ganhando++;
								}
							}
							j1.move_carta_jm((j1.mostra_mao_jogador_atual())[carta -1],j1.posicao_jogador_atual(),2, true);
							j1.incrementa_jog_atual();
						}

						//caso o jogador escolha esconder a carta
						else{
							j1.move_carta_jm((j1.mostra_mao_jogador_atual())[carta -1],j1.posicao_jogador_atual(),0, true);
							j1.incrementa_jog_atual();
						}
					}
					//caso o jogador escolha pedir truco mas os outros jogadores nao aceitem
					else if(truco == 's' && j1.verifica_truco(j1.posicao_jogador_atual()) == false){
						jogador_ganhando = j1.posicao_jogador_atual();
						j1.jogador_ganhou_rodada(jogador_ganhando);
						j1.fim_rodada(jogador_ganhando);
						break;
					}

					//Caso o jogador escolha nao pedir truco
					else if(truco == 'n'){

						//O jogador escolhe uma de suas cartas na mao
						std::cout << "Escolha a Carta (1 a "<< j1.mostra_mao_jogador_atual().size() <<" ): ";
						std::cin >> carta;
						std::cout<< "\n";

						if(carta < 1 || carta > j1.mostra_mao_jogador_atual().size()){
							std::cout<< "Invalid Argument, a primeira carta sera escolhida" << std::endl;
							carta = 1;
						}
						//Se o jogador atual nao for o jogador que comeca, este pode escolher esconder a carta
						if(j1.posicao_jogador_atual() != j1.jogador_comeca()){
							std::cout << "Deseja esconder a carta (s/n) ?";
							std::cin >> resposta;
							std::cout<< "\n";
						}
						//Caso escolha nao esconder a carta
						if(resposta == 'n' || j1.posicao_jogador_atual() == j1.jogador_comeca()){
							j1.vira_carta_jogador(carta - 1, j1.posicao_jogador_atual());
							//Se for o primeiro a jogar a carta jogada começara ganhando
							if(j1.mostra_monte(2).empty()){
								carta_ganhando = 0;
								jogador_ganhando = j1.posicao_jogador_atual();
							}
							//Se nao for o primeiro a jogar, sua carta sera comparada com a maior ou com a unica carta jogada
							else{
								//se a carta jogada for maior, atualiza o status de quem esta ganhando
								if(j1.compara(j1.mostra_mao_jogador_atual()[carta-1], j1.mostra_monte(2)[carta_ganhando].second,
															j1.mostra_monte(1)[0].second) == (int)p4::Jogo_Truco::Compara::Maior){

									carta_ganhando = 0;
									jogador_ganhando = j1.posicao_jogador_atual();
								}
								//caso for igual, o jogador ganhando recebe a condicao de empate
								else if(j1.compara(j1.mostra_mao_jogador_atual()[carta -1], j1.mostra_monte(2)[carta_ganhando].second,
										j1.mostra_monte(1)[0].second) == (int)p4::Jogo_Truco::Compara::Igual){

									carta_ganhando = 0;
									jogador_ganhando = j1.numero_de_jogadores();
								}
								else{
									carta_ganhando++;
								}
							}
							j1.move_carta_jm((j1.mostra_mao_jogador_atual())[carta -1],j1.posicao_jogador_atual(),2, true);
							j1.incrementa_jog_atual();
						}
						//caso escolha esconder as cartas
						else{
							j1.move_carta_jm((j1.mostra_mao_jogador_atual())[carta -1],j1.posicao_jogador_atual(),0, true);
							j1.incrementa_jog_atual();
						}
					}
				}
				//Caso Seja uma IA jogando:
				else{
					std::cout<< "\n" ;
					for(int i = 0; i < (int)j1.mostra_mao_jogador_atual().size() ; i++){
						std::cout<< "Suas cartas: ";
						std::cout<< " " << (j1.mostra_mao_jogador_atual())[i].numero();
						std::cout<< "\n";
					}
					//A IA joga carta em sequencia, por enquanto
					j1.vira_carta_jogador(0,j1.posicao_jogador_atual());

					//se for o primeiro a jogar, a carta comeca ganhando
					if(j1.mostra_monte(2).empty()){
						carta_ganhando = 0;
						jogador_ganhando = j1.posicao_jogador_atual();
					}
					//se ja houver cartas jogadas, a carta sera comparada com a que estiver ganhando
					else{
						//caso ganhe o status do ganhador sera atualizado
						if(j1.compara(j1.mostra_mao_jogador_atual()[0],
								j1.mostra_monte(2)[carta_ganhando].second,
								j1.mostra_monte(1)[0].second) == (int)p4::Jogo_Truco::Compara::Maior){

							carta_ganhando = 0;
							jogador_ganhando = j1.posicao_jogador_atual();

						}
						//caso empate, jogador_ganhando recebe a condicao de empate
						else if(j1.compara(j1.mostra_mao_jogador_atual()[0],
								j1.mostra_monte(2)[carta_ganhando].second,
								j1.mostra_monte(1)[0].second) == (int)p4::Jogo_Truco::Compara::Igual){

							carta_ganhando = 0;
							jogador_ganhando = j1.numero_de_jogadores();
						}
						else{
							carta_ganhando++;
						}
					}
					j1.move_carta_jm((j1.mostra_mao_jogador_atual())[0],j1.posicao_jogador_atual(),2,true);
					j1.incrementa_jog_atual();

				}
			}while(j1.checa_fim_rodada() == false);

			std::cout << "Fim Rodada" << std::endl;

			if(jogador_ganhando != j1.numero_de_jogadores()){
				std::cout << "Posicao Jogador Ganhou Rodada: " << jogador_ganhando << std::endl;
				std::cout << "Carta Ganhou Rodada: " << j1.mostra_monte(2)[carta_ganhando].second.numero() << std::endl;
			}
			else{
				std::cout << "Rodada Empatou" << std::endl;
			}

			j1.jogador_ganhou_rodada(jogador_ganhando);
			j1.fim_rodada(jogador_ganhando);
			j_rodada++;
		}
		if(j1.jogador_ganhou_turno() != 2 && j1.jogador_ganhou_turno()!= 3){
			std::cout<< "Jogador Ganhou: " << j1.valor_pontuacao() << " pontos" << std::endl;
			j1.jogador_soma_pontos(j1.jogador_ganhou_turno(),j1.valor_pontuacao());
		}
		std::cout<< "Fim turno" << std::endl;
		j1.comeca_novo_turno();
	}

	return 0;
}
