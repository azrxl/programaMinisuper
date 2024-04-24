#include "Interfaz.h"

int main()
{	
	Interfaz* interfaz = new Interfaz;
	Producto* ptr1 = new Conserva("1234", "conflei", 1000, 1, 2, 1, true);
	interfaz->agregar(ptr1);
	interfaz->menu();





	/*Producto* ptr2 = new Carne;
	Producto* ptr3 = new Embutido("yokeis",false,"5555","embutido","embutido",1555.355,1,4,2,true,5.5,2,3,23,4,6,24);

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

	Factura fac("123456", l);	
	
	Archivo& arch = Archivo::getArchivo();
	arch.guardarProductos("arch1",l);*/
	

}


//Interfaz es clase Frontera
//Producto y factura es clase Entidad
//Metodos de la interfaz son clase Control