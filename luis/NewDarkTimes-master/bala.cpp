#include "Headers.h"
using namespace std;

bala::bala(){}

bala::bala(Texture textura_bala2, Sprite sprite_bala2,Vector2f posicion)
{
    
    textura_bala=textura_bala2;
    sprite_bala=sprite_bala2;
    textura_bala.loadFromFile("bala.png");
    sprite_bala.setTexture(textura_bala);
    sprite_bala.setOrigin(sprite_bala.getTexture()->getSize().x/2.f, sprite_bala.getTexture()->getSize().y/2.f);
    sprite_bala.setScale(((float)10/sprite_bala.getTexture()->getSize().x),((float)10/sprite_bala.getTexture()->getSize().y));
    sprite_bala.setPosition(posicion);
   // sprite_bal.setColor(Color::Black);
}

Sprite bala::getspritebala()
{
    return sprite_bala;
}

void bala::setpos(Vector2f nuevopos)
{
	posicion=nuevopos;
	sprite_bala.setPosition(posicion);
}

void bala::setvector(Vector2f direccion_bala2)
{
    direccion_bala=direccion_bala2;
}
void bala::movebala(Vector2f direccion)
{
	float velocidad=5.0f;//se asigan la vel
    float tamx=abs(direccion.x-sprite_bala.getPosition().x);
	float tamy=abs(sprite_bala.getPosition().y-direccion.y);
	float RAX,RAY;
	RAX=tamx/sqrt((pow(tamx,2)+pow(tamy,2))/pow(velocidad,2));
	RAY=tamy/sqrt((pow(tamx,2)+pow(tamy,2))/pow(velocidad,2));
/*
	RAX=tamx/100;
	RAY=tamy/100;*/
    if((direccion.x!=sprite_bala.getPosition().x)||(sprite_bala.getPosition().x==direccion.x))
	{
	            if(direccion.x>sprite_bala.getPosition().x)
				{
	            
	            //Vector2f p;
	            direccion_bala.x=sprite_bala.getPosition().x+RAX;
	            direccion_bala.y=sprite_bala.getPosition().y;
	            sprite_bala.setPosition((Vector2f)direccion_bala);
	            
	            }
	            if(direccion.x<sprite_bala.getPosition().x)
				{
	            
	            //Vector2f p;
	            direccion_bala.x=sprite_bala.getPosition().x-RAX;
	            direccion_bala.y=sprite_bala.getPosition().y;
	            sprite_bala.setPosition((Vector2f)direccion_bala);
	
	            }
	        }
	        if((direccion.y!=sprite_bala.getPosition().y)||(sprite_bala.getPosition().y==direccion.y))
			{
	            if(direccion.y>sprite_bala.getPosition().y)
				{
	            
	           // Vector2f p;
	            direccion_bala.x=sprite_bala.getPosition().x;
	            direccion_bala.y=sprite_bala.getPosition().y+RAY;
	            sprite_bala.setPosition((Vector2f)direccion_bala);
	            
	            }
	            if(direccion.y<sprite_bala.getPosition().y)
				{
	            
	            //Vector2f p;
	            direccion_bala.x=sprite_bala.getPosition().x;
	            direccion_bala.y=sprite_bala.getPosition().y-RAY;
	            sprite_bala.setPosition((Vector2f)direccion_bala);
            
                }	

            }

}