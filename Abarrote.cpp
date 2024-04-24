#include "Abarrote.h"

Abarrote::Abarrote()
    : Perecedero(), nombreEmpresa{ "null" } {
    descripcion = "Abarrote";
    id = 2;
}
Abarrote::Abarrote(string _nombreEmpresa, string _codigo, string _nombreComercial, double _precio, int _categoria, int _existencia, int _limite, int diaV, int mesV, int annoV)
    : Perecedero(_codigo, _nombreComercial, _precio, _categoria, _existencia, _limite, diaV, mesV, annoV), nombreEmpresa{ _nombreEmpresa } {
    descripcion = "Abarrote";
    id = 2;
}

Abarrote::~Abarrote() {}

void Abarrote::setNombreEmpresa(string _nombre) { nombreEmpresa = _nombre; }

string Abarrote::toString() const {
    std::stringstream s;
    s << "Codigo: " << codigo << "\n"
      << "Nombre Comercial: " << nombreComercial << "\n"
      << "Nombre Empresa: " << nombreEmpresa << "\n"
      << "Descripcion: " << descripcion << "\n"
      << "Precio: " << precio << "\n"
      << "Ganancia aproximada: $" << getGanancia() << '\n'
      << "Categoria: " << categoria << "\n"
      << "Existencia: " << existencia << "\n"
      << "Limite: " << limite << "\n"
      << "Fecha de ingreso: " << fecha << "\n"
      << "Fecha de vencimiento: " << getVencimiento() << "\n";

    return s.str();
}

string Abarrote::guardar() const {
    std::stringstream s;
    s << id << '$'
        << codigo << '$'
        << nombreComercial << '$'
        << nombreEmpresa << '$'
        << precio << '$'
        << categoria << '$'
        << existencia << '$'
        << limite << '$'
        << fecha << '$'
        << dia << '$'
        << mes << '$'
        << anno << '$';
    return s.str();
}