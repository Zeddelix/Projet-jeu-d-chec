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

bool xDepartEquivalentxArrive(int xDepart, int xArrive){
    return xDepart == xArrive;
}

bool yDepartEquivalentyArrive(int yDepart, int yArrive){
    return yDepart == yArrive;
}

bool tour::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrive)
{
    int xDepart = caseDepart -> x(), yDepart = caseDepart -> y();
    int xArrive = caseArrive -> x(), yArrive = caseArrive -> y();
    int xPas, yPas;
    int xCalcul, yCalcul;


    if(!xDepartEquivalentxArrive(xDepart, xArrive)){
		xPas = 1;
		yPas = 0;
	}
    else if(!yDepartEquivalentyArrive(yDepart, yArrive)){
		xPas = 0;
		yPas = 1;
	}
	else return false;

    xCalcul = xDepart + xPas;
    yCalcul = yDepart + yPas;

    QPoint *caseActuelle = new QPoint(xCalcul, yCalcul);

    while(!xDepartEquivalentxArrive(caseActuelle->x(), xArrive) && !yDepartEquivalentyArrive(caseActuelle->y(), yArrive) && chest::partie().estVide(plateau, *caseActuelle)){
        caseActuelle->setX(caseActuelle->x()+1);
        caseActuelle->setY(caseActuelle->y()+1);
    }

    return xDepartEquivalentxArrive(caseActuelle->x(), xArrive) && yDepartEquivalentyArrive(caseActuelle->y(), yArrive);
}

}

