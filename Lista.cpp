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
