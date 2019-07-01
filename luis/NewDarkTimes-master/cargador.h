#ifndef CARGADOR_H
#define CARGADOR_H
#include "bala.h"

class cargador
{
    bool* draw;
    Vector2f* objetivos;
    bala* arrbalas;
    int size;
    public:
        cargador(Vector2f posicion){
            size=20;
            draw = new bool[size];
            objetivos = new Vector2f[size];
            arrbalas = new bala[size];
            for(int i=0;i<size;i++){
                arrbalas[i].setpos(posicion);
                arrbalas[i].disponible=true;
                draw[i]=false;
                arrbalas[i].textura_bala.loadFromFile("bala.png");
                arrbalas[i].sprite_bala.setTexture(arrbalas[i].textura_bala);
                arrbalas[i].sprite_bala.setOrigin(arrbalas[i].sprite_bala.getTexture()->getSize().x/2.f, arrbalas[i].sprite_bala.getTexture()->getSize().y/2.f);
                arrbalas[i].sprite_bala.setScale(((float)10/arrbalas[i].sprite_bala.getTexture()->getSize().x),((float)10/arrbalas[i].sprite_bala.getTexture()->getSize().y));
            }
        }
        void launchbala(Vector2f position,Vector2f objetive){
            for(int i=0;i<size;i++){
                if(arrbalas[i].disponible){
                    arrbalas[i].disponible=false;
                    draw[i]=true;
                    arrbalas[i].setpos(position);
                    objetivos[i].x=objetive.x;
                    objetivos[i].y=objetive.y;
                    break;
                }
                
            }
        }
        void refresh(Vector2f posicion){
            for(int i=0;i<size;i++){
                if(!arrbalas[i].disponible){
                    arrbalas[i].movebala(objetivos[i]);                
                }
            }
            completejob();
        }

        void completejob(){
            for(int i=0;i<size;i++){
                if(!arrbalas[i].disponible){
                    if(arrbalas[i].posicion.x>800||arrbalas[i].posicion.x<-5){
                        arrbalas[i].disponible=true;
                        draw[i]=false;
                    }
                    if(arrbalas[i].posicion.y>775||arrbalas[i].posicion.y<-5){
                        arrbalas[i].disponible=true;
                        draw[i]=false;
                    }
                }
            }
        }
        
        bala* getBalas(){
            return arrbalas;
        }
        bool isdrawale(int pos){
            if(draw[pos])
                return true;
            return false;
        }

        ~cargador(){
            delete[] arrbalas;
        }
};

#endif 