#ifndef CAVALIER_H
#define CAVALIER_H

#include <QObject>

class Cavalier : public Piece
{
public:
<<<<<<< HEAD
    Cavalier(bool couleur, QString image, QString nom);
=======
    Cavalier(bool couleur, QString nom);
>>>>>>> Gaulthier
    ~Cavalier();
    virtual bool peutDeplacer(const Plateau& P, QPoint depart, QPoint arrivee) override;


private:
<<<<<<< HEAD
    QPixmap* d_image;
=======
    QString d_image;
>>>>>>> Gaulthier
    QString d_nom;


};


#endif // CAVALIER_H
