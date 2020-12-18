#include "pion.h"
#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>

Pion::Pion(bool couleur, QString image, QString nom) : piece{couleur,image,nom}
{}



bool Pion::peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, QPoint casDep, QPoint casArriv, const bool couleur)
{
    int x = casArriv.x()-casDep.x();
    int y = casArriv.y() - casDep.y();

    if (couleur==0)//le pion est blanc, blanc en bas
    {
        if (x==0 && y==1)
            {
            if (P.getPiece(casArriv.x(), casArriv.y()).isEmpty()) return true; // La case +1 est libre
            }
        if (x==0 && y==2 && AEteDeplace()==false)
        {
            if(P.getPiece(casArriv.x(), casArriv.y()-1).isEmpty() && P.getPiece(casArriv.x(), casArriv.y()).isEmpty()) return true; // les cases +1 et +2 sont libres)
        }
        if ((x==1 && y==1) || (x==-1 && y==1))
        {
            if (P.getPiece(casArriv.x(), casArriv.y()).couleur==1) return true;//bouffer en diagonale
        }
    }


    else//le pion est noir, blanc en bas
    {
        if (x==0 && y==-1)
            {
            if (P.getPiece(casArriv.x(), casArriv.y()).isEmpty()) return true; // La case -1 est libre
            }
        if (x==0 && y==-2 && AEteDeplace()==false)
        {
            if(P.getPiece(casArriv.x(), casArriv.y()+1).isEmpty() && P.getPiece(casArriv.x(), casArriv.y()).isEmpty()) return true; // les cases -1 et -2 sont libres)
        }
        if ((x==1 && y==-1) || (x==-1 && y==-1))
        {
            if (P.getPiece(casArriv.x(), casArriv.y()).couleur==0) return true; //bouffer en diagonale
        }
    }
    return false;

     }


}

