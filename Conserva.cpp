#include "Conserva.h"

Conserva::Conserva()
	: Producto(), envasado{ false }
{
    descripcion = "Conserva";
	id = 1;
}
Conserva::Conserva(string _codigo, string _nombreComercial, double _precio, int _categoria, 
	int _existencia, int _limite, bool _envasado)
	: Producto(_codigo,  _nombreComercial, _precio,  _categoria,  _existencia,  _limite), 
	  envasado { _envasado }
{
	descripcion = "Conserva";
	id = 1;
} 
Conserva::~Conserva() {}

string Conserva::toString() const {
    std::stringstream s;
	s << "Codigo: " << codigo << "\n"
		<< "Nombre Comercial: " << nombreComercial << "\n"
		<< "Descripcion: " << descripcion << "\n"
		<< "Precio: " << precio << "\n"
		<< "Categoria: " << categoria << "\n"
		<< "Existencia: " << existencia << "\n"
		<< "Limite: " << limite << "\n"
		<< "Fecha de ingreso: " << getFecha() << "\n"
        << "Envasado: " << (envasado ? "Si" : "No") << "\n";
    return s.str();
}
string Conserva::guardar() const {
	std::stringstream s;
	s << id << '$'
		<< codigo << '$'
		<< nombreComercial << '$'
		<< precio << '$'
		<< categoria << '$'
		<< existencia << '$'
		<< limite << '$'
		<< envasado << '$'
		<< fecha << '$';
	return s.str();
}
void Conserva::setEnvasado(bool _envasado) { envasado = _envasado; }