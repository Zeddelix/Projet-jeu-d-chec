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
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrive) override;
};


}
#endif // KING_H
