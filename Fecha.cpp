#include "Fecha.h"

Fecha::Fecha()
    : dia{ 0 }, mes{ 0 }, anno{ 0 } {}

Fecha::Fecha(int d, int m, int a)
    : dia{ d }, mes{ m }, anno{ a } {}

Fecha::~Fecha() {}

void Fecha::setFecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anno = a;
}
void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnno(int a) { anno = a; }


std::string Fecha::getFecha() const {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anno);
}