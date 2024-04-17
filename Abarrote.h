#pragma once
#include "Perecedero.h"
class Abarrote :
    public Perecedero
{
public:
    Abarrote();
    Abarrote(string _nombreEmpresa, string _codigo, string _nombreComercial, string _descripcion,
            double _precio, int _categoria, int _existencia, int _limite, bool _nacional,
            double _peso, int dia, int mes, int anno, int diaVencimiento, int mesVencimiento, int annoVencimiento);
    virtual ~Abarrote();
    virtual string toString() const;
private:
    string nombreEmpresa;
};

