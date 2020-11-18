#include "pion.h"
#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>

<<<<<<< HEAD
Pion::Pion(bool couleur, QString image, QString nom) : piece{couleur,image,nom}
{}

QVector <QPoint> deplacementPossible (const plateau& P, QPoint casDep)
{
    if (Pion.couleur==0)
    {
        QPoint secondCoup(casDep.x(), casDep.y()+1);
        deplacementPossible.append(secondCoup);
        if (casDep.y()==1)
        {
            QPoint premierCoup(casDep.x(), casDep.y()+2);
            deplacementPossible.append(premierCoup);    // S'il est sur la case de départ, on lui autorisé le déplacement +2
        }
     }
     else
     {
        QPoint secondCoup(casDep.x(), casDep.y()-1);
        deplacementPossible.append(secondCoup);
        if (casDep.y()==6)
        {
            QPoint premierCoup(casDep.x(), casDep.y()-2);
            deplacementPossible.append(premierCoup);    // S'il est sur la case de départ, on lui autorisé le déplacement +2
        }

     }

return deplacementPossible;
}

bool Pion::peutDeplacer(const Plateau& P, QPoint casDep, QPoint casArriv, QVector<QPoint> deplacements)
{
    deplacementPossible(P,casDep);
    for (int i=0; i<deplacementPossible.size(), i++)
    { if (casArriv==deplacementPossible[i]) return true;
        else return false;
    }
=======
Pion::Pion(bool couleur, QString nom) : d_nom{nom}
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

QVector <QPoint> deplacementPossible (const Plateau& P, QPoint casDep)
{
    if (couleur==0)
    {
        QPoint secondCoup(casDep.x, casDep.y+1);
        if (casDep.y==1)
        {
            QPoint premierCoup(casDep.x, casDep.y+2);
            deplacementPossible.append(premierCoup);    // S'il est sur la case de départ, on lui autorisé le déplacement +2
        }
     }
     else
     {
        QPoint secondCoup(casDep.x, casDep.y-1);
        if (casDep.y==6)
        {
            QPoint premierCoup(casDep.x, casDep.y-2);
            deplacementPossible.append(premierCoup);    // S'il est sur la case de départ, on lui autorisé le déplacement +2
        }

     }


}

bool Pion::PeutDeplacer(const Plateau& P, QPoint casDep, QPoint casArriv, QVector<QPoint> Deplacements)
{
    deplacementPossible(const Plateau& P, QPoint casDep);
    for (int i=0; i<deplacementPossible.size(), i++)
    { if casArriv==i return true; }
    else return false;
>>>>>>> Gaulthier

}


