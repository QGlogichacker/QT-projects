#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H
#include <QWidget>
#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *event);
private:
    void onButtonClicked();
};

#endif // CUSTOMBUTTON_H
