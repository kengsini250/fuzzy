#ifndef FUZZY_H
#define FUZZY_H

#include "fuzzymath.h"
#include <QVector>

class Fuzzy
{
public:
    Fuzzy();
    void setValue(float a,float b);
    float getFuzzyValue();
    QVector<float> getSmall(){
        return ab_s;
    }
    QVector<float> getMid(){
        return ab_m;
    }
    QVector<float> getLarge(){
        return ab_l;
    }
    QVector<float> getAll(){
        return all;
    }

private:
    float a,b;
    float fuzzyValue = -1;
    QVector<float>a_s,a_m,a_l,b_s,b_m,b_l;
    QVector<float>ab_s,ab_m,ab_l,all;

    void math();
    void CenterGravity();
};

#endif // FUZZY_H
