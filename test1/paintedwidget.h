#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QObject>
#include <QWidget>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintedWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // PAINTEDWIDGET_H
