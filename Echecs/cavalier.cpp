#include "cavalier.h"
#include <QString>
#include <QObject>
#include <QPoint>



Cavalier::Cavalier(bool couleur, QString image, QString nom) : piece{couleur,image,nom}
{}

bool Cavalier::peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, QPoint casDep, QPoint casArriv, const bool couleur)
{
    int x = casArriv.x() - casArriv.y() ;
    int y = casArriv.y() - casDep.y();
    if ((abs(x==1) && abs(y==2) || (abs(x==2) && abs(y==1)) && (p.getPiece(casArriv.x(), casArriv.y()).isEmpty()) || p.getPiece(casArriv.x(), casArriv.y()).couleur()!=couleur) return true;
    else return false;
}
