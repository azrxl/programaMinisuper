#include "Embutido.h"
#include <sstream>

Embutido::Embutido() : Carne(), marca{ "null" }, empaqueTripa{ false } {}

Embutido::Embutido(string _marca, bool _empaqueTripa, string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno, int diaV, int mesV, int annoV)
    : Carne(_codigo, _nombreComercial, _descripcion, _precio, _categoria, _existencia, _limite, _nacional, _peso, dia, mes, anno, diaV, mesV, annoV),
    marca{ _marca }, empaqueTripa {_empaqueTripa }
{}

Embutido::~Embutido() {}

string Embutido::toString() const {
    std::stringstream s;
    s << "Código: " << codigo << "\n"
      << "Nombre Comercial: " << nombreComercial << "\n"
      << "Marca: " << marca << "\n"
      << "Descripción: " << descripcion << "\n"
      << "Empacado: " << (empaqueTripa ? "Si" : "No") << "\n"
      << "Precio: " << precio << "\n"
      << "Categoría: " << categoria << "\n"
      << "Existencia: " << existencia << "\n"
      << "Límite: " << limite << "\n"
      << "Fecha de ingreso: " << getFecha() << "\n"
      << "Fecha de vencimiento: " << getVencimiento() << "\n";
    return s.str();
}

string Embutido::guardar() const {
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
        << vencimiento.dia << '$'
        << vencimiento.mes << '$'
        << vencimiento.anno << '$'
        << '\n';
    return s.str();
}