#include "Interfaz.h"

int main()
{
	Interfaz* interfaz = new Interfaz;
	Producto* ptr = new Conserva("555", "wew", 600, 1, 3, 1, 1);
	interfaz->agregar(ptr);
	interfaz->menu();
}

//Interfaz es clase Frontera
//Producto y factura es clase Entidad
//Metodos de la interfaz son clase Control