#ifndef PRICECULCULATE_H
#define PRICECULCULATE_H
#include <QDateTime>

class PriceCulculate
{
public:
    PriceCulculate();
    virtual double calculate(qint64 time);
protected:
    virtual double dayPrice(qint64 time);
    virtual double hourPrice(qint64 time);
    virtual double secPrice(qint64 time);
};

#endif // PRICECULCULATE_H
