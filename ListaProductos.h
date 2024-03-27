#pragma once
#include "NodoProductos.h"

class ListaProductos { //Singleton?
public:
	ListaProductos();
	virtual ~ListaProductos();


private:
	NodoProductos* inicio;
};