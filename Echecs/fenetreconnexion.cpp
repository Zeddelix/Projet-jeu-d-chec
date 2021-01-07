#include "fenetreconnexion.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QLabel>
#include <QGridLayout>
#include <QMouseEvent>
#include <QMessageBox>
#include <partie.h>
#include <cmath>

using namespace chest;

fenetreConnexion::fenetreConnexion(QWidget *parent):QMainWindow(),d_parent{parent},d_label{new QLabel(this)},d_action{false}, d_partie{chest::partie()}
{
    setMinimumSize(1920,1080);
    setPalette(Qt::darkBlue);
    QObject::connect(this,SIGNAL(Click()),this,SLOT(aClick()));


    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            //QLabel *label = new QLabel(this);
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

void fenetreConnexion::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);

    for(int j=1;j<=4;++j)
    {
        for(int i=1;i<=4;++i)
        {
            painter.fillRect(400+100*2*i,-100+100*2*j,100,100,Qt::white);
            painter.fillRect(500+100*2*i,100*2*j,100,100,Qt::white);
        }
    }

    for(int j=1;j<=4;++j)
    {
        for(int i=1;i<=4;++i)
        {
            painter.fillRect(500+100*2*i,-100+100*2*j,100,100,Qt::darkGray);
            painter.fillRect(400+100*2*i,100*2*j,100,100,Qt::darkGray);
        }
    }


}

void fenetreConnexion::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {


        QPoint ptsCourant = event->pos();
       // std::cout << ptsCourant.y()<< std::endl << ptsCourant.x() << std::endl; // Affiche les coordonnées dans la console

        int YPtCourant = floor((ptsCourant.x()-600)/100) ;
        int XPtCourant = floor((ptsCourant.y()-100)/100) ;

        std::cout << YPtCourant << std::endl << XPtCourant << std::endl;

        QPoint ptCourant {XPtCourant,YPtCourant};

        QPoint ancien = d_partie.point();
        d_partie.setPoint(ptCourant);
        QPoint pointCourant = d_partie.point();

        if(d_action == false)
        {
            if(d_partie.selectionneSaPiece(d_partie.getPlateau(),&pointCourant,1))
            {
                d_action = true;
            }
        }
        else
        {
            d_action = false;
            d_partie.deplacePiece(&ancien,&pointCourant,1);
            misAJour();
        }

    }
}


void fenetreConnexion::misAJour()
{
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            //QLabel *label = new QLabel(this);
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

