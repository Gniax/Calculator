#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <iostream>
#include <QCoreApplication>
#include <QDebug>

Calculatrice::Calculatrice(QWidget *parent) : QMainWindow(parent)
{
    QGridLayout *gridLayout = new QGridLayout();

    mesTouchesNum[0] = new CToucheNum("0", this);
        connect(mesTouchesNum[0], SIGNAL(clicked()), this, SLOT(traiteAppuiNum()));

    mesTouchesNum[1] = new CToucheNum("1", this);
    mesTouchesNum[2] = new CToucheNum("2", this);
    mesTouchesNum[3] = new CToucheNum("3", this);
    mesTouchesNum[4] = new CToucheNum("4", this);
    mesTouchesNum[5] = new CToucheNum("5", this);
    mesTouchesNum[6] = new CToucheNum("6", this);
    mesTouchesNum[7] = new CToucheNum("7", this);
    mesTouchesNum[8] = new CToucheNum("8", this);
    mesTouchesNum[9] = new CToucheNum("9", this);
    mesTouchesNum[10] = new CToucheNum(".", this);

    //0th row
    gridLayout->addWidget(mesTouchesNum[1],0,0,1,1);
    gridLayout->addWidget(mesTouchesNum[2],0,1,1,1);
    gridLayout->addWidget(mesTouchesNum[3],0,2,1,1);

    //1th row
    gridLayout->addWidget(mesTouchesNum[4],1,0,1,1);
    gridLayout->addWidget(mesTouchesNum[5],1,1,1,1);
    gridLayout->addWidget(mesTouchesNum[6],1,2,1,1);

    //2th row
    gridLayout->addWidget(mesTouchesNum[7],2,0,1,1);
    gridLayout->addWidget(mesTouchesNum[8],2,1,1,1);
    gridLayout->addWidget(mesTouchesNum[9],2,2,1,1);

    gridLayout->addWidget(mesTouchesNum[0],3,0,1,1);
    gridLayout->addWidget(mesTouchesNum[10],3,1,1,1);
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

    w->setLayout(gridLayout);
    w->setWindowTitle("Calculatrice");
    w->setFixedSize(300,500);
    w->show();
}

Calculatrice::~Calculatrice()
{

}

void Calculatrice::traiteAppuiNum()
{
    CToucheNum* pButton = qobject_cast<CToucheNum*>(sender());
        if (pButton) // this is the type we expect
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
