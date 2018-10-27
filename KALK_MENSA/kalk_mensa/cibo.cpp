#include "cibo.h"


Cibo::Cibo(int q):quant(q){}
void Cibo::setquantita(int t){
    quant=t;
}
int Cibo::getquan()const{
    return quant;
}
void Cibo::operator*(int per){
    setquantita(per);
}
