/*
 * trunfo.cpp
 *
 *  Created on: 6 de jun de 2017
 *      Author: breno
 */

#include <QMessageBox>

#include <iostream>
#include <vector>
#include <trunfoui.h>
#include "jogotrunfo.h"
#include "jogada.h"
#include "../../carteado/src/p3/regra.h"
#include "cartatrunfo.h"
#include <QDebug>
#include <QtCore>
#include "inteligenciaartificial.h"


int main(int argc, char *argv[])
{
    //2 jogadores, 16 cartas cada, 32 cartas ao total
    p3::Regra* regra_trunfo = new p3::Regra(2, 16, -1, -1, -1, 32, p3::Regra::modo_fim::padrao,
                                            p3::Regra::condicao_vitoria::padrao, p3::Regra::condicao_derrota::zero_cartas);

    QApplication a(argc, argv);
    TrunfoUI *ui = new TrunfoUI();

    Jogo_trunfo jogo(regra_trunfo, ui->ask_names(), ui);
    jogo.jogar();

    return 0;
}
