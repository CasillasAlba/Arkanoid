/**
  * 
  * @author Alba Casillas Rodriguez - 76738108B
  * @author Jose Manuel Osuna Luque - 20224440B
  * Grupo de Practica D1 (Martes)
  * @date Abril 2019
  */

#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include "miniwin.h"

#define length(x) (sizeof(x)/sizeof(x[0]))

using namespace miniwin;
using namespace std;

const int UMBRAL = 15;
const int MAX_X = 800;
const int MAX_Y = 600;
const int MAX_VEL = 5;
const int RADIO = 10;
const int REC_DERECHA = 30;
const int REC_ABAJO = 15;
const int DESPLAZAMIENTO = 25;
const float VELOCIDAD_ARKANOID = 6;
const int FILAS_ARKANOID = 4;
const int ANCHO_ARKANOID = 50;
const int ALTO_ARKANOID = 25;
const int VIDAS = 20;
const float FACTOR_BLOQUE = 2.3;
const float FACTOR_BASE = 2.0;
const float FACTOR_FIJA = 1.8;

const Color GAMA[] = {ROJO, VERDE, AZUL, AMARILLO, MAGENTA, CYAN, BLANCO};
const int DISPONIBLES = (int) length(GAMA);

#endif /* DEFINICIONES_H */
