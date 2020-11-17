#ifndef PIECE_H
#define PIECE_H

#include <string>

namespace Ui { class Piece; }

class Piece
{
public:
    Piece();
    virtual ~Piece();
    virtual bool PeutDeplacer(Plateau p,case dep, cas arr) = 0;
    virtual std::string nom() const;
    virtual void Deplacer(case arr) = 0;
private:
    bool d_couleur;
    std::string d_image;
};
#endif // PIECE_H
