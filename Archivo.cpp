#include "Archivo.h"

Archivo::Archivo(std::string nombre): nombreArchivo(nombre) {}

void Archivo::guardarProductos(const Lista<Producto*>& lista) {
	std::ofstream archivo;
	archivo.open(nombreArchivo+"Productos", std::ios::app);
	if (!archivo.is_open())
		return;
	archivo << lista.cantidad() << '$' << lista.guardar();

	archivo.close();
}

void Archivo::guardarFacturas(const Lista<Factura*>& lista) {
	std::ofstream archivo;
	archivo.open(nombreArchivo+"Facturas", std::ios::app);
	if (!archivo.is_open())
		return;
	archivo << lista.cantidad() << '$' << lista.guardar();

	archivo.close();
}

bool Archivo::cargarProductos(Lista<Producto*>& productos) {
	std::ifstream archivo;
	archivo.open(nombreArchivo+"Productos");
	if (!archivo.is_open())
		return false;
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
	return true;
}

bool Archivo::cargarFacturas(Lista<Factura*>& facturas) {
	std::ifstream archivo;
	archivo.open(nombreArchivo+"Facturas");
	if (!archivo.is_open())
		return false;
	std::string valor;
	std::getline(archivo, valor, '$');
	int cantidad = std::stoi(valor);
	for (int i = 0; i < cantidad; ++i) {
		Factura* factura = new Factura;
		std::getline(archivo, valor, '$'); factura->setCodigo(valor);
		std::getline(archivo, valor, '$'); factura->setNombre(valor);
		std::getline(archivo, valor, '$'); factura->setSubtotal(std::stod(valor));
		std::getline(archivo, valor, '$'); factura->setIVA(std::stod(valor));
		std::getline(archivo, valor, '$'); factura->setTotal(std::stod(valor));
		std::getline(archivo, valor, '$');
		int cantidadProductos = std::stoi(valor);
		for (int i = 0;i < cantidadProductos;++i) {
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

				factura->agregarProductos(c);
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

				factura->agregarProductos(c);
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

				factura->agregarProductos(c);
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

				factura->agregarProductos(c);
				break;
			}}
		}
		facturas.agregar(factura);
	}
	return true;
}
