#include "pion.h"
#include "piece.h"
#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>

namespace chest {

pion::pion(const bool couleur,QPixmap image, const QString nom) : piece{couleur,image,nom}
{}


bool pion::peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur)
{
    int x = arrivee->x() - depart->x();
    int y = arrivee->y() - depart->y();

    if (couleur==0)//le pion est blanc, blanc en bas
    {
        if (x==0 && y==1)
            {
            if (p[arrivee->x()][arrivee->y()]==nullptr) return true; // La case +1 est libre
            }
        if (x==0 && y==2 && depart->y()==1)
        {
            if( p[arrivee->x()][arrivee->y()-1]==nullptr && p[arrivee->x()][arrivee->y()]==nullptr) return true; // les cases +1 et +2 sont libres)
        }
        if ((x==1 && y==1) || (x==-1 && y==1))
        {
            if ( p[arrivee->x()][arrivee->y()] -> couleur() ==1 ) return true;//bouffer en diagonale
        }
    }


    else//le pion est noir, blanc en bas
    {
        if (x==0 && y==-1)
            {
            if (p[arrivee->x()][arrivee->y()]==nullptr) return true; // La case -1 est libre
            }
        if (x==0 && y==-2 && depart->y()==6)
        {
            if(p[arrivee->x()][arrivee->y()+1]==nullptr && p[arrivee->x()][arrivee->y()]==nullptr) return true; // les cases -1 et -2 sont libres)
        }
        if ((x==1 && y==-1) || (x==-1 && y==-1))
        {
            if (p[arrivee->x()][arrivee->y()]->couleur()==0) return true; //bouffer en diagonale
        }
    }
    return false;

}

}


