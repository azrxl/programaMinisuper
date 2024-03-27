#include "Embutido.h"
#include <sstream>

Embutido::Embutido() : Carne(), marca{ "null" }, empaqueTripa{ false } {}

Embutido::Embutido(string _marca, string _nombreAnimal, string _parteAnimal, bool _empaqueTripa, string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno)
    : Carne(_nombreAnimal, _parteAnimal, _codigo, _nombreComercial, _descripcion, _precio, _categoria, _existencia, _limite, _nacional, _peso, dia, mes, anno),
    marca{ _marca }, empaqueTripa {_empaqueTripa }
{}

Embutido::~Embutido() {}

string Embutido::toString() const {
    std::stringstream s;
    s << "Código: " << codigo << "\n"
      << "Nombre Comercial: " << nombreComercial << "\n"
      << "Nombre Animal: " << nombreAnimal << "\n"
      << "Parte Animal: " << parteAnimal << "\n"
      << "Marca: " << marca << "\n"
      << "Descripción: " << descripcion << "\n"
      << "Empacado: " << (empaqueTripa ? "Si" : "No") << "\n"
      << "Precio: " << precio << "\n"
      << "Categoría: " << categoria << "\n"
      << "Existencia: " << existencia << "\n"
      << "Límite: " << limite << "\n"
      << "Fecha de vencimiento: " << vencimiento.getFecha() << "\n";

    return s.str();
}
