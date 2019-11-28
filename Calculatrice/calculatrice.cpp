#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <iostream>
#include <QCoreApplication>
#include <QDebug>
#include <QException>

Calculatrice::Calculatrice(QWidget *parent) : QMainWindow(parent)
{
    QGridLayout *monLayout = new QGridLayout();

    maStrOp1 = new QString("");
    maStrOp2 = new QString("");

    for(int i=0; i <10;i++)
    {
        QString iChar = QString::number(i);
        mesTouchesNum[i] = new CToucheNum(iChar, this);
        connect(mesTouchesNum[i], SIGNAL(clickedToucheNum(QChar)), this, SLOT(traiteAppuiNum(QChar)));
    }

   //mesTouchesNum[0]->setFixedHeight(50);
   // monLayout->setRowStretch(2, 2);

    mesTouchesNum[10] = new CToucheNum(".", this);
    connect(mesTouchesNum[10], SIGNAL(clickedToucheNum(QChar)), this, SLOT(traiteAppuiNum(QChar)));


    mesTouchesOp[0] = new CTouchesOp("+", this);
    connect(mesTouchesOp[0], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    mesTouchesOp[1] = new CTouchesOp("-", this);
    connect(mesTouchesOp[1], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    mesTouchesOp[2] = new CTouchesOp("*", this);
    connect(mesTouchesOp[2], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    mesTouchesOp[3] = new CTouchesOp("/", this);
    connect(mesTouchesOp[3], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    mesTouchesOp[4] = new CTouchesOp("=", this);
    connect(mesTouchesOp[4], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    mesTouchesOp[5] = new CTouchesOp("AC", this);
    connect(mesTouchesOp[5], SIGNAL(clickedToucheOp(QChar)), this, SLOT(traiteAppuiOp(QChar)));

    monAfficheur = new QLCDNumber(this);
    monAfficheur->setFixedSize(275, 75);

    //0th row
    monLayout->addWidget(monAfficheur,0,0,1,4);

    //1th row
    monLayout->addWidget(mesTouchesOp[5],1,0,1,4);

    //2th row
    monLayout->addWidget(mesTouchesNum[1],2,0,1,1);
    monLayout->addWidget(mesTouchesNum[2],2,1,1,1);
    monLayout->addWidget(mesTouchesNum[3],2,2,1,1);
    monLayout->addWidget(mesTouchesOp[0],2,3,1,1);

    //3nd row
    monLayout->addWidget(mesTouchesNum[4],3,0,1,1);
    monLayout->addWidget(mesTouchesNum[5],3,1,1,1);
    monLayout->addWidget(mesTouchesNum[6],3,2,1,1);
    monLayout->addWidget(mesTouchesOp[1],3,3,1,1);

    //4th row
    monLayout->addWidget(mesTouchesNum[7],4,0,1,1);
    monLayout->addWidget(mesTouchesNum[8],4,1,1,1);
    monLayout->addWidget(mesTouchesNum[9],4,2,1,1);
    monLayout->addWidget(mesTouchesOp[3],4,3,1,1);

    //5th row
    monLayout->addWidget(mesTouchesNum[10],5,0,1,1); //point
    monLayout->addWidget(mesTouchesNum[0],5,1,1,1); //0
    monLayout->addWidget(mesTouchesOp[4],5,2,1,1); // =
    monLayout->addWidget(mesTouchesOp[2],5,3,1,1); // *


    QWidget *w = new QWidget();

    w->setLayout(monLayout);
    w->setWindowTitle("Calculatrice");
    w->setFixedSize(300,500);
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
    monOp = uneToucheOp;
    monOp1 = false;
    if(uneToucheOp == 'AC')
    {
        monOp = '\x0';
        monOp1 = true;
        monAfficheur->display('0');
    }
    else
    {
        monAfficheur->display(monOp);
        if(uneToucheOp == '=' && *maStrOp1 != "" && *maStrOp2 != "")
        {
            traiteCalcul();
        }
    }

}

Calculatrice::traiteCalcul()
{
        qInfo() << "traitecalc ";
}
