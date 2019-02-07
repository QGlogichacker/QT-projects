#ifndef REALPRICE_H
#define REALPRICE_H
#include "priceculculate.h"

class RealPrice : public PriceCulculate
{
public:
    RealPrice();
protected:
    double caluculate(qint64 time);
    int flag;
    void setFlag(int f);

};

#endif // REALPRICE_H
