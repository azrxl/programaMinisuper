#pragma once
#include <fstream>
#include "Clases.h"

class Archivo {
public:
	Archivo();
	void guardarProductos(std::string nombre, const Lista<Producto*>& lista);
	void guardarFacturas(std::string nombre, const Lista<Factura*>& lista);
	void cargarProductos(std::string nombre, Lista<Producto*>&);
	void cargarFacturas(std::string nombre, Lista<Factura*>&);
};
