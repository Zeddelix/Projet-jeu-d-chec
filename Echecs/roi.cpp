#include "roi.h"

namespace chest {

roi::roi(const bool couleur,QPixmap image, const QString nom) : piece{couleur,image,nom}
{}


//precondition: arrivee et depart sont sur le plateau (arrivee tombe à l'eau)
bool roi::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart,const QPoint *caseArrive)//ici P est inutile
{
   int departX = caseDepart->x();
   int departY = caseDepart->y();
   int arriveX = caseArrive->x();
   int arriveY = caseArrive->y();

   if(arriveX == departX && (arriveY == departY+1 || arriveY == departY-1))
   {
       return false;
   }

   if (arriveX == departX-1 && (arriveY == departY+1 || arriveY == departY || arriveY == departY-1))
   {
       return false;
   }

   if (arriveX == departX+1 && (arriveY == departY+1 || arriveY == departY || arriveY == departY-1))
   {
       return false;
   }

   return true;

}


//interdit de mettre son roi en echec
//interdit d
//bool prendreUnPion//est ce que toutes les pieces peuvent prendre les pieces uniquement sur leur case d'arrivee
//bool Echec//menacé de capture
//EtMat//la menace est imparable (on peut tenter de parer la menace en déplaçant le roi, en interposant une pièce ou en capturant la pièce attaquante)
//le roque, qui permet le déplacement simultané du roi et de l'une des tours
//la prise en passant, qui permet une capture particulière des pions 
//(sauf roi) la promotion des pions, qui permet de les transformer en une pièce maîtresse de son choix (sauf le roi) lorsqu'ils atteignent la dernière rangée de l'échiquier

}
