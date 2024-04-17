#include "Interfaz.h"

void Interfaz::menu() {
    int opcion = 0;
    while (opcion != 4) {
        mostrarMenuPrincipal();
        opcion = obtenerOpcion(1, 4);
        system("cls");
        switch (opcion) {
        case 1:
            menuMantenimiento();
            break;
        case 2:
            menuVentas();
            break;
        case 3:
            menuReportar();
            break;
        }
    }
}


    void Interfaz::mostrarMenuPrincipal() {
        std::cout << "------ MENU ------\n"
            << "1. Mantenimiento\n"
            << "2. Ventas\n"
            << "3. Reportar\n"
            << "4. Salir\n"
            << "-------------------\n";
    }

    void Interfaz::menuMantenimiento() {
        int opcion = 0;
        while (opcion != 3) {
            std::cout << "------ MANTENIMIENTO ------\n"
                << "1. Facturas\n"
                << "2. Productos\n"
                << "3. Retornar\n";
            opcion = obtenerOpcion(1, 3);
            system("cls");
            switch (opcion) {
            case 1:
                menuFacturas();
                break;
            case 2:
                menuProductos();
                break;
            }
        }
    }

    void Interfaz::menuFacturas() {
        int opcion = 0;
        while (opcion != 3) {
            std::cout << "------ FACTURAS ------\n"
                << "1. Eliminar\n"
                << "2. Actualizar\n"
                << "3. Retornar\n";
            opcion = obtenerOpcion(1, 3);
            system("cls");
            switch (opcion) {
            case 1:
                gestionarFactura("eliminar");
                break;
            case 2:
                gestionarFactura("actualizar");
                break;
            }
        }
    }

    void Interfaz::menuProductos() {
        int opcion = 0;
        while (opcion != 4) {
            std::cout << "------ PRODUCTOS ------\n"
                << "1. Ingresar\n"
                << "2. Eliminar\n"
                << "3. Modificar\n"
                << "4. Retornar\n";
            opcion = obtenerOpcion(1, 4);
            system("cls");
            switch (opcion) {
            case 1:
                gestionarProducto("ingresar");
                break;
            case 2:
                gestionarProducto("eliminar");
                break;
            case 3:
                gestionarProducto("modificar");
                break;
            }
        }
    }

    void Interfaz::menuVentas() {
        int opcion = 0;
        while (opcion != 2) {
            std::cout << "------ VENTAS ------" << '\n'
                << "1. Nueva Factura" << '\n'
                << "2. Retornar" << '\n';
            std::cin >> opcion;
            system("cls");
            switch (opcion) {
            case 1:
                gestionarFactura("agregar");
                break;
            }
        }
    }

    void Interfaz::menuReportar() {
        int opcion = 0;
        while (opcion != 6) {
            std::cout << "------ REPORTAR ------" << '\n'
                << "1. Todos" << '\n'
                << "2. Por categoria" << '\n'
                << "3. Por debajo del limite" << '\n'
                << "4. Por cliente" << '\n'
                << "5. 5 mejores clientes" << '\n'
                << "6. Retornar" << '\n';
            std::cin >> opcion;
            system("cls");
            switch (opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            }
        }
    }

    int Interfaz::obtenerOpcion(int min, int max) {
        int opcion;
        std::cin >> opcion;
        while (opcion < min || opcion > max) {
            std::cout << "Opción inválida. Introduce una opción válida: ";
            std::cin >> opcion;
        }
        return opcion;
    }

    void Interfaz::gestionarFactura(const std::string& accion) {
        std::string codigo;
        std::cout << "Ingrese la cedula del cliente o el numero de factura a " << accion << ": ";
        std::cin >> codigo;
    }

    void Interfaz::gestionarProducto(const std::string& accion) {
        std::string codigo;
        std::cout << "Ingrese el codigo del producto a " << accion << ": ";
        std::cin >> codigo;
    }

