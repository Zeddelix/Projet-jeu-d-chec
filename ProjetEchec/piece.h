#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "plateau.h"
#include "case.h"


namespace chest {

class Piece
{
public:
    Piece(const bool couleur, std::string image, std::string nom);
    virtual ~Piece();
    virtual bool PeutDeplacer(Plateau p,case dep, cas arr) = 0;
    std::string nom() const;
    bool couleur() const;
    std::string image() const;
private:
    std::string d_nom;
    bool d_couleur;
    std::string d_image;
};
#endif // PIECE_H


}
