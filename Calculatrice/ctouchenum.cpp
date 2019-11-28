#include "ctouchenum.h"
#include <QPushButton>
#include "calculatrice.h"
#include <iostream>
#include <QDebug>

CToucheNum::CToucheNum(QString unNum, QWidget *w): QPushButton(unNum, w)
{
    sonNum = unNum;
    connect(this, SIGNAL(clicked()), this, SLOT (emitClicked()));
}

CToucheNum::emitClicked()
{
    emit(clickedToucheNum(sonNum.at(0)));
}

