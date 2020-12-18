#ifndef PION_H
#define PION_H
#include <QString>
#include <QObject>
#include <QPoint>
#include "partie.h"

class Pion : public piece
{
public:
    Pion(bool couleur, QPixmap image,  QString nom);
    ~Pion();
    virtual bool peutDeplacer(const partie& P, const QPoint depart, const QPoint arrivee, const bool couleur) override;


private:
    QPixmap* d_image;
    QString d_nom;



};

#endif // PION_H
