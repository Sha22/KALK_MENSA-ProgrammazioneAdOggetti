#include "studente.h"

double Studente::sconto=50;
Studente::Studente(QString n, QString c,double d,bool b):Convenzionato(n,c,d),borsa_di_studio(b){}
bool Studente::getBorsaStudio()const{return borsa_di_studio;}
double Studente::Totale(){
    double tot=0;
    for(std::vector<Cibo*>::iterator it=v.begin(); it!=v.end(); ++it){
        tot+=(*it)->get_prezzo();
    }
    if(borsa_di_studio)
        return 0;
        set_soldinellacarta(-(tot-(tot*sconto/100)));
        if(get_soldinellacarta()<0)
                throw Eccezione("RICARICA CARTA", tot-(tot*sconto/100));
    return tot-(tot*sconto/100);
}
QString Studente::stampa_scontrino(double t)const{
    if(borsa_di_studio){
        return Persona::stampa_scontrino(t) + "Borsa di Studio Attiva \n";
    }
    else{
        return Convenzionato::stampa_scontrino(t);
    }
}
