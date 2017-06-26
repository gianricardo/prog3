/********************************************************************************
** Form generated from reading UI file 'dealer.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEALER_H
#define UI_DEALER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_dealer
{
public:
    QLabel *label;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dealer)
    {
        if (dealer->objectName().isEmpty())
            dealer->setObjectName(QStringLiteral("dealer"));
        dealer->resize(519, 412);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dealer->sizePolicy().hasHeightForWidth());
        dealer->setSizePolicy(sizePolicy);
        label = new QLabel(dealer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 380, 111, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(dealer);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(12, 12, 495, 361));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/ohterimg/dealer.png")));
        buttonBox = new QDialogButtonBox(dealer);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(430, 380, 81, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        retranslateUi(dealer);
        QObject::connect(buttonBox, SIGNAL(accepted()), dealer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dealer, SLOT(reject()));

        QMetaObject::connectSlotsByName(dealer);
    } // setupUi

    void retranslateUi(QDialog *dealer)
    {
        dealer->setWindowTitle(QApplication::translate("dealer", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("dealer", "Vez do Dealer", Q_NULLPTR));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dealer: public Ui_dealer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEALER_H
