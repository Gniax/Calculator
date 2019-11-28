#ifndef CTOUCHESOP_H
#define CTOUCHESOP_H

#include <QWidget>
#include <QPushButton>

class CTouchesOp : public QPushButton
{
    Q_OBJECT
public:
    //Attributs
    QString sonOp;

    //Méthodes
    CTouchesOp(QString uneOp, QWidget *parent = 0);

signals:
    clickedToucheOp(QChar opTouche);

public slots:
    emitClicked();
};

#endif // CTOUCHESOP_H
