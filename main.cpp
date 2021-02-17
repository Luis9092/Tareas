#include "Empleado.cpp"

#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
using namespace std;



int main(){

string cod,nombres,apellidos,puesto;
float sueldo;

gotoxy(20,2);cout<<"Ingrese Codigo Empleado: ";
cin>>cod;

gotoxy(20,3);cout<<"Ingrese Nombres: ";
cin>>nombres;

gotoxy(20,4);cout<<"Ingrese Apellidos: ";
cin>>apellidos;

gotoxy(20,5);cout<<"Ingrese Puesto: ";
cin>>puesto;

gotoxy(20,6);cout<<"Ingrese sueldo: ";
cin>>sueldo;

Empleado obj = Empleado(nombres,apellidos,puesto,sueldo,cod);

	obj.mostrar();

}
