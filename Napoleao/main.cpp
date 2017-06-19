#include <iostream>
#include "napoleao.h"
#define RODADAS 5
#define JOGADORES 2
#define MAO 5

int main(void) {
	std::cout << "#################### INICIO DO TESTE ###############" << std::endl;
    Napoleao nap;
    nap.inicia_jogo();
    std::cout << "#################### FIM DO TESTE ###############" << std::endl;
    return 0;
}
