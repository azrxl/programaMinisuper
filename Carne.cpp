#include "Carne.h"

Carne::Carne()
    : Perecedero(), nombreAnimal{ "null" }, parteAnimal{ "null" } {
    descripcion = "Carne";
}

Carne::Carne(string _nombreAnimal, string _parteAnimal, string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno, int diaV, int mesV, int annoV)
    : Perecedero(_codigo, _nombreComercial, _descripcion, _precio, _categoria, _existencia, _limite, _nacional, _peso, dia, mes, anno, diaV, mesV, annoV),
    nombreAnimal{ _nombreAnimal },
    parteAnimal{ _parteAnimal }
{}

Carne::Carne(string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno, int diaV, int mesV, int annoV)
    : Perecedero(_codigo, _nombreComercial, _descripcion, _precio, _categoria, _existencia, _limite, _nacional, _peso, dia, mes, anno, diaV, mesV, annoV)
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
      << "Fecha de ingreso: " << getFecha() << "\n"
      << "Fecha de vencimiento: " << getVencimiento() << "\n";
    return s.str();
}

string Carne::guardar() const {
    std::stringstream s;
    s << codigo << '$'
        << nombreComercial << '$'
        << nombreAnimal << '$'
        << parteAnimal << '$'
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