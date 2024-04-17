#include "Interfaz.h"
using std::cout;
using std::cin;

void Interfaz::menu() {
	int opcion = 0;
	string codigo = "";
	while (opcion != 4) {
		cout << "------ MENU ------" << '\n'
			<< "1. Mantenimiento" << '\n'
			<< "2. Ventas" << '\n'
			<< "3. Reportar" << '\n'
			<< "4. Salir" << '\n'
			<< "-------------------";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			while (opcion != 3) {
				cout << "------ MANTENIMIENTO ------" << '\n'
					<< "1. Facturas" << '\n'
					<< "2. Productos" << '\n'
					<< "3. Retornar" << '\n';
				cin >> opcion;
				system("cls");
				switch (opcion) {
				case 1:
					while (opcion != 3) {
						cout << "------ FACTURAS ------" << '\n'
							<< "1. Eliminar" << '\n'
							<< "2. Actualizar" << '\n'
							<< "3. Retornar" << '\n';
						cin >> opcion;
						system("cls");
						switch (opcion) {
						case 1: {
							cout << "Ingrese la cedula del cliente o el numero de factura a eliminar: ";
							cin >> codigo;
							break;
						}
						case 2: {
							cout << "Ingrese la cedula del cliente o el numero de factura a actualizar: ";
							cin >> codigo;
							break;
						}
						case 3: break;
						}
					}
				case 2:
					while (opcion != 4) {
						cout << "------ PRODUCTOS ------" << '\n'
							<< "1. Ingresar" << '\n'
							<< "2. Eliminar" << '\n'
							<< "3. Modificar" << '\n'
							<< "4. Retornar" << '\n';
						cin >> opcion;
						system("cls");
						switch (opcion) {
						case 1: {
							cout << "Ingrese el codigo del producto a ingresar: ";
							cin >> codigo;
							break;
						}
						case 2: {
							cout << "Ingrese el codigo del producto a eliminar: ";
							cin >> codigo;
							break;
						}
						case 3: {
							cout << "Ingrese el codigo del producto a modificar: ";
							cin >> codigo;
							break;
						}
						}
					}
				}
			}
		case 2:
			while (opcion != 2) {
				cout << "------ VENTAS ------" << '\n'
					<< "1. Nueva Factura" << '\n'
					<< "2. Retornar" << '\n';
				cin >> opcion;
				system("cls");
				switch (opcion) {
				case 1: {
					cout << "Ingrese el numero de factura nuevo: ";
					cin >> codigo;
					cout << "Ingrese la cedula del cliente: ";
					cin >> codigo;
					break;
				}
				case 2: break;
				}
			}
		case 3:
			while (opcion != 6) {
				cout << "------ REPORTAR ------" << '\n'
					<< "1. Todos" << '\n'
					<< "2. Por categoria" << '\n'
					<< "3. Por debajo del limite" << '\n'
					<< "4. Por cliente" << '\n'
					<< "5. 5 mejores clientes" << '\n'
					<< "6. Retornar" << '\n';
				cin >> opcion;
				system("cls");
				switch (opcion) {
				case 1: {

					break;
				}
				case 2: {

					break;
				}
				case 3: {

					break;
				}
				case 4: {

					break;
				}
				case 5: {

					break;
				}
				case 6: break;
				}
			}
		case 4: break;
		}
	}
}
