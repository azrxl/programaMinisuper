#pragma once
#include "Producto.h"

struct NodoProductos {
	Producto* producto;
	NodoProductos* next;
};