/**
  * 
  * @author Alba Casillas Rodriguez - 76738108B
  * @author Jose Manuel Osuna Luque - 20224440B
  * Grupo de Practica D1 (Martes)
  * @date Mayo 2019
  */

#include "Simulador.h"
#include "ConjuntoParticulas.h"

using namespace miniwin;
using namespace std;


Simulador::Simulador(const ConjuntoParticulas&conjMovil, const ConjuntoParticulas& conjFijo, const int& ventanaAncho, const int& ventanaAlto) : moviles(conjMovil), fijas(conjFijo){
    ancho = ventanaAncho;
    alto = ventanaAlto;
    vredimensiona(ancho, alto);
}

Simulador::~Simulador(){
    vcierra();
}
    
const ConjuntoParticulas Simulador::getConjuntoMovil() const {
    return moviles;
}
    
const ConjuntoParticulas Simulador::getConjuntoFijo() const {
    return fijas;
}

void Simulador::setConjuntoMovil(const ConjuntoParticulas& movil) {
    moviles = movil;
}

void Simulador::setConjuntoFijo(const ConjuntoParticulas& fijo) {
    fijas = fijo;
}

//Metodos privados usados en PINTAR
void Simulador::pintarParticulaCircular(const Particula& part){
   color(part.getColor());
   circulo_lleno(part.getX(), part.getY(), RADIO);
}

void Simulador::pintarConjuntoMovil(){
    
    for(int c = 0; c < moviles.getUtiles(); c++){
        pintarParticulaCircular(moviles.ObtieneParticula(c));
    }
}

void Simulador::pintarParticulaRectangular(const Particula& part){
    color(part.getColor());
    //IZQ, ARR, DER, ABAJO
    //IZQ, posicion en el eje X, DER puntos a rellenar a la derecha
    //ARR, posicion en el eje Y, ABA puntos a rellenar hacia abajo
    //rectangulo_lleno(50, 50, 100, 75);
    rectangulo_lleno(part.getX()-(REC_DERECHA/2), part.getY()-(REC_ABAJO/2), part.getX()+(REC_DERECHA/2), part.getY()+(REC_ABAJO/2));
}

void Simulador::pintarConjuntoFijo(){
    
    for(int r = 0; r < fijas.getUtiles(); r++){
        pintarParticulaRectangular(fijas.ObtieneParticula(r));
    }
}

//################

void Simulador::Pintar(const int& tiempoEspera){
    borra();
    pintarConjuntoMovil();
    pintarConjuntoFijo();
    refresca();
    espera(tiempoEspera);
}

void Simulador::Rebotes(){
    
    for(int m=0; m<moviles.getUtiles(); m++){
        
        for(int f=0; f<fijas.getUtiles(); f++){
            
            if(moviles.ObtieneParticula(m).Colision(fijas.ObtieneParticula(f), FACTOR_FIJA)){
                moviles.ObtieneParticula(m).Rebota(fijas.ObtieneParticula(f));
            }
        }
    }
    
}

void Simulador::Step(){
    moviles.Mover(MAX_X, MAX_Y);
    moviles.GestionarColisiones();
    Rebotes();
}

//AGREGAR PARTICULA AL PULSAR UNA TECLA
void Simulador::IncluirConTecla(){ 
    
    int t = tecla();
    
    if (t == ESPACIO) {
        int opcion = ( rand() % 2);
        //CERO agrega a moviles
        if(opcion == 0){
            Particula x(true);
            moviles.AgregaParticula(x);
        
        //UNO agrega a fijas
        }else{
            Particula x(false);
            fijas.AgregaParticula(x);
        }    
    }
    
}
