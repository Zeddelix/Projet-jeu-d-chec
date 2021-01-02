<<<<<<< Updated upstream:ProjetEchec/main.cpp
#include <QCoreApplication>
=======
/**
cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 14)*/
#include <QApplication>
#include "fenetreconnexion.h"

>>>>>>> Stashed changes:Echecs/main.cpp

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //quelle différence avec QCoreApplication ?
    fenetreConnexion f(nullptr);
    //f.isFullScreen();
    f.show();
    return a.exec();
}
