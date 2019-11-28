#include "ctouchenum.h"
#include <QPushButton>
#include "calculatrice.h"
#include <iostream>

CToucheNum::CToucheNum(QString unNum, QWidget *w): QPushButton(unNum, w)
{
    //connect(this,SIGNAL (clickedToucheNum(QChar)), this->parent(), SLOT (Calculatrice::traiteAppuiNum(QChar)));
}

CToucheNum::emitClicked()
{

}

