#include "partie.h"
#include <iostream>
#include <memory>

/** a supprimer*/
#include "roi.h"

partie::partie()
{
    QPixmap image; //a enlever
    //ajouter les types dès qu'ils seront ajouter au projet

    d_plateau.resize(8);
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"tour1"));
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"cavalier1"));
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"fou1"));
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"dame"));
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"roi"));
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"fou2"));
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"cavalier2"));
    d_plateau[0].push_back(std::make_unique <roi>(0,image,"tour2"));

    d_plateau[1].push_back(std::make_unique <roi>(0,image,"pion1"));
    d_plateau[1].push_back(std::make_unique <roi>(0,image,"pion2"));
    d_plateau[1].push_back(std::make_unique <roi>(0,image,"pion3"));
    d_plateau[1].push_back(std::make_unique <roi>(0,image,"pion4"));
    d_plateau[1].push_back(std::make_unique <roi>(0,image,"pion5"));
    d_plateau[1].push_back(std::make_unique <roi>(0,image,"pion6"));
    d_plateau[1].push_back(std::make_unique <roi>(0,image,"pion7"));
    d_plateau[1].push_back(std::make_unique <roi>(0,image,"pion8"));

    d_plateau[2].resize(8);
    d_plateau[3].resize(8);
    d_plateau[4].resize(8);
    d_plateau[5].resize(8);

    d_plateau[6].push_back(std::make_unique <roi>(1,image,"pion1"));
    d_plateau[6].push_back(std::make_unique <roi>(1,image,"pion2"));
    d_plateau[6].push_back(std::make_unique <roi>(1,image,"pion3"));
    d_plateau[6].push_back(std::make_unique <roi>(1,image,"pion4"));
    d_plateau[6].push_back(std::make_unique <roi>(1,image,"pion5"));
    d_plateau[6].push_back(std::make_unique <roi>(1,image,"pion6"));
    d_plateau[6].push_back(std::make_unique <roi>(1,image,"pion7"));
    d_plateau[6].push_back(std::make_unique <roi>(1,image,"pion8"));

    d_plateau[7].push_back(std::make_unique <roi>(1,image,"tour1"));
    d_plateau[7].push_back(std::make_unique <roi>(1,image,"cavalier1"));
    d_plateau[7].push_back(std::make_unique <roi>(1,image,"fou1"));
    d_plateau[7].push_back(std::make_unique <roi>(1,image,"dame"));
    d_plateau[7].push_back(std::make_unique <roi>(1,image,"roi"));
    d_plateau[7].push_back(std::make_unique <roi>(1,image,"fou2"));
    d_plateau[7].push_back(std::make_unique <roi>(1,image,"cavalier2"));
    d_plateau[7].push_back(std::make_unique <roi>(1,image,"tour2"));
}

void partie::afficher()const
{}

void partie::affichageCase(QPoint c)const
{}

void partie::deplacePiece(QPoint depart,QPoint arrivee)
{
    d_plateau[arrivee.x()][arrivee.y()]=move(d_plateau[depart.x()][depart.y()]);
    affichageCase(depart);
    affichageCase(arrivee);
}
