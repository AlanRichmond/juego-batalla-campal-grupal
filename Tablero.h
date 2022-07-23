#ifndef TABLERO_H_
#define TABLERO_H_

#include <iostream>
#include "Vector.h"
#include "Casilla.h"
#include "Lista.h"
#include "Ficha.h"


class Tablero {
private:

	Lista<Lista<Lista< Casilla *> *> *> * casilleros;
	unsigned int xMaximo;
	unsigned int yMaximo;
	unsigned int zMaximo;


public:
	//PRE: Las dimenciones deben ser mayores o iguales a 1.
	//POST: Crea un tablero con las dimensiones dadas, con todos los casilleros vacios.
	Tablero(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo);

	//PRE:
	//POST: Elimina el tablero.
	virtual ~Tablero();

	//PRE: Las dimensiones deben ser mayores o iguales a 1 y menores o iguales al maximo.
	//POST: Devuelve el casillero indicado.
	Casilla * getCasillero(unsigned int x, unsigned int y, unsigned int z);
	
	//PRE: -
	//POS: Devuelve verdadero si la coordenada indicada esta en el rango entre 1 y los maximos.
	bool existeElCasillero(unsigned int x, unsigned int y, unsigned int z);
	
	//PRE: -
	//POS: Devuelve la posicion del X entre 1 y el maximo
	Lista<Lista<Lista<Casilla *> *> *> * getCasilleros();
	
	//PRE: -
	//POS: Devuelve la posicion del X entre 1 y el maximo
	int getxMaximo();

	//PRE: -
	//POS:Devuelve la posicion del Y entre 1 y el maximo
	int getyMaximo();

	//PRE: -
	//POS: Devuelve la posicion del Z entre 1 y el maximo
	int getzMaximo();

private:
	//PRE: -
	//POST: Si los valores no son correctos tira una excepcion.
	void validarRango(unsigned int x, unsigned int y, unsigned int z);

};

#endif
