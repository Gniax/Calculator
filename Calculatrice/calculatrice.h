#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>
#include <QWidget>
#include <QLCDNumber>
#include <QGridLayout>
#include "ctouchenum.h"
#include "ctouchesop.h"

namespace Ui {
class Calculatrice;
}

class Calculatrice : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculatrice(QWidget *parent = 0);
    ~Calculatrice();
    traiteAppuiOp(QChar uneToucheOp);

private:
    Ui::Calculatrice *ui;
    traiteCalcul();
    CToucheNum *mesTouchesNum[11];
    CTouchesOp *mesTouchesOp[6];
    QLCDNumber monAfficheur;
    QGridLayout monLayout;
    float maValOp1;
    float maValOp2;
    QString maStrOp1;
    QString maStrOp2;
    bool monOp1;
    char monOp;

public slots:
    void traiteAppuiNum();

};

#endif // CALCULATRICE_H
