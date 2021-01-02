#ifndef TOUR_H
#define TOUR_H

#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>
#include <QtWidgets/QWidget>
#include <partie.h>

namespace chest {

class tour : public piece
{

public:
    tour(bool couleur, QString image, QString nom);
    ~tour();
    virtual bool peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override;


private:
    QPixmap* d_image;
    QString d_nom;


};
#endif // TOUR_H

}

