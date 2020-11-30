/**
  * 
  * @author Alba Casillas Rodriguez - 76738108B
  * @author Jose Manuel Osuna Luque - 20224440B
  * Grupo de Practica D1 (Martes)
  * @date Mayo 2019
  */

#include "Particula.h"
#include "ConjuntoParticulas.h"

using namespace miniwin;
using namespace std;

ConjuntoParticulas::ConjuntoParticulas(){
    capacidad = 0;
    utiles = 0;
    movil = true;
    set = 0;
    //ReservaMemoria(capacidad);
}

//CapacidadC, tamaño del array con C particulas
ConjuntoParticulas::ConjuntoParticulas(int capacidadC){
    capacidad = capacidadC;
    utiles = 0;
    movil = true;
    ReservaMemoria(capacidad);
    
    for(int p=0; p<capacidad; p++){
        Particula x;
        AgregaParticula(x);
    }
}

//CapacidadC, tamaño del array con C particulas
ConjuntoParticulas::ConjuntoParticulas(int capacidadC, bool m){
    capacidad = capacidadC;
    utiles = 0;
    movil = m;
    ReservaMemoria(capacidad);
    
    for(int p=0; p<capacidad; p++){
        Particula x(m);
        AgregaParticula(x);
    }
    
}

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas& otro){
    ReservaMemoria(otro.getCapacidad());
    
    CopiarDatos(otro);
}

ConjuntoParticulas::~ConjuntoParticulas(){
    LiberaMemoria();
}

void ConjuntoParticulas::ReservaMemoria(int capacidadC){
    set = new Particula[capacidadC];
}

void ConjuntoParticulas::LiberaMemoria(){
    
    if(set) {
        delete [] set;
        set = 0;
        utiles = 0;
        capacidad = 0;
        movil = false;
    }
}

void ConjuntoParticulas::CopiarDatos(const ConjuntoParticulas& otro){
    capacidad = otro.getCapacidad();
    utiles = otro.getUtiles();
    movil = otro.getMovil();
    
    //El set de la clase; el otro set a copiar, n bytes a copiar
    memcpy(set, otro.getParticulas(), capacidad*sizeof(Particula));
}

void ConjuntoParticulas::Redimensionar(int nuevaCapacidad){
    
    Particula* nuevo = new Particula[nuevaCapacidad];
    
    for(int i = 0; i<utiles; i++){
        nuevo[i] = set[i];
    }
    
    delete [] set;
    
    capacidad = nuevaCapacidad;
    
    set = nuevo;

}

//Metodos GET para la consulta
const Particula* ConjuntoParticulas::getParticulas() const {return set;}
const int& ConjuntoParticulas::getCapacidad() const {return capacidad;}
const int& ConjuntoParticulas::getUtiles() const {return utiles;}
const bool& ConjuntoParticulas::getMovil() const{return movil;}

void ConjuntoParticulas::setMovil(const bool& nuevoMovil){
    movil = nuevoMovil;
    
    for(int u=0; u<getUtiles(); u++){
        ObtieneParticula(u).setParticulaMovil(movil);
    }
}

//Metodos
void ConjuntoParticulas::AgregaParticula(const Particula& pa){
    
    if(utiles == capacidad){
        Redimensionar(capacidad+TAM_BLOQUE);
    }
    
    //Si hay 1 util, es que la posicion 0 está cubierta
    set[utiles] = pa; //Se llena la posicion 1, y ahora estan cubiertas la 0 y la 1
    utiles++; //Hay dos utiles ocupadas
    
}

void ConjuntoParticulas::BorrarParticula(int pos){
    
    if(utiles > 0){
        //BORRADO
        
        for(int i = pos; i<utiles-1; i++){
            
            set[i] = set[i+1];
        }
        utiles--;

        if( (capacidad-utiles) > TAM_BLOQUE){
            Redimensionar(utiles);
        }
    }
    
}

Particula& ConjuntoParticulas::ObtieneParticula(int pos){
    return set[pos];
}

Particula ConjuntoParticulas::ObtieneParticula(int pos) const{
    return set[pos];
}

void ConjuntoParticulas::ReemplazaParticula(int pos, const Particula& otra){
    set[pos] = otra;
}

void ConjuntoParticulas::Mover(int ancho, int alto){
    
    for(int i = 0; i < utiles; i++){
        set[i].Mover(ancho, alto);
    }
    
}

void ConjuntoParticulas::GestionarColisiones(){
    
    for(int i=0; i<utiles-1; i++){
        
        for(int j=i+1; j < utiles; j++){
            
            if(set[i].Colision(set[j], 1.0)){
                set[i].Rebota(set[j]);
            }
            
        }
    }
}


//Sobrecarga de Operadores
ConjuntoParticulas& ConjuntoParticulas::operator=(const ConjuntoParticulas & nuevo){
    
    if(this != &nuevo){
        
        LiberaMemoria();
        ReservaMemoria(nuevo.getCapacidad());
        movil = nuevo.getMovil();
        CopiarDatos(nuevo);
    }
    
    return (*this);
}


ConjuntoParticulas ConjuntoParticulas::operator +(const ConjuntoParticulas &conjuntoP1) const{
    ConjuntoParticulas temp( (*this) );
    
    for(int i=0; i< conjuntoP1.getUtiles(); i++){
        temp.AgregaParticula(conjuntoP1.ObtieneParticula(i));
    }
    
    return (temp);

}

ostream& operator<<(ostream& salida, const ConjuntoParticulas& conjP){
    salida << "\t";
    
    for(int i=0; i<conjP.utiles; i++){
        
        //Es la última, no se añade un espacio
        if(i == (conjP.utiles-1) ){
            salida << conjP.set[i];
        }else{
            salida << conjP.set[i] << " ";
        }
        
    }
    
    salida << '\n';
    
    return salida;
  
}

void ConjuntoParticulas::gestionarTablero(){
        
    int x = 25;
    int contador = 0;
    int y = 0;
    
    for (int i = 0; i < getUtiles(); i++) {
        
        if(contador % (getUtiles()/FILAS_ARKANOID) == 0 && contador != 0){
            contador = 0;
            y = y+(ALTO_ARKANOID/2)+5;
            x = 25;
        }
        ObtieneParticula(i).setX(x);
        ObtieneParticula(i).setY(y);
        x = x+(ANCHO_ARKANOID+5);
        
        contador++;
     
    }
    
}