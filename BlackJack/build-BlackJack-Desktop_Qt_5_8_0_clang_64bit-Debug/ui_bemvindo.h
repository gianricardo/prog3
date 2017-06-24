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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_bemvindo
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QDialogButtonBox *Obrigado;

    void setupUi(QDialog *bemvindo)
    {
        if (bemvindo->objectName().isEmpty())
            bemvindo->setObjectName(QStringLiteral("bemvindo"));
        bemvindo->resize(400, 96);
        verticalLayout = new QVBoxLayout(bemvindo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(bemvindo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        Obrigado = new QDialogButtonBox(bemvindo);
        Obrigado->setObjectName(QStringLiteral("Obrigado"));
        Obrigado->setOrientation(Qt::Horizontal);
        Obrigado->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(Obrigado);


        retranslateUi(bemvindo);
        QObject::connect(Obrigado, SIGNAL(accepted()), bemvindo, SLOT(accept()));

        QMetaObject::connectSlotsByName(bemvindo);
    } // setupUi

    void retranslateUi(QDialog *bemvindo)
    {
        bemvindo->setWindowTitle(QApplication::translate("bemvindo", "Dialog", Q_NULLPTR));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class bemvindo: public Ui_bemvindo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEMVINDO_H
