#include "custombutton.h"
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
CustomButton::CustomButton(QWidget *parent):QPushButton(parent){
    connect(this, &CustomButton::clicked, this, onButtonClicked);
}

void CustomButton::onButtonClicked(){
    qDebug() << "you clicked this!";
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) {
        qDebug() << "left";
    } else {
        QPushButton::mousePressEvent(event);
    }
}
