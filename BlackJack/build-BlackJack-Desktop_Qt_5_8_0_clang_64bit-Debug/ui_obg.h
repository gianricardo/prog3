/********************************************************************************
** Form generated from reading UI file 'obg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBG_H
#define UI_OBG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_obg
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *obg)
    {
        if (obg->objectName().isEmpty())
            obg->setObjectName(QStringLiteral("obg"));
        obg->resize(410, 300);
        buttonBox = new QDialogButtonBox(obg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(70, 270, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label = new QLabel(obg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 280, 151, 16));
        label_2 = new QLabel(obg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 390, 259));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/ohterimg/bemvindo.jpg")));

        retranslateUi(obg);
        QObject::connect(buttonBox, SIGNAL(accepted()), obg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), obg, SLOT(reject()));

        QMetaObject::connectSlotsByName(obg);
    } // setupUi

    void retranslateUi(QDialog *obg)
    {
        obg->setWindowTitle(QApplication::translate("obg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("obg", "Obrigada por jogar", Q_NULLPTR));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class obg: public Ui_obg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBG_H
