#include <QLabel>
#include <QMouseEvent>
#ifndef EVENTLABEL_H
#define EVENTLABEL_H


class EventLabel : public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // EVENTLABEL_H

