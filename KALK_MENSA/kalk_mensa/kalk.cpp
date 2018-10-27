#include "kalk.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "user.h"
#include "persona.h"
#include<string>
#include "eccezione.h"
#include <iostream>
#include <QTextEdit>
#include <QString>

kalk::kalk(Persona* p, QWidget *parent) : person(p),QWidget(parent)
{
    cibo= new Primo();
    tot=0;
    segno=true;
    display=new QLineEdit;
    Convenzionato* c=dynamic_cast<Convenzionato*>(p);

    dati_inseriti=new QLabel("UTENTE INSERITO:");
    nomeutente_inserito=new QLabel(p->getName());
    cognomeutente_inserito=new QLabel(p->getCognome());

    pPrimo=new QPushButton(tr("Primo"),this);
    pSecondo=new QPushButton(tr("Secondo"),this);
    pContorno=new QPushButton(tr("Contorno"),this);

    connect(pPrimo, SIGNAL(clicked(bool)), this, SLOT(pPrimoclicked()));
    connect(pSecondo, SIGNAL(clicked(bool)), this, SLOT(pSecondoclicked()));
    connect(pContorno, SIGNAL(clicked(bool)), this, SLOT(pContornoclicked()));

    if(c){
    soldi_caricati=new QLabel(QString::number(c->get_soldinellacarta()));

    }

    uno=new QPushButton(tr("1"),this);
    due=new QPushButton(tr("2"),this);
    tre=new QPushButton(tr("3"),this);
    quattro=new QPushButton(tr("4"),this);
    cinque=new QPushButton(tr("5"),this);
    sei=new QPushButton(tr("6"),this);
    sette=new QPushButton(tr("7"),this);
    otto=new QPushButton(tr("8"),this);
    nove=new QPushButton(tr("9"),this);
    connect(uno,SIGNAL(clicked(bool)),this,SLOT(pUnoc()));
    connect(due,SIGNAL(clicked(bool)),this,SLOT(pDuec()));
    connect(tre,SIGNAL(clicked(bool)),this,SLOT(pTrec()));
    connect(quattro,SIGNAL(clicked(bool)),this,SLOT(pQuattroc()));
    connect(cinque,SIGNAL(clicked(bool)),this,SLOT(pCinquec()));
    connect(sei,SIGNAL(clicked(bool)),this,SLOT(pSeic()));
    connect(sette,SIGNAL(clicked(bool)),this,SLOT(pSettec()));
    connect(otto,SIGNAL(clicked(bool)),this,SLOT(pOttoc()));
    connect(nove,SIGNAL(clicked(bool)),this,SLOT(pNovec()));
    piu=new QPushButton(tr("+"),this);
    per=new QPushButton(tr("*"),this);
    meno=new QPushButton(tr("-"),this);
    connect(piu, SIGNAL(clicked(bool)), this, SLOT(pPiuclicked()));
    connect(per, SIGNAL(clicked(bool)), this, SLOT(pPerclicked()));
    connect(meno, SIGNAL(clicked(bool)), this, SLOT(pMenoclicked()));
    reset=new QPushButton(tr("Reset"),this);
    cambiaUtente=new QPushButton(tr("Cambia Utente"),this);
    Totale=new QPushButton(tr("Totale"),this);
    RicaricaCarta=new QPushButton(tr("Ricarica Carta"),this);
    Saldo_carta=new QPushButton(tr("Saldo carta"),this);
    Stampa=new QPushButton(tr("Stampa Scontrino"),this);
    QVBoxLayout* buttons=new QVBoxLayout();
    buttons->addWidget(reset);
    buttons->addWidget(cambiaUtente);
    buttons->addWidget(RicaricaCarta);
    buttons->addWidget(Saldo_carta);
    buttons->addWidget(Stampa);
    connect(reset, SIGNAL(clicked(bool)),this,SLOT(resets()));
    connect(cambiaUtente, SIGNAL(clicked(bool)),this, SLOT(changeuser()));
    connect(RicaricaCarta, SIGNAL(clicked(bool)), this, SLOT(ricarica()));
    connect(Totale, SIGNAL(clicked(bool)),this, SLOT(calcolaTot()));
    connect(Saldo_carta, SIGNAL(clicked(bool)), this, SLOT(displaySaldoCarta()));
    connect(Stampa,SIGNAL(clicked(bool)),this, SLOT(stampas()));
    Stampa->setEnabled(false);
    if(!c){
            RicaricaCarta->setEnabled(false);
            Saldo_carta->setEnabled(false);
        }

    QVBoxLayout*dati=new QVBoxLayout();

    dati->addWidget(dati_inseriti);
    dati->addWidget(nomeutente_inserito);
    dati->addWidget(cognomeutente_inserito);
    if(soldi_caricati)
    {dati->addWidget(soldi_caricati);}

    QVBoxLayout* menu=new QVBoxLayout();
    menu->addWidget(pPrimo);
    menu->addWidget(pSecondo);
    menu->addWidget(pContorno);


    QGridLayout* numeri=new QGridLayout;
    numeri->addWidget(sette,0,0);
    numeri->addWidget(otto,0,1);
    numeri->addWidget(nove,0,2);
    numeri->addWidget(quattro,1,0);
    numeri->addWidget(cinque,1,1);
    numeri->addWidget(sei,1,2);
    numeri->addWidget(uno,2,0);
    numeri->addWidget(due,2,1);
    numeri->addWidget(tre,2,2);
    if(c){
        uno->setEnabled(false);
        due->setEnabled(false);
        tre->setEnabled(false);
        quattro->setEnabled(false);
        cinque->setEnabled(false);
        sei->setEnabled(false);
        sette->setEnabled(false);
        otto->setEnabled(false);
        nove->setEnabled(false);
    }

    QVBoxLayout* operazioni=new QVBoxLayout;
    operazioni->addWidget(piu);
    operazioni->addWidget(meno);
    operazioni->addWidget(per);
    if(c)
        per->setEnabled(false);


    QGridLayout* layout=new QGridLayout;
    layout->addLayout(dati,0,0);
    layout->addLayout(buttons,1,0);
    layout->addWidget(display,0,1);
    layout->addWidget(Totale,0,2);
    layout->addLayout(menu,1,3);

    layout->addLayout(numeri,1,1);
    layout->addLayout(operazioni,1,2);
    setLayout(layout);



}
void kalk::pUnoc(){
    display->setText(display->text()+"1");
    numero=1;
    cibo->operator *(numero);
}
void kalk::pDuec(){
display->setText(display->text()+"2");
numero=2;
cibo->operator *(numero);
}
void kalk::pTrec(){
display->setText(display->text()+"3");
numero=3;
cibo->operator *(numero);
}
void kalk::pQuattroc(){
    display->setText(display->text()+"4");
    numero=4;
    cibo->operator *(numero);
}
void kalk::pCinquec(){
    display->setText(display->text()+"5");
    numero=5;
    cibo->operator *(numero);
}
void kalk::pSeic(){
    display->setText(display->text()+"6");
    numero=6;
    cibo->operator *(numero);
}
void kalk::pOttoc(){
    display->setText(display->text()+"8");
    numero=8;
    cibo->operator *(numero);
}
void kalk::pSettec(){
    display->setText(display->text()+"7");
    numero=7;
    cibo->operator *(numero);
}
void kalk::pNovec(){
    display->setText(display->text()+"9");
    numero=9;
    cibo->operator *(numero);
}
void kalk::changeuser(){
    delete person;
    this->close();
    user* newuser=new user();
    newuser->show();

}

void kalk::ricarica(){
    Convenzionato* c=static_cast<Convenzionato*>(person);
    setcarta* newwindow= new setcarta(c);
    newwindow->show();
}
void kalk::resets(){
    person->reset_v();
    display->setText("");
    segno=true;
    if(dynamic_cast<Convenzionato*>(person)){
        static_cast<Convenzionato*>(person)->set_soldinellacarta(tot);
        QString str;
        str.setNum(static_cast<Convenzionato*>(person)->get_soldinellacarta(),'g',3);
        soldi_caricati->setText(str);
     }
    tot=0;
    pPrimo->setEnabled(true);
    pSecondo->setEnabled(true);
    pContorno->setEnabled(true);
}

void kalk::stampas(){
    QTextEdit* qte=new QTextEdit;
        qte->setReadOnly(true);
        qte->append(person->stampa_scontrino(tot));
        qte->append("Buon appetito");
        qte->setGeometry(1000,180,200,400);
        qte->show();
}

void kalk::displaySaldoCarta(){
    Convenzionato*c=static_cast<Convenzionato*>(person);
    display->setText(QString::number(c->get_soldinellacarta()));
}


void kalk::pPrimoclicked(){
    delete cibo;
    cibo=new Primo();
    if((display->text()).isEmpty()){
    display->setText("primo");
    }
    else {
    display->setText(display->text()+" primo");
    }
    pPrimo->setEnabled(false);
    pSecondo->setEnabled(false);
    pContorno->setEnabled(false);
}

void kalk::pSecondoclicked(){
    delete cibo;
    cibo=new Secondo();
    if((display->text()).isEmpty()){
    display->setText("secondo");
    }
    else {
            display->setText(display->text()+" secondo");
        }

    pPrimo->setEnabled(false);
    pSecondo->setEnabled(false);
    pContorno->setEnabled(false);
}

void kalk::pContornoclicked(){
    delete cibo;
    cibo=new Contorno();
    if((display->text()).isEmpty()){
    display->setText("contorno");
    }
    else {
            display->setText(display->text()+" contorno");
        }

    pPrimo->setEnabled(false);
    pSecondo->setEnabled(false);
    pContorno->setEnabled(false);

}

void kalk::pPiuclicked(){

    display->setText(display->text()+"+");
    person->operator +(cibo);
    if(dynamic_cast<Convenzionato*>(person)){
        QString str;
        str.setNum(static_cast<Convenzionato*>(person)->get_soldinellacarta(),'g',3);
        soldi_caricati->setText(str);
    }
    segno=true;
    if(dynamic_cast<Primo*>(cibo)){
    pSecondo->setEnabled(true);
    pContorno->setEnabled(true);}
    if(dynamic_cast<Secondo*>(cibo))
    {pContorno->setEnabled(true);}
    if(dynamic_cast<Contorno*>(cibo))
    {piu->setEnabled(false);}


}
void kalk::pPerclicked(){
    display->setText(display->text()+"*");
}
void kalk::pMenoclicked(){
    display->setText(display->text()+"-");
    if(segno)
        person->operator +(cibo);
    else person->operator -(cibo);

    segno=false;
    pPrimo->setEnabled(true);
    pSecondo->setEnabled(true);
    pContorno->setEnabled(true);
    piu->setEnabled(true);
}

void kalk::calcolaTot(){
    if(segno){
            person->operator +(cibo);}
     else
            {person->operator -(cibo);}
    try{tot=person->Totale();}

    catch(Eccezione e){
       QString s=e.mostra_errore();
       tot=e.t;
       display->setText(QString::number(tot));

       errore=new QMessageBox();
       errore->setText(s);
       errore->show();
    }

   if(dynamic_cast<Studente*>(person)&& static_cast<Studente*>(person)->getBorsaStudio())
       display->setText("BORSA DI STUDIO");
    else{
   if(dynamic_cast<Convenzionato*>(person)){
           QString str;
           str.setNum(static_cast<Convenzionato*>(person)->get_soldinellacarta(),'g',3);
           soldi_caricati->setText(str);
   }
   display->setText(QString::number(tot));

}
    Stampa->setEnabled(true);
}

kalk::~kalk(){}
