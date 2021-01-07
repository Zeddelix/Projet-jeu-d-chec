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
    void Jouer();
protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    QWidget* d_parent;
    QLabel * d_label;
    chest::partie d_partie;
    void paintEvent(QPaintEvent *event) override;
};

#endif // FENETRECONNEXION_H
