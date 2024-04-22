#pragma once
#include "Carne.h"

class Embutido : public Carne {
public:
    Embutido();
    Embutido(string _codigo, string _nombreComercial, string _marca, bool _empaqueTripa,
        double _precio, int _categoria, int _existencia, int _limite,
        int diaVencimiento, int mesVencimiento, int annoVencimiento);
    virtual ~Embutido();
    virtual string toString() const;
    virtual string guardar() const;
    void setEmpaque(bool empaque);
private:
    string marca;
    bool empaqueTripa;
};

