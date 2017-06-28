#include "telapresidente.h"
#include "ui_telapresidente.h"

TelaPresidente::TelaPresidente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPresidente)
{
    ui->setupUi(this);
    ui->direita->hide();
    ui->esquerda->hide();
    ui->pass->hide();
    ui->play->hide();
    ui->label->hide();
    ui->east->hide();
    ui->west->hide();
    ui->north->hide();
    ui->nome_jogador->hide();
    ui->titulo->show();
    ui->voltar->hide();
    ui->text->hide();
    QBrush gameb(Qt::darkCyan);
    sceneGame = new QGraphicsScene(this) ;
    sceneInstructions = new QGraphicsScene(this) ;
    sceneMenu = new QGraphicsScene(this) ;
    sceneGame->setBackgroundBrush(gameb);
    sceneInstructions->setBackgroundBrush(gameb);
    sceneMenu->setBackgroundBrush(gameb);
    ui->graphicsView->setScene(sceneMenu);

    QPen pen(Qt::red);
    QBrush redb(Qt::red);
    cursor = sceneGame->addPolygon(QPolygonF({QPoint(150,480),QPoint(170,480),QPoint(160,490)}),pen,redb);

    win = new WinnerWindow(this) ;
    select = 1;
    select_max=13;
    this->setWindowFlags((windowFlags() | Qt::CustomizeWindowHint)& ~Qt::WindowCloseButtonHint & ~Qt::WindowMinimizeButtonHint);
    QObject::connect(ui->quit,SIGNAL(clicked()),this,SLOT(quiting()));
}

TelaPresidente::~TelaPresidente()
{
    delete ui;
    delete win;
    delete sceneGame;
    delete sceneMenu;
    delete sceneInstructions;
}

void TelaPresidente::show_hand(std::vector<p3::Carta> v0,std::vector<p3::Carta> v1,std::vector<p3::Carta> v2,std::vector<p3::Carta> v3)
{
    qDeleteAll(sceneGame->items());
    select_max=(int)v0.size();
    select=1;
    ui->label->hide();
    QPen pen(Qt::red);
    QBrush redb(Qt::red);
    cursor = sceneGame->addPolygon(QPolygonF({QPoint(150,480),QPoint(170,480),QPoint(160,490)}),pen,redb);
    int k=0;
    ImgCarta *item;
    for(auto i : v0){
        item=new ImgCarta(i.numero(),(int)i.naipe(),true,74+20*k,250);
        sceneGame->addItem(item);
        k++;
    }
    k=0;
    for(auto i : v1){
        item=new ImgCarta(i.numero(),(int)i.naipe(),false,0,39+15*k);
        sceneGame->addItem(item);
        k++;
    }
    k=0;
    for(auto i : v2){
        item=new ImgCarta(i.numero(),(int)i.naipe(),false,74+20*k,10);
        sceneGame->addItem(item);
        k++;
    }
    k=0;
    for(auto i : v3){
        item=new ImgCarta(i.numero(),(int)i.naipe(),false,385,39+15*k);
        sceneGame->addItem(item);
        k++;
    }
}

void TelaPresidente::show_montes(std::vector<p3::Carta> montes)
{
    int k=0;
    ImgCarta *item;
    for(unsigned int i=0;i<montes.size();i++){
        item=new ImgCarta(montes[i].numero(),(int)montes[i].naipe(),true,100+60*k,100);
        sceneGame->addItem(item);
        k++;
    }
    ui->titulo->hide();
}

int TelaPresidente::get_play()
{
    ui->label->show();
    QEventLoop espera;
    QObject::connect(ui->play,SIGNAL(clicked()),&espera,SLOT(quit()));
    QObject::connect(ui->pass,SIGNAL(clicked()),&espera,SLOT(quit()));
    espera.exec();
    return select;
}

int TelaPresidente::tela_inicio()
{
    QEventLoop espera;
    QObject::connect(ui->novo_jogo,SIGNAL(clicked()),&espera,SLOT(quit()));
    espera.exec();
    return 1;
}

void TelaPresidente::show_winner(int pos)
{
    win->show();
    win->mostra_vencedor(pos);
    QMessageBox::about(this,"","Obrigado por jogar");
    QApplication::quit();
}

void TelaPresidente::show_pontuation(std::vector<int> p)
{
    QMessageBox::information(this,"", QString(" Sua pontuacao: %1\n Pontuacao de West: %2\n Pontuacao de North: %3\n Pontuacao de East: %4\n").arg(
                                 QString::number(p[0]),QString::number(p[1]),QString::number(p[2]),QString::number(p[3])));
}

void TelaPresidente::show_position(std::vector<int> p)
{
    if(p[0]==0){
        QMessageBox::about(this,"","Você é o presidente");
    }else if(p[1]==0){
        QMessageBox::about(this,"","Você é o vicepresidente");
    }else if(p[2]==0){
        QMessageBox::about(this,"","Você é o vice bobo");
    }else{
        QMessageBox::about(this,"","Você é o bobo");
    }

}

int TelaPresidente::get_rounds()
{
    Rounds r;
    r.show();
    r.move(580,332);
    return r.rodadas();
}


void TelaPresidente::on_play_clicked()
{
    update();
}

void TelaPresidente::on_pass_clicked()
{
    update();
    select=0;
}

void TelaPresidente::on_esquerda_clicked()
{
    if(select>1){
        select--;
        cursor->moveBy(-40,0);
    }
    update();
}

void TelaPresidente::on_direita_clicked()
{
    if(select<select_max){
        select++;
        cursor->moveBy(40,0);
    }
    update();
}

void TelaPresidente::on_novo_jogo_clicked()
{
    ui->direita->show();
    ui->esquerda->show();
    ui->play->show();
    ui->pass->show();
    ui->east->show();
    ui->west->show();
    ui->north->show();
    ui->nome_jogador->setText(ui->lineEdit->text());
    ui->nome_jogador->show();
    ui->label->show();
    ui->instructions->hide();
    ui->novo_jogo->hide();
    ui->lineEdit->hide();
    ui->texto->hide();
    ui->titulo->hide();
    ui->graphicsView->setScene(sceneGame);
}

void TelaPresidente::on_instructions_clicked()
{
    ui->novo_jogo->hide();
    ui->instructions->hide();
    ui->lineEdit->hide();
    ui->titulo->move(300,50);
    ui->texto->hide();
    ui->voltar->show();
    ui->text->show();
    ui->text->setText("As regras do jogo são simples. Voce deve jogar o mesmo número de cartas que o adversário, porém sempre com um valor"
                      " maior que o anterior. A carta de valor mais alto é a de número 2, depois o ás, e depois segue a sequencia original"
                      " do baralho. O primeiro a terminar suas cartas na rodada é declarado presidente, o segundo vicepresidente, o terceiro"
                      " vicebobo e o ultimo, bobo. No início de uma nova rodada o bobo cede suas duas cartas mais altas ao presidente, enquanto"
                      " que o presidente cede suas duas mais baixas àquele. O vicepresidente recebe a carta mais alta do vicebobo e cede sua"
                      " mais baixa à esse. O presidente inicia a nova rodada. Use os botoes '<' e '>' para movimentar entre suas cartas. "
                      "Aperte 'jogar' para jogar a carta que esta indicada. Será jogado sempre o maior número de cartas possível da carta selecionada"
                      ", dependendo da quantidade que existir em sua mão. Se você selecionar uma carta que não pode ser jogada, o jogo automaticamente"
                      " passa sua vez. Se você não quiser jogar alguma carta também pode passar a vez.");
}

void TelaPresidente::on_voltar_clicked()
{
    ui->novo_jogo->show();
    ui->instructions->show();
    ui->titulo->show();
    ui->texto->show();
    ui->lineEdit->show();
    ui->voltar->hide();
    ui->text->hide();
}

void TelaPresidente::quiting()
{
    QApplication::closeAllWindows();
    QApplication::quit();
}
