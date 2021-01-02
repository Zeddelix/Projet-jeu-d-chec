#ifndef FOU_H
#define FOU_H

#include <QString>
#include <QObject>
#include <QPoint>
#include <QVector>
#include <QtWidgets/QWidget>
#include <partie.h>

namespace chest {

class fou : public piece
{
public:
    fou(bool couleur, QString image, QString nom);
    virtual bool peutDeplacer(const QVector<QVector<unique_ptr<piece>>> &p, const QPoint *depart, const QPoint *arrivee, const bool couleur) override;


private:
    QPixmap* d_image;
    QString d_nom;


};
#endif // FOU_H

}
