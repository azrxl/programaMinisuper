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
            switch (opcion) {
            case 1:
                std::cout << listaProductos.toString(opcion);
                break;
            case 2:
                int categoria;
                std::cout << "Ingrese la categoria del producto: "; categoria = obtenerOpcion(1,3);
                std::cout << "\nMostrando todos los productos con categoria " << categoria << ": \n";
                std::cout << listaProductos.toString(opcion, categoria);
                break;
            case 3:
                std::cout << "\nMostrando todos los productos por debajo del limite:";
                std::cout << listaProductos.toString(opcion);
                break;
            case 4: {
                std::string cedula;
                std::cout << "Ingrese la cedula del cliente o el numero de factura a reportar: "; std::cin >> cedula;
                std::cout << "\nMostrando la factura:\n";
                std::cout << listaProductos.toString(cedula);
                break;
            }
            case 5:
                std::cout << "\nMostrando los 5 mejores clientes:\n";
                std::cout << listaProductos.toString(opcion);
                break;
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
    std::string codigo;
    std::cout << "Ingrese la cedula del cliente o el numero de factura a " << accion << ": ";
    std::cin >> codigo;
    if (accion == "agregar") {
        
    }
    if (accion == "eliminar") {

    }
    if (accion == "actualizar") {

    }
}
void Interfaz::gestionarProducto(const std::string& accion) {
        if (accion == "ingresar") {
            agregarProducto();
        }
        if (accion == "eliminar") {
            std::string codigo;
            std::cout << "Ingrese el codigo o el nombre comercial del producto a " << accion << ": ";
            std::cin >> codigo;
            listaProductos.eliminar(codigo);
        }
        if (accion == "modificar") {
            std::string codigo;
            int codigo2;
            double codigo3 = 0.0;
            std::cout << "Ingrese el codigo o el nombre comercial del producto a " << accion << ": "; std::cin >> codigo;
            std::cout << "\n1. Modificar precio" 
                      << "\n2. Modificar existencias\n"; 
            codigo2 = obtenerOpcion(1,2);
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

        std::cout << "\nCódigo: "; std::cin >> aux1; c->setCodigo(aux1);
        std::cout << "\nNombre Comercial: "; std::cin >> aux1;  c->setNombreComercial(aux1);
        std::cout << "\nDescripción: "; std::cin >> aux1; c->setDescripcion(aux1);
        std::cout << "\nPrecio: "; std::cin >> aux3; c->setPrecio(aux3);
        std::cout << "\nCategoría: "; std::cin >> aux2; c->setCategoria(aux2);
        std::cout << "\nExistencia: "; std::cin >> aux2; c->setExistencia(aux2);
        std::cout << "\nLímite: "; std::cin >> aux2; c->setLimite(aux2);
        std::cout << "\nFecha de ingreso:\n";
        std::cout << "\nDia: "; std::cin >> aux2; int dia = aux2;
        std::cout << "\nMes: "; std::cin >> aux2; int mes = aux2;
        std::cout << "\nAnno: "; std::cin >> aux2; int anno = aux2;
        c->setFecha(dia, mes, anno);
        std::cout << "\nEnvasado (1 para true, 0 para false): "; std::cin >> aux4;
        c->setEnvasado(aux4);

        listaProductos.agregar(c);
    } 
void Interfaz::agregarAbarrote() {
        std::string aux1;
        int aux2;
        double aux3;
        Abarrote* c = new Abarrote;

        std::cout << "\nCódigo: "; std::cin >> aux1; c->setCodigo(aux1);
        std::cout << "\nNombre Comercial: "; std::cin >> aux1; c->setNombreComercial(aux1);
        std::cout << "\nNombre Empresa: "; std::cin >> aux1; c->setNombreComercial(aux1);
        std::cout << "\nDescripción: "; std::cin >> aux1; c->setDescripcion(aux1);
        std::cout << "\nPrecio: "; std::cin >> aux3; c->setPrecio(aux3);
        std::cout << "\nCategoría: "; std::cin >> aux2; c->setCategoria(aux2);
        std::cout << "\nExistencia: "; std::cin >> aux2; c->setExistencia(aux2);
        std::cout << "\nLímite: "; std::cin >> aux2; c->setLimite(aux2);
        std::cout << "\nFecha de ingreso:\n";
        std::cout << "\nDia: "; std::cin >> aux2; int dia = aux2;
        std::cout << "\nMes: "; std::cin >> aux2; int mes = aux2;
        std::cout << "\nAnno: "; std::cin >> aux2; int anno = aux2;
        c->setFecha(dia, mes, anno);
        std::cout << "\nDia Vencimiento: "; std::cin >> aux2; dia = aux2;
        std::cout << "\nMes Vencimiento: "; std::cin >> aux2; mes = aux2;
        std::cout << "\nAnno Vencimiento: "; std::cin >> aux2; anno = aux2;
        c->setFechaVencimiento(dia, mes, anno);

        listaProductos.agregar(c);
    }
void Interfaz::agregarCarne() {
        std::string aux1;
        int aux2;
        double aux3;
        Carne* c = new Carne;

        std::cout << "\nCódigo: "; std::cin >> aux1; c->setCodigo(aux1);
        std::cout << "\nNombre Comercial: "; std::cin >> aux1; c->setNombreComercial(aux1);
        std::cout << "\nNombre Animal: "; std::cin >> aux1; c->setAnimal(aux1);
        std::cout << "\nParte Animal: "; std::cin >> aux1; c->setParte(aux1);
        std::cout << "\nDescripción: "; std::cin >> aux1; c->setDescripcion(aux1);
        std::cout << "\nPrecio: "; std::cin >> aux3; c->setPrecio(aux3);
        std::cout << "\nCategoría: "; std::cin >> aux2; c->setCategoria(aux2);
        std::cout << "\nExistencia: "; std::cin >> aux2; c->setExistencia(aux2);
        std::cout << "\nLímite: "; std::cin >> aux2; c->setLimite(aux2);
        std::cout << "\nFecha de ingreso:\n";
        std::cout << "\nDia: "; std::cin >> aux2; int dia = aux2;
        std::cout << "\nMes: "; std::cin >> aux2; int mes = aux2;
        std::cout << "\nAnno: "; std::cin >> aux2; int anno = aux2;
        c->setFecha(dia, mes, anno);
        std::cout << "\nDia Vencimiento: "; std::cin >> aux2; dia = aux2;
        std::cout << "\nMes Vencimiento: "; std::cin >> aux2; mes = aux2;
        std::cout << "\nAnno Vencimiento: "; std::cin >> aux2; anno = aux2;
        c->setFechaVencimiento(dia, mes, anno);

        listaProductos.agregar(c);
    }
void Interfaz::agregarEmbutido() {
        std::string aux1;
        int aux2;
        double aux3;
        bool aux4;
        Embutido* c = new Embutido;

        std::cout << "\nCódigo: "; std::cin >> aux1; c->setCodigo(aux1);
        std::cout << "\nNombre Comercial: "; std::cin >> aux1; c->setNombreComercial(aux1);
        std::cout << "\nMarca: "; std::cin >> aux1; c->setNombreComercial(aux1);
        std::cout << "\nDescripción: "; std::cin >> aux1; c->setDescripcion(aux1);
        std::cout << "\nPrecio: "; std::cin >> aux3; c->setPrecio(aux3);
        std::cout << "\nCategoría: "; std::cin >> aux2; c->setCategoria(aux2);
        std::cout << "\nExistencia: "; std::cin >> aux2; c->setExistencia(aux2);
        std::cout << "\nLímite: "; std::cin >> aux2; c->setLimite(aux2);
        std::cout << "\nFecha de ingreso:\n";
        std::cout << "\nDia: "; std::cin >> aux2; int dia = aux2;
        std::cout << "\nMes: "; std::cin >> aux2; int mes = aux2;
        std::cout << "\nAnno: "; std::cin >> aux2; int anno = aux2;
        c->setFecha(dia, mes, anno);
        std::cout << "\nDia Vencimiento: "; std::cin >> aux2; dia = aux2;
        std::cout << "\nMes Vencimiento: "; std::cin >> aux2; mes = aux2;
        std::cout << "\nAnno Vencimiento: "; std::cin >> aux2; anno = aux2;
        c->setFechaVencimiento(dia, mes, anno);
        std::cout << "\nEmpacado con tripa  (1 para true, 0 para false): "; std::cin >> aux4; c->setEmpaque(aux4);

        listaProductos.agregar(c);
    }

void Interfaz::agregarFactura() {
    std::string aux1;
    int aux2;
    double aux3;
    bool aux4;
    Conserva* c = new Conserva;

    std::cout << "\nCódigo: "; std::cin >> aux1; c->setCodigo(aux1);
    std::cout << "\nNombre Comercial: "; std::cin >> aux1;  c->setNombreComercial(aux1);
    std::cout << "\nDescripción: "; std::cin >> aux1; c->setDescripcion(aux1);
    std::cout << "\nPrecio: "; std::cin >> aux3; c->setPrecio(aux3);
    std::cout << "\nCategoría: "; std::cin >> aux2; c->setCategoria(aux2);
    std::cout << "\nExistencia: "; std::cin >> aux2; c->setExistencia(aux2);
    std::cout << "\nLímite: "; std::cin >> aux2; c->setLimite(aux2);
    std::cout << "\nFecha de ingreso:\n";
    std::cout << "\nDia: "; std::cin >> aux2; int dia = aux2;
    std::cout << "\nMes: "; std::cin >> aux2; int mes = aux2;
    std::cout << "\nAnno: "; std::cin >> aux2; int anno = aux2;
    c->setFecha(dia, mes, anno);
    std::cout << "\nEnvasado (1 para true, 0 para false): "; std::cin >> aux4;
    c->setEnvasado(aux4);

    listaProductos.agregar(c);
}
