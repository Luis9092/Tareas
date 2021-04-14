// pruebamysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//#include "Cliente.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include "Cliente.h"
using namespace  std;
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void insertar();
void eliminar();
void mostrar();
void modificar();
void control();

int main() {
	control();
}
void control() {
	int a;
	do {
		system("cls");
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla puesto");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar dato");
		gotoxy(50, 11); cout << ("4. Modificar Datos");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar();
			break;

		case 2: system("cls");
			mostrar();
			break;

		case 3:system("cls");
			eliminar();
			break;
		case 4:system("cls");
			modificar();
			break;
		}
	} while (a != 5);
}


void insertar()
{
	string nit, nombre, apellidos, direccion, fecha_nacimiento;
	int telefono;
	cin.ignore();
	cout << "Ingrese Nit:";
	getline(cin, nit);
	cout << "Ingrese Nombres:";
	getline(cin, nombre);
	cout << "Ingrese Apellidos:";
	getline(cin, apellidos);
	cout << "Ingrese Direccion:";
	getline(cin, direccion);
	cout << "Ingrese Telefono:";    
	cin >> telefono;
	cin.ignore();
	cout << "Fecha Nacimiento:";
	cin >> fecha_nacimiento;

	Cliente c = Cliente(nombre, apellidos, direccion, telefono, fecha_nacimiento, nit);

	c.crear();
	
	system("pause");
	
}
void mostrar() {
	Cliente c = Cliente();
	c.leer();
	system("pause");
}

void modificar() {
	
	int id_Cliente;
 cout << ("__________________________________________________________________________________")<<endl;
 cout << ("|                   M O D I F I C A R                D A T O S                    |") << endl;
 cout << ("|_________________________________________________________________________________|") << endl;


	cout << "\nIngrese el id del registro que desea modificar: ";
	cin >> id_Cliente;

	Cliente c = Cliente();
	c.modificar(id_Cliente);

	system("pause");
	
}


void eliminar() {
	int idCliente;
	system("cls");
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idCliente;
	cin.ignore();
	Cliente c = Cliente();
	c.eliminar(idCliente);

	system("pause");

}