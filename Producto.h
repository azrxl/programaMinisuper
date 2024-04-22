#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <sstream>
#include <chrono>
#include<ctime>

using std::string;

class Producto {
public:
	Producto();
	Producto(string, string, double, int, int, int);
	virtual ~Producto();
	int porcentajeGanancia() const;
	virtual string toString() const = 0;
	string getNombre() const;
	string getNombreComercial() const;
	string getCodigo() const;
	double getPrecio() const;
	int getCategoria() const;
	int getLimite() const;
	int getTotal() const;
	int getID() const;
	int getExistencia() const;
	string getFecha() const;
	void setPrecio(double precio);
	void setExistencia(int existencia);
	void setCodigo(string _codigo);
	void setNombreComercial(string _nombreComercial);
	void setCategoria(int _categoria);
	void setLimite(int _limite);
	void setFecha(string _fecha);
	virtual string guardar() const = 0;

	Producto& operator--();

protected:
	int id;
	string codigo;
	string nombreComercial;
	string descripcion;
	double precio;
	int categoria;
	int existencia;
	int limite;
	string fecha;
private:
	char* obtenerFecha() const;
};

