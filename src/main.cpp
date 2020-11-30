/**
  * 
  * @author Alba Casillas Rodriguez - 76738108B
  * @author Jose Manuel Osuna Luque - 20224440B
  * Grupo de Practica D1 (Martes)
  * @date Mayo 2019
  * MAIN ENTREGADO POR EL PROFESOR
  */

#include "miniwin.h"
#include <ctime>
#include <iostream>
#include "Particula.h"
#include "definiciones.h"
#include "ConjuntoParticulas.h"
#include "Simulador.h"

using namespace miniwin;
using namespace std;

void pintaNube(const ConjuntoParticulas & miConjunto) {
    int N = miConjunto.getUtiles();
    Particula p;
    for (int i = 0; i < N; i++) {
        p = miConjunto.ObtieneParticula(i);
        color(p.getColor());
        circulo_lleno(p.getX(), p.getY(), RADIO);
    }

}

//FUNCION PROPIA PARA ARKANOID
void moverBase(Particula& base, const int ancho){
    int t = tecla();
    
    
    if(t != NINGUNA){
        
        int parteDerecha = (base.getX()+(REC_DERECHA/2))+DESPLAZAMIENTO;
        int parteIzquierda = (base.getX()-(REC_DERECHA/2))-DESPLAZAMIENTO;
    
        if (t == DERECHA && parteDerecha < ancho) {
        
            base.setX(base.getX()+DESPLAZAMIENTO);

        }else{

            if(t == IZQUIERDA && parteIzquierda > 0){
                base.setX(base.getX()-DESPLAZAMIENTO);
            }
        }
    
    }
    
}

//FUNCION PROPIA PARA ARKANOID
void pintarObjetos(Particula& pelota, Particula& base, const int ancho, const int alto, int& muertes){
    if(pelota.Colision(base, FACTOR_BASE)){
        int anchoBase = REC_DERECHA/2;
        pelota.RebotaArkanoid(base, anchoBase);
    }
    pelota.MoverArknoid(ancho, alto, muertes);
    
    color(pelota.getColor());
    circulo_lleno(pelota.getX(), pelota.getY(), RADIO);
    moverBase(base, ancho);
    color_rgb(255,131,168);
    rectangulo_lleno(base.getX()-(REC_DERECHA/2), base.getY()-(REC_ABAJO/3), base.getX()+(REC_DERECHA/2), base.getY()+(REC_ABAJO/3));
}

//FUNCION PROPIA PARA ARKANOID
void pintaBloques(const ConjuntoParticulas& bloques) {
    Particula p;
    
    for (int i = 0; i < bloques.getUtiles(); i++) {
      
        p = bloques.ObtieneParticula(i);
        color(p.getColor());
        
        rectangulo_lleno(p.getX(), p.getY(), p.getX()+(ANCHO_ARKANOID), p.getY()+(ALTO_ARKANOID/2));
      
    }

}

//FUNCION PROPIA PARA ARKANOID
void rebotesBloques(ConjuntoParticulas& bloques, Particula& pelota){
    
    for(int b=0; b<bloques.getUtiles(); b++){
        
        if(pelota.Colision(bloques.ObtieneParticula(b), FACTOR_BLOQUE)){
            pelota.RebotaArkanoid(bloques.ObtieneParticula(b), ANCHO_ARKANOID);
            bloques.BorrarParticula(b);
        }
        
    }
    
}

//FUNCION PROPIA PARA ARKANOID
void iniciar(Particula& pelota, Particula& base, const int ancho, const int alto){
    pelota.setDx(VELOCIDAD_ARKANOID/2);
    pelota.setDy(VELOCIDAD_ARKANOID);
    pelota.setColor(MAGENTA);
    pelota.setX(ancho/2); //Establece la coordenada X en el centro de la pantalla
    pelota.setY(alto/2); //Establece la coordenada Y en el centro de la pantalla
    circulo_lleno(pelota.getX(), pelota.getY(), RADIO);

    color_rgb(255,131,168);
    base.setX(ancho/2);
    base.setY(alto-20);
    rectangulo_lleno(base.getX()-(REC_DERECHA/2), base.getY()-(REC_ABAJO/3), base.getX()+(REC_DERECHA/2), base.getY()+(REC_ABAJO/3));
}

int main() {
    
    srand(time(0));

    int ancho = 800;
    int alto = 600;

    int opcion;

    cout << "\n  Opcion a probar: ";
    cin >> opcion;

    switch (opcion) {

        case 1:
        {
            cout << "\n** Prueba sobrecarga de operadores **" << endl;
            //vredimensiona(100, 100);
            ConjuntoParticulas a1, b1(4);
            cout << b1 << endl;

            Particula x;
            a1.AgregaParticula(x);
            x.Mover(ancho, alto);
            a1.AgregaParticula(x);
            cout << a1 << endl;

            b1.Mover(ancho, alto);
            a1 = a1 + b1;
            cout << a1 << endl;

            ConjuntoParticulas cc = a1 + b1;
            ConjuntoParticulas xx(cc);
            cout << xx << endl;
            cout << endl;
            vcierra();

            break;
        }

        case 2:
        {
            cout << "\n** Prueba Conjunto Particulas ** " << endl;
            int NRO = 20;
            vredimensiona(ancho, alto);
            ConjuntoParticulas rojas(NRO);
            ConjuntoParticulas verdes(NRO);
            ConjuntoParticulas blancas;
            Particula p;

            for (int i = 0; i < NRO; i++) {
                p = rojas.ObtieneParticula(i);
                p.setColor(ROJO);
                rojas.ReemplazaParticula(i, p);

                p = verdes.ObtieneParticula(i);
                p.setColor(VERDE);
                verdes.ReemplazaParticula(i, p);
            }
            
            ConjuntoParticulas aux;
            for (int i = 0; i < 200; i++) {
                rojas.Mover(ancho, alto);
                verdes.Mover(ancho, alto);
                blancas.Mover(ancho, alto);
                
                aux = rojas + verdes + blancas;
                
                borra();
                pintaNube(aux);
                if (i % 10 == 0) {
                    Particula p;
                    p.setColor(BLANCO);
                    blancas.AgregaParticula(p);
                    rojas.BorrarParticula(rand() % rojas.getUtiles());
                    verdes.BorrarParticula(rand() % verdes.getUtiles());
                    
                }

                refresca();
                espera(35);
                
            }
            vcierra();

            break;
        }

        case 3:
        {
            cout << "\n**************  Probando Simulador ****************\n";
            ConjuntoParticulas base(30, true);
            ConjuntoParticulas otro(10, false);
            int contador = 0;

            Simulador game(base, otro, ancho, alto);

            while (contador < 500) {
                game.Step();
                game.Pintar(30);
                //Opcion elegida NUEVA PARTICULA FIJA/MOVIL
                game.IncluirConTecla();
                contador++;
            }
            break;
        }
        
        case 4:
        {
            
        cout << "\n**************  Probando Arkanoid ****************\n";
        ancho = 600;
        alto = 400;
        vredimensiona(ancho, alto);
        
        Particula pelota;
        
        
        Particula base(false);
        
        iniciar(pelota, base, ancho, alto);
        
        int nBloques = (ancho/(ANCHO_ARKANOID+5))*FILAS_ARKANOID;
        
        ConjuntoParticulas bloques(nBloques, false);
        
        bloques.gestionarTablero();
        
        refresca();
        int muertes = 0;
                
        int inicio = tecla();
        
        while(inicio != RETURN){
            inicio = tecla();
        }
        
        while (bloques.getUtiles() > 0 && muertes < VIDAS) {
            borra();
            pintaBloques(bloques);
            pintarObjetos(pelota, base, ancho, alto, muertes);
            rebotesBloques(bloques, pelota);
            refresca();
            espera(35);
            
        }
        borra();
        pintarObjetos(pelota, base, ancho, alto, muertes);
        refresca();
        vcierra();
        
        if(muertes == VIDAS){
            cout << "Has muerto demasiado" << endl;
        }else{
            cout << "Genial, has ganado!" << endl;
        }
        
        break;

        }

    };

    return 0;
}
