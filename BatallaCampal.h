#ifndef BATALLACAMPAL_H_
#define BATALLACAMPAL_H_

#include <iostream>
#include <cstdlib>  /* Aqui estan contenidas  las funciones rand y srand */
#include <ctime> /* de aqui  haremos uso de la función time para obtener un indicador 
del tiempo actual del sistema, pese a que este cambia de segundo a segundo la semilla también cambiara */


#include "Tablero.h"
#include "Jugador.h"
#include "Lista.h"
#include "Vector.h"
#include "Imagen.h"

const unsigned int MAXIMO_TABLERO_X = 15;
const unsigned int MAXIMO_TABLERO_Y = 15;
const unsigned int MAXIMO_TABLERO_Z = 5;

const unsigned int MINIMO_DE_JUGADORES = 2;
const unsigned int MAXIMO_DE_JUGADORES = 4;

const unsigned int NUM_MAPA_MAXIMO = 3;
const unsigned int SOLDADOS_INICIALES = 3;


enum TiposDeCartas{
	Avion,
	Barco,
	Misil,
	OtroTurno,
	OtroSoldado,
	RondaSinCartas,
	EnBlanco
};
	

class BatallaCampal {
private:
	Tablero * tablero;
	Lista <Jugador *> * jugadores;
	unsigned int cantidadDeJugadores;
	unsigned int numeroDeMapa;
	Imagen imagen;

public:

	//PRE:-
	//POST: Inicializa el tablero en NULL y los jugadores en NULL
	BatallaCampal();

	//PRE: - 
	//POST: Elimina el tablero, los jugadores y la batalla campal.
	virtual ~BatallaCampal();
	
	//PRE: -
	//POST: Pedira la cantidad de jugadores, sus nombres, los inicializa en una lista y pide el numero de mapa.
	void menuDeJuego();
	
	//PRE:-
	//POST: Inicia el tablero en el escenario 1 pre configurado con sus maximos.
	void iniciarEscenarioUno(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo);

	//PRE:-
	//POST: Inicia el tablero en el escenario 2 pre configurado con sus maximos.
	void iniciarEscenarioDos(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo);
	
	//PRE:-
	//POST: Inicia el tablero en el escenario 3 pre configurado con sus maximos.
	void iniciarEscenarioTres(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo);
	
	//PRE:-
	//POST: Inicializa los soldados de los jugadores.
	void inicializarSoldados();
	
	
	
	//PRE: -
	//POST: Se ejecuta todas las funciones de batallaCampal.
	void jugar();
	
	//PRE: El jugador debe estar vivo.
	//POST: Se juega el turno completo de cada jugador, segun las reglas del juego.
	void jugarTurno(Jugador * jugador, bool castarActivadas);
	
	//PRE: -
	//POST: Se juegan cantidad de turnos como jugadores vivos queden.
    void jugarRonda(bool castarActivadas);
	
	
	
	// PRE: Debe existir una ficha.
	// POS: Devuelve la ficha que se ubica en la posicion que se pasa por parametro.
	Ficha * obtenerFicha( unsigned int x, unsigned int y, unsigned int z);
	
	//PRE: Debe existir la casilla 
	//POST: Devuelve el estado en el que se encuentra la casilla que se pasa por parametro.
	EstadoDeCasilla obtenerEstadoDeCasilla(unsigned int x, unsigned int y, unsigned int z);
	
	//PRE: Debe existir la casilla 
	//POST: Devuelve el tipo de casilla que se pasa por parametro.
	TipoDeCasilla obtenerTipoDeCasilla(unsigned int x, unsigned int y, unsigned int z);	

	//PRE: el numero de jugador debe ser mayor a 0.
	//POST: Obtiene el jugador cuyo numero es pasado por parametro.
	Jugador * obtenerJugador(unsigned int numeroDeJugador);
	
	//PRE: Debe existir un jugador y las coordenadas validas. 
	//POST: Devolvera true si hay un soldado en las posiciones pasadas por parametro, false si no hay un soldado. 
	bool tieneUnSoldado(Jugador * jugador, unsigned int x, unsigned int y, unsigned int z);

	
	
	//PRE: -
	//POST: Pide por consola una coordenada (x,y,z) y la retorna como vector dinamico.
	Vector<unsigned int> * pedirCoordenadas();
	
	//PRE: Debe existir el jugador y tener minimo un soldado en el tablero. 
	//POS:Pide al jugador las coordenadas donde se ubica uno de sus soldados para seleccionar el soldado que quiere mover.
	Vector<unsigned int> * pedirOrigenDelMovimiento(Jugador *jugador);

	//PRE: Debe existir el jugador.
	//POST: Se le pedira al jugador que ingrese coordenadas donde desee mover su jugador, comparara la posicion si hay otro soldado,
	//      si la casilla no es tierra y si la casilla no esta inactiva, retorta el destino del soldado.
	Vector<unsigned int> * pedirDestinoDelSoldado(Jugador *jugador);

	//PRE: Debe existir el jugador
	//POST: Pedira al jugador coordenadas para mover sus fichas. 
	Vector<Vector<unsigned int> *> * pedirMovimiento(Jugador *jugador);

	//PRE: -
	//POST: Destruira las coordenadas que se les pase por consola el jugador.
	void destruirCoordenadasDelMovimiento(Vector<Vector<unsigned int> *> * coordenadas);

	//PRE: -
	//POST: Coloca un soldado en un posicion valida, fijandose si hay otro soldado propio o enemigo.
	void colocarSoldado(Ficha * ficha, Vector<unsigned int> * posicion);
	
	//PRE: -
	//POST: movera el soldado elegido por el jugador a una casilla destino, verifica si la casilla esta ocupada o no.
	void mover(Vector<Vector<unsigned int> *> * coordenadasOrigenYDestino);
	
	//PRE: Recibe coordendas en donde se ubica el soldado del jugador y las coordendas de la casilla a la que se lo quiere mover.
	//POST: Compara si las coordendas destino estan a una casilla de distancia de las coordenadas origen que son las del soldado.
	bool movimientoCercano(Vector<unsigned int> * origen, Vector<unsigned int> * destino);

	
	
	//PRE: El jugador tiene que estar en juego.
	//POST:Pedira coordenadas (x,y,z) para que el jugador dispare y si la casilla no esta Vacia, eliminara una ficha del jugador contrario,
	//      destruira la casilla si es tierra dejandola inactiva, de lo contrario la vaciara.
	void disparar(Jugador * jugador);
	
	//PRE: La coordenada debe ser valida dentro de los maximos del tablero
	//POST: Devuelve true si la posicion no esta en los bordes del tablero, false de lo contrario.
	bool posicionDeMisilValida(Vector<unsigned int> * posicion);
	
	//PRE: -
	//POST: Lanzara un misil que destruye 27 casilleros en el tablero (3x3x3).
	void lanzarMisil(Jugador * jugador);
	
	//PRE: -
	//POST: Pedira al jugador coordenadas (x,y,z) para ubicar su Avion, solo se puede ubicar en una casilla que sea del tipo Aire, y si hay un
	//      Avion contrario se eliminan los dos Aviones.
	void colocarAvion(Jugador * jugador);
	
	//PRE: -
	//POST: Pedira al jugador coordenadas (x,y,z) para ubicar su Barco, solo se puede ubicar en una casilla que sea del tipo Agua, y si hay un
	//      Barco contrario se eliminan los dos Barcos.
	void colocarBarco(Jugador * jugador);
	
	//PRE: -
	//POST: El jugador sacara una carta al finalizar el turno y se llamara a la funcion correspondiente a la carta que salga.
	void sacarCarta(Jugador * jugador);
	
	
	
	//PRE: -
	//POST: Devolvera true si el jugador actual se queda sin soldados en el tablero.
	bool estaMuerto(Jugador * jugador);

	//PRE: -
	//POST: Retorta true si queda un solo jugador en el juego, de lo contrario false.
	bool juegoTerminado();
	

	
	//PRE: -
	//POST: Devuelve imagen del tablero segun el jugador actual. 
	void mostrarEstadoTablero(Jugador * jugador);

};

#endif
