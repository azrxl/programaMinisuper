#include "Archivo.h"

Archivo::Archivo() {}

Archivo& Archivo::getArchivo()
{
	static Archivo archivo;
	return archivo;
}

void Archivo::guardarProductos(std::string nombre, const Lista<Producto*>& lista)
{
	std::ofstream archivo;
	archivo.open(nombre, std::ios::trunc);
	if (!archivo.is_open())
		return;
	archivo << lista.guardar();

	archivo.close();
}

void Archivo::guardarFacturas(std::string nombre, const Lista<Factura*>& lista) {
	std::ofstream archivo;
	archivo.open(nombre, std::ios::trunc);
	if (!archivo.is_open())
		return;
	archivo << lista.cantidad() << '$' << lista.guardar();

	archivo.close();
}

void Archivo::cargarLista(std::string nombre, Lista<Producto*>& productos, Lista<Factura*>& facturas) {
	std::ifstream archivo;
	archivo.open(nombre);
	if (!archivo.is_open())
		return;
	std::string valor;
	std::getline(archivo, valor, '$');
	int cantidad = std::stoi(valor);
	for (int i = 0; i < cantidad; ++i) {
		//Identificador en cada tipo de producto.
		//Agregarlos
	}
	while (std::getline(archivo, valor, '$')) {

	}
	
}
