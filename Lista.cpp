#include "Lista.h"

Lista::Lista()
	: inicio{ nullptr } {}

Lista::~Lista() {
	Nodo* tmp = inicio;
	while (tmp != nullptr) {
		inicio = inicio->next;
		delete tmp;
		tmp = inicio;
	}
}

Nodo* Lista::getInicio() { return inicio; }

Lista& Lista::agregar(Producto* d)
{
	if (inicio == nullptr) {
		inicio = new Nodo;
		inicio->dato = d;
		inicio->next = nullptr;
	}
	else {
		Nodo* tmp = inicio;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = new Nodo;
		tmp->next->dato = d;
		tmp->next->next = nullptr;
	}
	return *this;
}

bool Lista::modificar(int opcion, string id, int n)
{
	Nodo* tmp = inicio;
	if (inicio->dato->getCodigo() == id || inicio->dato->getNombre() == id) {
		if (opcion == 1) 
			tmp->dato->setPrecio(n);
	
		if (opcion == 2)
			tmp->dato->setExistencia(n);
		return true;
	}
	else {
		while (tmp != nullptr) {
			if (tmp->next->dato->getCodigo() == id || tmp->next->dato->getNombre() == id) {
				if (opcion == 1)
					tmp->dato->setPrecio(n);

				if (opcion == 2)
					tmp->dato->setExistencia(n);
				return true;
			}
			tmp = tmp->next;
		}
	}
	return false;
}

bool Lista::eliminar(string nombre) {
	Nodo* tmp = inicio;
	if (inicio->dato->getCodigo() == nombre || inicio->dato->getNombre() == nombre) {
		inicio = inicio->next;
		delete tmp;
		return true;
	}
	else {
		Nodo* anterior = nullptr;
		while (tmp->next != nullptr) {
			if (tmp->next->dato->getCodigo() == nombre || tmp->next->dato->getNombre() == nombre) {
				anterior = tmp;
				tmp = tmp->next;
				anterior->next = tmp->next;
				delete tmp;
				return true;
			}
			tmp = tmp->next;
		}
	}
	return false;
}

std::string Lista::toString()
{
	std::stringstream s;
	Nodo* tmp = inicio;
	while (tmp != nullptr) {
		s << tmp->dato->toString() << "\n\n";
		tmp = tmp->next;
	}
	return s.str();
}

