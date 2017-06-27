#include "telapresidente.h"
#include <QApplication>
#include "../../Presidente/src/jogopresidente.h"
#include "../../carteado/src/p3/regra.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/rec/cartas/poker.svg"));
    TelaPresidente w;
    w.show();
    p3::Regra *rule_president = new p3::Regra(4,13,1,-1,-1,52,Regra::modo_fim::rodadas);
    JogoPresidente president(rule_president,{"Jogador","West","North","East"},w);
    president.play();
    return 0;
}
