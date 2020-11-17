#ifndef CAVALIER_H
#define CAVALIER_H

#include <QObject>

class Cavalier : public Piece
{
public:
    Cavalier();
    ~Cavalier();
    virtual Qimage d_i override;


private:
    virtual bool PeutDeplacer(Plateau P, casDep, casArriv) override
    virtual const string d_nom=Cavalier override;


};

#endif // CAVALIER_H
