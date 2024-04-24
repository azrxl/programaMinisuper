#include "Carne.h"

Carne::Carne()
    : Perecedero(), nombreAnimal{ "null" }, parteAnimal{ "null" } {
    descripcion = "Carne";
    id = 3;
}

Carne::Carne(string _nombreAnimal, string _parteAnimal, string _codigo, string _nombreComercial, double _precio, int _categoria, int _existencia, int _limite, int diaV, int mesV, int annoV)
    : Perecedero(_codigo, _nombreComercial, _precio, _categoria, _existencia, _limite, diaV, mesV, annoV),
    nombreAnimal{ _nombreAnimal },
    parteAnimal{ _parteAnimal } {
    descripcion = "Carne";
    id = 3;
}

Carne::Carne(string _codigo, string _nombreComercial, double _precio, int _categoria, int _existencia, int _limite, int diaV, int mesV, int annoV)
    : Perecedero(_codigo, _nombreComercial, _precio, _categoria, _existencia, _limite, diaV, mesV, annoV) {
    descripcion = "Carne";
    id = 3;
}

Carne::~Carne() {}

string Carne::toString() const {
    std::stringstream s;
    s << "Codigo: " << codigo << "\n"
      << "Nombre Comercial: " << nombreComercial << "\n"
      << "Nombre Animal: " << nombreAnimal << "\n"
      << "Parte Animal: " << parteAnimal << "\n"
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

string Carne::guardar() const {
    std::stringstream s;
    s << id << '$'
        << codigo << '$'
        << nombreComercial << '$'
        << nombreAnimal << '$'
        << parteAnimal << '$'
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
void Carne::setAnimal(string animal) { nombreAnimal = animal; }
void Carne::setParte(string parte) { parteAnimal = parte; }
