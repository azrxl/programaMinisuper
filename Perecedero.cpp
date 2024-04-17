#include "Perecedero.h"

Perecedero::Perecedero()
	: Producto(), nacional{ false }, peso{ 0.0 } {
	vencimiento.dia = 0;
	vencimiento.mes = 0;
	vencimiento.anno = 0;
}
Perecedero::Perecedero(string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno, int diaV, int mesV, int annoV)
	: Producto(_codigo, _nombreComercial, _descripcion, _precio, _categoria, _existencia, _limite, dia, mes, anno), 
	nacional{ _nacional }, peso{ _peso } {
	vencimiento.dia = diaV;
	vencimiento.mes = mesV;
	vencimiento.anno = annoV;
}

Perecedero::~Perecedero() {}

string Perecedero::getVencimiento() const { 
	return std::to_string(vencimiento.dia) + '/' + std::to_string(vencimiento.mes) + '/' + std::to_string(vencimiento.anno);
}

