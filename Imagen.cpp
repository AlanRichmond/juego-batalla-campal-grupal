#include "Imagen.h"
#include <string>

using namespace std; 
Imagen::Imagen(){
    this->inactiva.ReadFromFile("src/imagen/inactiva.bmp");
    this->avion.ReadFromFile("src/imagen/avion.bmp");
    this->barco.ReadFromFile("src/imagen/barco.bmp");
    this->soldado.ReadFromFile("src/imagen/Soldado.bmp");
    this->estado.SetBitDepth(24);
}

Imagen::~Imagen(){
}

void Imagen::medidaDeEstado(){
  this->estado.SetSize( this->background.TellWidth(), this->background.TellHeight()); 
}
 
void Imagen::agregarFondoAEstado(){
  RangedPixelToPixelCopy(this->background,0,this->background.TellWidth(),
                         this->background.TellHeight(),0,
                         this->estado,0,0); 
}

void  Imagen::agregarAvionAEstado(int coordenadaX, int coordenadaY, int coordenadaZ){
		RangedPixelToPixelCopyTransparent( this->avion, 0, this->avion.TellWidth(),
						this->avion.TellHeight(), 0,this->estado, 1070 - coordenadaZ*40,
						43 + coordenadaX*40,*this->avion(0,0) );

		RangedPixelToPixelCopyTransparent( this->avion, 0, this->avion.TellWidth(),
						this->avion.TellHeight(), 0,this->estado, 76 + coordenadaY*40,
						1035 - coordenadaZ*40,*this->avion(0,0) );
}

void  Imagen::agregarSoldadoAEstado(int coordenadaX, int coordenadaY){
		RangedPixelToPixelCopyTransparent( this->soldado, 0, this->soldado.TellWidth(),
						this->soldado.TellHeight(), 0,this->estado, 76 + coordenadaY*40,
						45 + coordenadaX*40,*this->soldado(0,0) );
}

void  Imagen::agregarBarcoAEstado(int coordenadaX, int coordenadaY){
		RangedPixelToPixelCopyTransparent( this->barco, 0, this->barco.TellWidth(),
						this->barco.TellHeight(), 0,this->estado, 76+ coordenadaY*40,
						45 + coordenadaX*40,*this->barco(0,0) );
}

void  Imagen::agregarInactivaAEstado(int coordenadaX, int coordenadaY, int coordenadaZ){
	if (coordenadaZ == 1){
		RangedPixelToPixelCopyTransparent( this->inactiva, 0, this->inactiva.TellWidth(),
				this->inactiva.TellHeight(), 0,this->estado, 76+ coordenadaY*40,
				45 + coordenadaX*40,*this->inactiva(0,0) );
	} else{
		RangedPixelToPixelCopyTransparent( this->inactiva, 0, this->inactiva.TellWidth(),
						this->inactiva.TellHeight(), 0,this->estado, 1072 - coordenadaZ*40,
						46 + coordenadaX*40,*this->inactiva(0,0) );

		RangedPixelToPixelCopyTransparent( this->inactiva, 0, this->inactiva.TellWidth(),
						this->inactiva.TellHeight(), 0,this->estado, 76 + coordenadaY*40,
						1035 - coordenadaZ*40,*this->inactiva(0,0) );
	}	
}

void Imagen::definirMapa(string background){
	if (background == "Background1"){
		this->background.ReadFromFile("src/imagen/Background1.bmp");
	}else if (background == "Background2"){
		this->background.ReadFromFile("src/imagen/Background2.bmp");
	}else if (background == "Background2"){
		this->background.ReadFromFile("src/imagen/Background3.bmp");
	}
}
  
void Imagen::recorrerTablero(Tablero * tablero, Jugador * jugador){
        tablero->getCasilleros()->iniciarCursor();
        while(tablero->getCasilleros()->avanzarCursor()){
            Lista<Lista<Casilla *> *> * casillasPlanoXY = tablero->getCasilleros()->obtenerCursor();//PLANO XY
            this->recorrerPlanoXY(casillasPlanoXY, jugador);
        }
    }

void Imagen::recorrerPlanoXY(Lista<Lista<Casilla *> *> * casillas, Jugador * jugador){
        casillas->iniciarCursor();
        while(casillas->avanzarCursor()){
            Lista<Casilla *> * casillasRecta = casillas->obtenerCursor();
            this->recorrerCasilla(casillasRecta, jugador);
        }
    }

void Imagen::recorrerCasilla(Lista<Casilla *> * casillas, Jugador * jugadorActual){
        casillas->iniciarCursor();
        while(casillas->avanzarCursor()){
            Casilla * casilla = casillas->obtenerCursor();
            if((casilla->estaOcupado()) && (casilla->getFicha()->getJugador() == jugadorActual->getNumero())){
               	this->chequearFicha(casilla); 
            }
            else if(casilla->getEstado() == Inactiva){
		if ((casilla->getFicha() != NULL) && (casilla->getFicha()->getJugador() == jugadorActual->getNumero())){
			this->chequearFicha(casilla); 
		} 
		agregarInactivaAEstado(casilla->getX(), casilla->getY(),casilla->getZ());
            }
        }
}
 
void Imagen::chequearFicha(Casilla * casilla){
	TipoDeFicha tipo = casilla->getFicha()->getTipo();
	if (tipo == FAvion) {
		this->agregarAvionAEstado(casilla->getX(), casilla->getY(),casilla->getZ());
	} else if (tipo == FSoldado){
		this->agregarSoldadoAEstado(casilla->getX(), casilla->getY());
	} else if (tipo == FBarco) {
		this->agregarBarcoAEstado(casilla->getX(), casilla->getY());
	}
}
	       
void Imagen::obtenerEstadoTablero(Tablero * tablero, Jugador *jugador){
  this->medidaDeEstado();
  this->agregarFondoAEstado();
  this->recorrerTablero(tablero, jugador);
  string fileName = "estadoTableroDe"+ jugador->getNombre() + ".bmp";
  this->estado.WriteToFile(fileName.c_str());
}
