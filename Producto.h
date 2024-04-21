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
	int getCategoria() const;
	int getLimite() const;
	std::string getFecha() const;
	int getTotal() const;
	void setPrecio(double precio);
	void setExistencia(int existencia);
	void setFecha(int dia, int mes, int anno);
	void setCodigo(std::string _codigo);
	void setNombreComercial(std::string _nombreComercial);
	void setDescripcion(std::string _descripcion);
	void setCategoria(int _categoria);
	void setLimite(int _limite);
	virtual string guardar() const = 0;

	Producto& operator--();

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

