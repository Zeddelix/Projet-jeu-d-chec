#include "tour.h"
#include <cmath>
#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>

namespace chest {

tour::~tour() {}

tour::tour()
{

}

bool tour::peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override
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
        if(p[xCalcul][yCalcul] != nullptr){
            return p[xCalcul][yCalcul] -> color != p[xDepart][yDepart] -> color;
        }
        else return true;
    }
    else return false;


}

}

