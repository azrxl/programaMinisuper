#include "Abarrote.h"

Abarrote::Abarrote()
    : Perecedero(), nombreEmpresa{ "null" }
{}
Abarrote::Abarrote(string _nombreEmpresa, string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno)
    : Perecedero(_codigo, _nombreComercial, _descripcion, _precio, _categoria, _existencia, _limite, _nacional, _peso, dia, mes, anno),
    nombreEmpresa{ _nombreEmpresa } 
{}

Abarrote::~Abarrote() {}

string Abarrote::toString() const
{
    std::stringstream s;
    s << "Código: " << codigo << "\n"
      << "Nombre Comercial: " << nombreComercial << "\n"
      << "Nombre Empresa: " << nombreEmpresa << "\n"
      << "Descripción: " << descripcion << "\n"
      << "Precio: " << precio << "\n"
      << "Categoría: " << categoria << "\n"
      << "Existencia: " << existencia << "\n"
      << "Límite: " << limite << "\n"
      << "Fecha de ingreso: " << fecha.getFecha() << "\n";

    return s.str();
}
