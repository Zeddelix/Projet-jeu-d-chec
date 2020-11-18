#include "pion.h"
#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>

Pion::Pion(bool couleur, QString image, QString nom) : piece{couleur,image,nom}
{}

/*QVector <QPoint> deplacementPossible (const plateau& P, QPoint casDep)
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


bool Pion::peutDeplacerTab(const Plateau& P, QPoint casDep, QPoint casArriv, const bool couleur)
{
    deplacementPossible(P,casDep);
    for (int i=0; i<deplacementPossible.size(), i++)
    { if (casArriv==deplacementPossible[i]) return true;
        else return false;
    }
<<<<<<< HEAD
=======
}
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
>>>>>>> Gaulthier
}
*/

bool Pion::peutDeplacer(const Plateau& P, QPoint casDep, QPoint casArriv, const bool couleur)
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

<<<<<<< HEAD
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
=======
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
