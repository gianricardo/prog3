#include "campeao_jogo.h"

Jogo_Campeao::Jogo_Campeao(Camp_regra * Regra, std::string jogador_um) : JogoBasico(Regra, { jogador_um, "jogador_dois"})    {}



void Jogo_Campeao::inicializacao(std::vector<Carta> copia1, std::vector<Carta> copia2, int dificuldade){ // o jogo inicia distribuindo as cartas aos jogadores. 
	// há o monte principal, que é onde são embaralhadas as cartas e um monte para cada jogador que 	conterá a carta à mesa
	embaralhar_monte_principal(); // 
	novo_monte(); // cria monte de jogador 1
	novo_monte(); // cria monte de jogador 2
	memoria = dificuldade;

	while (pontuacao_jogador_atual()<26 ){// o monte inicial é esvasiado carta apos carta, sendo distribuido aos jogadores 
		
	move_carta_mm(0, 1,  true,  true); // coloca carta no monte do primeiro jogador
	//vira_carta_monte(1, true);
	// mostra a carta
	move_carta_mm(0, 2,  true,  true);  // coloca carta no monte do segundo jogador
	//vira_carta_monte(2, true);
	// mostra a carta
	move_carta_mj ( 1, posicao_jogador_atual(),true);
	jogador_soma_pontos(1, posicao_jogador_atual()); // A pontuacao é o numero de cartas de cada jogador
	std::cout <<pontuacao_jogador_atual() << "  "  ;	
	muda_jogador_atual(1);	
	move_carta_mj ( 2, posicao_jogador_atual(),true);	
	jogador_soma_pontos(1, posicao_jogador_atual());	
	std::cout <<pontuacao_jogador_atual() <<"        ||";	
	muda_jogador_atual(0);
	std::cout << "cartas entregues \n";
	}
	for (int i=0; i<26;i++){
	vira_carta_jogador(i,0);	
	vira_carta_jogador(i,1);}		
	copia1= mostra_mao_jogador(0);
	copia2= mostra_mao_jogador(1);
	for (int i=0; i<26;i++){
	std::cout << copia1[i].numero() << " ";
	std::cout << copia2[i].numero()  << "  ||";
	std::cout << "cartas mostradas \n";}
}

//void Jogo_Campeao::turno (){}; // realiza as acoes de um turno 

int Jogo_Campeao::seleciona_aposta(){ // jogador seleciona aposta
	int a; 
	std::cout << "Selecione aposta\n";
	std::cin>> a;	
	return (a); 
}  

bool Jogo_Campeao::resultado_aposta(int aposta, std::vector<Carta> mao_atual, std::vector<Carta> mao_outro){ // calcula resultado da aposta
	int numero_atual = mao_atual[0].numero(); 
	int numero_outro = mao_outro[0].numero();
	switch (aposta) {
	case 0: // apostou ser maior
	std::cout << "apostou ser maior \n";
	std::cout << (numero_atual  >numero_outro) ; 
	return ( numero_atual > numero_outro)  ;
	case 1: // apostou ser igual
	std::cout << "apostou ser igual\n";
	std::cout << (numero_atual == numero_outro); 
	return ( numero_atual == numero_outro) ; 
	default: // apostou ser menor 
	std::cout << "apostou ser menor\n";
	std::cout <<( numero_atual < numero_outro); 
	return ( numero_atual < numero_outro) ;
	}
}

void Jogo_Campeao::movimenta_mesa ( bool  res_aposta,  std::vector<Carta> mao_atual, std::vector<Carta> mao_outro){ // se verdadeiro, jogador ganha as cartas, se não, jogador perde as cartas 
	
	int pos_atual = posicao_jogador_atual();
	int pos_outro = (-1*(pos_atual -1));	
	move_carta_jm(mao_atual[0], pos_atual,(pos_atual+1) , true); // move carta para o monte do jogador
	jogador_subtrai_pontos(1, pos_atual);
	move_carta_jm(mao_outro[0], pos_outro,(pos_outro+1) , true); // move carta para o monte do jogador
	jogador_subtrai_pontos(1, pos_outro);
	
	if (res_aposta){
	//          
	move_carta_mj((1), pos_atual, false);
	
	std::cout <<"Jogador " << (posicao_jogador_atual() +1) << "acertou aposta\n";
	move_carta_mj((2), pos_atual, false);	
	jogador_soma_pontos(2, pos_atual);	
	}else { 
	move_carta_mj((1), pos_outro, false);
	move_carta_mj((2), pos_outro, false);
	std::cout <<"Jogador " << (posicao_jogador_atual() +1) << "errou aposta\n";	
	jogador_soma_pontos(2, pos_outro);	
	}

} // movimenta a mesa de acord


int Jogo_Campeao::decisao_IA(std::vector<Carta> mao_jogador2 ) {
	switch (memoria){ // sem memoria 
	case 1: 
		if(7 <mao_jogador2[0].numero()){
		std::cout <<"Jogador 2 apostou ser maior\n";
		return 0;} else {
		std::cout <<"Jogador 2 apostou ser menor\n";
		return 2; }

	case 2 : // memoria de 3 cartas previamente vistas 
		if ( 6>pontuacao_jogador_atual() || 3 > mao_jogador2[0].numero() || 11 < mao_jogador2[0].numero()){ // se o computador tiver poucas cartas, ou uma carta muito alta ou baixa na mão, o valor individual da carta conta mais
 			if(7 <mao_jogador2[0].numero()){std::cout <<"Jogador 2 apostou ser maior\n";return 0;}
			else {std::cout <<"Jogador 2 apostou ser menor\n";return 2;}
	
// aqui temos um valor mediano, então o jogador considera o fato de ter cartas mais altas ou não 
		}else{int media = (mao_jogador2[0].numero() +mao_jogador2[1].numero() +mao_jogador2[2].numero()+ mao_jogador2[3].numero() + mao_jogador2[4].numero() +mao_jogador2[5].numero()) / 6; 
		if (7 <media) {std::cout <<"Jogador 2 apostou ser maior\n"; return 0;}
		else {std::cout <<"Jogador 2 apostou ser menor\n";return 2;}
	 	}
	default:  // sem inteligencia
	unsigned semente = std::chrono::steady_clock::now().time_since_epoch().count(); // utilizando uma seed de tempo para gaarantir a aleatoriedade do programa
	std::default_random_engine maquina_aleatoria(semente);
	std::uniform_int_distribution<int> aleat(0,2); // restringe escolhas entre 0 e 2
	int escolha=aleat(maquina_aleatoria);
	return (escolha);	
	}
}

void Jogo_Campeao::joga(int dificuldade){ 
	inicializacao(mostra_mao_jogador(0),mostra_mao_jogador(1),dificuldade);
	while (jogando()){
	turno(mostra_mao_jogador(0),mostra_mao_jogador(1));	
	verifica_fim_de_jogo();	
	}
	std::cout <<"fim de jogo\n";
}


void Jogo_Campeao::turno(std::vector<Carta> mao_atual, std::vector<Carta> mao_outro){
	int decisao; 
	if ( 1 == posicao_jogador_atual() ) { // turno automático
	decisao = decisao_IA(mostra_mao_jogador(1));
	}else{ 
	decisao = seleciona_aposta();
	}
	bool movimenta = resultado_aposta(decisao,mao_atual,mao_outro);
	movimenta_mesa ( movimenta,mao_atual, mao_outro);
	muda_jogador_atual(-1*(posicao_jogador_atual() -1) ); // troca jogador atual
	std::cout <<"fim de turno\n";
}
	
