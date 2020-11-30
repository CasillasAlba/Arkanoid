/**
  *
  * @author Alba Casillas Rodriguez - 76738108B
  * @author Jose Manuel Osuna Luque - 20224440B
  * Grupo de Practica D1 (Martes)
  * @date Mayo 2019
  */

#ifndef CONJUNTOPARTICULAS_H
#define CONJUNTOPARTICULAS_H

#include "Particula.h"
#include <cstring>

using namespace std;
using namespace miniwin;

const int TAM_BLOQUE = 5;


class ConjuntoParticulas{
    
private:
    
    Particula* set; //Array de particulas
    int capacidad;  //Capacidad del Array
    int utiles;     //Posiciones ocupadas
    bool movil;     //Indica si el conjunto tiene particulas moviles o fijas
    
    /**
     * Metodo Auxiliar para reservar memoria en el Array de Particulas de la clase
     * @param capacidadC, la nueva capacidad
     */
    void ReservaMemoria(int capacidadC);
    
    /**
     * Metodo auxiliar para liberar la memoria ocupada por el Array de Particulas de la clase
     */
    void LiberaMemoria();
    
    /**
     * Metodo Auxiliar usado para copiar un Array de Particulas en otro (Se usa en el constructor de copia)
     * @param otro, el objeto de la clase Conjunto Particula que tiene el array
     */
    void CopiarDatos(const ConjuntoParticulas& otro);
    
    /**
     * Metodo Auxiliar para dotar de un nuevo tamaño al Array de Particulas de la clase
     * @param nuevaCapacidad
     */
    void Redimensionar(int nuevaCapacidad);
    
public:
    
    /**
     * Constructor por Defecto de la clase Conjunto Particulas
     */
    ConjuntoParticulas();
    
    /**
     * Constructor por Parámetros de la clase Conjunto Particulas
     * @param capacidadC, la memoria que se reservará para el array de Particulas
     */
    ConjuntoParticulas(int capacidadC);
    
    /**
     * Constructor por Parametros de la clase Conjunto Particulas
     * @param capacidadC, la memoria que se reservará para el array de particulas
     * @param m, bool que indica si el conjunto tendrá particulas moviles o fijas
     */
    ConjuntoParticulas(int capacidadC, bool m);
    
    /**
     * Constructor de Copia
     * @param otro, es un objeto de la clase Conjunto Particula que será copiado
     */
    ConjuntoParticulas(const ConjuntoParticulas& otro);
    
    /**
     * Destructor de la clase Conjunto Particulas
     */
    ~ConjuntoParticulas();
    
    
    //Metodos GET para la consulta
    
    /**
     * Consultor del Array de Particulas de la clase
     * @return el array de Particulas de la clase, constante
     */
    const Particula* getParticulas() const;
    
    /**
     * Consultor de la capacidad total de Array de Particulas de la clase
     * @return un entero con el valor de la capacidad
     */
    const int& getCapacidad() const;
    
    /**
     * Consultor de la cantidad de espacio util del Array de Particulas de la clase
     * @return un entero que indica el valor real que está siendo usado del Array
     */
    const int& getUtiles() const;
    
    /**
     * Consultor del tipo de particulas del conjunto, moviles o fijas
     * @return TRUE si son moviles, FALSE si son fijas
     */
    const bool& getMovil() const;
    
    /**
     * Modificador del tipo de particulas del conjunto, moviles o fijas
     * @param nuevoMovil, TRUE si son moviles, FALSE si son fijas
     */
    void setMovil(const bool& nuevoMovil);
    
    //Metodos
    
    /**
     * Agrega una particula nueva al Conjunto de Particulas, al array de la clase. Redimensiona el Array de no tener espacio suficiente
     * @param pa, la nueva Particula que será añadida
     */
    void AgregaParticula(const Particula& pa);
    
    /**
     * Borra la Particula que se encuentre en la posición del parámetro del Array del Conjunto de Particulas
     * @param pos
     * @pre el valor de pos debe ser correcto
     */
    void BorrarParticula(int pos);
    
    /**
     * Devuelve la Particula que se encuentre en la posición indicada en el Array de Particulas de la clase
     * @param pos, un entero indicando la posición
     * @return La Particula en cuestión de dicha posición
     * @pre el valor del entero pos debe ser un valor correcto
     */
    Particula ObtieneParticula(int pos) const;
    
    /**
     * Devuelve la Particula que se encuentre en la posición indicada en el Array de Particulas de la clase (Permite Modificacion)
     * @param pos, un entero indicando la posición
     * @return La Particula en cuestión de dicha posición
     * @pre el valor del entero pos debe ser un valor correcto
     */
    Particula& ObtieneParticula(int pos);
    
    /**
     * Cambia la particula en cuestión de la posición por otra recibida por parámetro
     * @param otra, es la Particula que será intercambiada por la existente
     * @param pos, un entero que indica la posición de la Particula que se quiere reemplazar
     * @pre el valor de la posicion debe ser correcto
     */
    void ReemplazaParticula(int pos, const Particula& otra);
    
    /**
     * Simula un movimiento de las todas las Particulas incluidas en el Array de Particulas de la clase
     * @param ancho es el límite de anchura de la ventana en la que se moverán las particulas
     * @param alto es el limite de altura de la ventana en la que se moverán las particulas
     */
    void Mover(int ancho, int alto);
    
    /**
     * Controla si alguna de las Particulas del conjunto, al moverse, ha colisionado con otra del conjunto
     */
    void GestionarColisiones();
    
    //Sobrecarga de Operadores
    
    /**
     * Sobrecarga del operador asignación
     * @param nuevo, es el Conjunto Particula que contiene los datos que serán asignados a la clase
     * @return el propio objeto modificado
     */
    ConjuntoParticulas& operator=(const ConjuntoParticulas & nuevo);
    
    /**
     * Sobrecarga del operador suma
     * @param conjuntoP1, que contendrá los datos que se añadiran al objeto que invoca el operador
     * @return el propio objeto invocador con las particulas del otro Conjunto añadidas
     */
    ConjuntoParticulas operator +(const ConjuntoParticulas &conjuntoP1) const;
    
    /**
     * Sobrecarga del flujo de salida
     * @param salida, el flujo de salida
     * @param el conjunto que será mostrado por pantalla
     * @return el flujo de salida con los datos del conjunto añadidos para ser mostrados por pantalla
     */
    friend ostream& operator<<(ostream& salida, const ConjuntoParticulas& conj);
   
    void gestionarTablero();
    
};

#endif /* CONJUNTOPARTICULAS_H */

