#include "primo.h"

double Primo::prezzo_primo=5.0;
Primo::Primo(int q):Cibo(q){}
double Primo::get_prezzo()const{return prezzo_primo*getquan();}
Primo* Primo::clone()const{
    return new Primo(*this);
}
