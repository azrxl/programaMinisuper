#include "Embutido.h"
#include <sstream>

Embutido::Embutido() : Carne(), marca{ "null" }, empaqueTripa{ false } {
    descripcion = "Embutido";
    id = 4;
}

Embutido::Embutido(string _codigo, string _nombreComercial, string _marca, bool _empaqueTripa, double _precio, int _categoria, int _existencia, int _limite, int diaV, int mesV, int annoV)
    : Carne(_codigo, _nombreComercial, _precio, _categoria, _existencia, _limite, diaV, mesV, annoV),
    marca{ _marca }, empaqueTripa {_empaqueTripa } {
    descripcion = "Embutido";
    id = 4;
}

Embutido::~Embutido() {}

string Embutido::toString() const {
    std::stringstream s;
    s << "Codigo: " << codigo << "\n"
      << "Nombre Comercial: " << nombreComercial << "\n"
      << "Marca: " << marca << "\n"
      << "Descripcion: " << descripcion << "\n"
      << "Empacado: " << (empaqueTripa ? "Si" : "No") << "\n"
      << "Precio: " << precio << "\n"
      << "Categoria: " << categoria << "\n"
      << "Existencia: " << existencia << "\n"
      << "Limite: " << limite << "\n"
      << "Fecha de ingreso: " << getFecha() << "\n"
      << "Fecha de vencimiento: " << getVencimiento() << "\n"
      << "Empacado con tripa: " << (empaqueTripa ? "Si" : "No") << "\n";
    return s.str();
}

string Embutido::guardar() const {
    std::stringstream s;
    s << codigo << '$'
        << nombreComercial << '$'
        << marca << '$'   
        << empaqueTripa << '$'
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
void Embutido::setEmpaque(bool empaque) { empaqueTripa = empaque; }
