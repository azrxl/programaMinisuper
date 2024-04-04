#include <iostream>
#include "Lista.h"
#include "Conserva.h"
#include "Embutido.h"

int main()
{
	Producto* ptr0 = new Carne;
	Producto* ptr1 = new Conserva("1234", "Envase", "elpepe", 1000, 2, 5, 2, true, 5, 3, 4);
	Producto* ptr2 = new Carne;
	Lista l;
	l.agregar(ptr0).agregar(ptr1).agregar(ptr2);
	std::cout << l.toString();
	std::cout << '\n';
	std::cout << "Producto eliminado:\n";
	std::cout << l.eliminar("1234");
}
