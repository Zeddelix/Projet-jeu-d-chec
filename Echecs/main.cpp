/**
cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 14)*/
#include <QCoreApplication>
#include <QApplication>
#include "dame.h"
#include "partie.h"
#include "QMessageBox"
#include "fenetreconnexion.h"

int main(int argc, char *argv[])
{
  // QCoreApplication a(argc, argv);
    QApplication n(argc, argv);
   // QPixmap lol;

    //test deplacePiece//
    std::vector<std::vector<std::unique_ptr<chest::piece>>> p;
    p.resize(8);
    p[0].push_back(nullptr);
    p[0].push_back(nullptr);
    QPoint p1{0,0};
    chest::partie game;
    game.estVide(p,p1,0);
    fenetreConnexion f(nullptr);
     //f.isFullScreen();
    f.show();
    //return a.exec();
    return n.exec();

}


