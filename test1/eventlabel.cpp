#include "eventlabel.h"

void EventLabel::mouseMoveEvent(QMouseEvent *event){
    this->setText(tr("<center><h1>Move:(%1, %2)</h1></center>").arg(event->x()).arg(event->y()));
}

void EventLabel::mousePressEvent(QMouseEvent *event){
    this->setText(tr("<center><h1>Press:(%1, %2)</h1></center>").arg(event->x()).arg(event->y()));
}

void EventLabel::mouseReleaseEvent(QMouseEvent *event){
    this->setText(tr("<center><h1>Release:(%1, %2)</h1></center>").arg(event->x()).arg(event->y()));
}
