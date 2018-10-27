#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    inserisciUser=new QPushButton(tr("Inserisci Utente"),this);
    quit=new QPushButton(tr("Annulla"),this);
    benvenuto=new QLabel("Benvenuto nella KALK MENSA");
    mainlayout=new QVBoxLayout;
    mainlayout->addWidget(benvenuto);

    mainlayout->addWidget(inserisciUser);
    mainlayout->addWidget(quit);
    setLayout(mainlayout);


    connect(inserisciUser,SIGNAL(clicked(bool)),this, SLOT(openu()));
    connect(quit, SIGNAL(clicked(bool)), this ,SLOT(close()));
}

void MainWindow::openu(){
    use=new user();
    use->show();
    this->close();
}
MainWindow::~MainWindow()
{

}



