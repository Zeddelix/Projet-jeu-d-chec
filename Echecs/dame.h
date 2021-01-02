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
    virtual bool peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override;
};


}

#endif // DAME_H
