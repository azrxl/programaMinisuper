#include "Conserva.h"

Conserva::Conserva()
	: Producto(), envasado{ false }
{}
Conserva::Conserva(string _codigo, string _nombreComercial, string _descripcion, 
    double _precio, int _categoria, int _existencia, int _limite, bool _envasado, int dia, int mes, int anno)
	: Producto(_codigo,  _nombreComercial,  _descripcion, _precio,  _categoria,  _existencia,  _limite, dia, mes, anno), 
	  envasado { _envasado }
{} 
Conserva::~Conserva() {}

bool Conserva::isEnvasado() const { return envasado; }

string Conserva::toString() const 
{
    std::stringstream s;
    s << "C�digo: " << codigo << "\n"
      << "Nombre Comercial: " << nombreComercial << "\n"
      << "Descripci�n: " << descripcion << "\n"
      << "Precio: " << precio << "\n"
      << "Categor�a: " << categoria << "\n"
      << "Existencia: " << existencia << "\n"
      << "L�mite: " << limite << "\n"
      << "Envasado: " << (envasado ? "S�" : "No") << "\n"
      << "Fecha de ingreso: " << fecha.getFecha() << "\n";

    return s.str();
}
