/**
  * 
  * @author Alba Casillas Rodriguez - 76738108B
  * @author Jose Manuel Osuna Luque - 20224440B
  * Grupo de Practica D1 (Martes)
  * @date Abril 2019
  */

#include "Particula.h"

using namespace miniwin;
using namespace std;

//rand() % valores) + min

Particula::Particula(){
    x = rand() % (MAX_X+1);
    y = rand() % (MAX_Y+1);
    dx = (rand() % (MAX_VEL))+1;
    dy = (rand() % (MAX_VEL))+1;
    colorForma = GAMA[rand() % (DISPONIBLES)];
    particulaMovil = true;
    
}

Particula::Particula(bool m){
    x = rand() % (MAX_X+1);
    y = rand() % (MAX_Y+1);
    if(!m){
        dx = 0;
        dy = 0;
    }else{
        dx = (rand() % (MAX_VEL))+1;
        dy = (rand() % (MAX_VEL))+1;
    }
    
    colorForma = GAMA[rand() % (DISPONIBLES+1)];
    particulaMovil = m;
    
}

Particula::Particula(float posX, float posY){
    x = posX;
    y = posY;
    dx = (rand() % (MAX_VEL))+1;
    dy = (rand() % (MAX_VEL))+1;
    colorForma = ROJO;
    particulaMovil = true;
    
}

const float& Particula::getX() const{return x;}
const float& Particula::getY() const{return y;}
const float& Particula::getDx() const{return dx;}
const float& Particula::getDy() const{return dy;}
const Color& Particula::getColor() const{return colorForma;}
const bool& Particula::getParticulaMovil() const{return particulaMovil;}

void Particula::setX(const float& nuevaX){
    x = nuevaX;
}

void Particula::setY(const float& nuevaY){
    y = nuevaY;
}

void Particula::setDx(const float& nuevaDx){
    dx = nuevaDx;
}

void Particula::setDy(const float& nuevaDy){
    dy = nuevaDy;
}

void Particula::setColor(const Color& nuevoColor){
    colorForma = nuevoColor;
}

void Particula::setParticulaMovil(const bool& nuevaMov){
    particulaMovil = nuevaMov;
    
    if(particulaMovil){
        dx = (rand() % (MAX_VEL))+1;
        dy = (rand() % (MAX_VEL))+1;
    }else{
        dx = 0;
        dy = 0;
    }
}

void Particula::copiar(const Particula& nueva){
    x = nueva.x;
    y = nueva.y;
    dx = nueva.dx;
    dy = nueva.dy;
    colorForma = nueva.colorForma;
    particulaMovil = nueva.particulaMovil;
}

int Particula::distancia(const Particula& otra){
    //Calculo de la distancia
    //(b.x - a.x)^2 + (b.y - a.y)^2
        
    return sqrt( pow( (otra.getX() - getX()), 2 ) + pow( (otra.getY() - getY()), 2) );;
   
}

bool Particula::Colision(const Particula& otra, const float factor){
    
    bool choca;
    
    if(otra.getParticulaMovil()){
        choca = distancia(otra) < UMBRAL;
    }else{
        choca = distancia(otra) < UMBRAL*factor;
    }
    
    return choca;
    
}

void Particula::Mover(int ancho, int alto){
    
    const float factor = 0.95;
    x += dx;
    y += dy;
    
    if (x > ancho - RADIO) {
        dx = -dx * factor;
        x = ancho - RADIO;
    
    } else if (x < RADIO) {
      dx = -dx * factor;
      x = RADIO;
    
    } else if (y > alto - RADIO) {
      dy = -dy * factor;
      y = alto - RADIO;
    
    } else if (y < RADIO) {
      dy = -dy * factor;
      y = RADIO;
    }
    
}

void Particula::Intercambiar(float& valor, float& otroValor){
    
    float aux = valor;
    valor = otroValor;
    otroValor = aux;
    
}

void Particula::Rebota(Particula& otra){
    
    if(getParticulaMovil() && otra.getParticulaMovil()){
        float aux = otra.getDx();
    
        Intercambiar(this->dx, aux);
        otra.setDx(aux);

        aux = otra.getDy();
        Intercambiar(this->dy, aux);
        otra.setDy(aux);
    }else{
        if(getParticulaMovil() && !otra.getParticulaMovil()){
            setDx(getDx()*(-1));
            setDy(getDy()*(-1));
        }else{
            otra.setDx(otra.getDx()*(-1));
            otra.setDy(otra.getDy()*(-1));
        }
    }
    
}


Particula& Particula::operator=(const Particula & nuevo){
    
    if(&nuevo != this){
        copiar(nuevo);
    }
    
    return *this;
}

ostream& operator<<(ostream& salida, const Particula & part){
    
    if(part.particulaMovil){
        salida << "Particula(" << part.x << ", " << part.y << ", " << GAMA[part.colorForma] << ")";
    }else{
        salida << "Particula(" << part.x << ", " << part.y << ", " << part.x+REC_DERECHA << ", " << part.y+REC_ABAJO << ", " << GAMA[part.colorForma] << ")";
    }
    
    
    return salida;
}

void Particula::MoverArknoid(int ancho, int alto, int& muertes){
    
    const float factor = 1.02;
    x += dx;
    y += dy;
    
    if (x > ancho - RADIO) {
        dx = -dx * factor;
        x = ancho - RADIO;
    
    } else if (x < RADIO) {
      dx = -dx * factor;
      x = RADIO;
    
    } else if (y > alto - RADIO) {
        x = ancho/2;
        y = alto/2;
        muertes++;
    
    } else if (y < RADIO) {
      dy = -dy * factor;
      y = RADIO;
    }
    
}

void Particula::RebotaArkanoid(Particula& otra, const int& valorAncho){
    //Derecha
    if(getX() >= (otra.getX()-(valorAncho)) && getX() < (otra.getX()+(valorAncho)) ){
        setDy(getDy()*(-1));
    
    //Izquierda
    }else{
        setDx(getDx()*(-1));
        setDy(getDy()*(-1));
        
    }
    
}