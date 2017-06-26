/********************************************************************************
** Form generated from reading UI file 'novo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVO_H
#define UI_NOVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_novo
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;

    void setupUi(QDialog *novo)
    {
        if (novo->objectName().isEmpty())
            novo->setObjectName(QStringLiteral("novo"));
        novo->resize(541, 205);
        label = new QLabel(novo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 110, 99, 16));
        lineEdit = new QLineEdit(novo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 130, 125, 21));
        buttonBox = new QDialogButtonBox(novo);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 170, 81, 32));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label_2 = new QLabel(novo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-140, -180, 761, 471));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/ohterimg/logo.png")));
        label_2->raise();
        label->raise();
        lineEdit->raise();
        buttonBox->raise();

        retranslateUi(novo);
        QObject::connect(buttonBox, SIGNAL(accepted()), novo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), novo, SLOT(reject()));

        QMetaObject::connectSlotsByName(novo);
    } // setupUi

    void retranslateUi(QDialog *novo)
    {
        novo->setWindowTitle(QApplication::translate("novo", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("novo", "Insira seu nome:", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("novo", "Player", Q_NULLPTR));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class novo: public Ui_novo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVO_H
