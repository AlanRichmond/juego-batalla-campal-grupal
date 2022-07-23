#include "Casilla.h"

Casilla::Casilla(unsigned int x,unsigned int y,unsigned int z,TipoDeCasilla tipo,Ficha * ficha){
	if(x < 1){
		throw "X debe ser mayor o igual a 1";
	}
	if(y < 1){
		throw "Y debe ser mayor o igual a 1";
	}
	if(z < 1){
		throw "Z debe ser mayor o igual a 1";
	}

	this->x = x;
	this->y = y;
	this->z = z;
	this->estado = Vacia;
	this->tipo = tipo;
	this->ficha = ficha;
}

Casilla::~Casilla() {

}

EstadoDeCasilla Casilla::getEstado() const {
	return estado;
}

void Casilla::setEstado(EstadoDeCasilla estado) {
	this->estado = estado;
}

TipoDeCasilla Casilla::getTipo() const {
	return tipo;
}

unsigned int Casilla::getX() const {
	return x;
}

unsigned int Casilla::getY() const {
	return y;
}

unsigned int Casilla::getZ() const {
	return z;
}

Ficha * Casilla::getFicha(){
	return ficha;
}

void Casilla::setFicha(Ficha * ficha){
	if(ficha == NULL){
		throw "La ficha no puede estar vacia.";
	}
	this->ficha = ficha;
	this->estado = Ocupada;
}

void Casilla::vaciar(){
	this->estado = Vacia;
	this->ficha = NULL;
}

void Casilla::destruir(){
	this->estado = Inactiva;
	this->ficha = NULL;
}

void Casilla::setTipo(TipoDeCasilla tipo) {
	this->tipo = tipo;
}

bool Casilla::estaOcupado(){
	return (this->estado == Ocupada);
}
