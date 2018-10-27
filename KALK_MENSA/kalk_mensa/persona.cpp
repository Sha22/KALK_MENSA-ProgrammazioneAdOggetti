#include "persona.h"

Persona::Persona(QString n, QString c):nome(n),cognome(c){}
QString Persona::getName() const{return nome;}
QString Persona::getCognome()const {return cognome;}

void Persona::operator -(Cibo* c){
    for(std::vector<Cibo*>::iterator it=v.begin(); it!=v.end(); ++it){
        if(typeid(*c)==typeid(**it)){
            if(c->getquan() >= (*it)->getquan()){
            delete *it;
            it=v.erase(it);
            --it;
            }
            else{
                (*it)->setquantita((*it)->getquan()-c->getquan());
            }
        }
    }
}

QString Persona::stampa_scontrino(double tot) const{
    QString s;
    QString t;
    t.setNum(tot,'g',3);
    s.append("Mensa Sha-Giu Padova\n");
    s.append("Nome:" + nome + "\n");
    s.append("Cognome: "+ cognome + "\n");
    s.append("Importo totale: "+ t +" euro \n");
    return s;
}
void Persona::reset_v(){
    v.clear();
}
