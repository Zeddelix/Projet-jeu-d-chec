#ifndef PARTIE_H
#define PARTIE_H

#include <QVector>
#include <QLabel>
#include <iostream>
#include "piece.h"
#include <vector>

namespace chest {

class partie
{
public:
    partie();
    std::vector<std::vector<std::unique_ptr<chest::piece>>>&getPlateau();
    void deplacePiece(QPoint *caseDepart,QPoint *caseArrive);
    bool estVide(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &plateau,const QPoint caseCible) const;
    bool pionCorrect(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &plateau,const QPoint caseDepart,const bool joueur) const;
    bool estUnAdversaire(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &plateau,const QPoint caseDepart,const bool joueur) const;
    bool selectionneSaPiece(std::vector<std::vector<std::unique_ptr<chest::piece>>> &plateau,const QPoint *pts,const bool joueur) const;
    void joueTour();
    QPoint point() const;
    bool getJoueur() const;
    void setPoint(QPoint point);
    QPoint d_dernierPoint;
private:
    bool d_actuelJoueur = 1;
    std::vector<std::vector<std::unique_ptr<piece>>> d_plateau;
friend class fenetreconnexion;


};


}
#endif
