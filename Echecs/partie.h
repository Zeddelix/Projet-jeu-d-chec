#ifndef PARTIE_H
#define PARTIE_H

#include <QVector>
#include <iostream>
#include "piece.h"
#include <vector>

class partie
{
public:
    partie();
    void afficher()const;
    void affichageCase(QPoint *c)const;//private ?
    void deplacePiece(QPoint *depart,QPoint *arrivee);

private:
    std::vector<std::vector<std::unique_ptr<piece>>> d_plateau;
    //d_plateau(std::unique_ptr<piece>);//QPointer est un pointeur interlligent
};

#endif // PARTIE_H
