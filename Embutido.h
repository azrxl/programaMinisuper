#pragma once
#include "Carne.h"

class Embutido : public Carne {
public:
    Embutido();
    Embutido(string _marca, bool _empaqueTripa, string _codigo, string _nombreComercial, string _descripcion,
        double _precio, int _categoria, int _existencia, int _limite, bool _nacional, double _peso,
        int dia, int mes, int anno, int diaVencimiento, int mesVencimiento, int annoVencimiento);
    virtual ~Embutido();
    virtual string toString() const;
    virtual string guardar() const;
private:
    string marca;
    bool empaqueTripa;
};

