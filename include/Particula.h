/**
  * 
  * @author Alba Casillas Rodriguez - 76738108B
  * @author Jose Manuel Osuna Luque - 20224440B
  * Grupo de Practica D1 (Martes)
  * @date Abril 2019
  */

#ifndef PARTICULA_H
#define PARTICULA_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <cstring>

#include "miniwin.h"
#include "definiciones.h"

using namespace miniwin;
using namespace std;

class Particula{
    
private:
    //Estos atributos guardan la posicion en el plano XY
    float x;
    float y;
    //Guardan el desplazamiento en el plano XY
    float dx;
    float dy;
    //Guarda el color de la Particula
    Color colorForma;
    
    //Si la variable vale true, tomará los valores de XY
    //Si vale FALSE, será un rectángulo y necesitará los valorse AnchoLargo
    bool particulaMovil;
    
    /**
     * Metodo auxiliar privado para copiar datos y evitar repetir código
     * @param nueva, la Particula que contiene los nuevos datos que serán asignados a This
     */
    void copiar(const Particula& nueva);
    
public:
    
    /**
     * Constructor por Defecto
     */
    Particula();
    
    /**
     * Constructor por Defecto (diferenciando entre particula movil y fija)
     * @param m, booleano que indica movil si es TRUE, fija si es FALSE
     */
    Particula(bool m);
            
    /**
     * Constructor por Parámetros
     * @param posX, el valor en el eje X que le será asignado a la Particula
     * @param posY, el valor en el eje Y que le será asignado a la Particula
     */
    Particula(float posX, float posY);
        
    
    //Consultores    
    
    /**
     * Consultor de la variable X de la clase
     * @return el valor en el eje X de la Particula
     */
    const float& getX() const;
    
    /**
     * Consultor de la variable Y de la clase
     * @return el valor en el eje Y de la Particula
     */
    const float& getY() const;
    
    /**
     * Consultor de la variable dx de la clase
     * @return el valor de desplazamiento en el Eje X de la Particula
     */
    const float& getDx() const;
    
    /**
     * Consultor de la variable dy de la clase
     * @return el valor de desplazaiento en el eje Y de la Particula
     */
    const float& getDy() const;
    
    /**
     * Consultor de la variable color de la clase
     * @return el color de la Particula
     */
    const Color& getColor() const;
    
    /**
     * Consultor de la variable particulaMovil de la clase
     * @return True si es movil, false si es fija
     */
    const bool& getParticulaMovil() const;
    
    
    //Modificadores
    
    /**
     * Modificador de la variable x, la posicion en el eje X
     * @param nuevaX, nuevo valor para el eje X
     */
    void setX(const float& nuevaX);
    
    /**
     * Modificador de la variable y, la posicion en el eje Y
     * @param nuevaY, nuevo valor para el eje Y
     */
    void setY(const float& nuevaY);
    
    /**
     * Modificador de la variable dx, el desplazamiento de la Particula en el eje X
     * @param nuevaDx, nuevo valor para el desplazamiento en X
     */
    void setDx(const float& nuevaDx);
    
    /**
     * Modificador de la variable dy, el desplazamiento de la Particula en el eje Y
     * @param nuevaDy, nuevo valor para el desplazamiento en Y
     */
    void setDy(const float& nuevaDy);
    
    /**
     * Modificador de la variable color de la Particula
     * @param nuevoColor, el nuevo color que tendrá asociado la Particula
     */
    void setColor(const Color& nuevoColor);
    
    /**
     * Modificador de la variable particulaMovil de la clase
     * @param mov, True si es movil, false si es fija
     */
    void setParticulaMovil(const bool& nuevaMov);

    
    //Metodos
    
    /**
     * Calcula la distancia entre dos Particulas que servirá para ver si chocan entre ellas o no
     * @param otra, una particula
     * @return un entero que refleja la distancia entre ambas
     */
    int distancia(const Particula& otra);
    
    /**
     * Comprueba si la Particula que invoca el metodo ha chocado con otra Particula
     * @param otra, la particula con la que comprobará si ha chocado
     * @param factor, multiplicador para el umbral
     * @return true si ha chocado, false si no ha chocado
     */
    bool Colision(const Particula& otra, const float factor);
    
    /**
     * Simula un movimiento de la Particula en la ventana de ejecución
     * @param ancho, el limite de ancho de la ventana donde la Particula se mueve
     * @param alto, el limite de alto de la ventana donde la Particula se mueve
     */
    void Mover(int ancho, int alto);
    
    /**
     * Simula el choque entre dos particulas y su correspondiente acción de rebote
     * @param otra, la Particula con la que choca
     * @pre se ha producido una colisión con la particula recibida
     */
    void Rebota(Particula& otra);
    
    /**
     * Operador de Asignacion para Particula
     * @param nuevo, una Particula con los nuevos valores del objeto que invoca la asignacion
     * @return la propia Particula modificada
     */
    Particula& operator=(const Particula & nuevo);
    
    /**
     * Sobrecarga del flujo de salida
     * @param salida, el flujo de salida
     * @param el conjunto que será mostrado por pantalla
     * @return el flujo de salida con los datos del conjunto añadidos para ser mostrados por pantalla
     */
    friend ostream& operator<<(ostream& salida, const Particula& part);
    
    /**
     * Metodo auxiliar que realiza el intercambio de valores entre dos variables
     * @param valor, un dato a ser intercambiado
     * @param otroValor, otro dato con el que se intercambiará
     */
    void Intercambiar(float& valor, float& otroValor);
    
    /**
     * Simula un movimiento de la Particula en la ventana de ejecución
     * @param ancho, el limite de ancho de la ventana donde la Particula se mueve
     * @param alto, el limite de alto de la ventana donde la Particula se mueve
     */
    void MoverArknoid(int ancho, int alto, int& muertes);
    
    /**
     * Simula el choque entre la particula y la base
     * @param otra, la base con la que choca
     * @param valorAncho, será el tamaño que deberá comparar en ancho para saber si hace un rebote a izquierda o derecha
     * @pre se ha producido una colisión con la particula recibida
     */
    void RebotaArkanoid(Particula& otra, const int& valorAncho);
    
};


#endif /* PARTICULA_H */