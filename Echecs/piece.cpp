#include "piece.h"

namespace chest {


piece::piece(const bool couleur,QPixmap image,QString nom) :  d_nom{nom}, d_couleur{couleur}, d_image{image}
{}

piece::~piece()
{}

QString piece::nom() const
{
    return d_nom;
}

bool piece::couleur() const
{
    return d_couleur;
}

QPixmap piece::image() const
{
    return d_image;
}

QVector<QPoint> piece::tabDeplacementPossible (const std::vector<std::vector<std::unique_ptr<piece>>> &p, QPoint *casDep)
{

    int x = casDep->x();
    int y = casDep->y();
    QVector<QPoint> tabDeplacePossible;

    for(unsigned i = 0;i < p.size() ; i++)
    {
        for(unsigned j = 0; j < p[i].size();j++)
        {

            QPoint *arr{};
            arr->setX(x);
            arr->setY(y);

            if (p[x][y]->peutDeplacer(p,casDep,arr,d_couleur))
            {
                tabDeplacePossible.push_back(*arr);
            }
        }
    }

    return tabDeplacePossible;
}

}
