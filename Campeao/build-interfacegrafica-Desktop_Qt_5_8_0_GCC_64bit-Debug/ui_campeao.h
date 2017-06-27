/********************************************************************************
** Form generated from reading UI file 'campeao.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMPEAO_H
#define UI_CAMPEAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Campeao
{
public:
    QAction *actionnova_janela;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QWidget *Banana;
    QGridLayout *gridLayout_2;
    QPushButton *novajanela;
    QWidget *terceiro;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QLCDNumber *lcdNumber_2;
    QLineEdit *linhaa_2;
    QLineEdit *linhaa;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QGraphicsView *qgraphicsview;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Campeao)
    {
        if (Campeao->objectName().isEmpty())
            Campeao->setObjectName(QStringLiteral("Campeao"));
        Campeao->resize(697, 384);
        Campeao->setCursor(QCursor(Qt::SizeFDiagCursor));
        actionnova_janela = new QAction(Campeao);
        actionnova_janela->setObjectName(QStringLiteral("actionnova_janela"));
        centralWidget = new QWidget(Campeao);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setCursor(QCursor(Qt::ClosedHandCursor));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Banana = new QWidget(centralWidget);
        Banana->setObjectName(QStringLiteral("Banana"));
        gridLayout_2 = new QGridLayout(Banana);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        novajanela = new QPushButton(Banana);
        novajanela->setObjectName(QStringLiteral("novajanela"));

        gridLayout_2->addWidget(novajanela, 0, 0, 1, 1);


        gridLayout_3->addWidget(Banana, 6, 4, 1, 1);

        terceiro = new QWidget(centralWidget);
        terceiro->setObjectName(QStringLiteral("terceiro"));
        terceiro->setEnabled(true);
        gridLayout = new QGridLayout(terceiro);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(terceiro);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(terceiro);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton = new QPushButton(terceiro);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        label = new QLabel(terceiro);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 2);


        gridLayout_3->addWidget(terceiro, 2, 3, 1, 2);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 3, 1, 2);

        verticalSpacer = new QSpacerItem(20, 94, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 5, 4, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lcdNumber_2 = new QLCDNumber(widget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        gridLayout_4->addWidget(lcdNumber_2, 1, 2, 1, 1);

        linhaa_2 = new QLineEdit(widget);
        linhaa_2->setObjectName(QStringLiteral("linhaa_2"));
        linhaa_2->setReadOnly(true);

        gridLayout_4->addWidget(linhaa_2, 0, 2, 1, 1);

        linhaa = new QLineEdit(widget);
        linhaa->setObjectName(QStringLiteral("linhaa"));
        linhaa->setReadOnly(true);

        gridLayout_4->addWidget(linhaa, 0, 0, 1, 1);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        gridLayout_4->addWidget(lcdNumber, 1, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 1, 1, 1);


        gridLayout_3->addWidget(widget, 0, 3, 1, 2);

        qgraphicsview = new QGraphicsView(centralWidget);
        qgraphicsview->setObjectName(QStringLiteral("qgraphicsview"));
        qgraphicsview->setEnabled(true);
        qgraphicsview->setAutoFillBackground(false);
        qgraphicsview->setInteractive(true);

        gridLayout_3->addWidget(qgraphicsview, 0, 5, 7, 1);

        Campeao->setCentralWidget(centralWidget);
        terceiro->raise();
        widget->raise();
        Banana->raise();
        line->raise();
        qgraphicsview->raise();
        menuBar = new QMenuBar(Campeao);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 697, 22));
        Campeao->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Campeao);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Campeao->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Campeao);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Campeao->setStatusBar(statusBar);

        retranslateUi(Campeao);
        QObject::connect(novajanela, SIGNAL(clicked()), actionnova_janela, SLOT(trigger()));
        QObject::connect(novajanela, SIGNAL(clicked()), terceiro, SLOT(show()));

        QMetaObject::connectSlotsByName(Campeao);
    } // setupUi

    void retranslateUi(QMainWindow *Campeao)
    {
        Campeao->setWindowTitle(QApplication::translate("Campeao", "Campeao", Q_NULLPTR));
        actionnova_janela->setText(QApplication::translate("Campeao", "nova janela", Q_NULLPTR));
        novajanela->setText(QApplication::translate("Campeao", "Novo jogo", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Campeao", "Igual", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Campeao", "Maior", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Campeao", "Menor", Q_NULLPTR));
        label->setText(QApplication::translate("Campeao", "Fa\303\247a sua jogada:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Campeao", "Vs", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        qgraphicsview->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class Campeao: public Ui_Campeao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMPEAO_H
