#pragma once
#include "Clases.h"

class Factura {
public:
    Factura(std::string numero_factura, std::string nombre, Lista<Producto*>& productos);
    Factura();
    void agregarProductos(Producto*);
    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getNombreComercial() const;
    double getPrecio() const;
    int getExistencia() const;
    int getLimite() const;
    double getTotal() const;
    void setCodigo(std::string);
    void setNombre(std::string);
    void setSubtotal(double);
    void setIVA(double);
    void setTotal(double);
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