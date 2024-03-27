#include "Carne.h"

Carne::Carne()
    : Perecedero(), nombreAnimal{ "null" }, parteAnimal{ "null" }
{
    descripcion = "Carne";
}

Carne::Carne(string _nombreAnimal, string _parteAnimal, string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno)
    : Perecedero(_codigo, _nombreComercial, _descripcion, _precio, _categoria, _existencia, _limite, _nacional, _peso, dia, mes, anno),
    nombreAnimal{ _nombreAnimal },
    parteAnimal{ _parteAnimal }
{}

Carne::~Carne() {}

string Carne::toString() const {
    std::stringstream s;
    s << "Código: " << codigo << "\n"
      << "Nombre Comercial: " << nombreComercial << "\n"
      << "Nombre Animal: " << nombreAnimal << "\n"
      << "Parte Animal: " << parteAnimal << "\n"
      << "Descripción: " << descripcion << "\n"
      << "Precio: " << precio << "\n"
      << "Categoría: " << categoria << "\n"
      << "Existencia: " << existencia << "\n"
      << "Límite: " << limite << "\n"
      << "Fecha de vencimiento: " << vencimiento.getFecha() << "\n";

    return s.str();
}