#pragma once
#include "Carne.h"

class Embutido : public Carne {
public:
    Embutido();
    Embutido(string _marca, string _nombreAnimal, string _parteAnimal, string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso, int dia, int mes, int anno);
    virtual ~Embutido();
    virtual string toString() const;

private:
    string marca;
};

