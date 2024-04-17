#include "Conserva.h"

Conserva::Conserva()
	: Producto(), envasado{ false }
{
    descripcion = "conserva";
}
Conserva::Conserva(string _codigo, string _nombreComercial, string _descripcion, 
    double _precio, int _categoria, int _existencia, int _limite, bool _envasado, int dia, int mes, int anno)
	: Producto(_codigo,  _nombreComercial,  _descripcion, _precio,  _categoria,  _existencia,  _limite, dia, mes, anno), 
	  envasado { _envasado }
{} 
Conserva::~Conserva() {}

string Conserva::toString() const {
    std::stringstream s;
	s << "Código: " << codigo << "\n"
		<< "Nombre Comercial: " << nombreComercial << "\n"
		<< "Descripción: " << descripcion << "\n"
		<< "Precio: " << precio << "\n"
		<< "Categoría: " << categoria << "\n"
		<< "Existencia: " << existencia << "\n"
		<< "Límite: " << limite << "\n"
		<< "Fecha de ingreso: " << getFecha() << "\n"
        << "Envasado: " << (envasado ? "Sí" : "No") << "\n";
    return s.str();
}


string Conserva::guardar() const {
	std::stringstream s;
	s << codigo << '$'
		<< nombreComercial << '$'
		<< descripcion << '$'
		<< std::to_string(precio) << '$'
		<< std::to_string(categoria) << '$'
		<< std::to_string(existencia) << '$'
		<< std::to_string(limite) << '$'
		<< fecha.dia << '$'
		<< fecha.mes << '$'
		<< fecha.anno << '$'
		<< envasado << '$';
	return s.str();
}
