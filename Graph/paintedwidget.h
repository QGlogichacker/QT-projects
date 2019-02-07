#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QObject>


class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintedWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // PAINTEDWIDGET_H
