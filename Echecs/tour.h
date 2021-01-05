#ifndef TOUR_H
#define TOUR_H

#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>
#include <QWidget>
#include <partie.h>

namespace chest {

class tour : public piece
{

public:
    tour(bool couleur, QPixmap image, QString nom);
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override;
};

}
#endif // TOUR_H


