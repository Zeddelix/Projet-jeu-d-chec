#include "partie.h"
#include <iostream>
#include "roi.h"
#include "tour.h"
#include "cavalier.h"
#include "fou.h"
#include "pion.h"
#include "QPixmap"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QLabel>
#include <cmath>

//initialisation de la partie; du plateau et des pièces
chest::partie::partie()
{
    QString path = "../Echecs/Images_pieces/"; // Chemin relatif en partant du dossier Build
    QString colorName = "Noir";
    QPixmap pionImage = QPixmap(path + "Pion" + colorName +".png");
    QPixmap tourImage = QPixmap(path + "Tour" + colorName +".png");
    QPixmap cavalierImage = QPixmap(path + "Cavalier" + colorName +".png");
    QPixmap fouImage = QPixmap(path + "Fou" + colorName +".png");
    QPixmap roiImage = QPixmap(path + "Roi" + colorName +".png");
    QPixmap dameImage = QPixmap(path + "Dame" + colorName +".png");

    d_plateau.resize(8);

    d_plateau[0].push_back(std::make_unique <tour>(0, tourImage,"tour1"));
    d_plateau[0].push_back(std::make_unique <cavalier>(0,cavalierImage,"cavalier1"));
    d_plateau[0].push_back(std::make_unique <fou>(0,fouImage,"fou1"));
    d_plateau[0].push_back(std::make_unique <roi>(0,dameImage,"dame"));
    d_plateau[0].push_back(std::make_unique <roi>(0,roiImage,"roi"));
    d_plateau[0].push_back(std::make_unique <fou>(0,fouImage,"fou2"));
    d_plateau[0].push_back(std::make_unique <cavalier>(0,cavalierImage,"cavalier2"));
    d_plateau[0].push_back(std::make_unique <tour>(0,tourImage,"tour2"));

    d_plateau[1].push_back(std::make_unique <pion>(0,pionImage,"pion1"));
    d_plateau[1].push_back(std::make_unique <pion>(0,pionImage,"pion2"));
    d_plateau[1].push_back(std::make_unique <pion>(0,pionImage,"pion3"));
    d_plateau[1].push_back(std::make_unique <pion>(0,pionImage,"pion4"));
    d_plateau[1].push_back(std::make_unique <pion>(0,pionImage,"pion5"));
    d_plateau[1].push_back(std::make_unique <pion>(0,pionImage,"pion6"));
    d_plateau[1].push_back(std::make_unique <pion>(0,pionImage,"pion7"));
    d_plateau[1].push_back(std::make_unique <pion>(0,pionImage,"pion8"));

    d_plateau[2].resize(8);
    d_plateau[3].resize(8);
    d_plateau[4].resize(8);
    d_plateau[5].resize(8);

    colorName = "Blanc";
    pionImage = QPixmap(path + "Pion" + colorName +".png");
    tourImage = QPixmap(path + "Tour" + colorName +".png");
    cavalierImage = QPixmap(path + "Cavalier" + colorName +".png");
    fouImage = QPixmap(path + "Fou" + colorName +".png");
    roiImage = QPixmap(path + "Roi" + colorName +".png");
    dameImage = QPixmap(path + "Dame" + colorName +".png");

    d_plateau[6].push_back(std::make_unique <pion>(1,pionImage,"pion1"));
    d_plateau[6].push_back(std::make_unique <pion>(1,pionImage,"pion2"));
    d_plateau[6].push_back(std::make_unique <pion>(1,pionImage,"pion3"));
    d_plateau[6].push_back(std::make_unique <pion>(1,pionImage,"pion4"));
    d_plateau[6].push_back(std::make_unique <pion>(1,pionImage,"pion5"));
    d_plateau[6].push_back(std::make_unique <pion>(1,pionImage,"pion6"));
    d_plateau[6].push_back(std::make_unique <pion>(1,pionImage,"pion7"));
    d_plateau[6].push_back(std::make_unique <pion>(1,pionImage,"pion8"));

    d_plateau[7].push_back(std::make_unique <tour>(1,tourImage,"tour1"));
    d_plateau[7].push_back(std::make_unique <cavalier>(1,cavalierImage,"cavalier1"));
    d_plateau[7].push_back(std::make_unique <fou>(1,fouImage,"fou1"));
    d_plateau[7].push_back(std::make_unique <roi>(1,dameImage,"dame"));
    d_plateau[7].push_back(std::make_unique <roi>(1,roiImage,"roi"));
    d_plateau[7].push_back(std::make_unique <fou>(1,fouImage,"fou2"));
    d_plateau[7].push_back(std::make_unique <cavalier>(1,cavalierImage,"cavalier2"));
    d_plateau[7].push_back(std::make_unique <tour>(1,tourImage,"tour2"));

    d_actuelJoueur = 1;

}


std::vector<std::vector<std::unique_ptr<chest::piece>>> & chest::partie::getPlateau()
{
    return d_plateau;
}




void chest::partie::deplacePiece(QPoint *caseDepart,QPoint *caseArrive)
{
    int arriveY = caseArrive->y();
    int arriveX = caseArrive->x() ;

    int departY = caseDepart->y();
    int departX = caseDepart->x();


    if(!estVide(d_plateau,QPoint{arriveX,arriveY}))
    {
        QMessageBox msgBox;
        msgBox.setText("Case occupée.");
        msgBox.exec();

    }
    else
    {
        d_plateau[arriveX][arriveY] = move(d_plateau[departX][departY]);
        d_plateau[departX][departY].reset(nullptr);
        d_plateau[departX][departY] = nullptr;
    }
}

bool chest::partie::getJoueur() const
{
    return d_actuelJoueur;
}


bool chest::partie::estVide(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,const QPoint caseCible) const
{
    return p[caseCible.x()][caseCible.y()]==nullptr;
}

bool chest::partie::pionCorrect(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,const QPoint caseDepart, const bool joueur) const
{
    return p[caseDepart.x()][caseDepart.y()]->couleur() == joueur;
}

bool chest::partie::estUnAdversaire(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,const QPoint caseDepart, const bool joueur) const
{
    return p[caseDepart.x()][caseDepart.y()]->couleur()!=joueur;
}

bool chest::partie::selectionneSaPiece(std::vector<std::vector<std::unique_ptr<chest::piece> > > &p, const QPoint *point, const bool joueur) const
{
   if(estVide(p,*point))
   {
       QMessageBox msgBox;
       msgBox.setText("Case vide.");
       msgBox.exec();
       return false;
   }
   else
   {
        if(!pionCorrect(p,*point,joueur))
        {
            return true;
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Ce n'est votre pion.");
            msgBox.exec();
            return false;
        }
   }
}


void chest::partie::joueTour()
{
    d_actuelJoueur = !d_actuelJoueur;
}

QPoint chest::partie::point() const
{
    return d_dernierPoint;
}
void chest::partie::setPoint(QPoint point)
{
    d_dernierPoint = point;
}

