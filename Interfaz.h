#pragma once
#include "Clases.h"

class Interfaz {
public:
    void menu();

private:
    void mostrarMenuPrincipal();
    void menuMantenimiento();
    void menuFacturas();
    void menuProductos();
    void menuVentas();
    void menuReportar();
    int obtenerOpcion(int min, int max);
    void gestionarFactura(const std::string& accion);
    void gestionarProducto(const std::string& accion);

	Lista<Producto*> listaProductos;
	Lista<Factura*> listaFacturas;
};

