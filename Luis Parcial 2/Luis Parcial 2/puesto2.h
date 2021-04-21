#pragma once
#include "Producto.h"
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "puesto2.h"


using namespace std;
class puesto2 : Marca {

	void gotoxy(int x, int y)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}

public:
	puesto2() {
	}
	puesto2(string zx) : Marca (zx) {

	}

	// METODOS
	//set (modificar)
	void setpuesto(string zx) { marca = zx; 
}

	//get (mostrar)
	string getpuesto() { return marca; }

	// metodo
	void inser() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();


		if (cn.getConectar()) {
			string  insertar = "INSERT INTO marcas(Marca) VALUES ('" + marca + "')";
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
	void mostrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string a;
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |" << fila[1]  << endl;
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

	void eliminar(int idmarca) {
	int q_estado;
	ConexionBD cn = ConexionBD();
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	cn.abrir_conexion();
	char z;
	if (cn.getConectar()) {
		string Id = to_string(idmarca);
		// executar el query
		string eliminar = "select * from marcas where Id_marca= " + Id + "";
		const char* c = eliminar.c_str();
		q_estado = mysql_query(cn.getConectar(), c);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());
			while (fila = mysql_fetch_row(resultado)) {

				gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
				gotoxy(25, 8); cout << "Marca: " << fila[1];
		
				gotoxy(25, 20); cout << ("Desea Eliminar [s/n]: ");
				cin >> z;
				if ((z == 's') || (z == 'S')) {
					string eliminar = "delete from marcas where Id_marca =" + Id + "";
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
	void modificar(int idmarca) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string Id = to_string(idmarca);
			string marca;
			char s;
			string consulta2 = "select * from marcas where Id_marca= " + Id + "";
			const char* c = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 8); cout << "Marca: " << fila[1];


					cout << ("\n\nMarca: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "ingrese el nueva marca: \n";
						cin >> marca;
						string consulta2 = "update marcas set Marca = '" + marca + "' where Id_marca =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
				
				}

			}else {
				cout << "\n\n--------- Error al modificar  ---------" << endl;
			}

		}else {
			cout << " \n\n---------  Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
};