#include "partie.h"

piece::piece(const bool couleur,QPixmap image,QString nom) :  d_nom{nom}, d_couleur{couleur}, d_image{image}
{}

piece::~piece()
{}

QString piece::nom() const
{}

bool piece::couleur() const
{}

QPixmap* piece::image() const
{}

QVector <QPoint> tabDeplacementPossible (const QVector<QVector<std::unique_ptr<piece>>> &p, QPoint *casDep)
{}
