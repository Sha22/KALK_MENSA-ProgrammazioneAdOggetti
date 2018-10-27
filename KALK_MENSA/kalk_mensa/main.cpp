#include "mainwindow.h"
#include <QApplication>
#include "persona.h"
#include "primo.h"
#include "secondo.h"
#include "contorno.h"
#include"studente.h"
#include "nonconvenzionato.h"
#include "nonconvconbuono.h"
#include "convenzionato.h"
#include "cibo.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   /*Studente* ss=new Studente("sha","dl",2,false);
   //NonConvConBuono* nccb=new NonConvConBuono(true,3);
    Persona*p=ss;
    Cibo* c=new Primo();
    Cibo* l=new Secondo();
    Cibo* f=new Contorno();
    TEST SU STUDENTE attesa:accumulatore finale=0
   *p=(*p)+l-l;
    TEST SU NON CONVENZIONATO attesa:accumulatore finale=59
    NonConvenzionato* nc=new NonConvenzionato();
    p=nc;
    *p=(*p)+l-c+f;
    try{ *p=(*p)+(*c)*3+(*l)+(*f); }//2.5+2.5*3=1
    catch(Eccezione e){
                       e.ricarica_carta(*p);
                     }

    *p=(*p)+(*c)*3;
     p->stampa_scontrino();*/
    return a.exec();
}
