#include "Interfaz.h"

int main()
{
	Interfaz* interfaz = new Interfaz;
	interfaz->menu();




	/*Producto* ptr0 = new Carne("camila","pata","5678","carne","carne",2500,1,10,5,true,50,6,7,22, 9,10,23);
	Producto* ptr1 = new Conserva("1234", "Envase", "elpepe", 1000, 2, 5, 2, true, 5, 3, 4);
	Producto* ptr2 = new Carne;
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
