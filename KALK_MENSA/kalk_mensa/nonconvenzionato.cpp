#include "nonconvenzionato.h"

double NonConvenzionato::Totale(){
    double tot=0;
    for(std::vector<Cibo*>::iterator it=v.begin(); it!=v.end(); ++it){
        tot+=(*it)->get_prezzo();
    }
    return tot;
}
QString NonConvenzionato::stampa_scontrino(double t)const{return Persona::stampa_scontrino(t);}


void NonConvenzionato::operator +(Cibo* c){
    v.push_back(c->clone());
}
