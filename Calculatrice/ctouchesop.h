#ifndef CTOUCHESOP_H
#define CTOUCHESOP_H

#include <QWidget>
#include <QPushButton>

class CTouchesOp : public QWidget
{
    Q_OBJECT
public:
    //Attributs
    QString sonOp;

    //Méthodes
    CTouchesOp(QString uneOp, QWidget *parent = 0);
    emitClicked();
    clickedToucheOp(QChar opTouche);

signals:

public slots:
};

#endif // CTOUCHESOP_H
