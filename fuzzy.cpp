#include "fuzzy.h"

Fuzzy::Fuzzy()
{

}

void Fuzzy::setValue(float a, float b)
{
    this->a =a;
    this->b = b;
    math();
}

float Fuzzy::getFuzzyValue()
{
    return fuzzyValue;
}

void Fuzzy::math()
{
    a_s.clear();
    a_m.clear();
    a_l.clear();
    b_s.clear();
    b_m.clear();
    b_l.clear();
    ab_s.clear();
    ab_m.clear();
    ab_l.clear();
    all.clear();
    float temp = 0;

    //A S
    temp = BaseS[(int)(a*10)];
    for(int i=0;i<fuzzySize;i++){
        if(BaseS[i] < temp){
            a_s.push_back(BaseS[i]) ;
        }else{
            a_s.push_back(temp);
        }
    }

    //A M
    temp = BaseM[(int)(a*10)];
    for(int i=0;i<fuzzySize;i++){
        if(BaseM[i] < temp){
            a_m.push_back(BaseM[i]) ;
        }else{
            a_m.push_back(temp);
        }
    }

    //A L
    temp = BaseL[(int)(a*10)];
    for(int i=0;i<fuzzySize;i++){
        if(BaseL[i] < temp){
            a_l.push_back(BaseL[i]) ;
        }else{
            a_l.push_back(temp);
        }
    }

    //B S
    temp = BaseS[(int)(a*10)];
    for(int i=0;i<fuzzySize;i++){
        if(BaseS[i] < temp){
            b_s.push_back(BaseS[i]) ;
        }else{
            b_s.push_back(temp);
        }
    }

    //B M
    temp = BaseM[(int)(a*10)];
    for(int i=0;i<fuzzySize;i++){
        if(BaseM[i] < temp){
            b_m.push_back(BaseM[i]) ;
        }else{
            b_m.push_back(temp);
        }
    }

    //B L
    temp = BaseL[(int)(a*10)];
    for(int i=0;i<fuzzySize;i++){
        if(BaseL[i] < temp){
            b_l.push_back(BaseL[i]) ;
        }else{
            b_l.push_back(temp);
        }
    }

    //AB S
    for(int i=0;i<fuzzySize;i++){
        if(a_s[i]<b_s[i]){
            ab_s.push_back(a_s[i]);
        }else{
            ab_s.push_back(b_s[i]);
        }
    }

    //AB M
    for(int i=0;i<fuzzySize;i++){
        if(a_m[i]<b_m[i]){
            ab_m.push_back(a_m[i]);
        }else{
            ab_m.push_back(b_m[i]);
        }
    }
    //AB L
    for(int i=0;i<fuzzySize;i++){
        if(a_l[i]<b_l[i]){
            ab_l.push_back(a_l[i]);
        }else{
            ab_l.push_back(b_l[i]);
        }
    }
    //ALL
    for(int i=0;i<fuzzySize;i++){
        all.push_back(max(ab_s[i],ab_m[i],ab_l[i]));
    }


    CenterGravity();
}

void Fuzzy::CenterGravity()
{
    float up=0,down=0;//   up/down
    for(int i=0;i<fuzzySize;i++){
        up+=all[i]*x2D[i];
        down+=all[i];
    }
    fuzzyValue = up/down;
}
