#ifndef AFFICHAGEPARTIE_H
#define AFFICHAGEPARTIE_H

#include <QMainWindow>
#include <QPainter>

#include "partie.h"


class affichagePartie : public QMainWindow
{
    Q_OBJECT
public:
    affichagePartie(QWidget *parent=nullptr);
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

#endif
