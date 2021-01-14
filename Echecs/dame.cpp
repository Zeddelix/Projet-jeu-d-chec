#include "dame.h"

namespace chest {

dame::dame(bool couleur, QPixmap image, QString nom) : tour{couleur,image,nom} , fou{couleur,image,nom}
{}

 bool dame::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrive)
 {
    return fou::peutDeplacer(plateau,caseDepart,caseArrive) || tour::peutDeplacer(plateau,caseDepart,caseArrive);

 }
}
