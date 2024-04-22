#pragma once
#include "Factura.h"
#include <iostream>

Factura::Factura(std::string numero_factura, std::string nombre, Lista<Producto*>& productos) {
    this->nombre = nombre;
    this->codigo = numero_factura;
    this->productos = productos;
    this->subtotal = calcularSubtotal();
    this->iva = calcularIVA();
    this->total = calcularTotal();
}

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
    s << "Numero de Factura: " << codigo << '\n';
    s << "Cedula del cliente: " << nombre << '\n';
    s << "Descripcion de los productos:" << '\n';
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        s << " - " << (*it)->getNombre() << ": $" << (*it)->getPrecio() << '\n';
    }
    s << "Subtotal: $" << subtotal << '\n';
    s << "IVA: $" << iva << '\n';
    s << "Total a pagar: $" << total << '\n';
    return s.str();
}

std::string Factura::guardar() const { return ""; }
std::string Factura::getCodigo() const { return codigo; }
std::string Factura::getNombre() const { return nombre; }
double Factura::getTotal() const { return total; }
std::string Factura::getNombreComercial() const { return ""; }
double Factura::getPrecio() const { return 0.0; }
int Factura::getExistencia() const { return 0; }
int Factura::getLimite() const { return 0; }
