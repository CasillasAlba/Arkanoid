/**
  * 
  * @author Alba Casillas Rodriguez - 76738108B
  * @author Jose Manuel Osuna Luque - 20224440B
  * Grupo de Practica D1 (Martes)
  * @date Mayo 2019
  */

#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <cstring>

#include "ConjuntoParticulas.h"
#include "miniwin.h"
#include "definiciones.h"

using namespace miniwin;
using namespace std;

class Simulador{
    
private:
    //Conjunto de Particulas con velocidad distinta de 0
    ConjuntoParticulas moviles;
    //Conjuto de Particulas cuya velocidad es 0
    ConjuntoParticulas fijas;
    
    //Tamaño de la pantalla
    int ancho;
    int alto;
    
    /**
     * Metodo privado para pintar una particula con forma de circulo. Usado en PINTAR
     * @param part, la que será pintada
     */
    void pintarParticulaCircular(const Particula& part);
    
    /**
     * Metodo privado para pintar un conjunto completo de particulas moviles. Usado en PINTAR 
     * @param conjunto, el conjunto de particulas moviles que se dibujará
     */
    void pintarConjuntoMovil();
    
    /**
     * Metodo privado para pintar una particula con forma de rectangulo. Usado en PINTAR
     * @param part, la que será pintada
     */
    void pintarParticulaRectangular(const Particula& part);
    
    /**
     * Metodo privado para pintar un conjunto completo de particulas fijas. Usado en PINTAR 
     * @param conjunto, el conjunto de particulas fijas que se dibujará
     */
    void pintarConjuntoFijo();
    
public:
    
    /**
     * Constructor por parametros de Simulador
     * @param conjMovil que contiene el Conjunto de Particulas Moviles
     * @param conjFijo que contiene el Conjunto de Particulas Fijas
     * @param ancho el limite de ancho de la ventana donde se moveran las particulas
     * @param alto el limite de alto de la ventana donde se moveran las particulas
     */
    Simulador(const ConjuntoParticulas& conjMovil, const ConjuntoParticulas& conjFijo, const int& ventanaAncho, const int& ventanaAlto);
    
    /**
     * Destructor de la clase. Cierra la ventana del Miniwin
     */
    ~Simulador();
    
    
    //Consultores
    
    /**
     * Consultor del Conjunto de Particulas Moviles
     * @return el conjunto de particulas moviles
     */
    const ConjuntoParticulas getConjuntoMovil() const;
    
    /**
     * Consultor del Conjunto de Particulas Fijas
     * @return el conjunto de particulas fijas
     */
    const ConjuntoParticulas getConjuntoFijo() const;
    
    
    //Modificadores
    
    /**
     * Modificador del Conjunto de Particulas Moviles
     * @param movil, el conjunto que dará un nuevo valor al atributo de Conjunto de Particulas moviles
     */
    void setConjuntoMovil(const ConjuntoParticulas& movil);
    
    /**
     * Modificador del Conjunto de Particulas Fijas
     * @param fijo, el conjunto que dará un nuevo valor al atributo de Conjunto de Particulas fijas
     */
    void setConjuntoFijo(const ConjuntoParticulas& fijo);
    
    /**
     * Pintará las particulas fijas (rectángulos) y moviles (redondas) en la ventana.
     * Además llamará a la función espera y refresca de miniwin
     * @param espera es el tiempo de espera
     */
    void Pintar(const int& tiempoEspera);
    
    /**
     * Ejecuta un paso en la simulación. Por ahora solo mueve y gestiona colisiones entre particulas moviles
     */
    void Step();
    
    /**
     * Gestiona las colisiones entre las particulas fijas y moviles
     */
    void Rebotes();
    
    /**
     * Metodo que incluye una nueva particula a uno de los conjuntos
     */
    void IncluirConTecla();
};

#endif /* SIMULADOR_H */

