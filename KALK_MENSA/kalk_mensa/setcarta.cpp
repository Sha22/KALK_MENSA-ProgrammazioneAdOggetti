#include "setcarta.h"
#include "kalk.h"

setcarta::setcarta(Convenzionato*p, QWidget *parent) : QWidget(parent), persona(p)
{
       descrizione=new QLabel("SELEZIONA IMPORTO");
       importo=new QLineEdit();
       cancel=new QPushButton("Cancella");
       connect(cancel, SIGNAL(clicked(bool)), this, SLOT(cancella()));
       zero=new QPushButton(tr("0"),this);
       uno=new QPushButton(tr("1"),this);
       due=new QPushButton(tr("2"),this);
       tre=new QPushButton(tr("3"),this);
       quattro=new QPushButton(tr("4"),this);
       cinque=new QPushButton(tr("5"),this);
       sei=new QPushButton(tr("6"),this);
       sette=new QPushButton(tr("7"),this);
       otto=new QPushButton(tr("8"),this);
       nove=new QPushButton(tr("9"),this);
       connect(zero,SIGNAL(clicked(bool)),this,SLOT(p0()));
        connect(uno,SIGNAL(clicked(bool)),this,SLOT(p1()));
        connect(due,SIGNAL(clicked(bool)),this,SLOT(p2()));
        connect(tre,SIGNAL(clicked(bool)),this,SLOT(p3()));
        connect(quattro,SIGNAL(clicked(bool)),this,SLOT(p4()));
        connect(cinque,SIGNAL(clicked(bool)),this,SLOT(p5()));
        connect(sei,SIGNAL(clicked(bool)),this,SLOT(p6()));
        connect(sette,SIGNAL(clicked(bool)),this,SLOT(p7()));
        connect(otto,SIGNAL(clicked(bool)),this,SLOT(p8()));
        connect(nove,SIGNAL(clicked(bool)),this,SLOT(p9()));



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
       numeri->addWidget(zero,3,1);


        add=new QPushButton(tr("Aggiungi"),this);
        annulla=new QPushButton(tr("Annulla"), this);

        connect(add,SIGNAL(clicked(bool)),this, SLOT(aggiungi()));
        connect(annulla,SIGNAL(clicked(bool)),this, SLOT(annullaop()));

        QHBoxLayout* confirml=new QHBoxLayout();
        confirml->addWidget(add);
        confirml->addWidget(annulla);

       QVBoxLayout* layout=new QVBoxLayout();
       layout->addWidget(descrizione);
       layout->addWidget(importo);
       layout->addLayout(numeri);
       layout->addLayout(confirml);
       setLayout(layout);
}

void setcarta::p0(){
    importo->setText(importo->text()+"0");
}
void setcarta::p1(){
    importo->setText(importo->text()+"1");
}
void setcarta::p2(){
    importo->setText(importo->text()+"2");
}
void setcarta::p3(){
    importo->setText(importo->text()+"3");
}
void setcarta::p4(){
    importo->setText(importo->text()+"4");
}
void setcarta::p5(){
    importo->setText(importo->text()+"5");
}
void setcarta::p6(){
    importo->setText(importo->text()+"6");
}
void setcarta::p7(){
    importo->setText(importo->text()+"7");
}
void setcarta::p8(){
    importo->setText(importo->text()+"8");
}
void setcarta::p9(){
    importo->setText(importo->text()+"9");
}


void setcarta::aggiungi(){

    persona->set_soldinellacarta((importo->text()).toDouble());
    this->close();


}

void setcarta::annullaop(){
    this->close();
}

void setcarta::cancella(){
    importo->setText("");
}
