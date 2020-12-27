#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "QObject"
#include "QWidget"

class FenetreVide : public QWidget {
Q_OBJECT
public:
FenetreVide(QWidget *parent = nullptr);
};


#endif // AFFICHAGE_H
