#include <iostream>
#include "Lista.h"
#include "Conserva.h"
#include "Embutido.h"

int main()
{
	Producto* ptr1 = new Conserva;
	Producto* ptr2 = new Carne;
	Lista l;
	l.agregar(ptr1).agregar(ptr2);
	std::cout << l.toString();
}
