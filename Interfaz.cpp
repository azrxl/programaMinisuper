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
void Interfaz::agregar(Producto* lol)
{
    listaProductos.agregar(lol);
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
            system("cls");
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
                << "4. Factura por cliente" << '\n'
                << "5. Factura de los 5 mejores clientes" << '\n'
                << "6. Retornar" << '\n';
            opcion = obtenerOpcion(1, 6);
            system("cls");
            if (listaProductos.isEmpty() && listaFacturas.isEmpty()) {
                std::cout << "No hay elementos disponibles, volviendo al menu..\n";
                system("pause");
                system("cls");
                return;
            }
            switch (opcion) {
            case 1:
                if (listaProductos.isEmpty()) {
                    std::cout << "No hay elementos disponibles, volviendo al menu..\n";
                }
                else {
                    std::cout << listaProductos.toString(opcion);
                }
                break;
            case 2:
                int categoria;
                std::cout << "Ingrese la categoria del producto: "; categoria = obtenerOpcion(1,3);
                if (!listaProductos.buscar(categoria)) {
                    std::cout << "No hay elementos disponibles, volviendo al menu..\n";
                }
                else {
                    std::cout << "\nMostrando todos los productos con categoria " << categoria << ": \n";
                    std::cout << listaProductos.toString(opcion, categoria);
                }
                break;
            case 3:
                if (!listaProductos.buscar()) {
                    std::cout << "No hay elementos disponibles, volviendo al menu..\n";
                }
                else {
                    std::cout << "\nMostrando todos los productos por debajo del limite:";
                    std::cout << listaProductos.toString(opcion);
                }
                break;
            case 4: {
                std::string cedula;
                std::cout << "Ingrese la cedula del cliente o el numero de factura a reportar: "; std::cin >> cedula;
                if (!listaFacturas.buscar(cedula)) {
                    std::cout << "No hay elementos disponibles, volviendo al menu..\n";
                }
                else {
                    std::cout << "\nMostrando la factura:\n";
                    std::cout << listaFacturas.toString(cedula);
                }               
                break;
            }
            case 5:
                if (listaFacturas.isEmpty()) {
                    std::cout << "No hay elementos disponibles, volviendo al menu..\n";
                }
                else {
                    std::cout << "\nMostrando los 5 mejores clientes:\n";
                    std::cout << listaFacturas.toString(opcion);
                }
                break;
            case 6:
                return;
            }
            system("pause");
            system("cls");
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
    if (accion == "agregar") {
        agregarFactura();
    }
    else {
        if (listaFacturas.isEmpty()) {
            std::cout << "No hay facturas disponibles, volviendo al menu..\n";
            system("pause");
            system("cls");
            return;
        }
        std::string codigo;
        std::cout << "Mostrando facturas disponibles:\n" << listaFacturas.toString(1);
        std::cout << "Ingrese la cedula o el numero de factura a " << accion << ": "; std::cin >> codigo;
        if (accion == "eliminar") {
            if (listaFacturas.eliminar(codigo)) {
                std::cout << "\nFactura eliminada con exito, presione cualquier tecla para retornar.\n";
            }
            else {
                std::cout << "\nFallo al eliminar factura, presione cualquier tecla para retornar.\n";
            }
        }
        if (accion == "actualizar") {
            if (listaFacturas.actualizarFactura(codigo)) {
                std::cout << "\nFactura actualizada con exito, presione cualquier tecla para retornar.\n";
            }
            else {
                std::cout << "\nFallo al actualizar factura, presione cualquier tecla para retornar.\n";
            }
        }
        system("pause");
        system("cls");
    }
}
void Interfaz::gestionarProducto(const std::string& accion) {
        if (accion == "ingresar") {
            agregarProducto();
            system("cls");
        }
        else {
            if (listaProductos.isEmpty()) {
                std::cout << "No hay productos disponibles, volviendo al menu..\n";
                system("pause");
                system("cls");
                return; 
            }
            std::cout << "Mostrando productos disponibles:\n" << listaProductos.toString(0);
            std::cout << "Ingrese el codigo o el nombre comercial del producto a " << accion << ": ";
            if (accion == "eliminar") {
                std::string codigo;
                std::cin >> codigo;
                if (listaProductos.eliminar(codigo)) {
                    std::cout << "\nProducto eliminado con exito, presione cualquier tecla para retornar.\n";
                }
                else {
                    std::cout << "\nFallo al eliminar producto, presione cualquier tecla para retornar.\n";
                }
            }
            if (accion == "modificar") {
                std::string codigo;
                int codigo2;
                double codigo3 = 0.0;
                std::cin >> codigo;
                std::cout << "\n1. Modificar precio"
                    << "\n2. Modificar existencias\n";
                codigo2 = obtenerOpcion(1, 2);
                switch (codigo2) {
                case 1:
                    std::cout << "\nModificar precio a: "; std::cin >> codigo3;
                    break;
                case 2:
                    std::cout << "\nModificar existencias a: "; std::cin >> codigo3;
                    break;
                }
                if (listaProductos.modificarProducto(codigo2, codigo, codigo3)) {
                    std::cout << "\nProducto actualizado con exito, presione cualquier tecla para retornar.\n";
                }
                else {
                    std::cout << "\nFallo al actualizar producto, presione cualquier tecla para retornar.\n";
                }
            }
            system("pause");
            system("cls");
        }
    }
void Interfaz::agregarProducto() {
        int opcion = 0;
        while (opcion != 5) {
            std::cout << "------ INGRESO DE PRODUCTO ------" << '\n'
                << "1. Conserva" << '\n'
                << "2. Abarrote" << '\n'
                << "3. Carne" << '\n'
                << "4. Embutido" << '\n'
                << "5. Retornar" << '\n';
            opcion = obtenerOpcion(1,5);
            system("cls");
            switch (opcion) {
            case 1:
                agregarConserva();
                break;
            case 2:
                agregarAbarrote();
                break;
            case 3:
                agregarCarne();
                break;
            case 4:
                agregarEmbutido();
                break;
            }
        }
    }
void Interfaz::agregarConserva() {
        std::string aux1;
        int aux2;
        double aux3;
        bool aux4;
        Conserva* c = new Conserva;

        std::cout << "\nCodigo: "; std::cin >> aux1; c->setCodigo(aux1);
        std::cout << "\nNombre Comercial: "; std::cin >> aux1;  c->setNombreComercial(aux1);
        std::cout << "\nPrecio: "; std::cin >> aux3; c->setPrecio(aux3);
        std::cout << "\nCategoria: "; std::cin >> aux2; c->setCategoria(aux2);
        std::cout << "\nExistencia: "; std::cin >> aux2; c->setExistencia(aux2);
        std::cout << "\nLimite: "; std::cin >> aux2; c->setLimite(aux2);
        std::cout << "\nEnvasado (1 para true, 0 para false): "; std::cin >> aux4; c->setEnvasado(aux4);

        listaProductos.agregar(c);
    } 
void Interfaz::agregarAbarrote() {
        std::string aux1;
        int aux2;
        double aux3;
        Abarrote* c = new Abarrote;
        std::cout << "\nCodigo: "; std::cin >> aux1; c->setCodigo(aux1);
        std::cout << "\nNombre Comercial: "; std::cin >> aux1;  c->setNombreComercial(aux1);
        std::cout << "\nNombre Empresa: "; std::cin >> aux1; c->setNombreEmpresa(aux1);
        std::cout << "\nPrecio: "; std::cin >> aux3; c->setPrecio(aux3);
        std::cout << "\nCategoria: "; std::cin >> aux2; c->setCategoria(aux2);
        std::cout << "\nExistencia: "; std::cin >> aux2; c->setExistencia(aux2);
        std::cout << "\nLimite: "; std::cin >> aux2; c->setLimite(aux2);
        std::cout << "\nDia Vencimiento: "; std::cin >> aux2; c->setDia(aux2);
        std::cout << "\nMes Vencimiento: "; std::cin >> aux2; c->setMes(aux2);
        std::cout << "\nAnno Vencimiento: "; std::cin >> aux2; c->setAnno(aux2);

        listaProductos.agregar(c);
    }
void Interfaz::agregarCarne() {
        std::string aux1;
        int aux2;
        double aux3;
        Carne* c = new Carne;

        std::cout << "\nCodigo: "; std::cin >> aux1; c->setCodigo(aux1);
        std::cout << "\nNombre Comercial: "; std::cin >> aux1;  c->setNombreComercial(aux1);
        std::cout << "\nNombre Animal: "; std::cin >> aux1; c->setAnimal(aux1);
        std::cout << "\nParte Animal: "; std::cin >> aux1; c->setParte(aux1);
        std::cout << "\nPrecio: "; std::cin >> aux3; c->setPrecio(aux3);
        std::cout << "\nCategoria: "; std::cin >> aux2; c->setCategoria(aux2);
        std::cout << "\nExistencia: "; std::cin >> aux2; c->setExistencia(aux2);
        std::cout << "\nLimite: "; std::cin >> aux2; c->setLimite(aux2);
        std::cout << "\nDia Vencimiento: "; std::cin >> aux2; c->setDia(aux2);
        std::cout << "\nMes Vencimiento: "; std::cin >> aux2; c->setMes(aux2);
        std::cout << "\nAnno Vencimiento: "; std::cin >> aux2; c->setAnno(aux2);

        listaProductos.agregar(c);
    }
void Interfaz::agregarEmbutido() {
        std::string aux1;
        int aux2;
        double aux3;
        bool aux4;
        Embutido* c = new Embutido;

        std::cout << "\nCodigo: "; std::cin >> aux1; c->setCodigo(aux1);
        std::cout << "\nNombre Comercial: "; std::cin >> aux1;  c->setNombreComercial(aux1);
        std::cout << "\nMarca: "; std::cin >> aux1; c->setNombreComercial(aux1);
        std::cout << "\nEmpacado con tripa  (1 para true, 0 para false): "; std::cin >> aux4; c->setEmpaque(aux4);
        std::cout << "\nPrecio: "; std::cin >> aux3; c->setPrecio(aux3);
        std::cout << "\nCategoria: "; std::cin >> aux2; c->setCategoria(aux2);
        std::cout << "\nExistencia: "; std::cin >> aux2; c->setExistencia(aux2);
        std::cout << "\nLimite: "; std::cin >> aux2; c->setLimite(aux2);
        std::cout << "\nDia Vencimiento: "; std::cin >> aux2; c->setDia(aux2);
        std::cout << "\nMes Vencimiento: "; std::cin >> aux2; c->setMes(aux2);
        std::cout << "\nAnno Vencimiento: "; std::cin >> aux2; c->setAnno(aux2);
       
        listaProductos.agregar(c);
    }

void Interfaz::agregarFactura() {
    if (listaProductos.isEmpty()) {
        std::cout << "No hay productos disponibles, volviendo al menu..\n";
        system("pause");
        system("cls");
        return; // Salir del método si no hay productos disponibles
    }
    std::string cedula;
    unsigned int codigo = 0;
    bool repetir = true, agregado = false;
    Lista<Producto*> productosFactura; 

    std::cout << "Ingrese la cedula del cliente: "; std::cin >> cedula;
    system("cls");
    while (repetir) {
        if (listaProductos.outOfStock()) {
            std::cout << "Mostrando productos disponibles:\n" << listaProductos.toString(0);
            std::cout << "No quedan productos disponibles, realizando la factura..\n";
            system("pause");
            system("cls");
            break;
        }
        std::cout << "Mostrando productos disponibles:\n" << listaProductos.toString(0);
        std::cout << "Digite '0' para terminar de agregar productos..\n\n ";

        int producto;
        std::cout << "Ingrese el codigo del producto a agregar: "; std::cin >> producto;
        if (producto == 0)
            break; // Salir del bucle si el usuario ingresa 0

        Producto* dato = listaProductos.buscar(std::to_string(producto));
        if (!dato) {
            std::cout << "Producto no encontrado, intente de nuevo..\n";
            system("pause");
            system("cls");
            continue; // Volver al inicio del bucle
        }
        productosFactura.agregar(dato); // Agregar el producto a la factura
        agregado = true;
        listaProductos.actualizar(std::to_string(producto));
    }
    if (agregado) {
        Factura* factura = new Factura(std::to_string(++codigo), cedula, productosFactura);
        system("cls");
        std::cout << "Procesando factura..\n" << factura->toString();
        std::cout << "Presione cualquier tecla para pagar y continuar..\n\n ";
        system("pause");
        system("cls");
        listaFacturas.agregar(factura);
    }
    else {
        std::cout << "No se ingreso ningun producto, volviendo al menu..\n";
        system("pause");
        system("cls");
    }
}
