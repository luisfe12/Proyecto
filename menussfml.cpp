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
public:
    dibujado(int an, int alt, string titulo){
        fps=60;
        ventana1= new RenderWindow(VideoMode(an,alt),titulo);
        ventana1->setFramerateLimit(fps);
        textura1= new Texture;
        sprite1= new Sprite;
         //gameloop();
        textura1->loadFromFile("prueba.jpg");
        sprite1->setTexture(*textura1);
        sprite1->move(200,60);
        sprite1->setColor(Color::Blue);
        
       gameloop();
    }
    void gameloop(){
        while(ventana1->isOpen()){
            ventana1->clear();
            ventana1->draw(*sprite1);
            ventana1->display();
        }
    }
};
 int main(){
     dibujado *dib;
     dib= new dibujado(500,600,"sprite de prueba");
     delete dib;
 }