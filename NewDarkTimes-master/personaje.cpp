#include"Headers.h"
using namespace std;

personaje::personaje(){}
personaje::personaje(Texture textuta2, Sprite sprite2)
{
	textura1=textuta2;
	sprite1=sprite2;
	//textura1= new Texture;
    textura1.loadFromFile("prueba.jpg");
    //sprite1= new Sprite(*textura1);
	sprite1.move(400,400);
    //sprite2->move(400,400);
    seguimiento.x=400;
    seguimiento.y=400;
    sprite1.setOrigin(sprite1.getTexture()->getSize().x/2.f, sprite1.getTexture()->getSize().y/2.f);//pbtengo la posicion en el medio del sprite
       // sprite2->setOrigin(sprite2->getTexture()->getSize().x/2.f, sprite2->getTexture()->getSize().y/2.f);
        //2.f=2.0, ya que son decimales.
        //sprite1->setColor(Color::Blue);
       // sprite2->setScale(((float)ventana1->getSize().x/sprite2->getTexture()->getSize().x),((float)ventana1->getSize().y/sprite2->getTexture()->getSize().y));
    sprite1.setScale(((float)100/sprite1.getTexture()->getSize().x),((float)100/sprite1.getTexture()->getSize().y));
}

Sprite personaje::getsprite()
{
    return sprite1;
}
void personaje::setmouse(Vector2i mouse1)
{
	posicionmouse=mouse1;
}

void personaje::setseguimeiento(Vector2i seguimiento1)
{
	seguimiento=seguimiento1;
}

void personaje::setmvep(Vector2f p1)
{
	p=p1;
}

void personaje::setgiro(Vector2f giro1)
{
	giro=giro1;
}

void personaje::setangulo(int &tam1, float &angulo, double &a1, double &b1)
{
	tam=tam1;
	angl=angulo;
	a=a1;
	b=b1;
}
void personaje::obtener_mouse(RenderWindow &Window)
{
    posicionmouse=Mouse::getPosition(Window);
    posicionmouse=(Vector2i)Window.mapPixelToCoords(posicionmouse);
}

 void personaje::girarmouse()
 {
     giro = sprite1.getPosition();
     a = posicionmouse.x - giro.x;
     b = posicionmouse.y - giro.y;

        
     angl = -atan2( a , b) * 180 / 3.14;
     sprite1.setRotation(angl);
 }

  void personaje::setmovmou()
  {

			float tamx=abs(seguimiento.x-sprite1.getPosition().x);
			float tamy=abs(sprite1.getPosition().y-seguimiento.y);
			float RAX,RAY;
			if(tamx>tamy)
            {
				RAY=tamy/tamx;
				RAX=1;
			}
			else
            {
				RAX=tamx/tamy;
				RAY=1;
			}
			
	       	if(seguimiento.x!=sprite1.getPosition().x)
            {
	            if(seguimiento.x>sprite1.getPosition().x)
                {
	            
	            //Vector2f p;
	            p.x=sprite1.getPosition().x+RAX;
	            p.y=sprite1.getPosition().y;
	            sprite1.setPosition((Vector2f)p);
	            
	            }
	            if(seguimiento.x<sprite1.getPosition().x)
                {
	            
	            //Vector2f p;
	            p.x=sprite1.getPosition().x-RAX;
	            p.y=sprite1.getPosition().y;
	            sprite1.setPosition((Vector2f)p);
	
	            }
	        }
	        if(seguimiento.y!=sprite1.getPosition().y)
            {
	            if(seguimiento.y>sprite1.getPosition().y)
                {
	            
	           // Vector2f p;
	            p.x=sprite1.getPosition().x;
	            p.y=sprite1.getPosition().y+RAY;
	            sprite1.setPosition((Vector2f)p);
	            
	            }
	            if(seguimiento.y<sprite1.getPosition().y){
	            
	            //Vector2f p;
	            p.x=sprite1.getPosition().x;
	            p.y=sprite1.getPosition().y-RAY;
	            sprite1.setPosition((Vector2f)p);
	
	            }
	        }
	        
	        
	   }
  