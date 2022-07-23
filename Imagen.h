#ifndef IMAGEN_H_
#define IMAGEN_H_

#include "imagen/EasyBMP.h"
#include "Vector.h"
#include "Casilla.h"
#include "Lista.h"
#include "Ficha.h"
#include "Jugador.h"
#include "Tablero.h"

class Imagen {
private:
 
  BMP background; 
  BMP inactiva;
  BMP avion; 
  BMP barco;
  BMP soldado;
  BMP estado;
  
  //PRE: La imagen background debe estar definida. 
  //POST: Determina la medida de la imagen estado. 
  void medidaDeEstado();
  
  //PRE: Debe estar definida la medida de la imagen estado.
  //POST: Agrega la imagen background a la imagen estado.
  void agregarFondoAEstado();
  
  //PRE: La imagen background debe estar agregada a la imagen estado.
  //POST: Agrega imagen avion a los planos ZX y ZY  de la imagen estado en esas coordenadas. 
  void agregarAvionAEstado(int coordenadaX, int coordenadaY, int coordenadaZ);
  
  //PRE: La imagen background debe estar agregada a la imagen estado.
  //POST: Agrega imagen barco al plano XY de la imagen estado en esas coordenadas.
  void agregarBarcoAEstado(int coordenadaX, int coordenadaY);
  
  //PRE: La imagen background debe estar agregada a la imagen estado.
  //POST: Agrega imagen soldado al plano XY de la imagen estado en esas coordenadas.
  void agregarSoldadoAEstado(int coordenadaX, int coordenadaY);
  
  //PRE: La imagen background debe estar agregada a la imagen estado.
  //POST: Agrega imagen inactiva al plano XY o a los planos ZX y ZY en el caso de haber 
  //un avion antes en esas coordenadas en la imagen estado.
  void agregarInactivaAEstado(int coordenadaX, int coordenadaY, int coordenadaZ);
  
  //PRE: Debe existir un tablero y un jugador. 
  //POST: Recorre el tablero. 
  void recorrerTablero(Tablero * tablero, Jugador * jugador);
  
  //PRE: Debe existir la lista casillas y un jugador. 
  //POST: Recorre la lista casillas. 
  void recorrerPlanoXY(Lista<Lista<Casilla *> *> *casillas, Jugador * jugador);
  
  //PRE: Debe existir la lista casillas y un jugador. 
  //POST: Recorre cada casilla y segun esta determina si agregar alguna imagen a imagen estado. 
  void recorrerCasilla(Lista<Casilla *>* casillas, Jugador * jugadorActual);
  
  //PRE: Debe existir una casilla. 
  //POST: Agrega la imagen (acorde a la ficha de la casilla) a la imagen estado.
  void chequearFicha(Casilla * casilla);

public:
  
  //PRE: - 
  //POST: -
  Imagen();
 
  //PRE: - 
  //POST: Libera los recursos.
  ~Imagen();
 
  //PRE: -
  //POST: Define que imagen va a ser imagen background.
  void definirMapa(std::string background); 
  
  //PRE: Debe existir un tablero y un jugador.
  //POST: Devuelve la imagen estado del tablero de la perspectiva del jugador.
  void obtenerEstadoTablero(Tablero * tablero,Jugador * jugador);
  
};

#endif
