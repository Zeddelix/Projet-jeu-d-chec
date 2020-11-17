#ifndef DAME_H
#define DAME_H

#include "piece.h"

namespace chest {

class dame : public Piece
{
    virtual ~dame();
    virtual bool PeutDeplacer(Plateau p,case dep, cas arr) override;
    virtual std::string nom() const override;
    virtual void Deplacer(case arr) override;
};


}

#endif // DAME_H
