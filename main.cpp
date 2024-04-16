#include <iostream>
#include "Lista.h"
#include "Conserva.h"
#include "Embutido.h"
#include "Factura.h"

int main()
{
	Producto* ptr0 = new Carne("camila","pata","5678","carne","carne",2500,1,10,5,true,50,6,7,22);
	Producto* ptr1 = new Conserva("1234", "Envase", "elpepe", 1000, 2, 5, 2, true, 5, 3, 4);
	Producto* ptr2 = new Carne;

	Lista<Producto*> l;
	l.agregar(ptr0).agregar(ptr1).agregar(ptr2);
	std::cout << l.toString();
	std::cout << '\n';
	std::cout << "Producto modificado:\n";
	if (l.modificarProducto(1,"null",300)) {
		std::cout << l.toString();
	}
	else {
		std::cout << "No se pudo";
	}
	

	/*Factura fac("12345", l);
	std::cout << fac.toString();
*/
	delete ptr0;
	delete ptr1;
	delete ptr2;

}

