#ifndef FENETRECONNEXION_H
#define FENETRECONNEXION_H

#include <QMainWindow>
#include <QPainter>

#include "partie.h"


class fenetreConnexion : public QMainWindow
{
    Q_OBJECT
public:
    fenetreConnexion(QWidget *parent=nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    QWidget* d_parent;
    chest::partie d_partie;
    void paintEvent(QPaintEvent *event);
};

#endif // FENETRECONNEXION_H
