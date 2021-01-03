#include "fenetreconnexion.h"

fenetreConnexion::fenetreConnexion(QWidget *parent):QMainWindow(),d_parent{parent}
{
    setMinimumSize(1920,1080);
    setPalette(Qt::darkCyan);
}

void fenetreConnexion::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for(int j=1;j<=4;j=j+1)
    {
        for(int i=1;i<=4;i=i+1)
        {
            painter.fillRect(400+100*2*i,-100+100*2*j,100,100,Qt::black);
            painter.fillRect(500+100*2*i,100*2*j,100,100,Qt::black);
        }
    }
    for(int j=1;j<=4;j=j+1)
    {
        for(int i=1;i<=4;i=i+1)
        {
            painter.fillRect(500+100*2*i,-100+100*2*j,100,100,Qt::white);
            painter.fillRect(400+100*2*i,100*2*j,100,100,Qt::white);
        }
    }
}
