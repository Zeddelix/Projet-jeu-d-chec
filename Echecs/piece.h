#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "plateau.h"
#include "case.h"
#include <QObject>
#include <QString>


namespace chest {

class piece
{
public:
    piece(const bool couleur,QPixmap* image,const QString nom);
    virtual ~piece();
    virtual bool PeutDeplacer(Plateau p,case dep, cas arr) = 0;
    QString nom() const;
    bool couleur() const;
    QPixmap *image() const;
    QVector <QPoint> tabDeplacementPossible (const plateau& P, QPoint casDep);
private:
    QString d_nom;
    bool d_couleur;
    QPixmap *d_image;
    bool premierDeplacement;
};
#endif // PIECE_H


}
