/*
 * regratrunfo.h
 *
 *  Created on: 24 de mai de 2017
 *      Author: breno
 */

#ifndef REGRATRUNFO_H_
#define REGRATRUNFO_H_

#include <vector>

#include "carta.h"

class Carta_trunfo : public p3::Carta {
public:

	Carta_trunfo(int numero, Carta::Naipe naipe, bool frente = false);

	int participacao_gps();
	int titulos_mundiais_construtores();
	int vitorias();
	int pole_positions();
	int gps_com_podios();

private:

	int _participacao_gps = 0;
	int _titulos_mundiais_construtores = 0;
	int _vitorias = 0;
	int _pole_positions = 0;
	int _gps_com_podios = 0;

	using Atributos = std::vector<int>;
	std::vector< Atributos > lista_atributos {
		{430,	1,		23,		14, 	66	},	//1A
		{182,	0,		0,		1,		3	},	//2A
		{104,	0,		1,		3,		7	},	//3A
		{250,	0,		4,		2,		17	},	//4A
		{197,	1,		17,		11,		53	},	//5A
		{340,	0,		0,		0,		0	},	//6A
		{103,	0,		0,		0,		3	},	//7A
		{49,	0,		1,		1,		4	},	//8A

		{648,	8,		162,	141,	347	},	//1B
		{60,	1,		9,		4,		17	},	//2B
		{227,	0,		3,		5,		21	},	//3B
		{117,	0,		0,		0,		2	},	//4B
		{129,	2,		16,		11,		41	},	//5B
		{47,	0,		3,		1,		13	},	//6B
		{88,	0,		3,		2,		9	},	//7B
		{245,	2,		35,		50,		82	},	//8B

		{776,	16,		209,	203,	454	},	//1C
		{382,	0,		0,		1,		9	},	//2C
		{40,	0,		1,		0,		3	},	//3C
		{71,	0,		0,		0,		3	},	//4C
		{70,	0,		9,		10,		28	},	//5C
		{260,	1,		27,		15,		94	},	//6C
		{394,	2,		35,		39,		106	},	//7C
		{28,	1,		9,		7,		11	},	//8C

		{491,	7,		79,		107,	157	},	//1D
		{268,	0,		1,		1,		20	},	//2D
		{122,	0,		0,		2,		8	},	//3D
		{52,	0,		1,		0,		7	},	//4D
		{517,	9,		113,	125,	228	},	//5D
		{112,	0,		10,		12,		18	},	//6D
		{12,	0,		9,		8,		10	},	//7D
		{326,	0,		9,		9,		45	},	//8D
	};

	void set_atributos(Atributos att);
	int numero_naipe();
};




#endif /* REGRATRUNFO_H_ */
