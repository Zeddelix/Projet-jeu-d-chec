#ifndef PIECE_H
#define PIECE_H

#include <QMainWindow>
#include "case.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Piece; }
QT_END_NAMESPACE

class Piece : public QMainWindow
{
    Q_OBJECT

public:
    Piece(QWidget *parent = nullptr);
    virtual ~Piece();
    virtual bool PeutDeplacer(Plateau p,case dep, cas arr) = 0;
    virtual QString nom() const;
    virtual void Deplacer(case arr) = 0;
private:
    bool d_couleur;
    QPixmap d_image;
};
#endif // PIECE_H
