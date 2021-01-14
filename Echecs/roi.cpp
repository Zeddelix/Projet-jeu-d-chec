#include "roi.h"

namespace chest {

roi::roi(const bool couleur,QPixmap image, const QString nom) : piece{couleur,image,nom}
{}


bool roi::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart,const QPoint *caseArrive)//ici P est inutile
{
   int departX = caseDepart->x();
   int departY = caseDepart->y();
   int arriveX = caseArrive->x();
   int arriveY = caseArrive->y();

   if(arriveX == departX && (arriveY == departY+1 || arriveY == departY-1))
   {
       return true;
   }

   if (arriveX == departX-1 && (arriveY == departY+1 || arriveY == departY || arriveY == departY-1))
   {
       return true;
   }

   if (arriveX == departX+1 && (arriveY == departY+1 || arriveY == departY || arriveY == departY-1))
   {
       return true;
   }

   return false;

}


}
