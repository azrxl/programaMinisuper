#pragma once
#include "Clases.h"

class Interfaz {
public:
    void menu();
    void agregar(Producto*);
private:
    void mostrarMenuPrincipal();
    void menuMantenimiento();
    void menuFacturas();
    void menuProductos();
    void menuVentas();
    void menuReportar();
    void guardar();
    void cargar();
    int obtenerOpcion(int min, int max);
    void gestionarFactura(const std::string& accion);
    void gestionarProducto(const std::string& accion);
    void agregarProducto();
    void agregarConserva();
    void agregarAbarrote();
    void agregarCarne();
    void agregarEmbutido();
    void agregarFactura();

	Lista<Producto*> listaProductos;
	Lista<Factura*> listaFacturas;
};

