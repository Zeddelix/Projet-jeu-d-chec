#include "cavalier.h"
#include <QString>
#include <QObject>
#include <QPoint>



Cavalier::Cavalier(bool couleur, QString image, QString nom) : piece{couleur,image,nom}
{}

Cavalier::Cavalier(bool couleur, QString nom) : d_nom{nom}
{
    if(couleur)
         {
            d_image=
         }
    else
         {
            d_image=
         }
}


bool Cavalier::peutDeplacer(const Plateau& P, QPoint casDep, QPoint casArriv, const bool couleur)
{
    int x = casArriv.x()-casDep.x();
    int y = casArriv.y() - casDep.y();
    if ((abs(x==1) && abs(y==2) || (abs(x==2) && abs(y==1)) && ((P.getPiece(casArriv.x(), casArriv.y()).isEmpty()) || P.getPiece(casArriv.x(), casArriv.y()).couleur()!=couleur) return true;
    else return false;
}
