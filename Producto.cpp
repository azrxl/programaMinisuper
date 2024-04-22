#include "Producto.h"

Producto::Producto()
	: codigo{ "null" }, nombreComercial{ "null" }, descripcion{ "null" },
	precio{ 0.0 }, categoria{ -1 }, existencia{ 0 }, limite{ 0 }, id{ 0 } 
{
	fecha = getFecha();
}

Producto::Producto(string _codigo, string _nombreComercial, double _precio, int _categoria, int _existencia, int _limite)
	: codigo{ _codigo }, nombreComercial{ _nombreComercial }, descripcion{ "" }, id{ 0 },
	precio{ _precio }, categoria{ _categoria }, existencia{ _existencia }, limite{ _limite } {}

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
string Producto::getNombreComercial() const { return nombreComercial; }
string Producto::getCodigo() const { return codigo; }
double Producto::getPrecio() const { return precio; }
int Producto::getCategoria() const { return categoria; }
int Producto::getLimite() const { return limite; }
int Producto::getTotal() const { return 0; }
int Producto::getID() const { return id; }
int Producto::getExistencia() const { return existencia; }
string Producto::getFecha() const {
	return obtenerFecha();
}

string Producto::toString() const {
	std::stringstream s;
	s << "Codigo: " << codigo << "\n"
	  << "Nombre Comercial: " << nombreComercial << "\n"
   	  << "Descripcion: " << descripcion << "\n"
	  << "Precio: " << precio << "\n"
	  << "Categoria: " << categoria << "\n"
	  << "Existencia: " << existencia << "\n"
	  << "Limite: " << limite << "\n"
	  << "Fecha de ingreso: " << getFecha() << "\n";
	return s.str();
}

void Producto::setCodigo(string _codigo) { codigo = _codigo; }
void Producto::setNombreComercial(string _nombreComercial) { nombreComercial = _nombreComercial; }
void Producto::setCategoria(int _categoria) { categoria = _categoria; }
void Producto::setLimite(int _limite) { limite = _limite; }
void Producto::setFecha(string _fecha) { fecha = _fecha; }
void Producto::setPrecio(double _precio) { precio = _precio; }
void Producto::setExistencia(int _existencia) { existencia = _existencia; }

Producto& Producto::operator--() {
	existencia -= 1;
	return *this;
}

char* Producto::obtenerFecha() const {
	auto ahora = std::chrono::system_clock::now();
	std::time_t tiempoActual = std::chrono::system_clock::to_time_t(ahora);
	return std::ctime(&tiempoActual);
}
