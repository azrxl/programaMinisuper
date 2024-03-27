#pragma once
#include <string>
class Fecha
{
public:
	Fecha();
	Fecha(int, int, int);
	virtual ~Fecha();
	void setFecha(int, int, int);
	void setDia(int);
	void setMes(int);
	void setAnno(int);
	std::string getFecha() const;

private:
	int dia;
	int mes;
	int anno;

};

