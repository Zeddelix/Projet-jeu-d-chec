#ifndef PION_H
#define PION_H
#include <QString>
#include <QObject>
#include <QPoint>
#include "partie.h"

class Pion : public piece
{
public:
    Pion(bool couleur, QPixmap image, QString nom);
    virtual bool peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override;


};

#endif // PION_H
