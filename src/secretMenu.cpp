#include "secretMenu.h"

SecretMenu::SecretMenu(QObject *parent): QObject(parent)
{
    this->listening = false;
    this->timePressed = {};
    this->timeReleased = this->timePressed;
    this->sequence = "";
    this->resetTimer = new QTimer(this);

    connect(this->resetTimer, &QTimer::timeout,this,[=](){
        qDebug() <<"secret input timed out";
        this->sequence.clear();
        this->listening = false;
    });

}

Q_INVOKABLE void SecretMenu::processNumber(int num)
{
    if(this->listening){
        this->sequence += QString::number(num);
        if(this->sequence.length() >3){
            this->sequence = this->sequence.right(3);
        }
        qDebug() <<"secret sequence: " <<this->sequence;

        if(this->sequence == "123"){
            qDebug() <<"secret code has been entered";
            this->listening = false;
            emit SecretMenu::secretUnlocked();
        }
    }

}

Q_INVOKABLE void SecretMenu::processEvalPress()
{
    this->timePressed = QDateTime::currentDateTime();
    qDebug() <<"pressed: " << this->timePressed;
}

Q_INVOKABLE void SecretMenu::processEvalRelease()
{
    this->timeReleased = QDateTime::currentDateTime();
    
    auto t = this->timeReleased - this->timePressed;
    qDebug() <<"released: " << this->timeReleased <<" duration: " <<t.count() <<"ms";
    if(t.count() > 4000){
        qDebug() <<"waiting for \"123\" to open secret menu";
        this->listening = true;
        this->resetTimer->setSingleShot(true);
        this->resetTimer->start(5000);
    }
}
