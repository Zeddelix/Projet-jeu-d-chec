/**
cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 14)*/
#include <QCoreApplication>
#include "dame.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

       QPixmap lol;
   // chest::dame test{0,lol,"test"};
   //std::cout<<test.fou::nom().toStdString();
    return a.exec();
}
