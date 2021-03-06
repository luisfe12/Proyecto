#include "Headers.h"
#include "personaje.cpp"
#include "bala.h"
#include "bala.cpp"
#include "cargador.h"
#include <list>
#define Nentity 500
using namespace std;

//g++ main.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system Mapa.cpp window.cpp Entidad.cpp Area.cpp Colisiones.cpp Bloque.cpp

// El Main esta muy frondoso, MAS ABSTRACCION!
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(pred_window_tamx,pred_window_tamy), "My window");
    Texture text_menu1;
    Sprite sprite_menu1;
    Menu menu(window.getSize().x, window.getSize().y, text_menu1, sprite_menu1, window);
    
    //window.setMouseCursorGrabbed(0);
    srand(time(NULL));
    Zombie *mobs=new Zombie[Nentity];
    for(int i = 0; i < Nentity; i++)
    {
        mobs[i].setPosx_y(1366/2,768/2);
    }
   bool mover=false;
   bool mover1=false;
   // personaje jugador;
    Texture textura2;
    Sprite sprite2;
    Vector2i mouse;
    Vector2i segui;
    Vector2f p3;
    Vector2f giro3;
    int tam1;
    float angl1;
    double a1, b1;
    personaje jugador( textura2,  sprite2);
    jugador.setmouse(mouse);
    jugador.setseguimeiento(segui);
    jugador.setmvep(p3);
    jugador.setgiro(giro3);
    jugador.setangulo(tam1, angl1, a1, b1);
    jugador.obtener_mouse(window);
    //bala proyectil
    Texture textura_bala2,textura_bala3,textura_bala4;
    Sprite sprite_bala2, sprite_bala3, sprite_bala4 ;
    //Vector2f possprite=jugador.getsprite().getPosition;
    Vector2i pos;
    Vector2f direccion_bala2;
    //bala proyectil(textura_bala2, sprite_bala2,jugador.getsprite().getPosition());
    list<bala*> mylist;
    list<bala*>::iterator it;
   // bala proyectil1(textura_bala3, sprite_bala3,jugador.getsprite().getPosition());
    //bala proyectil2(textura_bala4, sprite_bala4,jugador.getsprite().getPosition());
    //bala proyectila[3]={proyectil,proyectil1,proyectil2};
    int i=0;
    bool disaparo=false;
    bool menuu=true;
    bool juego=false;
    //proyectil.setvector(direccion_bala2);
    Entidad mobs123[4]={{400,400,5},{400,400,5},{400,400,5},{400,400,5}};
    int x=0;
    window.setFramerateLimit(60);
    cargador balas(jugador.getsprite().getPosition()); /////   creacion de el cargador
    // run the program as long as the window is open
    Mapa render(800,pred_areas_numx,pred_bloq_numx);
    while (window.isOpen())
    {
        if(menuu==true)
        {
        sf::Event event1;

		while (window.pollEvent(event1))
		{
			switch (event1.type)
			{
			case sf::Event::KeyReleased:
				switch (event1.key.code)
				{
				case sf::Keyboard::Up:
					menu.Mover_arriba();
					break;

				case sf::Keyboard::Down:
					menu.Mover_abajo();
					break;

				case sf::Keyboard::Return:
					switch (menu.get_presionado())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
                        juego=true;
                        menuu=false;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();
        menu.drawfondo(window);
		menu.draw(window);

		window.display();
	}
    
        if(juego==true){
        jugador.obtener_mouse(window);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
       if(mover==true){
       jugador.setmovmou();
       //jugador.girarmouse();
       Vector2f possprite=jugador.getsprite().getPosition();
       }
        jugador.girarmouse();
      
        while (window.pollEvent(event))
        {
           
           
             //jugador.girarmouse();
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
            sf::CircleShape ward(100);
            ward.setFillColor(sf::Color(100,100,100));
            sf::Vector2i mposition= sf::Mouse::getPosition();
            ward.setPosition(sf::Vector2f(mposition.x,mposition.y));
            window.draw(ward);
            std::cout<<"mousepressed"<<mposition.x<<mposition.y<<"|";
            jugador.seguimiento.x=jugador.posicionmouse.x;
            jugador.seguimiento.y=jugador.posicionmouse.y;
            mover=true;
            }
            mylist.push_back(new bala(textura_bala2, sprite_bala2,jugador.getsprite().getPosition()));
            if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                   //window.draw(proyectil.getspritebala());
                   float x;
                   float y;
                   mylist.push_back(new bala(textura_bala2, sprite_bala2,jugador.getsprite().getPosition()));
                   if(jugador.posicionmouse.x>jugador.getsprite().getPosition().x)
                    x=1380.0f;
                    else
                    {
                        x=-10.0f;
                    }
                    float pendiente=jugador.posicionmouse.y-jugador.getsprite().getPosition().y;
                    pendiente/=(jugador.posicionmouse.x-jugador.getsprite().getPosition().x);
                    y=pendiente*(x-jugador.posicionmouse.x)+jugador.posicionmouse.y;

                    for(it=mylist.begin(); it!= mylist.end();++it){
                        (*it)->setpos(Vector2f(jugador.getsprite().getPosition().x,jugador.getsprite().getPosition().y));
                        disaparo=true;
                        if(disaparo==true)break;
                    }
                    
                    //mylist.push_back(new bala(textura_bala2, sprite_bala2,jugador.getsprite().getPosition()));
                  // proyectil.setpos(sf::Vector2f(jugador.getsprite().getPosition().x,jugador.getsprite().getPosition().y));
                   pos.x=x;
                   pos.y=y;
                   // aca
                   // balas.launchbala(sf::Vector2f(jugador.getsprite().getPosition().x,jugador.getsprite().getPosition().y),(Vector2f) pos);
                   //cout<<&proyectil;
                   //i++;
                   //mover1=true;
            }
            
        }
        
        // clear the window with black color
        //window.draw(jugador.getsprite());
        window.clear(sf::Color::Black);
        //
        //DIBUJO DEL MAPA
        //render.Dibujar(window,1);
        //render.Dibujar(window,2);
        
        render.Dibujar_mapa(window);
        //render.Dibujar_Area(window,0);

        //
      
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::CircleShape ward(100);
            ward.setFillColor(sf::Color(100,100,100));
            sf::Vector2i mposition= sf::Mouse::getPosition();
            ward.setPosition(sf::Vector2f(mposition.x,mposition.y));
            window.draw(ward);
            std::cout<<"mousepressed"<<mposition.x<<mposition.y<<"|";
            jugador.seguimiento.x=jugador.posicionmouse.x;
            jugador.seguimiento.y=jugador.posicionmouse.y;
            
        }
        // jugador.setmovmou();
        //
        x=(x+1)%300;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))x=0;
        std::cout<<x<<"||";
        for(int i = 0; i < Nentity; i++)
        {
            mobs[i].MoveAutomatico();
            mobs[i].Dibujar(window);
        }

        for(int i=0;i<Nentity;i++){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                mobs[i].setObj(sf::Mouse::getPosition().x+5,sf::Mouse::getPosition().y+5);   
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                    mobs[i].setObj(100*i%(16*100),100*i/(16*100)*100);
            }
            mobs[i].MoveAutomatico();
            mobs[i].Dibujar(window);
        }

        for(int i=0;i<4;i++){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                mobs123[i].setObj(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);   
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                mobs123[i].setObj(800/(i+2),(i+1)*150);
            }
            mobs123[i].MoveAutomatico();
            mobs123[i].Dibujar(window);
        }
        // draw everything here...
        // window.draw(...);
        std::cout<<std::endl;
        // end the current frame
        //window.draw(jugador.getsprite());

        window.draw(jugador.getsprite());
        balas.refresh(sf::Vector2f(jugador.getsprite().getPosition().x,jugador.getsprite().getPosition().y));


        // desde aca 
       /*  cout<<"asdasda"<<endl;
        for(int i=0;i<20;i++){
            if(balas.isdrawale(i)){
                bala* ptr = balas.getBalas();
                cout<<"dibujo bala"<<endl;
                window.draw((ptr+i)->getspritebala());
            }
            //proyectil.movebala((Vector2f)pos);
        //possprite=jugador.getsprite().getPosition();
        }
        balas.refresh(sf::Vector2f(jugador.getsprite().getPosition().x,jugador.getsprite().getPosition().y));
        cout<<"asdasda"<<endl;
        *///window.draw(proyectil.getspritebala());
        if(disaparo==true)
        {
            (*it)->movebala((Vector2f)pos);
            window.draw((*it)->getspritebala());
            disaparo=false;
        }
         //proyectil.movebala((Vector2f)pos);
        //possprite=jugador.getsprite().getPosition();
        window.display();
        
    }
    }
    return 0;
}