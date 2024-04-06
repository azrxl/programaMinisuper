#pragma once
#include <sstream>
#include <string>

template<typename T>
class Lista {
private:
	struct Nodo {
		T dato;
		Nodo* next;
	};

	Nodo* inicio;
public:
	class Iterador;

	Iterador begin() {
		return Iterador(inicio);
	}
	Iterador end() {
		return Iterador(nullptr);
	}

	Lista(): inicio{ nullptr } {}

	Nodo* getInicio() { return inicio; }

	virtual ~Lista() {
		Nodo* tmp = inicio;
		while (tmp != nullptr) {
			inicio = inicio->next;
			delete tmp;
			tmp = inicio;
		}
	}

	Lista& agregar(T dato)	{
		Nodo* tmp = new Nodo;
		tmp->dato = dato;
		tmp->next = inicio;
		inicio = tmp;

		return *this;
	}

	bool eliminar(std::string codigo) { //Eliminar por codigo de producto o nombre, y eliminar factura por su numero
		Nodo* tmp = inicio;
		if (inicio->dato->getCodigo() == codigo || inicio->dato->getNombre() == codigo) {
			inicio = inicio->next;
			delete tmp;
			return true;
		}
		else {
			Nodo* anterior = nullptr;
			for (Iterador it = begin(); it != end(); ++it) {
				if (tmp->next->dato->getCodigo() == codigo || tmp->next->dato->getNombre() == codigo) {
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

	bool modificarProducto(int opcion, std::string id, int valor) {
		Nodo* tmp = inicio;
		while (tmp != nullptr) {
			if (tmp->dato->getCodigo() == id || tmp->dato->getNombre() == id) {
				if (opcion == 1) {
					tmp->dato->setPrecio(valor);
					return true;
				}
				if (opcion == 2) {
					tmp->dato->setExistencia(valor);
					return true;
				}
				tmp = tmp->next;
			}
		}
		return false;
	}

	std::string toString() {
		std::stringstream s;
		Nodo* tmp = inicio;
		while (tmp != nullptr) {
			s << tmp->dato->toString() << "\n\n";
			tmp = tmp->next;
		}
		return s.str();
	}
};

template<typename T>
class Lista<T>::Iterador {
private:
	Nodo* nodo;
public:
	Iterador() : nodo{ nullptr } {}
	Iterador(Nodo* _nodo) : nodo{ _nodo } {}

	Iterador& operator=(const Iterador& otro) {
		nodo->dato = otro;
		return *this;
	}

	T& operator*() const {
		return inicio->dato;
	}

	Iterador& operator++() {
		if (nodo->next != nullptr)
			nodo = nodo->next;
		return *this;
	}

	bool operator==(const Iterador& otro) const {
		return nodo == otro.nodo;
	}

	bool operator!=(const Iterador& otro) const {
		return !(*this == otro);
	}
};