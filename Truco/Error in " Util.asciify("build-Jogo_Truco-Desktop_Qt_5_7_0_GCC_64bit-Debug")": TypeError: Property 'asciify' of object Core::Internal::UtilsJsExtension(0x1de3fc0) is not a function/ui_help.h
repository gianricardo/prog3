/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QStringLiteral("Help"));
        Help->resize(591, 460);
        gridLayout = new QGridLayout(Help);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plainTextEdit = new QPlainTextEdit(Help);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setMaximumSize(QSize(500, 600));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        plainTextEdit->setFont(font);
        plainTextEdit->setUndoRedoEnabled(true);
        plainTextEdit->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit, 3, 0, 1, 1);

        pushButton = new QPushButton(Help);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 4, 0, 1, 1);


        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QDialog *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "Dialog", 0));
        plainTextEdit->setPlainText(QApplication::translate("Help", "    	\n"
"    VIRA - Carta virada ap\303\263s a distrubui\303\247\303\243o das cartas. A manilha \303\251 a pr\303\263xima carta na sequ\303\252ncia, ap\303\263s esta.\n"
"    MANILHAS - S\303\243o as cartas mais fortes do jogo, na seguinte ordem: paus, copas, espadas e ouros.\n"
"    RODADA - S\303\243o necess\303\241rias 3 rodadas para vencer um turno. Em cada rodada, um jogador baixa uma carta. A carta mais forte da rodada, ganha a rodada para sua dupla\n"
"    TURNO - Vale um ponto e pode ser aumentado para 3, 6, 9 e 12 pontos. \303\211 disputado em melhor de 3 rodadas\n"
"    PARTIDA - Vence a partida a dupla que atingir 12 pontos. Os pontos s\303\243o conquistados em cada turno (de 3 rodadas cada).\n"
"    TRUCO - Truco \303\251 um pedido de aumento de aposta. Pode ser feito apenas na sua vez. Caso a dupla advers\303\241ria aceite o turno passa a valer 3 pontos, caso contr\303\241rio a dupla desafiadora ganha 1 ponto.\n"
"    SEIS - Aumento da aposta de truco, passando a valer 6 pontos caso o advers\303\241"
                        "rio aceite. Se o advers\303\241rio n\303\243o aceitar o pedido, o desafiador ganha 3 pontos.\n"
"    NOVE - Aumento da aposta de 6, passando a valer 9 pontos caso o advers\303\241rio aceite. Se o advers\303\241rio n\303\243o aceitar o pedido, o desafiador ganha 6 pontos.\n"
"    DOZE - Aumento da aposta de 9, passando a valer o jogo caso o advers\303\241rio aceite. Se o advers\303\241rio n\303\243o aceitar o pedido, o desafiador ganha 9 pontos.\n"
"    M\303\203O DE ONZE - A dupla que chegar a 11 pontos tem o direito de olhar as cartas um do outro e analisar se ir\303\243o ou n\303\243o aceitar a partida. Caso a dupla aceite, a M\303\243o de Onze j\303\241 come\303\247a valendo 3 pontos, caso contr\303\241rio o turno acaba dando 1 ponto \303\240 dupla advers\303\241ria.\n"
"    M\303\203O DE FERRO - \303\211 a M\303\243o de Onze especial, quando as duas duplas conseguem chegar a 11 pontos na partida.\n"
"    ESCONDER CARTA - Na sua vez de jogar, \303\251 poss\303\255vel esconder a carta ao inv\303\251s de baix"
                        "ar na mesa, como t\303\241tica de blefe. N\303\243o \303\251 permitido esconder a carta na primeira rodada.\n"
"\n"
"", 0));
        pushButton->setText(QApplication::translate("Help", "Retornar ao Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
