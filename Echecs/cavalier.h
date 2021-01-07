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
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrivee) override;

};


#endif // CAVALIER_H

}
