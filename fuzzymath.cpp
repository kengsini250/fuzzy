#include "fuzzymath.h"

float x2D[fuzzySize] = {0.0f,0.1f,0.2f,0.3f,0.4f,0.5f,0.6f,0.7f,0.8f,0.9f,1.0f};

float BaseS[fuzzySize] =   {1.0f,0.8f,0.6f,0.4f,0.2f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
float BaseM[fuzzySize] =  {0.0f,0.2f,0.4f,0.6f,0.8f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
float BaseL[fuzzySize] =   {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.2f,0.4f,0.6f,0.8f,1.0f};

float max(float f1, float f2, float f3)
{
    if (f1 < f2) {
        if (f2 < f3) {
            return f3;
        }
        else {
            return f2;
        }
    }
    else {
        if (f1 < f3) {
            return f3;
        }
        else {
            return f1;
        }
    }
}
