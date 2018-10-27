#include "convenzionato.h"
#include <iostream>
Convenzionato::Convenzionato(QString n="null", QString c="null", double d=0):Persona(n,c),soldi_nella_carta(d){}

double Convenzionato::get_soldinellacarta()const{
    return soldi_nella_carta;
}
void Convenzionato::set_soldinellacarta(double d){
    soldi_nella_carta+=d;
}
void Convenzionato::operator +(Cibo* c){
    if(c->getquan()>1)
        throw Eccezione("PUOI PRENDERNE SOLO UNO",0);
    else
        v.push_back(c->clone());
}

QString Convenzionato::stampa_scontrino(double t)const{
    QString s; s.setNum(get_soldinellacarta(),'g',3);
    return Persona::stampa_scontrino(t) + "Nella carta rimangono: " + s + " euro";
}
