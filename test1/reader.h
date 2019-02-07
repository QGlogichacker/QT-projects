#include<qDebug>
#include<QObject>
#ifndef READER_H
#define READER_H
class Reader:public QObject{
    Q_OBJECT
public:
    Reader(){}
    void receiveNewsPaper(const QString &name){
        qDebug()<< "Receives Newspaper: "<<name;
    }
};
#endif // READER_H
