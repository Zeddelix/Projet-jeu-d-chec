#include "cavalier.h"
#include <QString>
#include <QObject>
#include <QPoint>


namespace chest {

cavalier::cavalier(bool couleur, QPixmap image, QString nom) : piece{couleur,image,nom}
{}

bool cavalier::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrive)
{
    int pasX = caseDepart->x() - caseArrive->x();
    int pasY = caseDepart->y() - caseArrive->y();

    return (pasX == 1 && pasY == 2) || (pasX == 2 && pasY == 1);
}

}
