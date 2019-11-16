#include "painter.h"
#include <QDebug>

Painter::Painter(QWidget *parent) : QWidget(parent)
{

}

void Painter::setSizeAndPos(int x, int y, int w, int h)
{
    this->setGeometry(x,y,w,h);
    width=w;
    height=h;
}

void Painter::getData(float a, float b,QVector<float>ab_s,QVector<float>ab_m,QVector<float>ab_l,QVector<float>all)
{
    this->a = a;
    this->b = b;
    this->ab_s = ab_s;
    this->ab_m = ab_m;
    this->ab_l = ab_l;
    this->all = all;

    qDebug()<<this->ab_s;
    qDebug()<<this->ab_m;
    qDebug()<<this->ab_l;
    qDebug()<<this->all;
}

void Painter::Draw(QPainterPath* p,QVector<float> t,QPainter* draw)
{
    p->clear();
    int len = t.size();
    for(int i=0;i<len;i++){
        p->lineTo(x2D[i]*width,t[i]*height);
    }

    if(p->elementCount() != 0){
        if(t.last()>0){
            p->lineTo(width,0);
        }
        draw->drawPath(*p);
        qDebug()<<*p;
    }
}

void Painter::paintEvent(QPaintEvent *)
{
    QPainter clear(this);
    clear.translate(0,height-1);
    clear.scale(1,-1);
    clear.setBrush(QBrush(QColor(255,255,255)));
    clear.drawRect(0,0,width,height);

    QPainter p(this);
    p.translate(0,height-1);
    p.scale(1,-1);
    p.setBrush(QBrush(QColor(0,0,0)));
    p.drawLine(0,0,width,0);
    p.drawLine(0,0,0,height);
    p.drawLine(0,height,x2D[5]*width,0);
    p.drawLine(x2D[5]*width,0,width,height);
    p.drawLine(0,0,x2D[5]*width,height);
    p.drawLine(x2D[5]*width,height,width,0);

    QPainter pS(this);
    pS.translate(-1,height);
    pS.scale(1,-1);
    pS.setBrush(QColor(0,255,255,128));
    Draw(&s,ab_s,&pS);

    QPainter pM(this);
    pM.translate(-1,height);
    pM.scale(1,-1);
    pM.setBrush(QColor(255,0,255,128));
    Draw(&m,ab_m,&pM);

    QPainter pL(this);
    pL.translate(-1,height);
    pL.scale(1,-1);
    pL.setBrush(QColor(255,255,0,128));
    Draw(&l,ab_l,&pL);

    //    QPainter pAll(this);
    //    pAll.translate(-1,height);
    //    pAll.scale(1,-1);
    //    pAll.setBrush(QColor(128,128,128,128));
    //    Draw(&_all,all,&pAll);
}
