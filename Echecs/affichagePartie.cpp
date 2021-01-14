#include "affichagePartie.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QLabel>
#include <QGridLayout>
#include <QMouseEvent>
#include <QMessageBox>
#include <partie.h>
#include <cmath>

using namespace chest;

affichagePartie::affichagePartie(QWidget *parent):QMainWindow(),d_parent{parent},d_label{new QLabel(this)},d_action{false}, d_partie{chest::partie()}
{
    setMinimumSize(1920,1080);
    setPalette(Qt::darkBlue);
    QObject::connect(this,SIGNAL(Click()),this,SLOT(aClick()));


    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            d_label = new QLabel(this);
            if(d_partie.getPlateau()[j][i] != nullptr){
               d_label->setPixmap(d_partie.getPlateau()[j][i]->image());
                d_label->move(600+i*100, 100+j*100);
                d_label->resize(d_label->pixmap()->size());
                d_label->show();
            }
        }
    }

}

void affichagePartie::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);

    for(int j = 1 ; j <= 4; ++j)
    {
        for(int i = 1; i <= 4 ; ++i)
        {
            painter.fillRect(400+100*2*i,-100+100*2*j,100,100,Qt::white);
            painter.fillRect(500+100*2*i,100*2*j,100,100,Qt::white);
        }
    }

    for(int j = 1; j <= 4; ++j)
    {
        for(int i = 1;i <= 4; ++i)
        {
            painter.fillRect(500+100*2*i,-100+100*2*j,100,100,Qt::darkGray);
            painter.fillRect(400+100*2*i,100*2*j,100,100,Qt::darkGray);
        }
    }


}

void affichagePartie::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {


        QPoint cliqueActuel = event->pos();

        int YPtCourant = floor((cliqueActuel.x()-600)/100) ;
        int XPtCourant = floor((cliqueActuel.y()-100)/100) ;

        QPoint coupActuel {XPtCourant,YPtCourant};

        QPoint dernierCoup = d_partie.point();
        d_partie.setPoint(coupActuel);

        if(!d_action)
        {
            if(d_partie.selectionneSaPiece(d_partie.getPlateau(),&coupActuel, chest::partie().getJoueur()))
                d_action = true;
        }
        else
        {
            d_action = false;
            d_partie.deplacePiece(&dernierCoup,&coupActuel);
            d_partie.joueTour();
            misAJour();
        }

    }
}


void affichagePartie::misAJour()
{
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            d_label = new QLabel(this);
            if(d_partie.getPlateau()[j][i] != nullptr){
               d_label->setPixmap(d_partie.getPlateau()[j][i]->image());
                d_label->move(600+i*100, 100+j*100);
                d_label->resize(d_label->pixmap()->size());
                d_label->update();
                d_label->show();
            }
        }
    }
}

