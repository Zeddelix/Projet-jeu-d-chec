#include "tour.h"
#include <cmath>

#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>
#include <QtWidgets/QWidget>
#include <partie.h>

namespace chest {
tour::tour(bool couleur, QPixmap image, QString nom) : piece{couleur,image,nom}
{}

bool tour::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrive)
{
    int xDepart = caseDepart -> x(), yDepart = caseDepart -> y();
    int xArrive = caseArrive -> x(), yArrive = caseArrive -> y();
    int xPas, yPas;
    int xCalcul, yCalcul;


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

    while(xArrive != xCalcul && yArrive != yCalcul && plateau[xCalcul][yCalcul] == nullptr){
        xCalcul += xPas;
        yCalcul += yPas;
    }

    if(xArrive == xCalcul && yArrive != yCalcul){
        return plateau[xCalcul][yCalcul] != nullptr;
    }
    else
        return false;


}

}

