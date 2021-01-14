#ifndef FOU_H
#define FOU_H

#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>
#include <QtWidgets/QWidget>
#include "partie.h"

namespace chest {

class fou : public piece
{
public:
    fou(bool couleur, QPixmap image, QString nom);
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, const QPoint *caseDepart, const QPoint *caseArrive) override;
};

}
#endif
