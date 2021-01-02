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
    virtual bool peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override;


private:
    QPixmap* d_image;
    QString d_nom;


};

}
#endif // FOU_H
