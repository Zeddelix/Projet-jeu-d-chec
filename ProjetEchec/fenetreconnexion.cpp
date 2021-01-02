#include "fenetreconnexion.h"
#include <QDir>
#include <QInputDialog>
#include <QToolBar>
#include <QThread>
#include <QPen>
#include <QPainter>
class joueur
{

};

fenetreConnexion::fenetreConnexion(QWidget *parent):QMainWindow(),d_parent{parent}
{
    setMinimumSize(1920,1080);

/** QToolBar *toolBarFichier=addToolBar("qu'est ce que c'est que ça");
    joueurId=new QLabel("Identifiant");
    toolBarFichier->addWidget(joueurId);

    bool ok;
    QString j1=QInputDialog::getMultiLineText(this,tr("QInputDialog::getMultiLineText()"),tr("Pseudo"),"oui", &ok);
    QString j2=QInputDialog::getText(this,tr("Connection joueur1"),tr("Pseudo"),QLineEdit::Normal,QDir::home().dirName(), &ok);

    affichage();*/
    setPalette(Qt::darkCyan);
}
/**
void fenetreConnexion::affichage()
{
    QToolBar *toolBarFichier=addToolBar("qu'est ce que c'est que ça");
}
*/
void fenetreConnexion::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //QPen pen;
    //pen.setWidth(2);
    //pen.setColor(Qt::darkCyan);
    //painter.setPen(pen);

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
