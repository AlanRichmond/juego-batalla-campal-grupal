#include "Jugador.h"

Jugador::Jugador(unsigned int numero, std::string nombre) {
	this->numero = numero;
	this->nombre = nombre;
	this->fichas  = new Lista<Ficha *>;
}

Jugador::~Jugador() {
	delete this->fichas;

}

std::string& Jugador::getNombre() {
	return this->nombre;
}

unsigned int Jugador::getNumero()  {
	return this->numero;
}

Lista<Ficha*> * Jugador::getFichas(){
	return this->fichas;
}

void Jugador::agregarFicha(Ficha* ficha){
	if(ficha == NULL){
		throw "La ficha debe existir";
	}
	this->fichas->agregar(ficha, 1);
}	


void Jugador::eliminarFicha(Ficha* ficha){
	if(ficha == NULL){
		throw "La ficha debe existir";
	}
	unsigned int pos = 0;
	this->fichas->iniciarCursor();
	while(this->fichas->avanzarCursor()){
		pos++;
		if(this->fichas->obtenerCursor() == ficha){
			this->fichas->remover(pos);
		}	
	}
}

bool  Jugador::tieneLaFicha(TipoDeFicha tipo){
	this->fichas->iniciarCursor();
	while(this->fichas->avanzarCursor()){
		if(this->fichas->obtenerCursor()->getTipo() == tipo){
			return true;
		}
	}
	
	return false;
}

unsigned int Jugador::cantidadDeLaFicha(TipoDeFicha tipo){
	unsigned int contador = 0;
	this->fichas->iniciarCursor();
	while(this->fichas->avanzarCursor()){
			if(this->fichas->obtenerCursor()->getTipo() == tipo){
				contador++;
			}
	}

	return contador;
}

