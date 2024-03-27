#pragma once
#include "Perecedero.h"

class Carne :
    public Perecedero {
public:
    Carne();
    Carne(string _nombreAnimal, string parteAnimal, string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno);
    virtual ~Carne();
    virtual string toString() const;

protected:
    string nombreAnimal;
    string parteAnimal;
};