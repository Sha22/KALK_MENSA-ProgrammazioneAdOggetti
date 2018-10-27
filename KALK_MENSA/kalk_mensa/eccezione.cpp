#include "eccezione.h"
Eccezione::Eccezione(QString d, double tt):s(d),t(tt){}
QString Eccezione::mostra_errore()const{
    return s;
   }
