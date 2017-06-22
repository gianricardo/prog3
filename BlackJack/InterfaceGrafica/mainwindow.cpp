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
    connect(qApp, SIGNAL(windowClosed()), qApp, SLOT(quit()));
    ac=1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::placar(int total){
    ui->saldo->clear();
    ui->saldo->insert(QStringLiteral("$%1,00").arg(total));
}

int MainWindow::aposta(){
    nova_aposta na;
    na.setModal(true);
    na.exec();
    ui->apostaatual->clear();
    ui->apostaatual->insert(QStringLiteral("$%1,00").arg(na.val()));
    return na.val();
}

std::string MainWindow::novo_jogo(){
    novo nj;
    nj.setModal(true);
    nj.exec();
    nome=nj.nome();
    ui->nomedojogador->insert(nome);
    return nome.toStdString();
}

void MainWindow::boas_vindas(){
    bemvindo bv;
    bv.texto(nome);
    bv.exec();
}

void MainWindow::naposta(){
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
}

bool MainWindow::continuar(){
    continua c;
    c.exec();
    return c.result();
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
}

void MainWindow::placar_rodada(int saldo, int aposta){
    ui->saldo->clear();
    ui->saldo->insert(QStringLiteral("$%1,00").arg(saldo));
    ui->apostaatual->clear();
    ui->apostaatual->insert(QStringLiteral("$%1,00").arg(aposta));
}

void MainWindow::mostra_maos(/*std::vector<p3::Carta> d, std::vector<p3::Carta> p*/){
  /*  QGraphicsScene scene;
    ui->graphicsView->setScene(&scene);
    scene.addRect(100, 0, 80, 100);
    scene.addEllipse(50, 100, 100, 80);
    ui->acaow->show();
    QEventLoop loop;
    QObject::connect(ui->hit, SIGNAL(clicked()),&loop, SLOT(quit()));
    QObject::connect(ui->double_2, SIGNAL(clicked()),&loop, SLOT(quit()));
    QObject::connect(ui->stay, SIGNAL(clicked()),&loop, SLOT(quit()));
    loop.exec();
    ui->acaow->hide();
*/

}
void MainWindow::obrigado(){
    QMessageBox msgBox;
    msgBox.setText("Obrigado por jogar!");
    msgBox.setInformativeText(":)");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
    qApp -> closeAllWindows();
    qApp -> quit();
    qApp ->quitOnLastWindowClosed();
}


void   MainWindow::closeEvent(QCloseEvent*)
{
    qApp->quit();
}
