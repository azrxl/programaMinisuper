#include "Archivo.h"

Archivo::Archivo() {}

Archivo& Archivo::getArchivo()
{
	static Archivo archivo;
	return archivo;
}

void Archivo::guardarProductos(std::string nombre, const Lista<Producto>* lista)
{
	std::ofstream archivo;
	archivo.open(nombre, std::ios::app);
	if (!archivo.is_open())
		return;
	
	
}
