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

//initialisation de la partie càd du plateau et des pièces
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

    //ajouter les types dès qu'ils seront ajouter au projet
    //auto d = std::make_unique<roi>(0,image,"tour1");
    //d_plateau[0][0] = std::make_unique<roi>(0,image,"tour1");

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

}


std::vector<std::vector<std::unique_ptr<chest::piece>>> & chest::partie::getPlateau()
{
    return d_plateau;
}




void chest::partie::deplacePiece(QPoint *caseDepart,QPoint *caseArrive,bool joueur)
{
    int arriveY = caseArrive->y();
    int arriveX = caseArrive->x() ;

    int departY = caseDepart->y();
    int departX = caseDepart->x();


    //std::swap( d_plateau[XArrive][YArrivee],d_plateau[XDepart][YDepart]);
    if(!estVide(d_plateau,QPoint{arriveX,arriveY},joueur))
    {
        QMessageBox msgBox;
        msgBox.setText("Case occupée.");
        msgBox.exec();

    }
    else
    {
        d_plateau[arriveX][arriveY] = move(d_plateau[departX][departX]);
        d_plateau[departX][departY].reset(nullptr);
        d_plateau[departX][departY] = nullptr;
    }
}




bool chest::partie::estVide(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint caseDepart, bool joueur) //verrifie que la piece appartient au joueur à qui c'est le tour
{
    return p[caseDepart.x()][caseDepart.y()]==nullptr;
}

bool chest::partie::pionCorrect(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint caseDepart, bool joueur)
{
    return p[caseDepart.x()][caseDepart.y()]->couleur() == joueur;
}

bool chest::partie::estUnAdversaire(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint caseDepart, bool joueur)
{
    return p[caseDepart.x()][caseDepart.y()]->couleur()!=joueur;
}

bool chest::partie::selectionneSaPiece(std::vector<std::vector<std::unique_ptr<chest::piece> > > &p, QPoint *point, bool joueur)
{
   if(estVide(p,*point,joueur))
   {
       QMessageBox msgBox;
       msgBox.setText("Case vide.");
       msgBox.exec();
       return false;
   }
   else
   {
        if(pionCorrect(p,*point,joueur) == false)
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

}

QPoint chest::partie::point() const
{
    return d_dernierPoint;
}
void chest::partie::setPoint(QPoint point)
{
    d_dernierPoint = point;
}

