#include "fou.h"
#include <cmath>

namespace chest {

fou::~fou() {}

fou::fou()
{

}

bool fou::peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override
{
    bool deplacement = false;
    int xDepart = depart.x(), yDepart = depart.y();
    int xArrive = arrive.x(), yArrive= arrive.y();

    if(xDepart == xArrive)
        return false;

    int xPas = xArrive - xDepart; // 2 - 0 = 2
    int yPas = yArrive - yDepart; // 0 - 2 = -2
    int xCalcul = abs(xPas), yCalcul = abs(yPas);

    if(xCalcul != yCalcul)
        return false;

    xPas /= abs(xPas);
    yPas /= abs(yPas);

    xCalcul = xDepart + xPas;
    yCalcul = yDepart + yPas;

    while(xArrive != xCalcul && P[xCalcul][yCalcul] == nullptr){
        xCalcul += xPas;
        yCalcul += yPas;
    }

    if(xArrive == xCalcul){
        if(p[xCalcul][yCalcul] != nullptr)){
            return p[xCalcul][yCalcul] -> color != p[xDepart][yDepart] -> color;
        }
        else return true;
    }
    else return false;


}

}

