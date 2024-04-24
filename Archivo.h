#pragma once
#include <fstream>
#include <iostream>
#include "Lista.h"
#include "Producto.h"
#include "Factura.h"
#include "Embutido.h"
#include "Conserva.h"

class Factura;

class Archivo {
public:
	Archivo(std::string nombre);
	void guardarProductos(const Lista<Producto*>&);
	void guardarFacturas(const Lista<Factura*>&);
	bool cargarProductos(Lista<Producto*>&);
	bool cargarFacturas(Lista<Factura*>&);
private:
	std::string nombreArchivo;
};

