#ifndef PLAYER_H
#define PLAYER_H

#include <jogador.h>

template<class CARD>
class Player : public p3::JogadorBasico<CARD> {

public:

    Player(std::string name = "") : p3::JogadorBasico<CARD>(name) {}
};

#endif // PLAYER_H
