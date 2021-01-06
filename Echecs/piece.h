#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QWidget>
#include <memory>
#include <QLabel>

namespace chest {

/** a suprimer*/
class piece
{
public:
    piece(const bool couleur,QPixmap image,QString nom);
    virtual ~piece();
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &p,const QPoint *dep, const QPoint *arr,const bool couleur) = 0;
    QString nom() const;
    bool couleur() const;
    QPixmap *image() const;
    QVector <QPoint> tabDeplacementPossible (const std::vector<std::vector<std::unique_ptr<piece>>> &p, QPoint *casDep);
    QLabel* d_picture;
private:
    QString d_nom;
    bool d_couleur;
    QPixmap d_image;
    bool premierDeplacement;

};
}

#endif // PIECE_H
