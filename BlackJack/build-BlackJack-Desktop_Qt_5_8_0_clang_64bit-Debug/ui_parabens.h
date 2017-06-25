/********************************************************************************
** Form generated from reading UI file 'parabens.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARABENS_H
#define UI_PARABENS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_parabens
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *parabens)
    {
        if (parabens->objectName().isEmpty())
            parabens->setObjectName(QStringLiteral("parabens"));
        parabens->setEnabled(true);
        parabens->resize(400, 197);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(parabens->sizePolicy().hasHeightForWidth());
        parabens->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(parabens);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(220, 160, 164, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        textEdit = new QTextEdit(parabens);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 361, 131));
        textEdit->setReadOnly(true);
        label = new QLabel(parabens);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 0, 311, 251));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ohterimg/chips1.png")));
        label->raise();
        buttonBox->raise();
        textEdit->raise();

        retranslateUi(parabens);
        QObject::connect(buttonBox, SIGNAL(accepted()), parabens, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), parabens, SLOT(reject()));

        QMetaObject::connectSlotsByName(parabens);
    } // setupUi

    void retranslateUi(QDialog *parabens)
    {
        parabens->setWindowTitle(QApplication::translate("parabens", "Dialog", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class parabens: public Ui_parabens {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARABENS_H
