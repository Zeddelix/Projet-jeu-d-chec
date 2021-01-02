#ifndef KING_H
#define KING_H

#include <QObject>
#include <QWidget>

#include "partie.h"

namespace chest {

class roi : public piece
{
public:
    roi(const bool couleur, QPixmap image,const QString nom);
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override;
};


}
#endif // KING_H
