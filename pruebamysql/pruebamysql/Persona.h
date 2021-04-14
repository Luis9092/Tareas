#pragma once
#include "Persona.h"
#include <iostream>
using namespace std;
class Persona
{
	// atributos
protected: string Nombres, Apellidos, Direccion, Fecha_nacimiento;
		 int Telefono = 0;
		 // costructor
protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, int tel, string fn) {
		Nombres = nom;
		Apellidos = ape;
		Direccion = dir;
		Telefono = tel;
		Fecha_nacimiento = fn;
	}




};
