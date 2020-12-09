#ifndef PARTIE_H
#define PARTIE_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include <iostream>
#include <memory>
#include "piece.h"
#include <vector>
/** a suprimer*/
class piece
{
public:
    piece(const bool couleur,QPixmap image,QString nom);
    virtual ~piece();
    virtual bool peutDeplacer(const QVector<QVector<std::unique_ptr<piece>>> &p,const QPoint *dep, const QPoint *arr,const bool couleur) = 0;
    QString nom() const;
    bool couleur() const;
    QPixmap *image() const;
    QVector <QPoint> tabDeplacementPossible (const QVector<QVector<std::unique_ptr<piece>>> &p, QPoint *casDep);
private:
    QString d_nom;
    bool d_couleur;
    QPixmap d_image;
    bool premierDeplacement;
};

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
