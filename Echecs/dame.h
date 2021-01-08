#ifndef DAME_H
#define DAME_H

#include "piece.h"
#include "fou.h"
#include "tour.h"

namespace chest {

class dame : public tour, public fou
{
public:
    dame(bool couleur, QPixmap image, QString nom);
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrive) override;
};


}

#endif
