#ifndef TOUR_H
#define TOUR_H

#include <QObject>

class Tour : public piece
{
public:
    Tour(bool couleur, QString image, QString nom);
    ~Tour();
    virtual bool peutDeplacer(const Plateau& P, QPoint depart, QPoint arrivee) override;


private:
    QPixmap* d_image;
    QString d_nom;


};


#endif // TOUR_H
