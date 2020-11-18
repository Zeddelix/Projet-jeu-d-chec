#include "cavalier.h"
#include <QString>
#include <QObject>
#include <QPoint>


Cavalier::Cavalier(bool couleur, QString image, QString nom) : piece{couleur,image,nom}
{}

virtual bool Cavalier::PeutDeplacer(plateau P, casDep, casArriv) override
{
    // Faire un tableau de booléen ?
}
