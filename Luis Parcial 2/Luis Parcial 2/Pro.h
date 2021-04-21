#pragma once
#include "Producto.h"
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Pro.h"


using namespace std;

class Pro : Producto {

	void gotoxy(int x, int y)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}

private: int idmarca;
	   // constructor
public:
	Pro() {
	}
	Pro(string pro, string des, string ima, double pcos, double pven, int exis, string fn, int m) : Producto(pro, des, ima, pcos,pven,exis, fn) {
		idmarca = m;

	}

	// METODOS
	//set (modificar)
	void setproducto(string pro) { producto = pro; }
	void setdescripcion(string des) { descripcion = des; }
	void setimagen(string ima) { imagen = ima; }
	void setpcosto(double pcos) { pcosto = pcos; }
	void setpventa(double pven) { pventa = pven; }
	void setexistencia(int exis) { existencia = exis; }
	void setfecha(string fn) { fecha = fn; }
	void setidmarca(int m) { idmarca = m; }

	//get (mostrar)
	string getproducto() { return producto; }
	string getdescripcion() { return descripcion; }
	string getimagen() { return imagen; }
	double getpcosto() { return pcosto; }
    double getpventa() { return pventa; }
    int getexistencia() { return existencia; }
    string 	getfecha() { return fecha; }
    int	getidmarca() { return idmarca; }
    
	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string cos = to_string(pcosto);
		string ven = to_string(pventa);
		string et = to_string(existencia);
		string ma = to_string(idmarca);
	

		if (cn.getConectar()) {
			string  insertar = "INSERT INTO productos(Producto,Descripcion,Imagen,Precio_costo,Precio_venta,Existencia,Fecha_ingreso,Id_marca) VALUES ('" + producto + "','" + descripcion + "','" + imagen + "'," + cos + "," + ven + "," + et + "," + fecha + "," +ma + ")";
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
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " |" << fila[1] << "|" << fila[2] << "|   " << fila[3] << "|  " << fila[4] << "|   " << fila[5] << "|    " << fila[6]<<"  |" << fila[7]<<"  |" << fila[8]<<endl;
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
	void eliminar(int idpro) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		char z;
		if (cn.getConectar()) {
			string Id = to_string(idpro);
			// executar el query
			string eliminar = "select * from productos where Id_Producto= " + Id + "";
			const char* c = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 8); cout << "Producto: " << fila[1];
					gotoxy(25, 9); cout << "Descripcion: " << fila[2];
					gotoxy(25, 10); cout << "Imagen: " << fila[3];
					gotoxy(25, 11); cout << "Precio Costo: " << fila[4];
					gotoxy(25, 12); cout << "Precio Venta: " << fila[5];
					gotoxy(25, 13); cout << "Existencia: " << fila[6];
					gotoxy(25, 14); cout << "Fecha Ingreso: " << fila[7];
					gotoxy(25, 15); cout << "Id Marca: " << fila[8];

					gotoxy(25, 20); cout << ("Desea Eliminar [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						string eliminar = "delete from productos where Id_Producto =" + Id + "";
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
	void modificar(int idpro) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string Id = to_string(idpro);
			string pro, desc, ima, fech="now()";
			int exis=0,idmarc;
			double costop, ventap;
			char s;
			string consulta2 = "select * from productos where Id_Producto= " + Id + "";
			const char* c = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
		
				if (!q_estado) {
						resultado = mysql_store_result(cn.getConectar());

						while (fila = mysql_fetch_row(resultado)) {

							gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
							gotoxy(25, 8); cout << "Producto: " << fila[1];
							gotoxy(25, 9); cout << "Descripcion: " << fila[2];
							gotoxy(25, 10); cout << "Imagen: " << fila[3];
							gotoxy(25, 11); cout << "Precio Costo: " << fila[4];
							gotoxy(25, 12); cout << "Precio Venta: " << fila[5];
							gotoxy(25, 13); cout << "Existencia: " << fila[6];
							gotoxy(25, 14); cout << "Fecha Ingreso; " << fila[7];
							gotoxy(25, 15); cout << "Id Marca: " << fila[8];


							cout << ("\n\nProducto: ") << fila[1] << endl;
							cout << ("Desea modificarlo [s/n]: ");
							cin >> s;
							if ((s == 's') || (s == 'S')) {
								cout << "ingrese el nuevo Producto: \n";
								getline(cin, pro);
								string consulta2 = "update productos set Producto = '" + pro + "' where Id_Producto =" + Id + "";
								const char* c = consulta2.c_str();
								q_estado = mysql_query(cn.getConectar(), c);
							}
							cin.ignore();

							cout << ("\n\nDescripcion: ") << fila[2] << endl;
							cout << ("Desea modificarlo [s/n]: ");
							cin >> s;
							if ((s == 's') || (s == 'S')) {
								cin.ignore();

								cout << "ingrese el nueva descripcion: \n";
								getline(cin, desc);
								string consulta2 = "update productos set Descripcion = '" + desc + "' where Id_Producto =" + Id + "";
								const char* c = consulta2.c_str();
								q_estado = mysql_query(cn.getConectar(), c);
							}
							cin.ignore();

							cout << ("\n\nimagen: ") << fila[3] << endl;
							cout << ("Desea modificarlo [s/n]: ");
							cin >> s;
							if ((s == 's') || (s == 'S')) {
								cout << "ingrese la nueva imagen : \n";
								cin >> ima;
								string consulta2 = "update productos set Imagen = '" + ima + "' where Id_Producto =" + Id + "";
								const char* c = consulta2.c_str();
								q_estado = mysql_query(cn.getConectar(), c);
							}

							cout << ("\n\nPrecio Costo: ") << fila[4] << endl;
							cout << ("Desea modificarlo [s/n]: ");
							cin >> s;
							if ((s == 's') || (s == 'S')) {
								cout << "ingrese el nuevo precio costo: \n";
								cin >> costop;
								string uno = to_string(costop);
								string consulta2 = "update productos set Precio_costo = " + uno + " where Id_Producto =" + Id + "";
								const char* c = consulta2.c_str();
								q_estado = mysql_query(cn.getConectar(), c);
							}


							cout << ("\n\nPrecio Venta: ") << fila[5] << endl;
							cout << ("Desea modificarlo [s/n]: ");
							cin >> s;
							if ((s == 's') || (s == 'S')) {
								cout << "ingrese el nuevo precio venta: \n";
								cin >> ventap;
								string dos = to_string(ventap);
								string consulta2 = "update productos set Precio_venta = " + dos + " where Id_Producto =" + Id + "";
								const char* c = consulta2.c_str();
								q_estado = mysql_query(cn.getConectar(), c);
							}

							cout << ("\n\nExistencia: ") << fila[5] << endl;
							cout << ("Desea modificarlo [s/n]: ");
							cin >> s;
							if ((s == 's') || (s == 'S')) {
								cout << "ingrese el nueva existencia: \n";
								cin >> exis;
								string tres = to_string(exis);
								string consulta2 = "update productos set Existencia = " + tres + " where Id_Producto =" + Id + "";
								const char* c = consulta2.c_str();
								q_estado = mysql_query(cn.getConectar(), c);
							}

							

							cout << ("\n\nFecha ingreso: ") << fila[7] << endl;
							cout << ("Desea modificarlo [s/n]: ");
							cin >> s;
							if ((s == 's') || (s == 'S')) {
								cout << "ingrese la nueva fecha: \n";
								cin >> fecha;
								string consulta2 = "update productos set Fecha_ingreso = '" + fecha + "' where Id_Producto =" + Id + "";
								const char* c = consulta2.c_str();
								q_estado = mysql_query(cn.getConectar(), c);
							}
							cout << ("\n\nId Marca: ") << fila[8] << endl;
							cout << ("Desea modificarlo [s/n]: ");
							cin >> s;
							if ((s == 's') || (s == 'S')) {
								cout << "ingrese nuevo Id Marca: \n";
								cin >> idmarc;
								string cua = to_string(idmarc);
								string consulta2 = "update productos set Id_marca = '" + cua + "' where Id_Producto =" + Id + "";
								const char* c = consulta2.c_str();
								q_estado = mysql_query(cn.getConectar(), c);
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
};