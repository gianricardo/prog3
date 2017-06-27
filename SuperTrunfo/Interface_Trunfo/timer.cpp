#include "timer.h"

Timer::Timer(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
}

void Timer::start_timer(float seconds)
{
    timer->start(1000*seconds);
    loop.exec();
    timer->stop();
}
