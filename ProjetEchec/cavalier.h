#ifndef CAVALIER_H
#define CAVALIER_H

#include <QObject>

class Cavalier : public Piece
{
public:
    Cavalier(bool couleur, QString nom);
    ~Cavalier();
    virtual bool peutDeplacer(const Plateau& P, QPoint depart, QPoint arrivee) override;


private:
    QString d_image;
    QString d_nom;


};


#endif // CAVALIER_H
