/**
cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 14)*/
//#include <QCoreApplication>
#include "affichage.h"
#include "QApplication"

int main(int argc, char *argv[])
{


    //QCoreApplication a(argc, argv);
    QApplication app(argc, argv);
    FenetreVide fenetre{};
    fenetre.show();

    return app.exec();
}
