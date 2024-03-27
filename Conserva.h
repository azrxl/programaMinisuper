#pragma once
#include "Producto.h"

class Conserva :
    public Producto
{
public:
    Conserva();
    Conserva(string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _envasado, int dia, int mes, int anno);
    virtual ~Conserva();
    bool isEnvasado() const;
    string toString() const;
private:
    bool envasado;
};

