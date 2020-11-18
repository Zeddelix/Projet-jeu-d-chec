#ifndef PION_H
#define PION_H
#include <QString>
#include <QObject>
#include <QPoint>

class Pion : public Piece
{
public:
    Pion(bool couleur, QString nom);
    ~Pion();
    virtual bool peutDeplacer(const Plateau& P, QPoint depart, QPoint arrivee) override;
    virtual QVector <QPoint> deplacementPossible (const Plateau& P, QPoint casDep);


private:
    QString d_image;
    QString d_nom;


};

#endif // PION_H
