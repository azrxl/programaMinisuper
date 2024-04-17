#pragma once
#include "Lista.h"
#include "Producto.h"
#include "sstream"

class Factura {
public:
    Factura(std::string numero_factura, Lista<Producto*>& productos);
    std::string getCodigo();
    std::string getNombre();
    double calcularSubtotal();
    double calcularIVA() const;
    double calcularTotal() const;
    std::string toString();
private:
    std::string codigo;
    std::string nombre;
    Lista<Producto*> productos;
    double subtotal;
    double iva;
    double total;
};