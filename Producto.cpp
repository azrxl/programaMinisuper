#include "Producto.h"

Producto::Producto()
	: codigo{ "null" }, nombreComercial{ "null" }, descripcion{ "null" },
	precio{ 0.0 }, categoria{ -1 }, existencia{ 0 }, limite{ 0 } {
	fecha.dia = 0;
	fecha.mes = 0;
	fecha.anno = 0;
}
Producto::Producto(string _codigo, string _nombreComercial, string _descripcion, double _precio, int _categoria, int _existencia, int _limite, int dia, int mes, int anno)
	: codigo{ _codigo }, nombreComercial{ _nombreComercial }, descripcion{ _descripcion },
	precio{ _precio }, categoria{ _categoria }, existencia{ _existencia }, limite{ _limite } {
	fecha.dia = dia;
	fecha.mes = mes;
	fecha.anno = anno;
}
Producto::~Producto() {}

int Producto::porcentajeGanancia() const {
	if (categoria == 1)
		return 15;
	if (categoria == 2)
		return 20;
	if (categoria == 3)
		return 30;
	return 0;
}

string Producto::getNombre() const { return nombreComercial; }
string Producto::getCodigo() const { return codigo; }
double Producto::getPrecio() const { return precio; }

std::string Producto::getFecha() const {
	return std::to_string(fecha.dia) + "/" + std::to_string(fecha.mes) + "/" + std::to_string(fecha.anno);
}

string Producto::toString() const {
	std::stringstream s;
	s << "Código: " << codigo << "\n"
	  << "Nombre Comercial: " << nombreComercial << "\n"
   	  << "Descripción: " << descripcion << "\n"
	  << "Precio: " << precio << "\n"
	  << "Categoría: " << categoria << "\n"
	  << "Existencia: " << existencia << "\n"
	  << "Límite: " << limite << "\n"
	  << "Fecha de ingreso: " << getFecha() << "\n";
	return s.str();
}

void Producto::setCodigo(string _codigo) { codigo = _codigo; }
void Producto::setNombreComercial(string _nombreComercial) { nombreComercial = _nombreComercial; }
void Producto::setDescripcion(string _descripcion) { descripcion = _descripcion; }
void Producto::setCategoria(int _categoria) { categoria = _categoria; }
void Producto::setLimite(int _limite) { limite = _limite; }
void Producto::setPrecio(double _precio) { precio = _precio; }
void Producto::setExistencia(int _existencia) { existencia = _existencia; }
void Producto::setFecha(int dia, int mes, int anno) {
	fecha.dia = dia;
	fecha.mes = mes;
	fecha.anno = anno;
}
