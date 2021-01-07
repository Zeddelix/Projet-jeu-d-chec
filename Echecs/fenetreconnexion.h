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
    void misAJour();
protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    QWidget* d_parent;
    QLabel * d_label;
    chest::partie d_partie;
    void paintEvent(QPaintEvent *event) override;
    bool d_action;
};

#endif // FENETRECONNEXION_H
