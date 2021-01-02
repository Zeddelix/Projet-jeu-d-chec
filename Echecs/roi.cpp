#include "roi.h"

namespace chest {

roi::roi(const bool couleur,QPixmap image, const QString nom) : piece{couleur,image,nom}
{}


//precondition: arrivee et depart sont sur le plateau (arrivee tombe à l'eau)
bool roi::peutDeplacer(const std::vector<std::vector<std::unique_ptr<piece>>> &P, const QPoint *depart,const QPoint *arrivee,const bool couleur)//ici P est inutile
{
    bool deplacement=0;
    int xD=depart->x();
    int yD=depart->y();
    int xA=arrivee->y();
    int yA=arrivee->y();

    if(xA==xD && (yA==yD+1 || yA==yD-1))
    {
        deplacement=1;
    }
    else if (xA==xD-1 && (yA==yD+1 || yA==yD || yA==yD-1))
    {
        deplacement=1;
    }
    else if (xA==xD+1 && (yA==yD+1 || yA==yD || yA==yD-1))
    {
        deplacement=1;
    } 
    return deplacement;
}

//interdit de mettre son roi en echec
//interdit d
//bool prendreUnPion//est ce que toutes les pieces peuvent prendre les pieces uniquement sur leur case d'arrivee
//bool Echec//menacé de capture
//EtMat//la menace est imparable (on peut tenter de parer la menace en déplaçant le roi, en interposant une pièce ou en capturant la pièce attaquante)
//le roque, qui permet le déplacement simultané du roi et de l'une des tours
//la prise en passant, qui permet une capture particulière des pions 
//(sauf roi) la promotion des pions, qui permet de les transformer en une pièce maîtresse de son choix (sauf le roi) lorsqu'ils atteignent la dernière rangée de l'échiquier

}
