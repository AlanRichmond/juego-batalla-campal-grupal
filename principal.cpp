#include <iostream>
#include "BatallaCampal.h"

int main(){
	
	BatallaCampal * batallaCampal = new BatallaCampal();
	
	batallaCampal->jugar();

	delete batallaCampal;
	
	return 0;
}

