#pragma once
#include <sstream>
#include "Nodo.h"

class Lista { 
public:
	Lista();
	virtual ~Lista();
	Nodo* getInicio();
	Lista& agregar(Producto* dato);
	std::string toString();

private:
	Nodo* inicio;
};