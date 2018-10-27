#include "contorno.h"

double Contorno::prezzo_contorno=3.0;
Contorno::Contorno(int q):Cibo(q){}
double Contorno::get_prezzo()const{return prezzo_contorno*getquan();}
Contorno* Contorno::clone()const{
    return new Contorno(*this);
}
