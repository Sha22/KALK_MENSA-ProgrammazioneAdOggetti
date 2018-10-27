#include "nonconvconbuono.h"

NonConvConBuono::NonConvConBuono(int q):NonConvenzionato(),buoni(q){}
double NonConvConBuono::Totale(){
    double tot=0;
    for(std::vector<Cibo*>::iterator it=v.begin();it !=v.end();++it){
        if((*it)->getquan()>buoni){
            int diff=(*it)->getquan()-buoni;
            (*it)->setquantita(diff);
            tot+=(*it)->get_prezzo();
        }
    }
    return tot;

}
QString NonConvConBuono::stampa_scontrino(double t)const{
    QString str=NonConvenzionato::stampa_scontrino(t);
    QString s; s.setNum(buoni);
   return str + "Numero di buoni utilizzati: " + s + "\n";
}
