#include "cavalier.h"
#include <QString>
#include <QObject>
#include <QPoint>



Cavalier::Cavalier(bool couleur, QPixmap image, QString nom) : piece{couleur,image,nom}
{}

bool Cavalier::peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur)
{
    int x = depart->x() - arrivee->x();
    int y = depart->y() - arrivee->y();
    if ((abs(x==1) && abs(y==2) || (abs(x==2) && abs(y==1)) && ((p[arrivee->x()][arrivee->y()])==nullptr)) || ( (p[arrivee->x()][arrivee->y()]->couleur()!=couleur))) return true;
    else return false;
}
