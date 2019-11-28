#ifndef CTOUCHENUM_H
#define CTOUCHENUM_H

#include <QWidget>
#include <QPushButton>

class CToucheNum : public QPushButton
{
    Q_OBJECT
public:
    //Attributs
    QString sonNum;

    //Méthodes
    CToucheNum(QString unNum, QWidget *w);

signals:
    clickedToucheNum(QChar);

public slots:
    emitClicked();
};

#endif // CTOUCHENUM_H
