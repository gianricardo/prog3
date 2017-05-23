/*
 * mesa.h
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#ifndef MESA_H_
#define MESA_H_

#include "baralho.h"

namespace p3 {

class Mesa {
public:

    //Constroi uma mesa com um baralho principal com "main_deck_size" numero de cartas
	Mesa(std::size_t main_deck_size = 0);
	virtual ~Mesa();

	 //Distribui cartas do monte principal para todos os jogadores
	void distribuir(unsigned int qtd_cartas, bool cima = true); //distribui uma quantidade de cartas
    
    //Adiciona um jogador a mesa
	void add_jogador(std::string name = "");
	
	 //Torna um jogador da mesa inapto de jogar
	void rem_jogador(std::size_t pos);

	
	 //Pega uma carta do topo de um monte de cartas especificado
	Carta pega_topo(std::size_t monte = 0);

    //Pega uma carta de baixo de um monte de cartas especificado
	Carta pega_baixo(std::size_t monte = 0);

	 //Coloca uma carta no topo de um monte de cartas especificado
	void coloca_topo(Carta c, std::size_t i = 0);
    
	 //Coloca uma carta em baixo de um monte de cartas especificado
	void coloca_baixo(Carta c, std::size_t i = 0);

    //Retorna o tamanho de um monte especificado
	std::size_t tamanho_monte(std::size_t monte = 0) const;

    //Retorna o numero de jogadores
	std::size_t numero_jogadores() const;

    //Retorna um jogador especificado
    Jogador ver_jogador(std::size_t i = 0) const;


    //Acrescenta pontos a um jogador "i"
	void jogador_soma_pontos(int valor, std::size_t i = 0);

	
    //Tira uma carta "c" de um jogador "i", caso ele nao tenha retorna false
	bool jogador_tira_carta(Carta c, std::size_t i = 0);

    //Acrescenta uma carta "c" a mao do jogador "i"
	void jogador_recebe_carta(Carta c, std::size_t i = 0);

	
    //Pega uma carta do topo de um monte de cartas especificado
	void novo_monte();
    
    //Limpa o monte
	void deleta_monte(std::size_t i);

	std::size_t n_montes() const;

private:
	Baralho _monte; //monte principal
	std::vector<Baralho> _outros_montes;

	std::vector<Jogador> _jogadores;
};

} /* namespace p3 */

#endif /* MESA_H_ */
