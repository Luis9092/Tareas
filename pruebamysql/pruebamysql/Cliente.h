#pragma once
#include "Cliente.h"
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;

class Cliente : Persona {

	void gotoxy(int x, int y)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}
	
private: string nit;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;

	}

	// METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { Nombres = nom; }
	void setApellidos(string ape) { Apellidos = ape; }
	void setDireccion(string dir) { Direccion = dir; }
	void setTelefono(int tel) { Telefono = tel; }
	void setFecha_Nacimiento(int fn) { Fecha_nacimiento = fn; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return Nombres; }
	string getApellidos() { return Apellidos; }
	string getDireccion() { return Direccion; }
	int getTelefono() { return Telefono; }
	string getFecha_Nacimiento() { return Fecha_nacimiento; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(Telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(Nit,Nombres,Apellidos,Direccion,Telefono,Fecha_nacimiento) VALUES ('" + nit + "','" + Nombres + "','" + Apellidos + "','" + Direccion + "'," + t + ",'" + Fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso, Grande Luis ... ..." << endl;
			}
			else {
				cout << "--------- Error al Ingresar Datos ---------" << endl;
			}
		}
		else {
			cout << "--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string a;
			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				gotoxy(0, 6); cout << "ID|" << "NIT |" << "NOMBRES |" << "APELLIDOS |" << "DIRECCION |" << "TELEFONO |      " << "FECHA NACIMIENTO       |";
				gotoxy(0, 7); cout << ("----------------------------------------------------------------------------------------------------------------");
				cout << ("\n");
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " |" << fila[1] << "|" << fila[2] << "|   " << fila[3] << "|  " << fila[4] << "|   " << fila[5] << "|    " << fila[6] << endl;
				}

			}
			else {
				cout << "--------- Error en la Base de datos  ---------" << endl;
			}

		}
		else {
			cout << "--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar(int id_Cliente) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string Id = to_string(id_Cliente);
			string nit2,nombre,ape,dire,fecha;
			int telefono=0;
			char z;
			string consulta2 = "select * from clientes where idClientes= " + Id + "";
			const char* c = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 8); cout << "Nit: " << fila[1];
					gotoxy(25, 9); cout << "Nombres: " << fila[2];
					gotoxy(25, 10); cout << "Apellidos: " << fila[3];
					gotoxy(25, 11); cout << "Direccion: " << fila[4];
					gotoxy(25, 12); cout << "Telefono: " << fila[5];
					gotoxy(25, 13); cout << "Fecha de Nacimiento; " << fila[6];
					
					cout << ("\n\nNit: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin>>z;
					if ((z == 's') || (z == 'S')) {
						cin.ignore();
						cout << "\ningrese el nuevo Nit: ";
						getline(cin, nit2);
						string consulta2 = "update clientes set Nit = '" + nit2 + "' where idClientes =" + Id + " ";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
					cin.ignore();
					cout << ("\n\nNombres: ") << fila[2] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						cin.ignore();
						cout << "\ningrese el nuevo Nombre: ";
						getline(cin, nombre);
						string consulta2 = "update clientes set Nombres = '" + nombre + "' where idClientes =" + Id + " ";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
						
					}
					cin.ignore();
					cout << ("\n\nApellidos: ") << fila[3] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						cin.ignore();
						cout << "\ningrese el nuevo Apellido: ";
						getline(cin, ape);
						string consulta2 = "update clientes set Apellidos = '" + ape + "' where idClientes =" + Id + " ";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);

					}
					cin.ignore();
					cout << ("\n\nDireccion: ") << fila[4] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						cin.ignore();
						cout << "\ningrese el nueva Direccion: ";
						getline(cin, dire);
						string consulta2 = "update clientes set Direccion = '" + dire + "' where idClientes =" + Id + " ";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);

					}
					
					cout << ("\n\nTelefono: ") << fila[5] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						
						cout << "\ningrese el nuevo No. Telefono: ";
						cin >> telefono;
						string tel = to_string(telefono);

						string consulta2 = "update clientes set Telefono = " + tel + " where idClientes =" + Id + " ";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);

					}
					cin.ignore();
					cout << ("\n\nFecha de Nacimiento: ") << fila[6] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						cin.ignore();
						cout << "\ningrese el nueva Fecha de nacimiento: ";
						getline(cin, fecha);
						string consulta2 = "update clientes set Fecha_nacimiento = '" + fecha + "' where idClientes =" + Id + " ";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
						cout << ("\n\n Datos Actualizados Correctamente, Grande Luis ...");
					}

				}

			}
			else {
				cout << "\n\n--------- Error al modificar  ---------" << endl;
			}

		}
		else {
			cout << " \n\n---------  Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar(int idCliente) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		char z;
		if (cn.getConectar()) {
			string Id = to_string(idCliente);
			// executar el query
			string eliminar = "select * from clientes where idClientes= " + Id + "";
			const char* c = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 8); cout << "Nit: " << fila[1];
					gotoxy(25, 9); cout << "Nombres: " << fila[2];
					gotoxy(25, 10); cout << "Apellidos: " << fila[3];
					gotoxy(25, 11); cout << "Direccion: " << fila[4];
					gotoxy(25, 12); cout << "Telefono: " << fila[5];
					gotoxy(25, 13); cout << "Fecha de Nacimiento; " << fila[6];
					
					gotoxy(25,20); cout << ("Desea Eliminar [s/n]: ");
					cin >> z;
					if((z=='s')||(z=='S')){
						string eliminar = "delete from clientes where idClientes =" + Id + "";
						const char* c = eliminar.c_str();
						q_estado = mysql_query(cn.getConectar(), c);

					cout << "\n\n\t\tEliminacion Exitosa, Grande Luis ..." << endl;
					}
					else {
						cout << ("\n\t\tRegistro No Eliminado");
					}
				}
			}
			else {
				cout << "\n\n\t\t--------- Error al eliminar  ---------" << endl;
			}
		}
		else {
			cout << "\n\n\t\t--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
};