#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->acaow->hide();
    QBrush blueb(Qt::darkGreen);
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(blueb);
    ui->graphicsView->setScene(scene);
    this->setWindowState(Qt::WindowMaximized);
    this->setWindowFlags ( Qt::CustomizeWindowHint );

    ac=1;
}

MainWindow::~MainWindow()
{
    qDeleteAll(scene->items());
    delete ui->acaow;
    delete ui->placarw;
    delete scene;
    delete imagem;
    delete ui->centralwidget;
    delete ui;
}


void MainWindow::placar(int total){
    ui->saldo->clear();
    ui->saldo->insert(QStringLiteral("$%1,00").arg(total));
}

int MainWindow::aposta(){
    nova_aposta na;
    na.show();
    na.exec();
    ui->apostaatual->clear();
    ui->apostaatual->insert(QStringLiteral("$%1,00").arg(na.val()));
    int res = na.val();
    na.close();
    return res;
}

std::string MainWindow::novo_jogo(){
    novo nj;
    nj.show();
    nj.exec();
    nome=nj.nome();
    nj.close();
    ui->nomedojogador->insert(nome);
    return nome.toStdString();
}

void MainWindow::boas_vindas(){
    bemvindo bv;
    bv.texto(nome);
    bv.exec();
    bv.close();
}

void MainWindow::naposta(){
    qDeleteAll(scene->items());
    n_aposta na;
    na.exec();
}

int MainWindow::jogue(){
    ui->acaow->show();
    QEventLoop loop;
    QObject::connect(ui->hit, SIGNAL(clicked()),&loop, SLOT(quit()));
    QObject::connect(ui->double_2, SIGNAL(clicked()),&loop, SLOT(quit()));
    QObject::connect(ui->stay, SIGNAL(clicked()),&loop, SLOT(quit()));
    loop.exec();
    loop.quit();
    int i=ac;
    ui->acaow->hide();
    return i;
}


void MainWindow::on_actionhit_triggered()
{
    ac=1;
}

void MainWindow::on_actiondouble_triggered()
{
    ac=2;
}

void MainWindow::on_actionstay_triggered()
{
    ac=3;
}


void MainWindow::vez_dealer(){
    dealer d;
    d.exec();
    d.close();
}

bool MainWindow::continuar(){
    continua c;
    c.exec();
    bool re = c.result();
    c.close();
    return re;
}

void MainWindow::vencedor(bool a, int b, int c){
    QString texto;
    if(a){
        texto=QString("Parabéns %1, você venceu.\nGanhou $%2,00 e agora tem $%3,00 de saldo!").arg(nome).arg(QString::number(b)).arg(QString::number(c));
    }else{
        texto=QString("Desculpe %1, você perdeu.\nPerdeu $%2,00 e agora tem $%3,00 de saldo!").arg(nome).arg(QString::number(b)).arg(QString::number(c));
    }
    parabens p;
    p.insere(texto);
    p.exec();
    p.close();
    qDeleteAll(scene->items());
}

void MainWindow::placar_rodada(int saldo, int aposta){
    ui->saldo->clear();
    ui->saldo->insert(QStringLiteral("$%1,00").arg(saldo));
    ui->apostaatual->clear();
    ui->apostaatual->insert(QStringLiteral("$%1,00").arg(aposta));
}

void MainWindow::mostra_maos(std::vector<p3::Carta> d, std::vector<p3::Carta> p){
    qDeleteAll(scene->items());
    int xd=-100;
    int yd=-50;
    int xp=-100;
    int yp=100;
    imagem_carta *f = new imagem_carta(9,1);
    imagem_carta *e = new imagem_carta(9,0);
    f->setPos(xd,yd);
    e->setPos(xp,yp);
    scene->addItem(f);
    scene->addItem(e);
    xd=xd+40;
    xp=xp+40;
    for (auto a:d){
        int n=0;
        if (a.naipe()==(typename p3::Carta::Naipe)0){n=0;}
        if (a.naipe()==(typename p3::Carta::Naipe)1){n=1;}
        if (a.naipe()==(typename p3::Carta::Naipe)2){n=2;}
        if (a.naipe()==(typename p3::Carta::Naipe)3){n=3;}
        imagem_carta *c = new imagem_carta(n,a.numero());
        c->setPos(xd,yd);
        scene->addItem(c);
        xd=xd+40;
    }
    for (auto b:p){
        int n=0;
        if (b.naipe()==(typename p3::Carta::Naipe)0){n=0;}
        if (b.naipe()==(typename p3::Carta::Naipe)1){n=1;}
        if (b.naipe()==(typename p3::Carta::Naipe)2){n=2;}
        if (b.naipe()==(typename p3::Carta::Naipe)3){n=3;}
        imagem_carta *c = new imagem_carta(n,b.numero());
        c->setPos(xp,yp);
        scene->addItem(c);
        xp=xp+40;
    }
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();
}

void MainWindow::obrigado(){
    obg o;
    o.show();
    o.exec();
    o.close();
    qApp -> closeAllWindows();
    qApp -> quit();
    qApp ->quitOnLastWindowClosed();
}
