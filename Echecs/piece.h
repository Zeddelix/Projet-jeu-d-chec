#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QWidget>
#include <memory>

namespace chest {

class piece
{
public:
    piece(const bool couleur,QPixmap image,QString nom);
    virtual ~piece();
    virtual bool peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &plateau,const QPoint *caseDepart, const QPoint *caseArrive) = 0;
    QString nom() const;
    bool couleur() const;
    QPixmap image() const;
    QVector <QPoint> tabDeplacementPossible (const std::vector<std::vector<std::unique_ptr<piece>>> &plateau, QPoint *caseDepart);
private:
    QString d_nom;
    bool d_couleur;
    QPixmap d_image;
    bool premierDeplacement;

};
}

#endif
