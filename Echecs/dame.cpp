#include "dame.h"

namespace chest {

dame::dame(bool couleur, QPixmap image, QString nom) : tour{couleur,image,nom} , fou{couleur,image,nom}
{}

 bool dame::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur)
 {
    return fou::peutDeplacer(p,depart,arrivee,couleur) || tour::peutDeplacer(p,depart,arrivee,couleur);

 }


}
