#ifndef PION_H
#define PION_H

#include <QObject>

class Pion : public Piece
{
public:
    Pion();
    ~Pion();
    virtual Qimage d_i override


private:
    virtual bool PeutDeplacer(Plateau P, casDep, casArriv) override
    virtual const string d_nom=pion override;


};

#endif // PION_H
