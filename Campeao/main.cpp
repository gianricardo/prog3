
#include <QApplication>
#include <QLabel>
#include <QPushButton>

#include "carta.h"

int main(int argc, char **argv){

	QApplication app(argc, argv);

	QLabel l("abcde");

	QPushButton *p = new QPushButton("abc", &l);

	l.setGeometry(0, 0, 200, 400);

	l.show();

	return app.exec();
}
