#include "affichage.h"
#include "QPushButton"
#include "QPainter"
#include "QLabel"
#include "QLayout"
#include "QPainter"

FenetreVide::FenetreVide(QWidget *parent) : QWidget{parent}
{
    resize(200, 100); //taille
    setMinimumSize(1080,720); //taille minimum
    setMaximumSize(1920,1080); //taille maximum
    setWindowTitle("Chest Miage"); //titre


    QPainter painter(this); // construire
    painter.setBrush(Qt::black);; // personnaliser
    painter.drawRect(0,0, 160, 160 ); // dessiner



    //afficher une image
    /*
    QLabel  *label_img  = new QLabel(this);
    QPixmap *pixmap_img = new QPixmap("C:/Users/killian/Pictures/test.jpg");
    label_img->setPixmap(*pixmap_img);
    auto layout = new QGridLayout(this);
    layout->addWidget(label_img);
    setLayout(layout);
    */

    //affichage bouton
    //auto b = new QPushButton{"Jouer", this}; //ajout bouton
    //b->setGeometry(400, 300,200, 100);
    //setStyleSheet("background-color: black;");



}

