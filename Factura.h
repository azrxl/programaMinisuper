#pragma once
#include "Lista.h"
#include "Producto.h"
#include "sstream"

class Factura {
public:
    Factura(std::string numero_factura, Lista<Producto*>& productos);
    std::string getCodigo() const;
    std::string getNombre() const;
    double getTotal() const;
    double calcularSubtotal();
    double calcularIVA() const;
    double calcularTotal() const;
    std::string toString() const;
    std::string guardar() const;
private:
    std::string codigo;
    std::string nombre;
    Lista<Producto*> productos;
    double subtotal;
    double iva;
    double total;
};