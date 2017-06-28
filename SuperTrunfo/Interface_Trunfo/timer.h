#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QTimer>
#include <QtCore>
#include <QEventLoop>

class Timer : public QWidget
{
    Q_OBJECT
public:
    explicit Timer(QWidget *parent = 0);
    void start_timer(float seconds);

private:
    QTimer *timer;
    QEventLoop loop;

signals:

public slots:

};

#endif // TIMER_H
