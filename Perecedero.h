#pragma once
#include "Producto.h"
#include "Fecha.h"

class Perecedero :
    public Producto
{
public:
    Perecedero();
    Perecedero(string, string, string, double, int, int, int, bool, double, int, int, int);
    virtual ~Perecedero();
    virtual string toString() const = 0;
protected:
    Fecha vencimiento;
    bool nacional;
    double peso;

};

