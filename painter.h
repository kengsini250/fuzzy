#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include "fuzzymath.h"

class Painter : public QWidget
{
    Q_OBJECT
public:
    explicit Painter(QWidget *parent = nullptr);
    void setSizeAndPos(int x,int y,int w,int h);
    void getData(float a,float b,QVector<float>ab_s,QVector<float>ab_m,QVector<float>ab_l,QVector<float>all);

    void Draw(QPainterPath* p,QVector<float> t,QPainter*  draw);
protected:
    void paintEvent(QPaintEvent *);

private:
    int width,height;
    float a,b;
    QVector<float>ab_s,ab_m,ab_l,all;
    QPainterPath s,m,l,_all;
};

#endif // PAINTER_H
