#ifndef BALA_H
#define BALA_H
#include "Headers.h"
//+#include "bala.h"
#include <iostream>

#include <math.h>
#include<string>
#include <iterator>
using namespace std;
using namespace sf;

class bala
{
    public:
    Texture textura_bala;
    Sprite sprite_bala;
    Vector2f posicion;
    Vector2f direccion_bala;
    bool disponible;
    bala();
    bala(Texture textura_bala2, Sprite sprite_bala2,Vector2f pos);
    Sprite getspritebala();
    void setpos(Vector2f);
    void movebala(Vector2f direccion);
    void setvector(Vector2f direccion_bala2);
};

#endif 