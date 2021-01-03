#include "partie.h"
#include <iostream>
/** a supprimer*/
#include "roi.h"
#include "tour.h"
#include "cavalier.h"
#include "fou.h"
#include "pion.h"
#include "QMessageBox"

//initialisation de la partie càd du plateau et des pièces
chest::partie::partie()
{
    QPixmap image; //a enlever
    //ajouter les types dès qu'ils seront ajouter au projet
    //auto d = std::make_unique<roi>(0,image,"tour1");
    //d_plateau[0][0] = std::make_unique<roi>(0,image,"tour1");

    d_plateau.resize(8);

    d_plateau[0].push_back(std::make_unique <tour>(0,image,"tour1"));
    d_plateau[0].push_back(std::make_unique <cavalier>(0,image,"cavalier1"));
    d_plateau[0].push_back(std::make_unique <fou>(0,image,"fou1"));
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"dame"));
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"roi"));
    d_plateau[0].push_back(std::make_unique <fou>(0,image,"fou2"));
    d_plateau[0].push_back(std::make_unique <cavalier>(0,image,"cavalier2"));
    d_plateau[0].push_back(std::make_unique <tour>(0,image,"tour2"));

    d_plateau[1].push_back(std::make_unique <pion>(0,image,"pion1"));
    d_plateau[1].push_back(std::make_unique <pion>(0,image,"pion2"));
    d_plateau[1].push_back(std::make_unique <pion>(0,image,"pion3"));
    d_plateau[1].push_back(std::make_unique <pion>(0,image,"pion4"));
    d_plateau[1].push_back(std::make_unique <pion>(0,image,"pion5"));
    d_plateau[1].push_back(std::make_unique <pion>(0,image,"pion6"));
    d_plateau[1].push_back(std::make_unique <pion>(0,image,"pion7"));
    d_plateau[1].push_back(std::make_unique <pion>(0,image,"pion8"));

    d_plateau[2].resize(8);
    d_plateau[3].resize(8);
    d_plateau[4].resize(8);
    d_plateau[5].resize(8);

    d_plateau[6].push_back(std::make_unique <pion>(1,image,"pion1"));
    d_plateau[6].push_back(std::make_unique <pion>(1,image,"pion2"));
    d_plateau[6].push_back(std::make_unique <pion>(1,image,"pion3"));
    d_plateau[6].push_back(std::make_unique <pion>(1,image,"pion4"));
    d_plateau[6].push_back(std::make_unique <pion>(1,image,"pion5"));
    d_plateau[6].push_back(std::make_unique <pion>(1,image,"pion6"));
    d_plateau[6].push_back(std::make_unique <pion>(1,image,"pion7"));
    d_plateau[6].push_back(std::make_unique <pion>(1,image,"pion8"));

    d_plateau[7].push_back(std::make_unique <tour>(1,image,"tour1"));
    d_plateau[7].push_back(std::make_unique <cavalier>(1,image,"cavalier1"));
    d_plateau[7].push_back(std::make_unique <fou>(1,image,"fou1"));
    d_plateau[7].push_back(std::make_unique <roi>(1,image,"dame"));
    d_plateau[7].push_back(std::make_unique <roi>(1,image,"roi"));
    d_plateau[7].push_back(std::make_unique <fou>(1,image,"fou2"));
    d_plateau[7].push_back(std::make_unique <cavalier>(1,image,"cavalier2"));
    d_plateau[7].push_back(std::make_unique <tour>(1,image,"tour2"));

}

void chest::partie::afficher()const
{
}

void chest::partie::affichageCase(QPoint *c)const
{}

void chest::partie::deplacePiece(std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint *depart,QPoint *arrivee,bool joueur)
{

}


bool chest::partie::estVide(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint depart, bool joueur) //verrifie que la piece appartient au joueur à qui c'est le tour
{
    if (p[depart.x()][depart.y()]==nullptr)//cas case vide
    {
        return true;
    }

    return false;

}

bool chest::partie::pionCorrect(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint depart, bool joueur)
{
    if(p[depart.x()][depart.y()]->couleur() != joueur)
    {
        return false;
    }
    else
        return true;

}

bool chest::partie::estUnAdversaire(const std::vector<std::vector<std::unique_ptr<chest::piece>>> &p,QPoint depart, bool joueur)
{
     if (p[depart.x()][depart.y()]->couleur()==joueur)//cas pion de son équipe
        {
         return false;
        }
        else    //cas pion adverse
        {
            return true;
        }
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


