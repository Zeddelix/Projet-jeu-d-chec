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

//initialisation de la partie càd du plateau et des pièces
chest::partie::partie()
{
    QString path = "../Echecs/Images_pieces/"; // Chemin relatif en partant du dossier Build
    bool color = 0;
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

void chest::partie::afficher(QLabel *label)const
{
    afficherCase(1, 1, label);

    /*for(int j = 0; j < 8; ++j){
        for(int i = 0; i < 8; ++i){
            if(d_plateau[i][j] != nullptr){

                qDebug() << 600+i*100 << 100+j*100 << " est " << d_plateau[i][j]->nom();
                QPixmap piece = d_plateau[i][j]->image();
                label->setPixmap(piece);
                label->move(600+i*100, 100+j*100);
                label->resize(label->pixmap()->size());
                label->show();
            }
            else
                qDebug() << i << j << " est vide.";
        }
    }*/
}

void chest::partie::afficherCase(int i, int j, QLabel *label)const
{
    QPixmap piece = d_plateau[i][j]->image();
    label->setPixmap(piece);
    label->move(600+i*100, 100+j*100);
    //label->resize(label->pixmap()->size());

    label->show();

}

void chest::partie::affichageCase(QPoint *c)const
{}

std::vector<std::vector<std::unique_ptr<chest::piece>>> & chest::partie::getPlateau()
{
    return d_plateau;
}




void chest::partie::deplacePiece(std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint *depart,QPoint *arrivee,bool joueur)
{

}




bool chest::partie::estVide(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint depart, bool joueur) //verrifie que la piece appartient au joueur à qui c'est le tour
{
return p[depart.x()][depart.y()]==nullptr;
}

bool chest::partie::pionCorrect(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint depart, bool joueur)
{
    return p[depart.x()][depart.y()]->couleur() == joueur;
}

bool chest::partie::estUnAdversaire(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint depart, bool joueur)
{
    return p[depart.x()][depart.y()]->couleur()!=joueur;
}

bool chest::partie::selectionneSaPiece(std::vector<std::vector<std::unique_ptr<chest::piece> > > &p, QPoint *depart, QPoint *arrivee, bool joueur)
{
   if(estVide(p,*depart,joueur))
   {
       QMessageBox msgBox;
       msgBox.setText("Case vide.");
       msgBox.exec();
       return false;
   }
   else
   {
        if(pionCorrect(p,*depart,joueur) == false)
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

QPoint chest::partie::point() const
{
    return d_dernierPoint;
}
void chest::partie::setPoint(QPoint point)
{
    d_dernierPoint = point;
}

