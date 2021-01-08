/**
cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 14)*/
#include <QCoreApplication>
#include <QApplication>
#include "dame.h"
#include "partie.h"
#include "QMessageBox"
#include "affichagePartie.h"

int main(int argc, char *argv[])
{
    QApplication n(argc, argv);
    affichagePartie f(nullptr);
    f.show();
    return n.exec();

}


