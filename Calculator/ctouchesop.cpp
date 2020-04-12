#include "ctouchesop.h"

CTouchesOp::CTouchesOp(QString uneOp, QWidget *parent) : QPushButton(uneOp, parent)
{
    sonOp = uneOp;
    connect(this, SIGNAL(clicked()), this, SLOT (emitClicked()));
}

CTouchesOp::emitClicked()
{
    emit(clickedToucheOp(sonOp.at(0)));
}

