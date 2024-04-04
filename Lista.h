#pragma once
#include <sstream>
#include "Nodo.h"

class Lista { 
public:
	Lista();
	virtual ~Lista();
	Nodo* getInicio();
	Lista& agregar(Producto* dato);
	bool eliminar(string id);
	bool modificar(int opcion, string id, int n);
	std::string toString();

private:
	Nodo* inicio;
};