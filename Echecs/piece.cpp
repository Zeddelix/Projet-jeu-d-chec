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

QVector<QPoint> piece::tabDeplacementPossible(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, QPoint *caseDepart)
{

    int x = caseDepart->x();
    int y = caseDepart->y();

    QVector<QPoint> tabDeplacePossible;

    for(unsigned i = 0; i < plateau.size() ; i++)
    {
        for(unsigned j = 0; j < plateau[i].size(); j++)
        {

            QPoint *caseArrive{};
            caseArrive->setX(x);
            caseArrive->setY(y);

            if (plateau[x][y]->peutDeplacer(plateau,caseDepart,caseArrive))
                tabDeplacePossible.push_back(*caseArrive);
        }
    }

    return tabDeplacePossible;
}

}
