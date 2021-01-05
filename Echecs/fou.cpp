#include "fou.h"
#include <cmath>

#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>
#include <QWidget>
#include <partie.h>

namespace chest {

fou::fou(bool couleur, QPixmap image, QString nom) : piece{couleur,image,nom}
{}

bool fou::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur)
{
    int xDepart = depart -> x(), yDepart = depart -> y();
    int xArrive = arrivee -> x(), yArrive= arrivee -> y();

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

    while(xArrive != xCalcul && p[xCalcul][yCalcul] == nullptr){
        xCalcul += xPas;
        yCalcul += yPas;
    }

    if(xArrive == xCalcul){
        if(p[xCalcul][yCalcul] != nullptr)
            return p[xCalcul][yCalcul] -> couleur() != couleur;
        else
            return true;
    }
    else return false;

}

}

