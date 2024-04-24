#include "Archivo.h"

Archivo::Archivo() {}

void Archivo::guardarProductos(std::string nombre, const Lista<Producto*>& lista)
{
	std::ofstream archivo;
	archivo.open(nombre, std::ios::trunc);
	if (!archivo.is_open())
		return;
	archivo << lista.cantidad() << '$' << lista.guardar();

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

void Archivo::cargarProductos(std::string nombre, Lista<Producto*>& productos) {
	std::ifstream archivo;
	archivo.open(nombre);
	if (!archivo.is_open())
		return;
	std::string valor;
	std::getline(archivo, valor, '$');
	int cantidad = std::stoi(valor);
	for (int i = 0; i < cantidad; ++i) {
		std::getline(archivo, valor, '$');
		switch (std::stoi(valor)) {
		case 1: { 
			Conserva* c = new Conserva;
			std::getline(archivo, valor, '$'); c->setCodigo(valor);
			std::getline(archivo, valor, '$'); c->setNombreComercial(valor);
			std::getline(archivo, valor, '$'); c->setPrecio(std::stod(valor));
			std::getline(archivo, valor, '$'); c->setCategoria(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setExistencia(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setLimite(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setEnvasado(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setFecha(valor);

			productos.agregar(c);
			break;
		}
		case 2: {
			Abarrote* c = new Abarrote;
			std::getline(archivo, valor, '$'); c->setCodigo(valor);
			std::getline(archivo, valor, '$'); c->setNombreComercial(valor);
			std::getline(archivo, valor, '$'); c->setNombreEmpresa(valor);
			std::getline(archivo, valor, '$'); c->setPrecio(std::stod(valor));
			std::getline(archivo, valor, '$'); c->setCategoria(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setExistencia(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setLimite(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setFecha(valor);
			std::getline(archivo, valor, '$'); c->setDia(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setMes(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setAnno(std::stoi(valor));

			productos.agregar(c);
			break;
		}
		case 3: {
			Carne* c = new Carne;
			std::getline(archivo, valor, '$'); c->setCodigo(valor);
			std::getline(archivo, valor, '$'); c->setNombreComercial(valor);
			std::getline(archivo, valor, '$'); c->setAnimal(valor);
			std::getline(archivo, valor, '$'); c->setParte(valor);
			std::getline(archivo, valor, '$'); c->setPrecio(std::stod(valor));
			std::getline(archivo, valor, '$'); c->setCategoria(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setExistencia(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setLimite(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setFecha(valor);
			std::getline(archivo, valor, '$'); c->setDia(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setMes(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setAnno(std::stoi(valor));

			productos.agregar(c);
			break;
		}
		case 4: {
			Embutido* c = new Embutido;
			std::getline(archivo, valor, '$'); c->setCodigo(valor);
			std::getline(archivo, valor, '$'); c->setMarca(valor);
			std::getline(archivo, valor, '$'); c->setEmpaque(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setPrecio(std::stod(valor));
			std::getline(archivo, valor, '$'); c->setCategoria(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setExistencia(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setLimite(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setFecha(valor);
			std::getline(archivo, valor, '$'); c->setDia(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setMes(std::stoi(valor));
			std::getline(archivo, valor, '$'); c->setAnno(std::stoi(valor));

			productos.agregar(c);
			break;
		}}
	}
	while (std::getline(archivo, valor, '$')) {

	}
	
}

void Archivo::cargarFacturas(std::string nombre, Lista<Factura*>&) {
	std::ifstream archivo;
	archivo.open(nombre);
	if (!archivo.is_open())
		return;
	std::string valor;
	std::getline(archivo, valor, '$');
	int cantidad = std::stoi(valor);
	for (int i = 0; i < cantidad; ++i) {
		std::getline(archivo, valor, '$');
	}
}
