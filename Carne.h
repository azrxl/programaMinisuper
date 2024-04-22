#pragma once
#include "Perecedero.h"

class Carne :
    public Perecedero {
public:
    Carne();
    Carne(string _nombreAnimal, string parteAnimal, string _codigo, string _nombreComercial,
          double _precio, int _categoria, int _existencia, int _limite, 
          int diaVencimiento, int mesVencimiento, int annoVencimiento);
    Carne(string _codigo, string _nombreComercial, double _precio,
          int _categoria, int _existencia, int _limite,
          int diaVencimiento, int mesVencimiento, int annoVencimiento);
    virtual ~Carne();
    virtual string toString() const;
    virtual string guardar() const;
    void setAnimal(string);
    void setParte(string);

private:
    string nombreAnimal;
    string parteAnimal;
};