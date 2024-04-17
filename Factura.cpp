#pragma once
#include "Factura.h"
#include <iostream>

Factura::Factura(std::string numero_factura, Lista<Producto*>& productos) {
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

std::string Factura::toString() {
    std::stringstream s;
    s << "Número de Factura: " << codigo << '\n';
    s << "Descripción de los productos:" << '\n';
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        s << " - " << (*it)->getNombre() << ": $" << (*it)->getPrecio() << '\n';
    }
    s << "Subtotal: $" << subtotal << '\n';
    s << "IVA: $" << iva << '\n';
    s << "Total a pagar: $" << total << '\n';
    return s.str();
}

std::string Factura::getCodigo() {
    return codigo;
}

std::string Factura::getNombre() {
    return nombre;
}