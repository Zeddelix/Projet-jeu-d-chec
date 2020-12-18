#ifndef FOU_H
#define FOU_H

#include <QObject>

class Fou : public piece
{
public:
    Fou(bool couleur, QString image, QString nom);
    ~Fou();
    virtual bool peutDeplacer(const Plateau& P, QPoint depart, QPoint arrivee) override;


private:
    QPixmap* d_image;
    QString d_nom;


};


#endif // FOU_H
