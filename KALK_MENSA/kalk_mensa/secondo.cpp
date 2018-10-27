#include "secondo.h"

double Secondo::prezzo_secondo=6.0;
Secondo::Secondo(int q):Cibo(q){}
double Secondo::get_prezzo()const{return prezzo_secondo*getquan();}
Secondo* Secondo::clone()const{
    return new Secondo(*this);
}
