#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <iostream>
#include <QCoreApplication>
#include <QDebug>

Calculatrice::Calculatrice(QWidget *parent) : QMainWindow(parent)
{
    QGridLayout *monLayout = new QGridLayout();

    for(int i=0; i <10;i++)
    {
        QString iChar = QString::number(i);
        mesTouchesNum[i] = new CToucheNum(iChar, this);
        connect(mesTouchesNum[i], SIGNAL(clickedToucheNum(QChar)), this, SLOT(traiteAppuiNum(QChar)));
    }
    mesTouchesNum[10] = new CToucheNum(".", this);

    //0th row
    monLayout->addWidget(mesTouchesNum[1],0,0,1,1);
    monLayout->addWidget(mesTouchesNum[2],0,1,1,1);
    monLayout->addWidget(mesTouchesNum[3],0,2,1,1);

    //1th row
    monLayout->addWidget(mesTouchesNum[4],1,0,1,1);
    monLayout->addWidget(mesTouchesNum[5],1,1,1,1);
    monLayout->addWidget(mesTouchesNum[6],1,2,1,1);

    //2th row
    monLayout->addWidget(mesTouchesNum[7],2,0,1,1);
    monLayout->addWidget(mesTouchesNum[8],2,1,1,1);
    monLayout->addWidget(mesTouchesNum[9],2,2,1,1);

    monLayout->addWidget(mesTouchesNum[0],3,0,1,1);
    monLayout->addWidget(mesTouchesNum[10],3,1,1,1);
    // 2nd row with 2-column span
    //gridLayout->addWidget(b5,2,0,1,2);

    // 3rd row with 3-column span
    //gridLayout->addWidget(b6,3,0,1,3);

    QWidget *w = new QWidget();

    mesTouchesOp[0] = new CTouchesOp("+", this);
    mesTouchesOp[1] = new CTouchesOp("-", this);
    mesTouchesOp[2] = new CTouchesOp("*", this);
    mesTouchesOp[3] = new CTouchesOp("/", this);
    mesTouchesOp[4] = new CTouchesOp("=", this);
    mesTouchesOp[5] = new CTouchesOp("AC", this);

    //monAfficheur = new QLCDNumber(this);

    w->setLayout(monLayout);
    w->setWindowTitle("Calculatrice");
    w->setFixedSize(300,500);
    w->show();
}

Calculatrice::~Calculatrice()
{

}

void Calculatrice::traiteAppuiNum(QChar val)
{
    CToucheNum* pButton = qobject_cast<CToucheNum*>(sender());
    if (pButton)
    {
        QString buttonText = pButton->text();
        qInfo() << "test " << buttonText;
    }
}

Calculatrice::traiteAppuiOp(QChar uneToucheOp)
{
    //return uneToucheOp;
}

Calculatrice::traiteCalcul()
{

}
