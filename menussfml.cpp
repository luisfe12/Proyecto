//Tutorial de Escuela de juegos, un argentino
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;


class dibujado{
private:
   RenderWindow *ventana1;
   int fps;
   Texture *textura1;
   Sprite *sprite1;
   Event *evento1;
   Vector2i posicionmouse;
public:
    dibujado(int an, int alt, string titulo){
        fps=60;
        ventana1= new RenderWindow(VideoMode(an,alt),titulo);
        ventana1->setFramerateLimit(fps);
        textura1= new Texture;
        sprite1= new Sprite;
        evento1= new Event;
         //gameloop();
        textura1->loadFromFile("prueba.jpg");
        sprite1->setTexture(*textura1);
        sprite1->move(400,400);
        sprite1->setOrigin(sprite1->getTexture()->getSize().x/2.f, sprite1->getTexture()->getSize().y/2.f);//pbtengo la posicion en el medio del sprite
        //2.f=2.0, ya que son decimales.
        sprite1->setColor(Color::Blue);
        sprite1->setScale(((float)ventana1->getSize().x/sprite1->getTexture()->getSize().x),((float)ventana1->getSize().y/sprite1->getTexture()->getSize().y));
        
        
       gameloop();
    }
    void obtener_mouse(){
        posicionmouse=Mouse::getPosition(*ventana1);
        posicionmouse=(Vector2i)ventana1->mapPixelToCoords(posicionmouse);

    }
    void procesarevento(){
        while(ventana1->pollEvent(*evento1)){
            switch (evento1->type)
            {
            case Event::Closed:
                ventana1->close();
                exit(1);
                break;
            case Event::KeyPressed:
                if(Keyboard::isKeyPressed(Keyboard::W)){
                    sprite1->setPosition(sprite1->getPosition().x, sprite1->getPosition().y -1);
                }
            case Event::MouseButtonPressed:
                if(Mouse::isButtonPressed(Mouse::Left)){
                   
                    sprite1->setPosition((Vector2f)posicionmouse);
                      
            
            
            }
        }
    }
    }
    void gameloop(){
        while(ventana1->isOpen()){
            obtener_mouse();
            procesarevento();
            // sprite1->setRotation(sprite1->getRotation()+2);
             sprite1->setColor(Color::Red);
             //sprite1->setColor(Color::Green);
            ventana1->clear();
            ventana1->draw(*sprite1);
           // sprite1->getRotation(sprite1->setRotation()+10);
            ventana1->display();
        }
    }
};
 int main(){
     dibujado *dib;
     dib= new dibujado(800,800,"sprite de prueba");
     delete dib;
 }