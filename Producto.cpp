#include "Producto.h"

Producto::Producto()
	: codigo{ "null" }, nombreComercial{ "null" }, descripcion{ "null" },
	precio{ 0.0 }, categoria{ -1 }, existencia{ 0 }, limite{ 0 }
{}
Producto::Producto(string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, int dia, int mes, int anno)
	: codigo{ _codigo }, nombreComercial{ _nombreComercial }, descripcion{ _descripcion },
	precio{ _precio }, categoria{ _categoria }, existencia{ _existencia }, limite{ _limite }
{
	fecha.setFecha(dia, mes, anno);
}
Producto::~Producto() {}

int Producto::porcentajeGanancia() { return ganancia(categoria); }

string Producto::getNombre(){ return nombreComercial; }

string Producto::getCodigo() { return codigo; }

void Producto::setPrecio(int _precio) { precio = _precio; }

void Producto::setExistencia(int _existencia) { existencia = _existencia; }
