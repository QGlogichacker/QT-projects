#include "realprice.h"
#include <QDateTime>
#include <QtMath>
#include <QDebug>

RealPrice::RealPrice(){
    flag = 0;
}

double RealPrice::caluculate(qint64 time){
    switch(flag){
    case 0:
        return time;break;
    case 1:
        return time*2;break;
    case 2:
        return log10(time);break;
    }
}

void RealPrice::setFlag(int f){
    this->flag = f;
}
