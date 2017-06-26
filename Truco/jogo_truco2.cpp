/*
 * jogo_truco2.cpp
 *
 *  Created on: 25 de jun de 2017
 *      Author: bruno
 */

#include "jogo_truco2.h"

namespace p4 {

Jogo_Truco2::Jogo_Truco2(p3::Regra *regra, std::vector<std::string> nomes):Jogo_Truco(regra,nomes){

    interface = new Jogo2(0,QString::fromStdString(nomes[0]));
    interface->show();

}

Jogo_Truco2::~Jogo_Truco2() {
	// TODO Auto-generated destructor stub
}

} /* namespace p4 */
