#pragma once
#include <fstream>
#include "Lista.h"
#include "Producto.h"
#include "Factura.h"

//Implementado con singleton

class Archivo
{
public:
	Archivo(std::string nombre)
		: nombreArchivo{nombre} {}
	virtual ~Archivo();
	void guardarProductos(Lista<Producto>* lista);
	void guardarFacturas(Lista<Factura>* lista);
	void cargarLista(std::string nombre);

private:
	std::string nombreArchivo;
};
