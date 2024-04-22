#pragma once
#include "Perecedero.h"
class Abarrote :
    public Perecedero
{
public:
    Abarrote();
    Abarrote(string _nombreEmpresa, string _codigo, string _nombreComercial, double _precio,
        int _categoria, int _existencia, int _limite, int diaVencimiento, int mesVencimiento, int annoVencimiento);
    virtual ~Abarrote();
    virtual string toString() const;
    virtual string guardar() const;
private:
    string nombreEmpresa;
};

