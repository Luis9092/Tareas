// Luis Parcial 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include "Pro.h"
#include "puesto2.h"
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
void control2();
void control1();

void insertar_marca();
void eliminar_marca();
void mostrar_marca();
void modificar_marca();

int main() {
	control2();
}

void control2() {
	int a;
	do {
		system("cls");
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Tabla Marcas");
		gotoxy(50, 10); cout << ("2. Tabla Productos");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		system("cls");
		case 1:control1();
			break;

		case 2: system("cls");
			control();
			break;

		}
	} while (a != 3);
}

void control() {
	int a;
	do {
		system("cls");
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla productos");
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
void control1() {
	int a;
	do {
		system("cls");
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla marcas");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar datos");
		gotoxy(50, 11); cout << ("4. Modificar Datos");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_marca();
			break;

		case 2: system("cls");
			mostrar_marca();
			break;

		case 3:system("cls");
			eliminar_marca();
			break;
		case 4:system("cls");
			modificar_marca();
			break;
		}
	} while (a != 5);
}
void insertar_marca() {
	string marca;

	cin.ignore();
	cout << "Ingrese Marca: ";
	getline(cin, marca);

	puesto2 z = puesto2(marca);

	z.inser();

	system("pause");

}
void mostrar_marca() {
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D A S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "Marca |";
	cout << ("\n\n");
	puesto2 m = puesto2();
	m.mostrar();
	system("pause");
}
void eliminar_marca() {
	int idmarca;
	system("cls");
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idmarca;
	cin.ignore();
	puesto2 c = puesto2();
	c.eliminar(idmarca);

	system("pause");

}
void modificar_marca() {

	int id_marca;
	cout << ("__________________________________________________________________________________") << endl;
	cout << ("|                   M O D I F I C A R                D A T O S                    |") << endl;
	cout << ("|_________________________________________________________________________________|") << endl;
	cout << "\n\nIngrese el id del registro que desea modificar: ";
	cin >> id_marca;

	puesto2 m = puesto2();
	m.modificar(id_marca);
	system("pause");
}


void insertar()
{
	string producto, descrip, imagen;
	int existente, id;
	double pcostos, pventas;
	string fecha_ingreso = "now()";
	
	cin.ignore();
	cout << "Ingrese Producto: ";
	getline(cin, producto);
	cout << "Ingrese Descripcion: ";
	getline(cin, descrip);
	cout << "Ingrese Imagen: ";
	getline(cin, imagen);
	cout << "Ingrese Precio Costo: ";
	cin >> pcostos;
	cout << "Ingrese Precio Venta:";
	cin >> pventas;
	cin.ignore();
	cout << "Fecha existencia: ";
	cin >> existente;
	cout << "Ingrese Id Marca:";
	cin >> id;

	Pro c = Pro(producto, descrip, imagen,pcostos, pventas, existente,fecha_ingreso,id);

	c.crear();

	system("pause");

}
void mostrar() {
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D A S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "Producto |" << "Descripcion |" << " Imagen  |" << "Precio costo |" << "Precio Venta |" << "Existencia |    " << "Fecha Ingreso       |" << "Id marca";
	cout << ("\n\n\n");

	Pro c = Pro();
	c.leer();
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
	Pro c = Pro();
	c.eliminar(idCliente);

	system("pause");

}
void modificar() {

	int id_pro;
	cout << ("__________________________________________________________________________________") << endl;
	cout << ("|                   M O D I F I C A R                D A T O S                    |") << endl;
	cout << ("|_________________________________________________________________________________|") << endl;


	cout << "\n\nIngrese el id del registro que desea modificar: ";
	cin >> id_pro;

	Pro c = Pro();
	c.modificar(id_pro);

	system("pause");

}

