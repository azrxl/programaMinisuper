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
	Lista() : inicio{ nullptr } {}

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

	Lista& agregar(T dato) {
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
		for (auto it = begin(); it != end(); ++it) {
			if ((*it)->getCodigo() == id || (*it)->getNombre() == id) {
				switch (opcion) {
				case 1:
					(*it)->setPrecio(valor);
					return true;
				case 2:
					(*it)->setExistencia((int)valor);
					return true;
				}
			}
		}
		return false;
	}
	void ordenar() {
		if (!inicio || !inicio->next) {
			return;
		}
		bool intercambio = true;
		while (intercambio) {
			intercambio = false;
			Nodo* actual = inicio;
			Nodo* siguiente = inicio->next;
			while (actual->next) {
				if (actual->dato->getTotal() < siguiente->dato->getTotal()) {
					intercambiar(actual, siguiente);
					intercambio = true;
				}
				actual = siguiente;
				siguiente = siguiente->next;
			}
		}
	}
	T buscar(std::string id) {
		for (auto it = begin();it != end();++it) {
			if ((*it)->getCodigo() == id) {
				return (*it);
			}
		}
		return nullptr;
	}
	int cantidad() const {
		int i = 0;
		for (auto it = begin();it != end();++it, ++i);
		return i;
	}
	bool isEmpty() const {
		return !inicio;
	}
	bool outOfStock() {
		int i = 0;
		for (auto it = begin();it != end();++it) 
			if ((*it)->getExistencia() < (*it)->getLimite()) ++i;
		return i == cantidad();
	}
	std::string toString(int opcion) {
		std::stringstream s;
		switch (opcion) {
		case 0:
			for (auto it = begin(); it != end();++it) {
				if ((*it)->getExistencia() < (*it)->getLimite())
					s << "Agotado -> ";
				s << (*it)->getCodigo() << " - " << (*it)->getNombreComercial() << ": " << (*it)->getPrecio() << '$' << '\n';
			}
			break;
		case 1:
			for (auto it = begin(); it != end();++it) {
				s << (*it)->toString() << "\n-----------------------------\n";
			}
			break;
		case 3:
			for (auto it = begin(); it != end();++it) {
				if ((*it)->getExistencia() < (*it)->getLimite()) {
					s << (*it)->toString() << "\n-----------------------------\n";
				}
			}
			break;
		case 5:
			ordenar();
			int cont = 0;
			for (auto it = begin(); it != end() && cont < 5;++it, ++cont) {
				s << (*it)->toString() << "\n-----------------------------\n";
			}
			break;
		}
		return s.str();
	}
	std::string toString(int opcion, int valor) {
		std::stringstream s;
		for (auto it = begin(); it != end();++it) {
			if ((*it)->getCategoria() == valor) {
				s << (*it)->toString() << "\n-----------------------------\n";
			}
		}
		return s.str();
	}
	std::string toString(std::string valor) {
		std::stringstream s;
		for (auto it = begin(); it != end();++it) {
			if ((*it)->getNombre() == valor || (*it)->getCodigo() == valor) {
				s << (*it)->toString() << "\n-----------------------------\n";
			}
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
				throw "Excepcion de memoria";
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
	private:
	void intercambiar(Nodo* n1, Nodo* n2) {
		if (!n1 || !n2 || n1 == n2) return;
		Nodo* prevN1 = nullptr;
		Nodo* prevN2 = nullptr;
		Nodo* tmp = inicio;
		while (tmp != nullptr && tmp->next != n1 && tmp->next != n2) tmp = tmp->next;

		if (!tmp) return;

		if (tmp->next == n1) {
			prevN1 = tmp;
			while (tmp && tmp->next != n2) tmp = tmp->next;
			if (!tmp) return;
			prevN2 = tmp;
		}
		else {
			prevN2 = tmp;
			while (tmp && tmp->next != n1) tmp = tmp->next;
			if (!tmp) return;
			prevN1 = tmp;
		}

		if (prevN1) prevN1->next = n2;
		else inicio = n2;

		if (prevN2) prevN2->next = n1;
		else inicio = n1;

		tmp = n1->next;
		n1->next = n2->next;
		n2->next = tmp;
	}
};
