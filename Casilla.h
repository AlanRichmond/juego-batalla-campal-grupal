#ifndef CASILLA_H_
#define CASILLA_H_

#include <iostream>
#include "Ficha.h"



enum EstadoDeCasilla{
	Vacia,
	Inactiva,
	Ocupada
};

enum TipoDeCasilla{
	Tierra,
	Agua,
	Aire,
	Fuego,
	General
};

class Casilla{
private:
	EstadoDeCasilla estado;
	TipoDeCasilla tipo;
	unsigned int x;
	unsigned int y;
	unsigned int z;
	Ficha * ficha;


public:
	//PRE: x y z deben ser mayores o iguales a 1.
	//POST: Crea el casillero en esa posicion y ese tipo, y el estado es Vacio.
	Casilla(unsigned int x,unsigned int y,unsigned int z, TipoDeCasilla tipo,Ficha * ficha);

	//PRE: -
	//POST: Elimina la casilla.
	virtual ~Casilla();

	//PRE:
	//POST:	Devuelve el estado actual.
	EstadoDeCasilla getEstado() const;

	//PRE: -
	//POST: Cambia el estado de la casilla actual.
	void setEstado(EstadoDeCasilla estado);

	//PRE: -
	//POST: Devuelve el tipo de casillero actual.
	TipoDeCasilla getTipo() const;


	//PRE:
	//POST: Devuelve la posicion del X entre 1 y el maximo
	unsigned int getX() const;

	//PRE:
	//POST: Devuelve la posicion del Y entre 1 y el maximo
	unsigned int getY() const;

	//PRE:
	//POST: Devuelve la posicion del Z entre 1 y el maximo
	unsigned int getZ() const;

	//PRE: -
	//POST: Devuelve la ficha del casillero actual.
	Ficha * getFicha();

	//PRE: La ficha no esta vacia.
	//POST: Cambia la ficha del casillero actual.
	void setFicha(Ficha * ficha);

	//PRE: la casilla debe existir.
	//POST: Deja vacia la casilla actual.
	void vaciar();
	
	//PRE: La casilla debe existir 
	//POST: Deja inactiva la casilla y deja la ficha en NULL
	void destruir();

	//PRE: La casilla debe estar creada
	//POST: Cambiara el tipo de casilla.
	void setTipo(TipoDeCasilla tipo);

	//PRE: Debe existir la casilla
	//POST: Devolvera True si la casilla esta ocupada, false de lo contrario.
	bool estaOcupado();
};

#endif
