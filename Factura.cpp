#pragma once
#include "Factura.h"
#include <iostream>

Factura::Factura(std::string numero_factura, std::string _nombre, Lista<Producto*>& _productos) : nombre(_nombre),
codigo (numero_factura), productos(_productos) {
    subtotal = calcularSubtotal();
    iva = calcularIVA();
    total = calcularTotal();
}

Factura::Factura() : nombre(""), codigo(""), subtotal(0.0), iva(0), total(0.0), productos() {}

double Factura::calcularSubtotal() {
    double subtotal = 0;
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        subtotal += (*it)->getPrecio();
    }
    return subtotal;
}

double Factura::calcularIVA() const {
    // Supongamos un IVA del 16%
    return subtotal * 0.16;
}

double Factura::calcularTotal() const {
    return subtotal + iva;
}

std::string Factura::toString() const {
    std::stringstream s;
    int cantidad = 0;
    s << "Numero de Factura: " << codigo << '\n';
    s << "Cedula del cliente: " << nombre << '\n';
    s << "Descripcion de los productos:" << '\n';
    for (auto it = productos.begin(); it != productos.end(); ++it, ++cantidad) {
        s << " - " << (*it)->getNombre() << ": $" << (*it)->getPrecio() << '\n';
    }
    s << "Cantidad de productos: " << cantidad << '\n';
    s << "Subtotal: $" << subtotal << '\n';
    s << "IVA: $" << iva << '\n';
    s << "Total a pagar: $" << total << '\n';
    return s.str();
}
std::string Factura::guardar() const {
    std::stringstream s;

}
std::string Factura::getCodigo() const { return codigo; }
std::string Factura::getNombre() const { return nombre; }
double Factura::getTotal() const { return total; }
std::string Factura::getNombreComercial() const { return ""; }
double Factura::getPrecio() const { return 0.0; }
int Factura::getExistencia() const { return 0; }
int Factura::getLimite() const { return 0; }
