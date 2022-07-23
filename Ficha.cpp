#include "Ficha.h"

Ficha::Ficha(TipoDeFicha tipo, unsigned int jugador, EstadoDeFicha estado){
	if(jugador == 0){
		throw "El jugador no puede estar vacio";
	}
	this->tipo = tipo;
	this->jugador = jugador;
	this->estado = estado;
}

Ficha::~Ficha() {

}

EstadoDeFicha Ficha::getEstado()  {
	return this->estado;
}

void Ficha::setEstado(EstadoDeFicha estado) {
	this->estado = estado;
}

void Ficha::eliminar(){
	if(this->estado == Eliminada){
		throw "la ficha ya esta eliminada";
	}
	this->estado = Eliminada;
}

unsigned int Ficha::getJugador(){
	return this->jugador;
}

void Ficha::setJugador(unsigned int jugador) {
	this->jugador = jugador;
}

TipoDeFicha Ficha::getTipo(){
	return this->tipo;
}

