/**
cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 14)
*/

#include <QCoreApplication>

#include <memory>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    return a.exec();


   auto p = std::make_unique<int>(5);

}
