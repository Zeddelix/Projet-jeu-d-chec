#include "piece.h"


namespace chest {



Piece::Piece(const bool couleur, std::string image,std::string nom) : d_nom{nom}, d_couleur{couleur} ,  d_image{image}
    {}

    Piece::~Piece() {}


    bool Piece::couleur() const
    {
        return d_couleur;
    }

    std::string Piece::image() const
    {
        return d_image;
    }

    std::string Piece::nom() const
    {

        std::string couleur;
        if(d_couleur)
        {
            couleur = "blanc";
        }
        else
        {
            couleur = "noir";
        }

        return d_nom + couleur;
    }

}
