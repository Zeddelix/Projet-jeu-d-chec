#include "pion.h"
#include "piece.h"
#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>

namespace chest {

pion::pion(const bool couleur,QPixmap image, const QString nom) : piece{couleur,image,nom}
{}


bool pion::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrive)
{
    int pasX = caseArrive->x() - caseDepart->x();
    int pasY = caseArrive->y() - caseDepart->y();

    bool couleur = plateau[caseDepart->x()][caseDepart->y()]->couleur();

    if (couleur)
    {
        if (pasX == 0 && pasY == 1)
        {
            if (plateau[caseArrive->x()][caseArrive->y()]==nullptr)
                return true;
        }
        if (pasX == 0 && pasY == 2 && caseDepart->y() == 1)
        {
            if( plateau[caseArrive->x()][caseArrive->y()-1]==nullptr && plateau[caseArrive->x()][caseArrive->y()]==nullptr)
                return true;
        }
        if ((pasX == 1 && pasY == 1) || (pasX == -1 && pasY == 1))
        {
            if (plateau[caseArrive->x()][caseArrive->y()] -> couleur() == 1)
                return true;
        }
    }
    else
    {
        if (pasX == 0 && pasY == -1)
        {
            if (plateau[caseArrive->x()][caseArrive->y()]==nullptr)
                return true;
        }
        if (pasX == 0 && pasY == -2 && caseDepart->y() == 6)
        {
            if(plateau[caseArrive->x()][caseArrive->y()+1]==nullptr && plateau[caseArrive->x()][caseArrive->y()]==nullptr)
                return true;
        }
        if ((pasX==1 && pasY == -1) || (pasX == -1 && pasY == -1))
        {
            if (plateau[caseArrive->x()][caseArrive->y()]->couleur()==0)
                return true;
        }
    }
    return false;

}

}


