#include "fenetreconnexion.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QLabel>
#include <QGridLayout>
#include <QMouseEvent>
#include <QMessageBox>

fenetreConnexion::fenetreConnexion(QWidget *parent):QMainWindow(),d_parent{parent}, d_partie{chest::partie()}
{
    setMinimumSize(1920,1080);
    setPalette(Qt::darkBlue);
    QObject::connect(this,SIGNAL(Click()),this,SLOT(aClick()));
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

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            QLabel *label = new QLabel(this);
            if(d_partie.getPlateau()[j][i] != nullptr){
                QPixmap piece = d_partie.getPlateau()[j][i]->image();
                label->setPixmap(piece);
                label->move(600+i*100, 100+j*100);
                label->resize(label->pixmap()->size());
                label->show();
            }
        }
    }

}

void fenetreConnexion::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPoint ptsCourant = event->pos();
        //setPoint(ptsCourant);
    }
}
