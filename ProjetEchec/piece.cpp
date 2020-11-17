#include "piece.h"


namespace chest {



    Piece::Piece(const bool couleur, std::string image) : d_couleur{couleur} , d_image{image}
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

}
