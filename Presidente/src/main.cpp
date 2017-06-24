#include "../../Presidente/Presidente/telapresidente.h"
#include <QApplication>
#include "jogopresidente.h"
#include "regrapresidente.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/rec/cartas/poker.svg"));
    TelaPresidente w;
    w.show();
    RegraPresidente *rule_president = new RegraPresidente(4,13,10,-1,-1,52,Regra::modo_fim::rodadas);
    JogoPresidente president(rule_president,{"Jogador","West","North","East"},w);
    president.play();
    return 0;
}
