#pragma once
#include <fstream>
#include "Lista.h"
#include "Producto.h"
#include "Factura.h"

//Implementado con singleton

class Archivo {
public:
	static Archivo& getArchivo();
	void guardarProductos(std::string nombre, const Lista<Producto*>& lista);
	void guardarFacturas(std::string nombre, const Lista<Factura*>& lista);
	void cargarLista(std::string nombre, Lista<Producto*>&, Lista<Factura*>&);

private:
	Archivo();
	Archivo(const Archivo&) = delete;
	Archivo& operator=(const Archivo&) = delete;
};
