#pragma once
#include <string>
#include <sstream>

using std::string;

class Producto {
public:
	Producto();
	Producto(string, string, string, double, int, int, int, int, int, int);
	virtual ~Producto();
	int porcentajeGanancia() const;
	virtual string toString() const = 0;
	string getNombre() const;
	string getCodigo() const;
	double getPrecio() const;
	std::string getFecha() const;
	void setPrecio(int precio);
	void setExistencia(int existencia);
	virtual string guardar() const;

protected:
	struct Fecha {
		int dia;
		int mes;
		int anno;
	};
	string codigo;
	string nombreComercial;
	string descripcion;
	double precio;
	int categoria;
	int existencia;
	int limite;
	Fecha fecha;
};

