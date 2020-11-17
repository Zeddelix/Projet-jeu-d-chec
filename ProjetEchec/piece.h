#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "plateau.h"
#include "case.h"


namespace chest {

class Piece
{
public:
    Piece(const bool couleur, std::string image);
    virtual ~Piece();
    virtual bool PeutDeplacer(Plateau p,case dep, cas arr) = 0;
    virtual std::string nom() const = 0;
    virtual void Deplacer(case arr) = 0;
    bool couleur() const;
    std::string image() const;
private:
    bool d_couleur;
    std::string d_image;
};
#endif // PIECE_H


}
