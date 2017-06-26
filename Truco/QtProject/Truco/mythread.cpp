#include "mythread.h"

MyThread::MyThread(QObject *parent):
    QThread(parent)
{
    Stop = false;
}


void MyThread::stop(){
    Stop = true;
}

void MyThread::run(unsigned int card)
{
    for(int i = 0; i < 100000; i++){
        QMutex mutex;
        mutex.lock();
        if(this->Stop)break;
        mutex.unlock();


        emit selectCard(card);

        this->msleep(100);
    }


}
