#include "BatallaCampal.h"

///////INICIALIZACION DEL JUEGO///////

BatallaCampal::BatallaCampal() {
	this->tablero = NULL;
	this->jugadores = NULL;
	this->cantidadDeJugadores = 0;
	this->numeroDeMapa = 0;
}


BatallaCampal::~BatallaCampal() {
	delete this->jugadores;
	delete this->tablero;
	
}


void BatallaCampal::menuDeJuego(){
	std::cout << "Bienvenido a la BatallaCampal." << std::endl;
	while(this->cantidadDeJugadores > MAXIMO_DE_JUGADORES || this->cantidadDeJugadores < MINIMO_DE_JUGADORES){ 
		std::cout << "Ingrese la cantidad de jugadores que van a participar. (" << MINIMO_DE_JUGADORES << " a " << MAXIMO_DE_JUGADORES << ")" << std::endl;
		std::cin >> this->cantidadDeJugadores;
		if(this->cantidadDeJugadores > MAXIMO_DE_JUGADORES || this->cantidadDeJugadores < MINIMO_DE_JUGADORES){
			std::cout << "La cantidad de jugadores elegida no es valida. (" << MINIMO_DE_JUGADORES << " a " << MAXIMO_DE_JUGADORES << ")" << std::endl;
		}
	}
	
	this->jugadores = new Lista <Jugador *>();
	for(unsigned int i = 1; i <= this->cantidadDeJugadores; i++){
		std::string nombreJugador;
		std::cout << "Jugador " <<  i << " ingrese su nombre." << std::endl;
		std::cin >> nombreJugador;
		
		this->jugadores->agregar(new Jugador(i,nombreJugador),i);
		
	}
	
	while(this->numeroDeMapa < 1 || this->numeroDeMapa > NUM_MAPA_MAXIMO){ 
		std::cout << "Ingrese el numero de mapa que desea jugar. (1 a " << NUM_MAPA_MAXIMO << ")" << std::endl;
		std::cin >> this->numeroDeMapa;
		if(this->numeroDeMapa < 1 || this->numeroDeMapa > NUM_MAPA_MAXIMO){
			std::cout << "El numero de mapa ingresado no es valido. (1 a " << NUM_MAPA_MAXIMO << ")" << std::endl;
		}
    }
    if(this->numeroDeMapa == 1){
        iniciarEscenarioUno(MAXIMO_TABLERO_X, MAXIMO_TABLERO_Y, MAXIMO_TABLERO_Z);
    }else if(this->numeroDeMapa == 2){
        iniciarEscenarioDos(MAXIMO_TABLERO_X, MAXIMO_TABLERO_Y, MAXIMO_TABLERO_Z);
    }else if(this->numeroDeMapa == 3){
        iniciarEscenarioTres(MAXIMO_TABLERO_X, MAXIMO_TABLERO_Y, MAXIMO_TABLERO_Z);
    }
}


void BatallaCampal::iniciarEscenarioUno(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo){
    imagen.definirMapa("Background1");
	this->tablero = new Tablero(xMaximo,yMaximo,zMaximo);
	for(unsigned int x = 1; x <= xMaximo; x++){
		for(unsigned int y = 1; y <= yMaximo; y++){
			for(unsigned int z = 1; z <= zMaximo; z++){
				if(z == 1){
					if((y ==1) || (y == 2) || (y == 14)|| (y == 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==3) && (x <= 4)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==3)&& (4 < x) && (x <= 11)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==3)&& (11 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==4) && (x <= 3)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==4)&& (3 < x) && (x <= 12)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==4)&& (12 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==5) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==5)&& (2 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==5)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==6) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==6)&& (2 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==6)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==7) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==7)&& (2 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==7)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==8) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==8)&& (2 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==8)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==9) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==9)&& (2 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==9)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==10) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==10)&& (2 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==10)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==11) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==11)&& (2 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==11)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==12) && (x <= 3)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==12)&& (3 < x) && (x <= 12)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==12)&& (12 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==13) && (x <= 4)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==13)&& (4 < x) && (x <= 11)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==13)&& (11 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
				}
				else{
					this->tablero->getCasillero(x,y,z)->setTipo(Aire);
				}
			}
		}
	}
}


void BatallaCampal::iniciarEscenarioDos(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo){
    imagen.definirMapa("Background2");
	this->tablero = new Tablero(xMaximo,yMaximo,zMaximo);
	for(unsigned int x = 1; x <= xMaximo; x++){
		for(unsigned int y = 1; y <= yMaximo; y++){
			for(unsigned int z = 1; z <= zMaximo; z++){
				if(z == 1){
					if((y ==1) || (y == 2)|| (y == 3)|| (y == 4)|| (y == 12)|| (y == 13)|| (y == 14)|| (y == 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==5) && (x <= 6)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==5)&& (6 < x) && (x <= 9)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==5)&& (9 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==6) && (x <= 6)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==6)&& (6 < x) && (x <= 9)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==6)&& (9 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==7) && (x <= 6)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==7)&& (6 < x) && (x <= 9)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==7)&& (9 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==8) && (x <= 6)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==8)&& (6 < x) && (x <= 9)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==8)&& (9 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==9) && (x <= 6)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==9)&& (6 < x) && (x <= 9)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==9)&& (9 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==10) && (x <= 6)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==10)&& (6 < x) && (x <= 9)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==10)&& (9 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==11) && (x <= 6)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==11)&& (6 < x) && (x <= 9)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==11)&& (9 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
				}
				else{
					this->tablero->getCasillero(x,y,z)->setTipo(Aire);
				}
			}
		}
	}
}


void BatallaCampal::iniciarEscenarioTres(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo){
    imagen.definirMapa("Background3");
	this->tablero = new Tablero(xMaximo,yMaximo,zMaximo);
	for(unsigned int x = 1; x <= xMaximo; x++){
		for(unsigned int y = 1; y <= yMaximo; y++){
			for(unsigned int z = 1; z <= zMaximo; z++){
				if(z == 1){
					if((y ==1) && (x <= 7)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if(((y ==1) && (7 < x) && (x <= 15))){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==2) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==2)&& (2 < x) && (x <= 8)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==2)&& (8 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==2)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==3) && (x <= 8)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==3)&& (8 < x) && (x <= 11)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==3)&& (11 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if(y ==4){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==5) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==5)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==6) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==6)&& (2 < x) && (x <= 5)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==6)&& (5 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==6)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==7)&& (2 < x)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==7)&& (2 < x) && (x <= 5)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==7)&& (5 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==7)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==8)&& (2 < x)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==8)&& (3 == x) ){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==8)&& (4 == x) ){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==8)&& (5 == x) ){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==8)&& (5 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==8)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==9) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==9)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==10) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==10)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==11) && (x <= 2)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==11)&& (2 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==11)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==12) && (x <= 5)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==12)&& (5 < x) && (x <= 13)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==12)&& (13 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==13) && (x <= 7)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==13)&& (7 < x) && (x <= 12)){
						this->tablero->getCasillero(x,y,z)->setTipo(Tierra);}
					else if((y ==13)&& (12 < x) && (x <= 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}
					else if((y ==14) || (y == 15)){
						this->tablero->getCasillero(x,y,z)->setTipo(Agua);}

				}
				else{
					this->tablero->getCasillero(x,y,z)->setTipo(Aire);
				}
			}
		}
	}
}

	
void BatallaCampal::inicializarSoldados(){
	for(unsigned int i = 1; i <= SOLDADOS_INICIALES; i++){
		for(unsigned int j = 1; j <= this->cantidadDeJugadores; j++){
			mostrarEstadoTablero(this->jugadores->obtener(j));
			std::cout << "Jugador " << this->jugadores->obtener(j)->getNombre() << " ingrese la coordenada para su soldado " << i << std::endl;
			Vector<unsigned int> * coordenadas = pedirDestinoDelSoldado(this->jugadores->obtener(j));
            Ficha * ficha = new Ficha(FSoldado,j,Activa);
			colocarSoldado(ficha,coordenadas);
            this->jugadores->obtener(j)->agregarFicha(ficha);
			delete coordenadas;
		}
	}
}


///////CUERPO PRINCIPAL///////

void BatallaCampal::jugar(){
		 
	menuDeJuego();
	inicializarSoldados();
	while(!juegoTerminado()){
		jugarRonda(true);
	}

	bool hayUnGanador = false;
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		if(!estaMuerto(this->jugadores->obtenerCursor())){
			std::cout << this->jugadores->obtenerCursor()->getNombre() << " se queda con la victoria." << std::endl << "GAME OVER" << std::endl;
			hayUnGanador = true;
		}
	}

	if(!hayUnGanador){
		std::cout << "Perdieron todos los  jugadores. GAME OVER" << std::endl;
	}

}


void BatallaCampal::jugarTurno(Jugador * jugador, bool cartasActivadas){

	mostrarEstadoTablero(jugador);
	disparar(jugador);
	
	if(!estaMuerto(jugador)){
		std::string respuesta = "x";
		while(respuesta!="n" && respuesta!="s"){
			std::cout << "Desea mover algun soldado? (s/n)" << std::endl;
			std::cin >> respuesta;
		}

		if(respuesta == "s"){
			Vector<Vector<unsigned int> *> * movimiento = pedirMovimiento(jugador);
			mover(movimiento);
		}
	
		if(jugador->tieneLaFicha(FBarco)){
			lanzarMisil(jugador);
		}else if(jugador->tieneLaFicha(FAvion)){
			disparar(jugador);
			disparar(jugador);
		}

		if(cartasActivadas){
			sacarCarta(jugador);
		}
	}
}


void BatallaCampal::jugarRonda(bool cartasActivadas){
	
	bool terminado = false;
	unsigned int i = 1;

	while( i<=this->cantidadDeJugadores  && !terminado){

		jugarTurno( this->jugadores->obtener(i), cartasActivadas);
		terminado = juegoTerminado();
		i++;

	}
}


///////OBTENCION DE VARIABLES///////

Ficha * BatallaCampal::obtenerFicha( unsigned int x, unsigned int y, unsigned int z){
	return this->tablero->getCasillero(x,y,z)->getFicha();
}


EstadoDeCasilla BatallaCampal::obtenerEstadoDeCasilla(unsigned int x, unsigned int y, unsigned int z){	
	return this->tablero->getCasillero(x,y,z)->getEstado();
}


TipoDeCasilla BatallaCampal::obtenerTipoDeCasilla(unsigned int x, unsigned int y, unsigned int z){
	return this->tablero->getCasillero(x,y,z)->getTipo();
}


Jugador * BatallaCampal::obtenerJugador(unsigned int numeroDeJugador){

	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		if(this->jugadores->obtenerCursor()->getNumero() == numeroDeJugador ){
			return this->jugadores->obtenerCursor();
		}
	}
	return NULL;
}


bool BatallaCampal::tieneUnSoldado(Jugador* jugador, unsigned int x, unsigned int y, unsigned int z){
	return ((obtenerFicha(x, y, z) != NULL)
		&& (obtenerFicha(x, y, z)->getJugador() == jugador->getNumero())
		&& (obtenerFicha(x, y, z)->getTipo() == FSoldado));
}


///////MOVIMIENTO///////

Vector<unsigned int> * BatallaCampal::pedirCoordenadas(){
	unsigned int aux;
	Vector<unsigned int> * coordenadas = new Vector<unsigned int> (3, 0);
	while(!(this->tablero->existeElCasillero(coordenadas->obtener(1),coordenadas->obtener(2),coordenadas->obtener(3)))){
		std::cout << "Ingrese coordenada X" << std::endl;
		std::cin >> aux;
		coordenadas->agregar(1,aux);
		
		std::cout << "Ingrese coordenada Y" << std::endl;
		std::cin >> aux;
		coordenadas->agregar(2,aux);

		std::cout << "Ingrese coordenada z" << std::endl;
		std::cin >> aux;
		coordenadas->agregar(3,aux);
	}

	return coordenadas;
}


Vector<unsigned int> * BatallaCampal::pedirOrigenDelMovimiento(Jugador *jugador){
	Vector<unsigned int> * vectorOrigen;
	bool origenValido = false;
	while(!origenValido){
		std::cout << jugador->getNombre() << ", ingresa la coordenada del soldado que desea mover." << std::endl;
		vectorOrigen = pedirCoordenadas();
		if(!tieneUnSoldado(jugador,vectorOrigen->obtener(1),vectorOrigen->obtener(2),vectorOrigen->obtener(3))){
			std::cout << "No tienes ningun soldado en esa posicion. Intente de nuevo." << std::endl;
			delete vectorOrigen;
		}else{
			origenValido = true;
		}
	}
	return vectorOrigen;
}


Vector<unsigned int> * BatallaCampal::pedirDestinoDelSoldado(Jugador *jugador){
	Vector<unsigned int> * vectorDestino;
	bool destinoValido = false;
	while(!destinoValido){
		std::cout << jugador->getNombre() << ", ingresa la coordenada en la cual desea colocar su soldado." << std::endl;
		vectorDestino = pedirCoordenadas();
		unsigned int x = vectorDestino->obtener(1);
		unsigned int y = vectorDestino->obtener(2);
		unsigned int z = vectorDestino->obtener(3);

		if(tieneUnSoldado(jugador,x,y,z)){
			std::cout << "Ya tienes un soldado en esa posicion. Intente de nuevo." << std::endl;
			delete vectorDestino;
		}else if(obtenerTipoDeCasilla(x,y,z) != Tierra){
			std::cout << "Los soldados solo pueden moverse por tierra. Intente de nuevo." << std::endl;
			delete vectorDestino;
		}else if(obtenerEstadoDeCasilla(x,y,z) == Inactiva){
			std::cout << "El casillero al que deseas moverte esta destruido. Intente de nuevo." << std::endl;
			delete vectorDestino;
		}else{
			destinoValido = true;
		}	
	}
	return vectorDestino;
}


Vector<Vector<unsigned int> *> * BatallaCampal::pedirMovimiento(Jugador *jugador){
	
	Vector<Vector<unsigned int> *> * coordenadasDelMovimiento = new Vector<Vector<unsigned int> *>(2,NULL);
	Vector<unsigned int> * origen;
	Vector<unsigned int> * destino;
	bool valido = false;
	while(!valido){
		origen = pedirOrigenDelMovimiento(jugador);
		destino = pedirDestinoDelSoldado(jugador);
		if(movimientoCercano(origen,destino)){
			coordenadasDelMovimiento->agregar(1,origen);
			coordenadasDelMovimiento->agregar(2,destino);
			valido = true;
		}else{
			delete origen;
			delete destino;
		}
	}
	return coordenadasDelMovimiento;
}

	
void BatallaCampal::destruirCoordenadasDelMovimiento(Vector<Vector<unsigned int> *> * coordenadas){
		
	delete coordenadas->obtener(1);
	delete coordenadas->obtener(2);
	delete coordenadas;
}


void BatallaCampal::colocarSoldado(Ficha * ficha, Vector<unsigned int> * posicion){

	unsigned int x = posicion->obtener(1);
	unsigned int y = posicion->obtener(2);
	unsigned int z = posicion->obtener(3);

	if(this->tablero->getCasillero(x,y,z)->estaOcupado()){

		unsigned int numeroJugadorContrario = this->tablero->getCasillero(x,y,z)->getFicha()->getJugador();
		Jugador * jugadorContrario = obtenerJugador(numeroJugadorContrario);
		jugadorContrario->eliminarFicha(this->tablero->getCasillero(x,y,z)->getFicha());

		unsigned int numeroJugador = ficha->getJugador();
		Jugador * jugador = obtenerJugador(numeroJugador);
		jugador->eliminarFicha(ficha);

		this->tablero->getCasillero(x,y,z)->destruir();

		std::cout << "Tu soldado ha entrado en guerra." << std::endl;

	}else{
		this->tablero->getCasillero(x,y,z)->setFicha(ficha);
	}
}


void BatallaCampal::mover(Vector<Vector<unsigned int> *> * coordenadasOrigenYDestino){
	
	unsigned int xOrigen = coordenadasOrigenYDestino->obtener(1)->obtener(1);
	unsigned int yOrigen = coordenadasOrigenYDestino->obtener(1)->obtener(2);
	unsigned int zOrigen = coordenadasOrigenYDestino->obtener(1)->obtener(3);
	
	Ficha * ficha = this->tablero->getCasillero(xOrigen, yOrigen, zOrigen)->getFicha();
	this->tablero->getCasillero(xOrigen, yOrigen, zOrigen)->vaciar();

	colocarSoldado(ficha,coordenadasOrigenYDestino->obtener(2));

	destruirCoordenadasDelMovimiento(coordenadasOrigenYDestino);

}


bool BatallaCampal::movimientoCercano(Vector<unsigned int> * origen, Vector<unsigned int> * destino){
	int distX = (origen->obtener(1) - destino->obtener(1));
	int distY = (origen->obtener(2) - destino->obtener(2));
	if((distX*distX) > 1 || (distY*distY) > 1){
		std::cout << "Solo puedes moverte un casillero. Elige otra coordenada" << std::endl;
		return false;
	}
	return true;
}


///////ACCIONES Y CARTAS///////

void BatallaCampal::disparar(Jugador * jugador){
	Vector<unsigned int> * vectorPosicion;
	std::cout << jugador->getNombre() << ", ingresa la coordenada a la cual desea disparar." << std::endl;
	vectorPosicion = pedirCoordenadas();
	unsigned int x = vectorPosicion->obtener(1);
	unsigned int y = vectorPosicion->obtener(2);
	unsigned int z = vectorPosicion->obtener(3);
	
	if(this->tablero->getCasillero(x,y,z)->estaOcupado()){
		unsigned int numeroJugador = this->tablero->getCasillero(x, y, z)->getFicha()->getJugador();
		Jugador * jugadorContrario =obtenerJugador(numeroJugador);
		jugadorContrario->eliminarFicha(this->tablero->getCasillero(x, y, z)->getFicha());
		std::cout << "Has conseguido una baja." << std::endl;
	}
	
	if(obtenerTipoDeCasilla(x,y,z) == Tierra){
			this->tablero->getCasillero(x,y,z)->destruir();
	}else{
			this->tablero->getCasillero(x,y,z)->vaciar();
	}
	delete vectorPosicion;
	
}


bool BatallaCampal::posicionDeMisilValida(Vector<unsigned int> * posicion){
	unsigned int x = posicion->obtener(1);
	unsigned int y = posicion->obtener(2);
	unsigned int z = posicion->obtener(3);
	
	return (x!=1  &&  x!=MAXIMO_TABLERO_X &&
		y!=1  &&  y!=MAXIMO_TABLERO_Y &&
		z!=1  &&  z!=MAXIMO_TABLERO_Z);
}
	

void BatallaCampal::lanzarMisil(Jugador * jugador){
	Vector<unsigned int> * vectorPosicion = new Vector<unsigned int>(3,0);
	std::cout << jugador->getNombre() << ", ingresa la coordenada a la cual desea lanzar su misil. (NO LO PUEDE LANZAR A LOS LIMITES DEL MAPA)" << std::endl;
	bool coordenadaValida = false;
	while(!coordenadaValida){
		delete vectorPosicion;
		vectorPosicion = pedirCoordenadas();
		coordenadaValida = posicionDeMisilValida(vectorPosicion); 
	}
	
	unsigned int x = vectorPosicion->obtener(1);
	unsigned int y = vectorPosicion->obtener(2);
	unsigned int z = vectorPosicion->obtener(3);
	for(unsigned int i = x-1; i <= x+1 ; i++){
		for(unsigned int j = y-1; j <= y+1 ; j++){
			for(unsigned int k = z-1; k <= z+1 ; k++){
				if(this->tablero->getCasillero(i,j,k)->estaOcupado()){
					unsigned int numeroJugador = this->tablero->getCasillero(i,j,k)->getFicha()->getJugador();
					Jugador * jugador = obtenerJugador(numeroJugador);
					jugador->eliminarFicha(this->tablero->getCasillero(i,j,k)->getFicha());
					std::cout << "Hubo una baja." << std::endl;
					this->tablero->getCasillero(i,j,k)->vaciar();
				}
				if(obtenerTipoDeCasilla(i,j,k) == Tierra){
					this->tablero->getCasillero(i,j,k)->destruir();
				}
			}
		}
	}
	delete vectorPosicion;
}


void BatallaCampal::colocarAvion(Jugador * jugador){
	Vector<unsigned int> * vectorPosicion;
	bool posicionValida = false;
	while(!posicionValida){
		std::cout << jugador->getNombre() << ", ingresa la coordenada en la cual desea colocar su avion." << std::endl;
		vectorPosicion = pedirCoordenadas();
		unsigned int x = vectorPosicion->obtener(1);
		unsigned int y = vectorPosicion->obtener(2);
		unsigned int z = vectorPosicion->obtener(3);
		if(obtenerTipoDeCasilla(x,y,z) != Aire){
			std::cout << "Solo puedes colocar un avion en el aire. Intente de nuevo." << std::endl;
			delete vectorPosicion;
		
		}else if(this->tablero->getCasillero(x, y, z)->estaOcupado()){
			unsigned int numeroJugador = this->tablero->getCasillero(x, y, z)->getFicha()->getJugador();
			Jugador * jugadorContrario =obtenerJugador(numeroJugador);
			jugadorContrario->eliminarFicha(this->tablero->getCasillero(x, y, z)->getFicha());
			this->tablero->getCasillero(x, y, z)->vaciar();
			std::cout << "Tu avion choco con otro avion." << std::endl;
			posicionValida = true;

		}else{
			Ficha * fichaAvion = new Ficha(FAvion, jugador->getNumero(), Activa);
			this->tablero->getCasillero(x,y,z)->setFicha(fichaAvion);
			jugador->agregarFicha(fichaAvion);
			disparar(jugador);
			disparar(jugador);
			posicionValida = true;
		}
	}
	
	delete vectorPosicion;
}


void BatallaCampal::colocarBarco(Jugador * jugador){
	Vector<unsigned int> * vectorPosicion;
	bool posicionValida = false;
	while(!posicionValida){
		std::cout << jugador->getNombre() << ", ingresa la coordenada en la cual desea colocar su barco." << std::endl;
		vectorPosicion = pedirCoordenadas();
		unsigned int x = vectorPosicion->obtener(1);
		unsigned int y = vectorPosicion->obtener(2);
		unsigned int z = vectorPosicion->obtener(3);
		if(obtenerTipoDeCasilla(x,y,z) != Agua){
			std::cout << "Solo puedes colocar un barco en el agua. Intente de nuevo." << std::endl;
			delete vectorPosicion;
		
		}else if(this->tablero->getCasillero(x, y, z)->estaOcupado()){
			unsigned int numeroJugador = this->tablero->getCasillero(x, y, z)->getFicha()->getJugador();
			Jugador * jugadorContrario =obtenerJugador(numeroJugador);
			jugadorContrario->eliminarFicha(this->tablero->getCasillero(x, y, z)->getFicha());
			this->tablero->getCasillero(x, y, z)->vaciar();
			std::cout << "Tu barco choco con otro barco." << std::endl;
			posicionValida = true;

		}else{
			Ficha * fichaBarco = new Ficha(FBarco, jugador->getNumero(), Activa);
			this->tablero->getCasillero(x,y,z)->setFicha(fichaBarco);
			jugador->agregarFicha(fichaBarco);
			lanzarMisil(jugador);      
			posicionValida = true;
			
		}
	}
	
	delete vectorPosicion;
}


void BatallaCampal::sacarCarta(Jugador * jugador){
	srand(time(NULL));
	int numeroDeCarta  = rand() % 9;
	std::cout << jugador->getNombre() << " saco la carta ";
	switch(numeroDeCarta){
   		case Avion:
			std::cout << "de Avion." << std::endl;
			
			if(!jugador->tieneLaFicha(FAvion)){
				colocarAvion(jugador);
			}else{
				std::cout << "Ya tienes la cantidad maxima de aviones." << std::endl;
			}
			
   			break;
			
   		case Barco:
			std::cout << "de Barco." << std::endl;
			
			if(!jugador->tieneLaFicha(FBarco)){
				colocarBarco(jugador);
			}else{
				std::cout << "Ya tienes la cantidad maxima de barcos." << std::endl;
			}
    			
			break;
			
   		case Misil:
			std::cout << "de Misil." << std::endl;
			lanzarMisil(jugador);
   			break;
			
		case OtroTurno:
			std::cout << "Otro Turno. Juega de nuevo." << std::endl;
			jugarTurno(jugador, true);
			break;
			
		case OtroSoldado:
			std::cout << "de Otro Soldado" << std::endl;
			if(jugador->cantidadDeLaFicha(FSoldado) < SOLDADOS_INICIALES){
				Vector<unsigned int> * posicion = pedirDestinoDelSoldado(jugador);
				colocarSoldado(new Ficha(FSoldado,jugador->getNumero(),Activa),posicion);
			}else{
				std::cout << "Ya tienes la cantidad maxima de soldados." << std::endl;
			}
			break;
			
		case RondaSinCartas:
			std::cout << "de Ronda Sin Cartas." << std::endl;
			jugarRonda(false);
			break;
			
   		default:
			std::cout << "en Blanco." << std::endl;
			break;
	}
}


///////VALIDACIONES DE FIN DEL JUEGO///////

bool BatallaCampal::estaMuerto(Jugador * jugador){

	return (jugador->cantidadDeLaFicha(FSoldado) == 0);
}


bool BatallaCampal::juegoTerminado(){

	unsigned int cantidadDeMuertos = 0;
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		if( estaMuerto(this->jugadores->obtenerCursor())){
			cantidadDeMuertos++;
		}
	}
	if(cantidadDeMuertos >= (this->cantidadDeJugadores -1)){
		return true;
	}
	return false;
}
		   

///////IMPRESIONES///////
		  
void BatallaCampal::mostrarEstadoTablero(Jugador * jugador){
	imagen.obtenerEstadoTablero(this->tablero, jugador);
}
