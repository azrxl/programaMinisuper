#pragma once
#include "Producto.h"

class Perecedero :
    public Producto
{
public:
    Perecedero();
    Perecedero(string, string, double, int, int, int, int, int, int);
    virtual ~Perecedero();
    virtual string getVencimiento() const;
    virtual string toString() const = 0;
    virtual string guardar() const = 0;
    void setDia(int);
    void setMes(int);
    void setAnno(int);
protected:
    int dia, mes, anno;
};

