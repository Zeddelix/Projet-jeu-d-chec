#ifndef FENETRECONNEXION_H
#define FENETRECONNEXION_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QMessageBox>
#include "partie.h"
//#include "joueur.h"

class fenetreConnexion : public QMainWindow
{
    Q_OBJECT
public:
    fenetreConnexion(QWidget *parent=nullptr);
    void affichage();
private:
    QWidget* d_parent;
    chest::partie* d_p;
    QLabel *joueurId;
    QLabel *joueurMdp;
    QMessageBox *Id;
    void paintEvent(QPaintEvent *event);
};

#endif // FENETRECONNEXION_H
