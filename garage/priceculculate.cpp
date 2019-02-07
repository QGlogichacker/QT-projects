#include "priceculculate.h"
PriceCulculate::PriceCulculate(){

}

double PriceCulculate::calculate(qint64 time){
    return hourPrice(time) + dayPrice(time) + secPrice(time);
}
double PriceCulculate::hourPrice(qint64 time){
    return 0;
}
double PriceCulculate::dayPrice(qint64 time){
    return 0;
}
double PriceCulculate::secPrice(qint64 time){
    return 0;
}
