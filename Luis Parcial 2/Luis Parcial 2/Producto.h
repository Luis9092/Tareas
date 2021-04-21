#pragma once
#include "Producto.h"
#include <iostream>
using namespace std;
class Producto
{
	// atributos
protected: string producto, descripcion, imagen, fecha;
		 int existencia = 0;
		 double pcosto = 0, pventa = 0;

		 // costructor
protected:
	Producto() {
	}
	Producto(string pro, string des, string ima, double pcos, double pven, int exis, string fn) {
		producto = pro;
		descripcion = des;
		imagen = ima;
		pcosto = pcos;
		pventa = pven;
		existencia = exis;
		fecha = fn;
	}
};
class Marca
{
	// atributos
protected: string marca;
		 
		 // costructor
protected:
	Marca() {
	}
	Marca( string zx) {
		marca = zx;
	}
};