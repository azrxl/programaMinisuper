#pragma once
#include "Producto.h"

class Conserva :
    public Producto
{
public:
    Conserva();
    Conserva(string _codigo, string _nombreComercial, double _precio, int _categoria, int _existencia, int _limite, bool _envasado);
    virtual ~Conserva();
    string toString() const;
    virtual string guardar() const;
    void setEnvasado(bool _envasado);
private:
    bool envasado;
};

