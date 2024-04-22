#include "Perecedero.h"

Perecedero::Perecedero()
	: Producto(), dia{ 0 }, mes{ 0 }, anno{ 0 } {}

Perecedero::Perecedero(string _codigo, string _nombreComercial, double _precio, int _categoria, int _existencia, int _limite, int diaV, int mesV, int annoV)
	: Producto(_codigo, _nombreComercial, _precio, _categoria, _existencia, _limite), dia{ diaV }, mes{ mesV }, anno{ annoV } {}

Perecedero::~Perecedero() {}

string Perecedero::getVencimiento() const { 
	return std::to_string(dia) + '/' + std::to_string(mes) + '/' + std::to_string(anno);
}
void Perecedero::setDia(int _dia) { dia = _dia; }
void Perecedero::setMes(int _mes) { mes = _mes; }
void Perecedero::setAnno(int _anno) { dia = _anno; }