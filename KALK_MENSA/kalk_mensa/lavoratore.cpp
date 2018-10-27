#include "lavoratore.h"
double Lavoratore::sconto=30;
Lavoratore::Lavoratore(QString n, QString c,double d):Convenzionato(n,c,d){}
double Lavoratore::Totale(){
    double tot=0;
    for(std::vector<Cibo*>::iterator it=v.begin(); it!=v.end(); ++it){
        tot+=(*it)->get_prezzo();
    }
    set_soldinellacarta(-(tot-(tot*sconto/100)));
    if(get_soldinellacarta()<0)
        throw Eccezione("RICARICA LA CARTA",tot-(tot*sconto/100));
    return tot-(tot*sconto/100);
}
