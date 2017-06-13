
#include "rules.h"

Rules::Rules() : p3::Regra(1, 0, 6, -1, -1, 114, Regra::modo_fim::rodadas,
                           Regra::condicao_vitoria::maior_pontuacao, 
                           Regra::condicao_derrota::nenhuma, 10) {
    
    
}
