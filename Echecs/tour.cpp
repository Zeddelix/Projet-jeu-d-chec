#include "tour.h"
#include <cmath>

namespace chest {

tour::~tour() {}

tour::tour()
{

}

bool tour::peutDeplacer(const partie& P, const QPoint depart, const QPoint arrive, const bool couleur)
{
    bool deplacement = false;
    int xDepart = depart.x(), yDepart = depart.y();
    int xArrive = arrive.x(), yArrive= arrive.y();

    if(xDepart == xArrive)
        return false;


	if(xDepart != xArrive){
		xPas = 1;
		yPas = 0;
	}
	else if(yDepart != yArrive){
		xPas = 0;
		yPas = 1;
	}
	else return false;

    xCalcul = xDepart + xPas;
    yCalcul = yDepart + yPas;

    while(xArrive != xCalcul && yArrive != yCalcul && P[xCalcul][yCalcul] == nullptr){
        xCalcul += xPas;
        yCalcul += yPas;
    }

    if(xArrive == xCalcul && yArrive != yCalcul){
        if(P[xCalcul][yCalcul] != nullptr){
            return P[xCalcul][yCalcul] -> color != P[xDepart][yDepart] -> color;
        }
        else return true;
    }
    else return false;


}

}

