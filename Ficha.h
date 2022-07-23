#ifndef FICHA_H_
#define FICHA_H_



enum TipoDeFicha{
	FSoldado,
	FAvion,
	FBarco
};
enum EstadoDeFicha{
	Eliminada,
	Activa
};


class Ficha {
private:
	TipoDeFicha tipo;
	unsigned int jugador;
	EstadoDeFicha estado;

public:

	//PRE: Jugador no puede ser vacio.
	//POST: Crea la ficha con el tipo y el jugador.
	Ficha(TipoDeFicha tipo, unsigned int jugador,EstadoDeFicha estado);

	//PRE: -
	//POST: Elimina la ficha.
	virtual ~Ficha();

	//PRE: -
	//POST: Devuelve en el estado que esta la ficha
	EstadoDeFicha getEstado();

	//PRE: -
	//POST: Cambia el estado de la casilla.
	void setEstado(EstadoDeFicha estado);

	//PRE: -
	//POST: Elimina la ficha.
	void eliminar();

	//PRE: Debe existir el jugador 
	//POST: Retorna el jugador actual.
	unsigned int getJugador();

	//PRE: El jugador tiene que ser mayor a 0.
	//POST: Cambia al jugador
	void setJugador(unsigned int jugador);

	//PRE:-
	//POST: Devuelve el tipo
	TipoDeFicha getTipo();

};
#endif
