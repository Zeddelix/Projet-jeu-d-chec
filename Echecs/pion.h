#ifndef PION_H
#define PION_H
#include <QString>
#include <QObject>
#include <QPoint>
#include "partie.h"

namespace chest {

class pion : public piece
{
public:
    pion(bool couleur, QPixmap image, QString nom);
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrive) override;


};


}
#endif
