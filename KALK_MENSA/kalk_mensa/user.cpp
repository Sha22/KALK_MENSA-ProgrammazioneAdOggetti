#include "user.h"
#include "QVBoxLayout"

user::user(QWidget *parent) :
    QWidget(parent)
{

        nUtente=new QLabel("Nome");
        nomeUtente=new QLineEdit(this);
        nomeUtente->setPlaceholderText("Default");
        cUtente=new QLabel("Cognome");
        cognomeUtente=new QLineEdit(this);
        cognomeUtente->setPlaceholderText("Default");
        cCarta=new QLabel("Soldi carta");
        carta=new  QLineEdit(this);
        vBorsa=new QLabel("Borsa di Studio");
        borsa_di_studio=new QCheckBox(this);
        vLavoratore=new QLabel("Lavoratore");
        lavoratore=new QCheckBox(this);
        studente=new QCheckBox(this);
        vStudente=new QLabel("Studente");
        nonconv=new QCheckBox(this);
        vNonC=new QLabel("Non Convenzionato");
        tipologia=new QLabel ("Seleziona la tipologia di "
                              "utente:");
        inseriscidati=new QLabel("Inserisci i dati relativi all'utente:");
        vnonconvconbuono=new QLabel("Buono");
        nonconvconbuono=new QSpinBox(this);
        nonconvconbuono->setValue(0);
        nonconvconbuono->setRange(0,9);

        QVBoxLayout* l=new QVBoxLayout();
        QHBoxLayout*lavoratorelay=new QHBoxLayout();
        l->addWidget(tipologia);
        lavoratorelay->addWidget(vLavoratore);
        lavoratorelay->addWidget(lavoratore);
        l->addLayout(lavoratorelay);
        connect(lavoratore,SIGNAL(toggled(bool) ),this, SLOT (hidebuttonb()));
        connect(lavoratore,SIGNAL(toggled(bool) ),this, SLOT (hidebuono()));
        connect(lavoratore,SIGNAL(toggled(bool) ),this, SLOT (hideothers()));

        QHBoxLayout*studentelay=new QHBoxLayout();
        studentelay->addWidget(vStudente);
        studentelay->addWidget(studente);
        l->addLayout(studentelay);
        connect(studente,SIGNAL(toggled(bool) ),this, SLOT (hidebuono()));
        connect(studente,SIGNAL(toggled(bool) ),this, SLOT (hideothers1()));

        QHBoxLayout*nclay=new QHBoxLayout();
        nclay->addWidget(vNonC);
        nclay->addWidget(nonconv);
        l->addLayout(nclay);
        connect(nonconv,SIGNAL(toggled(bool) ),this, SLOT (hidebuttonb()));
        connect(nonconv,SIGNAL(toggled(bool) ),this, SLOT (hidebuttoncarta()));
        connect(nonconv,SIGNAL(toggled(bool)),this,SLOT (hidenome()));
        connect(nonconv,SIGNAL(toggled(bool)),this,SLOT (hideothers2()));
        l->addWidget(inseriscidati);
        QHBoxLayout*nome=new QHBoxLayout();
        nome->addWidget(nUtente);
        nome->addWidget(nomeUtente);
        l->addLayout(nome);
        QHBoxLayout*cognome=new QHBoxLayout();
        cognome->addWidget(cUtente);
        cognome->addWidget(cognomeUtente);
        l->addLayout(cognome);
        QHBoxLayout*borsalay=new QHBoxLayout();
        borsalay->addWidget(vBorsa);
        borsalay->addWidget(borsa_di_studio);
        l->addLayout(borsalay);
        connect(borsa_di_studio,SIGNAL(toggled(bool) ),this, SLOT (hidebuttoncarta()));
        QHBoxLayout*cartalay=new QHBoxLayout();
        cartalay->addWidget(cCarta);
        cartalay->addWidget(carta);
        l->addLayout(cartalay);
         QHBoxLayout*buoni=new QHBoxLayout();
         buoni->addWidget(vnonconvconbuono);
         buoni->addWidget(nonconvconbuono);
            l->addLayout(buoni);



        Conferma=new QPushButton(tr("Conferma"),this);
        Annulla=new QPushButton(tr("Annulla"),this);
        connect(Conferma,SIGNAL(clicked(bool)) ,this, SLOT (openKalK()));
        connect(Annulla,SIGNAL(clicked(bool)) ,this, SLOT (close()));
        QHBoxLayout*bottoni=new QHBoxLayout();
        bottoni->addWidget(Conferma);
        bottoni->addWidget(Annulla);
        l->addLayout(bottoni);
        setLayout(l);
        show();

}

void user::hidebuttonb(){
    if(nonconv->isChecked() || lavoratore->isChecked()){
    borsa_di_studio->hide();
    vBorsa->hide();
    }
    else {borsa_di_studio->show();
            vBorsa->show();};

}
void user::hidebuttonl(){
    vLavoratore->hide();
    lavoratore->hide();
}
void user::hidebuttoncarta(){
    if(nonconv->isChecked() ||borsa_di_studio->isChecked()){
    carta->hide();
    cCarta->hide();}
    else {
        carta->show();
        cCarta->show();
    }
}

void user::hidenome(){
    if(nonconv->isChecked()){
        nomeUtente->hide();
        cognomeUtente->hide();
        nUtente->hide();
        cUtente->hide();
    }
    else{
        nomeUtente->show();
        cognomeUtente->show();
        nUtente->show();
        cUtente->show();
    }
}

void user::hideothers(){
    if(lavoratore->isChecked()){
        studente->setEnabled(false);
        nonconv->setEnabled(false);
    }
    else {studente->setEnabled(true);
        nonconv->setEnabled(true);

    }
}

void user::hideothers1(){
    if(studente->isChecked()){
        lavoratore->setEnabled(false);
        nonconv->setEnabled(false);
    }
    else {lavoratore->setEnabled(true);
        nonconv->setEnabled(true);
}
}
void user::hideothers2(){
    if(nonconv->isChecked()){
        studente->setEnabled(false);
        lavoratore->setEnabled(false);
    }
    else {studente->setEnabled(true);
        lavoratore->setEnabled(true);
}
}

void user::hidebuono(){
    if(lavoratore->isChecked()||studente->isChecked()){
    vnonconvconbuono->hide();
    nonconvconbuono->hide();}
    else{
        vnonconvconbuono->show();
        nonconvconbuono->show();
    }
}

void user::openKalK(){
    if(nomeUtente->text().isEmpty() || cognomeUtente->text().isEmpty()){
        nUtente->setStyleSheet("QLabel {  color : red; }");
        cUtente->setStyleSheet("QLabel {  color : red; }");
    }
    if(lavoratore->isChecked() && !(nomeUtente->text().isEmpty())
            && !(cognomeUtente->text().isEmpty()))
    {p=new Lavoratore(nomeUtente->text(), cognomeUtente->text(), (carta->text()).toDouble());}

    if(studente->isChecked() && !(nomeUtente->text().isEmpty())
            && !(cognomeUtente->text().isEmpty())) {
        if(borsa_di_studio->isChecked())
                p=new Studente(nomeUtente->text(), cognomeUtente->text(), (carta->text()).toDouble(), true);
                else
                p=new Studente(nomeUtente->text(), cognomeUtente->text(), (carta->text()).toDouble(), false);}


     if(nonconv->isChecked()){
         if(nonconvconbuono->value()>0){
           p=new NonConvConBuono(nonconvconbuono->value());
         }
         else
             p=new NonConvenzionato();
     }

     if (!(lavoratore->isChecked()) || !(studente->isChecked()) || !(nonconv->isCheckable())){
         vLavoratore->setStyleSheet("QLabel {  color : red; }");
         vStudente->setStyleSheet("QLabel {  color : red; }");
         vNonC->setStyleSheet("QLabel {  color : red; }");

     }


    if(p){
    kalkwindow=new kalk(p);
    kalkwindow->show();
    this->hide();
    }


}

user::~user()
{

}
