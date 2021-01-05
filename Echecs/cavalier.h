#ifndef CAVALIER_H
#define CAVALIER_H
#include "partie.h"
#include <QObject>
#include <QWidget>

namespace chest {

class cavalier : public piece
{
public:
    cavalier(bool couleur, QPixmap image, QString nom);
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override;

};


#endif // CAVALIER_H

}
