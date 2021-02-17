//Empleado
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

using namespace std;


class Personaj{
	
	protected: string nombres, apellidos, puesto;
	
	float sueldo;
	
	protected:
		Personaj(){
		}
		Personaj(string nomb, string apell, string  pues, float su){
		nombres = nomb;
		apellidos= apell;
		puesto=pues;
		sueldo= su;
		}
		
		void mostrar();
};
