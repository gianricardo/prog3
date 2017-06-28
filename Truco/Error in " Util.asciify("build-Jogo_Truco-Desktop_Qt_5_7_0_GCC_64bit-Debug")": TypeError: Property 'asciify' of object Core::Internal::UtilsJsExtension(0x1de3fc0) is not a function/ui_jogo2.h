/********************************************************************************
** Form generated from reading UI file 'jogo2.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOGO2_H
#define UI_JOGO2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Jogo2
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Jogo2)
    {
        if (Jogo2->objectName().isEmpty())
            Jogo2->setObjectName(QStringLiteral("Jogo2"));
        Jogo2->resize(800, 600);
        centralwidget = new QWidget(Jogo2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(451, 381));
        graphicsView->setMaximumSize(QSize(2000, 2000));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMaximumSize(QSize(200, 16777215));
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);
        lineEdit_3->setMaximumSize(QSize(200, 16777215));
        lineEdit_3->setFont(font);
        lineEdit_3->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);
        lineEdit_4->setMaximumSize(QSize(200, 16777215));
        lineEdit_4->setFont(font);
        lineEdit_4->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_4);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(200, 16777215));
        lineEdit_5->setFont(font);
        lineEdit_5->setReadOnly(true);

        gridLayout->addWidget(lineEdit_5, 1, 1, 1, 1);

        Jogo2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Jogo2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        Jogo2->setMenuBar(menubar);
        statusbar = new QStatusBar(Jogo2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Jogo2->setStatusBar(statusbar);

        retranslateUi(Jogo2);

        QMetaObject::connectSlotsByName(Jogo2);
    } // setupUi

    void retranslateUi(QMainWindow *Jogo2)
    {
        Jogo2->setWindowTitle(QApplication::translate("Jogo2", "MainWindow", 0));
        pushButton->setText(QApplication::translate("Jogo2", "Truco/Aumentar", 0));
        pushButton_2->setText(QApplication::translate("Jogo2", "Jogada Normal", 0));
        pushButton_4->setText(QApplication::translate("Jogo2", "Jogar", 0));
        pushButton_3->setText(QApplication::translate("Jogo2", "quit", 0));
    } // retranslateUi

};

namespace Ui {
    class Jogo2: public Ui_Jogo2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOGO2_H
