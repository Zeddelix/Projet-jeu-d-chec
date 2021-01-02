#ifndef PARTIE_H
#define PARTIE_H

#include <QVector>
#include <iostream>
#include "piece.h"
#include <vector>

namespace chest {

class partie
{
public:
    partie();
    void afficher()const;
    void affichageCase(QPoint *c)const;//private ?
    void deplacePiece(std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint *depart,QPoint *arrivee,bool joueur);
    bool estVide(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint depart, bool joueur);
    bool pionCorrect(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint depart, bool joueur);
    bool estUnAdversaire(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint depart, bool joueur);
    bool selectionneSaPiece(std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint *depart,QPoint *arrivee,bool joueur);
private:
    std::vector<std::vector<std::unique_ptr<piece>>> d_plateau;
    //d_plateau(std::unique_ptr<piece>);//QPointer est un pointeur interlligent
};


}
#endif // PARTIE_H
