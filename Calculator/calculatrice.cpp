#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <iostream>
#include <QCoreApplication>
#include <QDebug>
#include <QException>

Calculatrice::Calculatrice(QWidget *parent) : QMainWindow(parent)
{
    QApplication::setFont(QFont("Helvetica", 12, QFont::Bold));
    QGridLayout *monLayout = new QGridLayout();

    maStrOp1 = new QString("");
    maStrOp2 = new QString("");
    monOp1 = false;
    maValOp1 = 0;
    maValOp2 = 0;

    for(int i=0; i <10;i++)
    {
        QString iChar = QString::number(i);

        mesTouchesNum[i] = new CToucheNum(iChar, this);
        mesTouchesNum[i]->setFixedHeight(50);
        mesTouchesNum[i]->setStyleSheet("background-color: darkgray; color: white; border-radius:10px; border: 1px solid white;");
        connect(mesTouchesNum[i], SIGNAL(clickedToucheNum(QChar)), this, SLOT(traiteAppuiNum(QChar)));
    }

    mesTouchesNum[10] = new CToucheNum(".", this);
    mesTouchesNum[10]->setFixedHeight(50);
    mesTouchesNum[10]->setStyleSheet("background-color: rgb(0, 77, 153); color: black; border-radius:10px; border: 1px solid black;");
    connect(mesTouchesNum[10], SIGNAL(clickedToucheNum(QChar)), this, SLOT(traiteAppuiNum(QChar)));    

    mesTouchesOp[0] = new CTouchesOp("+", this);
    mesTouchesOp[0]->setFixedHeight(50);
    mesTouchesOp[0]->setStyleSheet("background-color: rgb(0, 77, 153); color: black; border-radius:10px; border: 1px solid black;");
    connect(mesTouchesOp[0], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));


    mesTouchesOp[1] = new CTouchesOp("-", this);
    mesTouchesOp[1]->setFixedHeight(50);
    mesTouchesOp[1]->setStyleSheet("background-color: rgb(0, 77, 153); color: black; border-radius:10px; border: 1px solid black;");
    connect(mesTouchesOp[1], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    mesTouchesOp[2] = new CTouchesOp("*", this);
    mesTouchesOp[2]->setFixedHeight(50);
    mesTouchesOp[2]->setStyleSheet("background-color: rgb(0, 77, 153); color: black; border-radius:10px; border: 1px solid black;");
    connect(mesTouchesOp[2], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    mesTouchesOp[3] = new CTouchesOp("/", this);
    mesTouchesOp[3]->setFixedHeight(50);
    mesTouchesOp[3]->setStyleSheet("background-color: rgb(0, 77, 153); color: black; border-radius:10px; border: 1px solid black;");
    connect(mesTouchesOp[3], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    mesTouchesOp[4] = new CTouchesOp("=", this);
    mesTouchesOp[4]->setFixedHeight(50);
    mesTouchesOp[4]->setStyleSheet("background-color: rgb(0, 77, 153); color: black; border-radius:10px; border: 1px solid black;");
    connect(mesTouchesOp[4], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    mesTouchesOp[5] = new CTouchesOp("AC", this);
    mesTouchesOp[5]->setFixedHeight(50);
    mesTouchesOp[5]->setStyleSheet("background-color: rgb(0, 77, 153); color: black; border-radius:10px; border: 1px solid black;");
    connect(mesTouchesOp[5], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    QPalette lcdpalette = palette();
    lcdpalette.setColor(QPalette::WindowText, Qt::green);
    lcdpalette.setColor(QPalette::Background, Qt::black);

    monAfficheur = new QLCDNumber(this);
    monAfficheur->setFixedSize(275, 75);
    monAfficheur->setDigitCount(8);
    monAfficheur->setLineWidth(1);
    monAfficheur->setPalette(lcdpalette);
    monAfficheur->setAutoFillBackground(true);

    //ligne 0
    monLayout->addWidget(monAfficheur,0,0,1,4);

    //1ere ligne
    monLayout->addWidget(mesTouchesOp[5],1,0,1,4);

    //2eme ligne
    monLayout->addWidget(mesTouchesNum[1],2,0,1,1);
    monLayout->addWidget(mesTouchesNum[2],2,1,1,1);
    monLayout->addWidget(mesTouchesNum[3],2,2,1,1);
    monLayout->addWidget(mesTouchesOp[0],2,3,1,1);

    //3eme ligne
    monLayout->addWidget(mesTouchesNum[4],3,0,1,1);
    monLayout->addWidget(mesTouchesNum[5],3,1,1,1);
    monLayout->addWidget(mesTouchesNum[6],3,2,1,1);
    monLayout->addWidget(mesTouchesOp[1],3,3,1,1);

    //4eme ligne
    monLayout->addWidget(mesTouchesNum[7],4,0,1,1);
    monLayout->addWidget(mesTouchesNum[8],4,1,1,1);
    monLayout->addWidget(mesTouchesNum[9],4,2,1,1);
    monLayout->addWidget(mesTouchesOp[3],4,3,1,1);

    //5eme ligne
    monLayout->addWidget(mesTouchesNum[10],5,0,1,1); //point
    monLayout->addWidget(mesTouchesNum[0],5,1,1,1); //0
    monLayout->addWidget(mesTouchesOp[4],5,2,1,1); // =
    monLayout->addWidget(mesTouchesOp[2],5,3,1,1); // *

    QPalette widgetpalette = palette();
    widgetpalette.setColor(QPalette::Background, Qt::darkGray);

    QWidget *w = new QWidget();

    w->setLayout(monLayout);
    w->setWindowTitle("Calculatrice");
    w->setFixedSize(300,500);
    w->setAutoFillBackground(true);
    w->setPalette(widgetpalette);
    w->show();
}

Calculatrice::~Calculatrice()
{

}

void Calculatrice::traiteAppuiNum(QChar uneValNum)
{
    if(monOp1 == true)
    {
        maStrOp1->append(uneValNum);
        monAfficheur->display(*maStrOp1);
    }
    else
    {
        maStrOp2->append(uneValNum);
        monAfficheur->display(*maStrOp2);
    }
}

void Calculatrice::traiteAppuiOp(QChar uneToucheOp)
{
    if(uneToucheOp == "A") //on réinitialise tout si on appuie sur AC
    {
        monOp = '\x0';
        maValOp1 = 0;
        maValOp2 = 0;
        *maStrOp1 = "";
        *maStrOp2 = "";
        monAfficheur->display("0");
    }
    else if(uneToucheOp == '=')//Si c'est la touche égal: on traite sans ajouter l'opérateur
    {
        if(*maStrOp1 != "" && *maStrOp2 != "")
        {
            traiteCalcul();
        }
       monOp1 = false;
    }
    else //Si c'est d'autre opérateurs: on traite
    {
       // Si c'est le premier calcul, on ajoute directement l'opérateur pour éviter
       // une absence d'opérateur si on demande directement le résulat après.
       if(monOp == '\x0') monOp = uneToucheOp;

        monOp1 = true;
        monAfficheur->display(monOp);
        if(*maStrOp1 != "" && *maStrOp2 != "") //Si on a bien les deux valeurs
        {
            traiteCalcul();
            monOp = uneToucheOp; //On ajoute le nouvel opérateur après avoir effectué le calcul
        }
        else //sinon on ajoute quand même
        {
            monOp = uneToucheOp;
        }
    }
}

Calculatrice::traiteCalcul()
{
    switch(monOp.unicode())
    {
        case ('+'):
            maValOp1 = maStrOp1->toFloat();
            maValOp2 = maStrOp2->toFloat();
            *maStrOp2 = QString::number(maValOp2 + maValOp1);
            *maStrOp1 = "";
            monAfficheur->display(*maStrOp2);
        break;

        case ('-'):
            maValOp1 = maStrOp1->toFloat();
            maValOp2 = maStrOp2->toFloat();
            *maStrOp2 = QString::number(maValOp2 - maValOp1);
            *maStrOp1 = "";
            monAfficheur->display(*maStrOp2);
        break;

        case ('*'):
            maValOp1 = maStrOp1->toFloat();
            maValOp2 = maStrOp2->toFloat();
            *maStrOp2 = QString::number(maValOp2 * maValOp1);
            *maStrOp1 = "";
            monAfficheur->display(*maStrOp2);
        break;

        case ('/'):
            maValOp1 = maStrOp1->toFloat();
            maValOp2 = maStrOp2->toFloat();
            *maStrOp2 = QString::number(maValOp2 / maValOp1);
            *maStrOp1 = "";
            monAfficheur->display(*maStrOp2);
        break;

        default:
        break;

    }
}
