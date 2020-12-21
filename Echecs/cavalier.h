#ifndef CAVALIER_H
#define CAVALIER_H
#include "partie.h"
#include <QObject>
#include <QWidget>

class Cavalier : public piece
{
public:
    Cavalier(bool couleur, QPixmap image, QString nom);
    virtual bool peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override;

};


#endif // CAVALIER_H
