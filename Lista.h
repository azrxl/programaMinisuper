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
	Lista(): inicio{ nullptr } {}

	Lista(const Lista& otra) : inicio{ nullptr } {
		for (auto it = otra.begin(); it != otra.end(); ++it) {
			agregar(*it);
		}
	}
	Lista& operator=(const Lista& otra) {
		if (this == &otra) return *this;
		Lista tmp(otra);
		Nodo* tmpN = inicio;
		inicio = tmp.inicio;
		tmp.inicio = tmpN;
		return *this;
	}

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
			while (tmp != nullptr) {
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

	bool modificarProducto(int opcion, std::string id, double valor) {
		for(auto i = begin(); i != end(); ++i) {
			if ((*i)->getCodigo() == id || (*i)->getNombre() == id) {
				switch (opcion) {
				case 1:
					(*i)->setPrecio(valor);
					return true;
				case 2:
					(*i)->setExistencia(valor);
					return true;
				}
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

	std::string guardar() const {
		std::stringstream s;
		for (auto it = begin(); it != end(); ++it) {
			s << (*it)->guardar() << '\n';
		}
		return s.str();
	}

	Nodo* getInicio() { return inicio; }

	class Iterador {
	private:
		Nodo* actual;

	public:
		Iterador(Nodo* nodo) : actual(nodo) {}

		T& operator*() const {
			if (!actual) {
				throw "nya";
			}
			return actual->dato;
		}

		Iterador& operator++() {
			if (actual) {
				actual = actual->next;
			}
			return *this;
		}

		bool operator!=(const Iterador& otro) const {
			return actual != otro.actual;
		}
	};
	Iterador begin() const {
		return Iterador(inicio);
	}
	Iterador end() const {
		return Iterador(nullptr);
	}
};

