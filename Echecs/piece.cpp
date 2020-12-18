#include "piece.h"


namespace chest {



piece::piece(const bool couleur,QPixmap* image,const QString nom) : d_nom{nom}, d_couleur{couleur} ,  d_image{image}
{}

    piece::~piece() {}


    bool piece::couleur() const
    {
        return d_couleur;
    }

    QPixmap* piece::image() const
    {
        return d_image;
    }

    QString piece::nom() const
    {

        QString couleur;
        if(d_couleur == 0)
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

 QVector<QPoint> piece::tabDeplacementPossible(const plateau& P, QPoint casDep)
{

}
