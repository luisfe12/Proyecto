//Tutorial de Escuela de juegos, un argentino
//https://en.sfml-dev.org/forums/index.php?topic=10167.0
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include<string>
using namespace std;
using namespace sf;


class bala{
private:
    Texture *textu_bal;
    Sprite *sprite_bal;
    Vector2f p;
   // Vector2f direccion;
public:
    bala(Vector2f pos){
         textu_bal = new Texture;
         sprite_bal = new Sprite;
         textu_bal->loadFromFile("prueba.jpg");
         sprite_bal= new Sprite(*textu_bal);
         sprite_bal->setOrigin(sprite_bal->getTexture()->getSize().x/2.f, sprite_bal->getTexture()->getSize().y/2.f);
         sprite_bal->setScale(((float)10/sprite_bal->getTexture()->getSize().x),((float)10/sprite_bal->getTexture()->getSize().y));
         sprite_bal->setPosition(pos);
         sprite_bal->setColor(Color::Black);

     }
    void movimiento(Vector2f direccion){
            float tamx=abs(direccion.x-sprite_bal->getPosition().x);
			float tamy=abs(sprite_bal->getPosition().y-direccion.y);
			float RAX,RAY;
			
				RAX=tamx/5;
				RAY=tamy/5;
			

            if((direccion.x!=sprite_bal->getPosition().x)||(sprite_bal->getPosition().x==direccion.x)){
	            if(direccion.x>sprite_bal->getPosition().x){
	            
	            //Vector2f p;
	            p.x=sprite_bal->getPosition().x+RAX;
	            p.y=sprite_bal->getPosition().y;
	            sprite_bal->setPosition((Vector2f)p);
	            
	            }
	            if(direccion.x<sprite_bal->getPosition().x){
	            
	            //Vector2f p;
	            p.x=sprite_bal->getPosition().x-RAX;
	            p.y=sprite_bal->getPosition().y;
	            sprite_bal->setPosition((Vector2f)p);
	
	            }
	        }
	        if((direccion.y!=sprite_bal->getPosition().y)||(sprite_bal->getPosition().y==direccion.y)){
	            if(direccion.y>sprite_bal->getPosition().y){
	            
	           // Vector2f p;
	            p.x=sprite_bal->getPosition().x;
	            p.y=sprite_bal->getPosition().y+RAY;
	            sprite_bal->setPosition((Vector2f)p);
	            
	            }
	            if(direccion.y<sprite_bal->getPosition().y){
	            
	            //Vector2f p;
	            p.x=sprite_bal->getPosition().x;
	            p.y=sprite_bal->getPosition().y-RAY;
	            sprite_bal->setPosition((Vector2f)p);
            
                }	

            }

            if((direccion.y==sprite_bal->getPosition().y)&&(direccion.x==sprite_bal->getPosition().x))
            
                delete sprite_bal;
           /* if((direccion.x>=sprite_bal->getPosition().x)&(direccion.y>sprite_bal->getPosition().y)){
                    p.x=sprite_bal->getPosition().x+RAX;
	                p.y=sprite_bal->getPosition().y-RAY;
	                sprite_bal->setPosition((Vector2f)p);
            
                
            }*/
    
    }
    
    Sprite get_sprite(){
        return *sprite_bal;
    }

};

class dibujado{
private:
   RenderWindow *ventana1;
   int fps;
   Texture *textura1;
   Font *fuente1;
   Text *txtbalas;
   Sprite *sprite1;
   bala *bal;
   Event *evento1;
   Vector2i posicionmouse;
   Vector2i seguimiento;   
   Vector2i seguimiento2;
   Vector2f giro;
   Vector2f p;
   View *view1;
   View *vienminmap;
   int tam;
   float angl;
   double a, b;
   //bool com=false;
public:
    dibujado(int an, int alt, string titulo){
        fps=60;
        ventana1= new RenderWindow(VideoMode(an,alt),titulo);
        ventana1->setFramerateLimit(fps);
         view1= new View;
         vienminmap=new View;
        


       /* view1->move(100.f, 100.f);
        view1->zoom(0.5f);*/
        /*view1->setCenter(400.f, 400.f);
        view1->move(100.f, 100.f);
        view1->setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));*/

       vienminmap->setViewport(FloatRect(0.75f, 0.f, 0.25f, 0.25f));
        textura1= new Texture;
         textura1->loadFromFile("prueba.jpg");
        sprite1= new Sprite(*textura1);
       // sprite2=new Sprite(*textura1);
        evento1= new Event;
       //view1= new View;
         //gameloop();
        
        
       
        //sprite2->setTexture(*textura1);
        sprite1->move(400,400);
        //sprite2->move(400,400);
        seguimiento.x=400;
        seguimiento.y=400;
        sprite1->setOrigin(sprite1->getTexture()->getSize().x/2.f, sprite1->getTexture()->getSize().y/2.f);//pbtengo la posicion en el medio del sprite
       // sprite2->setOrigin(sprite2->getTexture()->getSize().x/2.f, sprite2->getTexture()->getSize().y/2.f);
        //2.f=2.0, ya que son decimales.
        //sprite1->setColor(Color::Blue);
       // sprite2->setScale(((float)ventana1->getSize().x/sprite2->getTexture()->getSize().x),((float)ventana1->getSize().y/sprite2->getTexture()->getSize().y));
        sprite1->setScale(((float)100/sprite1->getTexture()->getSize().x),((float)100/sprite1->getTexture()->getSize().y));
       // view1->FloatRect(200.f, 200.f, 300.f, 200.f);
      // view1->setViewport(FloatRect(200.f, 200.f, 300.f, 200.f));
         fuente1 = new Font;
          txtbalas = new Text;
         fuente1->loadFromFile("Roboto.ttf");
         //txtbalas = new Text;
         txtbalas->setFont(*fuente1);
         txtbalas->setString("balas");
         txtbalas->setCharacterSize(24);
        // txtbalas->setPosition(0,0);
         txtbalas->setFillColor(Color::Green);

       gameloop();
    }

    void obtener_mouse(){
        posicionmouse=Mouse::getPosition(*ventana1);
        posicionmouse=(Vector2i)ventana1->mapPixelToCoords(posicionmouse);

    }

    void procesarevento(){
        setmovmou();
        girmouse();
         
        
        while(ventana1->pollEvent(*evento1)){
            switch (evento1->type)
            {
            case Event::Closed:
                ventana1->close();
                exit(1);
                break;
            case Event::KeyPressed:
               if(Keyboard::isKeyPressed(Keyboard::Space)){
                   //com=true;
                   seguimiento2.x=posicionmouse.x;
                   seguimiento2.y=posicionmouse.y;
                   bal=new bala(sprite1->getPosition());
               
                   /* Sprite *sprite2;
                    sprite2=new Sprite(*textura1);
                    sprite2->setPosition(sprite1->getPosition().x, sprite1->getPosition().y);
                         if(sprite2!=NULL){*/
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    ventana1->close();
                    exit(1);
                }
                
                
            case Event::MouseButtonPressed:
               if(Mouse::isButtonPressed(Mouse::Left)){
                	seguimiento.x=posicionmouse.x;
                	seguimiento.y=posicionmouse.y;
                    //int color = rand()%255;
                    sprite1->setColor(Color(rand()%255,rand()%255,rand()%255));
            
                }   
                else if(Mouse::isButtonPressed(Mouse::Right)){
                    cout<<"izquierdo no derecho "<<endl;
                    seguimiento2.x=posicionmouse.x;
                   seguimiento2.y=posicionmouse.y;
                   bal=new bala(sprite1->getPosition());

                }
           
            case Event::MouseWheelScrolled:

                if(evento1->mouseWheelScroll.wheel == sf::Mouse::VerticalWheel){
                    cout << "reconoce rueda" << endl;
                    
                    
                }

            }
        
        }
    
    }

    
		
        void girmouse(){
            giro = sprite1->getPosition();
            a = posicionmouse.x - giro.x;
            b = posicionmouse.y - giro.y;

        
            angl = -atan2( a , b) * 180 / 3.14;
            sprite1->setRotation(angl);
        }

       
  


        
		void setmovmou(){
            
			float tamx=abs(seguimiento.x-sprite1->getPosition().x);
			float tamy=abs(sprite1->getPosition().y-seguimiento.y);
			float RAX,RAY;
			if(tamx>tamy){
				RAY=tamy/tamx;
				RAX=1;
			}
			else{
				RAX=tamx/tamy;
				RAY=1;
			}
			
	       	if(seguimiento.x!=sprite1->getPosition().x){
	            if(seguimiento.x>sprite1->getPosition().x){
	            
	            //Vector2f p;
	            p.x=sprite1->getPosition().x+RAX;
	            p.y=sprite1->getPosition().y;
	            sprite1->setPosition((Vector2f)p);
	            
	            }
	            if(seguimiento.x<sprite1->getPosition().x){
	            
	            //Vector2f p;
	            p.x=sprite1->getPosition().x-RAX;
	            p.y=sprite1->getPosition().y;
	            sprite1->setPosition((Vector2f)p);
	
	            }
	        }
	        if(seguimiento.y!=sprite1->getPosition().y){
	            if(seguimiento.y>sprite1->getPosition().y){
	            
	           // Vector2f p;
	            p.x=sprite1->getPosition().x;
	            p.y=sprite1->getPosition().y+RAY;
	            sprite1->setPosition((Vector2f)p);
	            
	            }
	            if(seguimiento.y<sprite1->getPosition().y){
	            
	            //Vector2f p;
	            p.x=sprite1->getPosition().x;
	            p.y=sprite1->getPosition().y-RAY;
	            sprite1->setPosition((Vector2f)p);
	
	            }
	        }
	        
	        
	   }
  

    void gameloop(){
        while(ventana1->isOpen()){
            obtener_mouse();
           // procesarevento();
            //setmovmou(sprite1, posicionmouse);
            // sprite1->setRotation(sprite1->getRotation()+2);
            //sprite2->setColor(Color::Cyan);
             //ventana1->setView(*vienminmap);
            ventana1->clear(Color::White);
           //ventana1->draw(*sprite2);
            //ventana1->draw(*sprite1);
            ventana1->draw(*txtbalas);
            procesarevento();
            
            if(bal!=NULL)
            {
                bal->movimiento((Vector2f)seguimiento2);
                ventana1->draw(bal->get_sprite());
            }
           ventana1->draw(*sprite1);
            ventana1->display();
        }
    }
};




 int main(){
     dibujado *dib;
     dib= new dibujado(800,800,"sprite de prueba");
     delete dib;
 }
