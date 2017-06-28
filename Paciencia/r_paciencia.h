/*
 * r_paciencia.h
 *
 *  Created on: 20 de jun de 2017
 *      Author: lucas
 */

#ifndef R_PACIENCIA_H_
#define R_PACIENCIA_H_

#include <regra.h>

namespace p3 {

class R_Paciencia : public p3::Regra {
public:

	R_Paciencia();

	bool verifica_ordem (int num1, int num2, int m);
	bool verifica_naipe (Carta::Naipe n1, Carta::Naipe n2, int m);

};

} /* namespace p3 */

#endif /* R_PACIENCIA_H_ */
