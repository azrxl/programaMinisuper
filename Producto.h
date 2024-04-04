#pragma once
#include <string>
#include <sstream>
#include "Categoria.h"
#include "Fecha.h"

using std::string;

class Producto
	: public Categoria
{
public:
	Producto();
	Producto(string, string, string, double, int, int, int, int, int, int);
	virtual ~Producto();
	int porcentajeGanancia();
	virtual string toString() const = 0;
	string getNombre();
	string getCodigo();
protected:
	string codigo;
	string nombreComercial;
	string descripcion;
	double precio;
	int categoria;
	int existencia;
	int limite;
	Fecha fecha;

};

