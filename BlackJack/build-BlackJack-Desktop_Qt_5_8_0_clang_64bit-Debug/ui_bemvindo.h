/********************************************************************************
** Form generated from reading UI file 'bemvindo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEMVINDO_H
#define UI_BEMVINDO_H

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

class Ui_bemvindo
{
public:
    QLineEdit *lineEdit;
    QDialogButtonBox *Obrigado;
    QLabel *label;

    void setupUi(QDialog *bemvindo)
    {
        if (bemvindo->objectName().isEmpty())
            bemvindo->setObjectName(QStringLiteral("bemvindo"));
        bemvindo->resize(400, 300);
        lineEdit = new QLineEdit(bemvindo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 230, 376, 41));
        lineEdit->setReadOnly(true);
        Obrigado = new QDialogButtonBox(bemvindo);
        Obrigado->setObjectName(QStringLiteral("Obrigado"));
        Obrigado->setGeometry(QRect(0, 270, 388, 29));
        Obrigado->setOrientation(Qt::Horizontal);
        Obrigado->setStandardButtons(QDialogButtonBox::Ok);
        label = new QLabel(bemvindo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 376, 221));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ohterimg/bemvindo.jpg")));

        retranslateUi(bemvindo);
        QObject::connect(Obrigado, SIGNAL(accepted()), bemvindo, SLOT(accept()));

        QMetaObject::connectSlotsByName(bemvindo);
    } // setupUi

    void retranslateUi(QDialog *bemvindo)
    {
        bemvindo->setWindowTitle(QApplication::translate("bemvindo", "Dialog", Q_NULLPTR));
        lineEdit->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class bemvindo: public Ui_bemvindo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEMVINDO_H
