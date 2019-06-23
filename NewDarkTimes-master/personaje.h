#ifndef PERSONAJE_H
#define PERSONAJE_H
#include"Headers.h"
#include "personaje.h"
#include <iostream>

#include <math.h>
#include<string>
using namespace std;
using namespace sf;

class personaje
{
    public:
         Texture textura1;
         Sprite sprite1;
         Vector2i posicionmouse;
         Vector2i seguimiento;
         Vector2f p;
         Vector2f giro;
         int tam;
         float angl;
         double a, b;
         personaje();
         personaje(Texture textuta2, Sprite sprite2);
        Sprite getsprite();
        void setmouse(Vector2i mouse1);
        void setseguimeiento(Vector2i seguimiento1);
        void setmvep(Vector2f p1);
        void setgiro(Vector2f giro1);
        void setangulo(int &tam1, float &angulo, double &a1, double &b1);
        void obtener_mouse(RenderWindow &Window);
        void girarmouse();
        void setmovmou();


};

#endif 