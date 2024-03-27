#include "Perecedero.h"

Perecedero::Perecedero()
	: Producto(), nacional{ false }, peso{ 0.0 } 
{}
Perecedero::Perecedero(string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno)
	: Producto(_codigo, _nombreComercial, _descripcion, _precio, _categoria, _existencia, _limite, dia, mes, anno), 
	nacional{ _nacional }, peso{ _peso }
{
	vencimiento.setFecha(dia, mes, anno);
}

Perecedero::~Perecedero() {}


