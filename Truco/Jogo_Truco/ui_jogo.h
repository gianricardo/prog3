/********************************************************************************
** Form generated from reading UI file 'jogo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOGO_H
#define UI_JOGO_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Jogo
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_9;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Jogo)
    {
        if (Jogo->objectName().isEmpty())
            Jogo->setObjectName(QStringLiteral("Jogo"));
        Jogo->setWindowModality(Qt::NonModal);
        Jogo->resize(765, 589);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Jogo->sizePolicy().hasHeightForWidth());
        Jogo->setSizePolicy(sizePolicy);
        Jogo->setMinimumSize(QSize(543, 477));
        Jogo->setToolButtonStyle(Qt::ToolButtonIconOnly);
        widget = new QWidget(Jogo);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(451, 381));
        graphicsView->setMaximumSize(QSize(2000, 2000));
        graphicsView->setSizeIncrement(QSize(0, 0));
        graphicsView->setLineWidth(1);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        graphicsView->setRubberBandSelectionMode(Qt::IntersectsItemShape);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(0, 0));
        lineEdit->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);

        verticalLayout->addWidget(lineEdit);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy2.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy2);
        lineEdit_5->setMinimumSize(QSize(0, 0));
        lineEdit_5->setMaximumSize(QSize(200, 16777215));
        lineEdit_5->setFont(font);
        lineEdit_5->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_5);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);
        lineEdit_2->setMinimumSize(QSize(0, 0));
        lineEdit_2->setMaximumSize(QSize(200, 16777215));
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy2.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy2);
        lineEdit_6->setMinimumSize(QSize(0, 0));
        lineEdit_6->setMaximumSize(QSize(200, 16777215));
        lineEdit_6->setFont(font);
        lineEdit_6->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_6);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy2.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy2);
        lineEdit_4->setMinimumSize(QSize(0, 0));
        lineEdit_4->setMaximumSize(QSize(200, 16777215));
        lineEdit_4->setFont(font);
        lineEdit_4->setText(QStringLiteral(""));
        lineEdit_4->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy2.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy2);
        lineEdit_7->setMinimumSize(QSize(0, 0));
        lineEdit_7->setMaximumSize(QSize(200, 16777215));
        lineEdit_7->setFont(font);
        lineEdit_7->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_7);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy2.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy2);
        lineEdit_3->setMinimumSize(QSize(0, 0));
        lineEdit_3->setMaximumSize(QSize(200, 16777215));
        lineEdit_3->setFont(font);
        lineEdit_3->setEchoMode(QLineEdit::Normal);
        lineEdit_3->setDragEnabled(false);
        lineEdit_3->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_8 = new QLineEdit(widget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        sizePolicy2.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy2);
        lineEdit_8->setMinimumSize(QSize(0, 0));
        lineEdit_8->setMaximumSize(QSize(200, 16777215));
        lineEdit_8->setFont(font);
        lineEdit_8->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_8);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(pushButton_3);


        horizontalLayout_2->addLayout(horizontalLayout);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        lineEdit_9 = new QLineEdit(widget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setMinimumSize(QSize(0, 0));
        lineEdit_9->setMaximumSize(QSize(200, 16777215));
        lineEdit_9->setFont(font);
        lineEdit_9->setReadOnly(true);

        gridLayout->addWidget(lineEdit_9, 1, 1, 1, 1);

        Jogo->setCentralWidget(widget);
        statusbar = new QStatusBar(Jogo);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Jogo->setStatusBar(statusbar);

        retranslateUi(Jogo);

        QMetaObject::connectSlotsByName(Jogo);
    } // setupUi

    void retranslateUi(QMainWindow *Jogo)
    {
        Jogo->setWindowTitle(QApplication::translate("Jogo", "Jogo", 0));
        lineEdit_3->setText(QString());
        pushButton_2->setText(QApplication::translate("Jogo", "Truco/Aumentar", 0));
        pushButton_4->setText(QApplication::translate("Jogo", "Jogada normal", 0));
        pushButton_3->setText(QApplication::translate("Jogo", "Jogar", 0));
        pushButton->setText(QApplication::translate("Jogo", "quit", 0));
    } // retranslateUi

};

namespace Ui {
    class Jogo: public Ui_Jogo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOGO_H
