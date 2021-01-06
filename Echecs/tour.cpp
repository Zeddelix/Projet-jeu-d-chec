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
{    d_picture->setPixmap(image);
     //d_picture->move(600+i*100, 100+j*100);
     d_picture->resize(d_picture->pixmap()->size());
     d_picture->show();}

bool tour::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur)
{
    int xDepart = depart -> x(), yDepart = depart -> y();
    int xArrive = arrivee -> x(), yArrive= arrivee -> y();
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

    while(xArrive != xCalcul && yArrive != yCalcul && p[xCalcul][yCalcul] == nullptr){
        xCalcul += xPas;
        yCalcul += yPas;
    }

    if(xArrive == xCalcul && yArrive != yCalcul){
        if(p[xCalcul][yCalcul] != nullptr){
            return p[xCalcul][yCalcul] -> couleur() != couleur;
        }
        else return true;
    }
    else return false;


}

}

