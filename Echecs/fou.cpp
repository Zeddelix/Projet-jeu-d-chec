#include "fou.h"
#include <cmath>

#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>
#include <QWidget>
#include <partie.h>

namespace chest {

fou::fou(bool couleur, QPixmap image, QString nom) : piece{couleur,image,nom}
{}

bool laCaseEstAtteinte(int arriveX, int absX){
    return arriveX == absX;
}

bool fou::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &p, const QPoint *caseDepart, const QPoint *caseArrive)
{
    int departX = caseDepart -> x(), departY = caseDepart -> y();
    int arriveX = caseArrive -> x(), arriveY = caseArrive -> y();

    if(departX == arriveX){
        return false;
    }

    int xPas = arriveX - departX;
    int yPas = arriveY - departY;
    int absX = abs(xPas), absY = abs(yPas);

    if(absX != absY){
        return false;
    }

    xPas /= abs(xPas);
    yPas /= abs(yPas);

    absX = departX + xPas;
    absY = departY + yPas;

    while(!laCaseEstAtteinte(arriveX, absX) && p[absX][absY] == nullptr)
    {
        absX += xPas;
        absY += yPas;
    }

    return arriveX == absX;

}


}

