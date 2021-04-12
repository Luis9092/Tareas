// pruebamysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void modificar2();
void modificar();
void eliminar2();
void insertar2();
void mostrar2();
void eliminar();
void insertar();
void mostrar();
void control();
void control2();
void control3();
int q_estado;

int main() {
	control();
}

void control() {
	int a;
	do{
	system("cls");
	gotoxy(35, 3); cout << ("----------       M E N U     D E    O P C I O N E S        ---------");
	gotoxy(50, 8); cout << ("1. Tabla Marcas");
	gotoxy(50, 10); cout << ("2. Tabla Productos");
	gotoxy(50, 12); cout << ("3. Salir");
	gotoxy(50, 18); cout << ("Ingresar Opcion: ");
	cin >> a;
	switch (a) {
	case 1: control2();
		break;

	case 2: control3();
		break;
	}
	} while (a != 3);
}

void control2() {
	int a;
	do{
		system("cls");
		gotoxy(35,3); cout << ("-------------    T A B L A        M A R C A S    -------------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla Marcas");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar dato");
		gotoxy(50, 11); cout << ("4. Modificar Dato");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 18); cout << ("Ingresar Opcion: ");
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
	
	case 4: system("cls");
		modificar();
	}
	} while (a !=5 );
}
void control3() {
	int a;
	do {
		system("cls");
		gotoxy(35, 3); cout << ("----------      T A B L A     P R O D U C T O S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla Productos");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar dato");
		gotoxy(50, 11); cout << ("4. Modificar dato");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar2();
			break;

		case 2: system("cls");
			mostrar2();
			break;

		case 3:system("cls");
			eliminar2();
			break;

		case 4: system("cls");
			modificar2();
			break;
		}
	} while (a != 5);
}


void insertar() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "CRUD", "terremoto123", "db_mercado", 3306, NULL, 0);
	if (conectar) {
		string marca;
		cout << "Ingrese Marca:";
		cin >> marca;


		string insertar = "insert into marcas(Marca) values('" + marca + "')";
		const char* i = insertar.c_str();

		// executar el query
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {

			cout << "Ingreso Exitoso ..." << endl;
		}
		else {
			cout << " xxx Error al Ingresar xxx" << endl;
		}
	}else {
		cout << " xxx Error en la Conexion xxxx" << endl;
}
system("pause");

}


void mostrar() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "CRUD", "terremoto123", "db_mercado", 3306, NULL, 0);
	gotoxy(20, 2);cout << ("__________________________________________________________________________________");
	gotoxy(20, 3);cout << ("|                    P A L A B R A S       G U A R D A D A S                      |");
	gotoxy(20, 4);cout << ("|_________________________________________________________________________________|");
	gotoxy(25,8); cout << "------------ Datos Tabla Puestos ------------" << endl;

	string consulta = "select * from marcas";

	const char* c = consulta.c_str();

	q_estado = mysql_query(conectar, c);

	if (!q_estado) {
		resultado = mysql_store_result(conectar);

		while (fila = mysql_fetch_row(resultado)) {

			cout<<"\t\t\t\t\t" << fila[0] << ". " << fila[1] << endl;
		}
	}else {
		cout << " xxx Error al Consultar xxx" << endl;
	}

	system("pause");
}

void eliminar(){
	MYSQL* conectar;
	conectar = mysql_init(0);
conectar = mysql_real_connect(conectar, "localhost", "CRUD", "terremoto123", "db_mercado", 3306, NULL, 0);
if (conectar) {
	string ID2;
	gotoxy(20, 2);cout << ("__________________________________________________________________________________");
	gotoxy(20, 3);cout << ("|                      E L I M I N A R         P A L A B R A                      |");
	gotoxy(20, 4);cout << ("|_________________________________________________________________________________|");

	gotoxy(20, 8);cout << "Ingrese el id de la marca que desea eliminar";
	cin >> ID2;
	string eliminar = "delete from marcas where Id_marca =" + ID2 + "";
	const char* f = eliminar.c_str();
	q_estado = mysql_query(conectar, f);

	if (!q_estado) {
		cout << ("\n\t\tDatos Eliminados Correctamente");
}
}else {
	cout << "Error en la conexion\n";
}
system("pause");
}

void modificar(){
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "CRUD", "terremoto123", "db_mercado", 3306, NULL, 0);
if (conectar) {
	
	string idmarca, marca;
	char s;
	gotoxy(20, 2);cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(20, 4);cout << ("|_________________________________________________________________________________|");
	
	gotoxy(20, 6); cout << "Ingrese el id del registro que desea modificar: ";
	cin >> idmarca;
	string consulta = "select * from marcas where Id_marca=" + idmarca + "";
	const char* m = consulta.c_str();
	q_estado = mysql_query(conectar, m);

	if (!q_estado) {
		
		resultado = mysql_store_result(conectar);

		while (fila = mysql_fetch_row(resultado)) {

			gotoxy(25, 10); cout <<"Id Marca: "<< fila[0];
			gotoxy(25, 11); cout << ("Marca: ") << fila[1] << endl;
			cout << ("Desea modificarlo [s/n]: ");
			cin >> s;
			if ((s=='s')||(s=='S')){
				cout << "ingrese el nuevo nombre de la marca: \n";
				cin >> marca;
				string modificar = "update marcas set Marca = '" + marca + "' where Id_marca =" + idmarca + "";
				const char* m = modificar.c_str();
				q_estado = mysql_query(conectar, m);
			}else {
				cout << ("Bien hecho crack")<<endl;
			}
		}
		}
	else {
		cout << "Error al modificar\n";
	}
}
else {
	cout << "Error en la conexion\n";
}
system("pause");
}
void insertar2() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "CRUD", "terremoto123", "db_mercado", 3306, NULL, 0);

	if (conectar) {
		string Fecha_ingreso = "now()";
		string producto, Descripcion, Precio_costo, Precio_venta, Existencia, Id_marca;
		gotoxy(20, 2); cout << ("__________________________________________________________________________________");
		gotoxy(20, 3); cout << ("|                    I N S E R T A R            P A L A B R A                     |");
		gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
		cin.ignore();
		gotoxy(25, 8); cout << "Ingrese producto:";
		getline(cin,producto);
		cin.ignore();
		gotoxy(25, 9); cout << "Ingrese Descripcion:";
		getline(cin,Descripcion);

		gotoxy(25, 10); cout << "Ingrese Precio costo:";
		cin >> Precio_costo;


		gotoxy(25, 11); cout << "Ingrese Precio Venta:";
		cin >> Precio_venta;

		gotoxy(25, 12); cout << "Ingrese Existencia:";
		cin >> Existencia;

		gotoxy(25, 13); cout << "Ingrese Id Marca:";
		cin >> Id_marca;

		string insertar2 = "insert into productos(Producto,Descripcion,Precio_costo,Precio_venta,Existencia,Fecha_ingreso,Id_marca) values(' " + producto + " ',' " + Descripcion + " '," + Precio_costo + " , " + Precio_venta + " ," + Existencia + " ," + Fecha_ingreso + "," + Id_marca + ")";
		const char* a = insertar2.c_str();

		// executar el query
		q_estado = mysql_query(conectar, a);

		if (!q_estado) {

			cout << "\n\t\t\t------------- Ingreso Exitoso --------------" << endl;
		}
		else {
			cout << "\n\t\t\t-------------   Eror al Ingresar  -----------------" << endl;
		}
	}
	else {
		cout << " ---- Error en la Conexion -----" << endl;
	}
	system("pause");
}
void mostrar2() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;

	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "CRUD", "terremoto123", "db_mercado", 3306, NULL, 0);

	if (conectar) {
		cout << "Conexion exitosa\n";
		string consulta = "select * from productos";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			gotoxy(20, 2); cout << ("__________________________________________________________________________________");
			gotoxy(20, 3); cout << ("|                    P A L A B R A S       G U A R D A D A S                      |");
			gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
			gotoxy(0, 6); cout << "ID |" << "Producto |" << "Descripcion |" << "Precio costo |" << "Precio Venta |" << "Existencia |      " << "Fecha Ingreso       |" << "Id marca";
			gotoxy(0, 7); cout << ("----------------------------------------------------------------------------------------------------------------");
			cout << ("\n");
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << " |" << fila[1] << "     |" << fila[2] << "   |" << fila[3] << "        |" << fila[4] << "        |" << fila[5] << "        |" << fila[6] << "       |" << fila[7] << endl;
			}
		}
		else {
			cout << "No hay datos registrados\n";
		}
	}
	else {
		cout << "Error en la conexion\n";
	}
	cout << ("\n\n\n\n");
	system("pause");
}

void eliminar2() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "CRUD", "terremoto123", "db_mercado", 3306, NULL, 0);
	string Id_Producto;
	if (conectar) {

		gotoxy(20, 2);
		cout << ("__________________________________________________________________________________");
		gotoxy(20, 3);
		cout << ("|                      E L I M I N A R         P A L A B R A                      |");
		gotoxy(20, 4);
		cout << ("|_________________________________________________________________________________|");
		gotoxy(25, 10); cout << "Ingrese el Id del producto que desea eliminar :";
		cin >> Id_Producto;
		string eliminar = "delete from productos where Id_producto =" + Id_Producto + "";
		const char* d = eliminar.c_str();
		q_estado = mysql_query(conectar, d);
		if (!q_estado) {
			cout << "Eliminacion exitosa\n";
		}
		else {
			cout << "Error al eliminar\n";
		}
	}
	else {
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void modificar2() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "CRUD", "terremoto123", "db_mercado", 3306, NULL, 0);
	if (conectar) {
		string ID, pro,desc,pcosto,pventa,exis,idmarc;
		string fecha = "now()";
		char s;
		gotoxy(20, 2); cout << ("__________________________________________________________________________________");
		gotoxy(20, 3); cout << ("|                   M O D I F I C A R                D A T O S                    |");
		gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");

		gotoxy(20, 6); cout << "Ingrese el id del registro que desea modificar\n";
		cin >> ID;
		string consulta = "select * from productos where Id_Producto=" + ID + "";
		const char* m = consulta.c_str();
		q_estado = mysql_query(conectar, m);

		if (!q_estado) {
			resultado = mysql_store_result(conectar);

			while (fila = mysql_fetch_row(resultado)) {

				gotoxy(30, 4); cout << "------------    [" << fila[0] << "]     ------------- ";
				gotoxy(25, 5); cout << "Producto: " << fila[1];
				gotoxy(25, 6); cout << "Descripcion: " << fila[2];
				gotoxy(25, 7); cout << "Precio Costo: " << fila[3];
				gotoxy(25, 8); cout << "Precio Venta: " << fila[4];
				gotoxy(25, 9); cout << "Existencia: " << fila[5];
				gotoxy(25, 10); cout << "Fecha Ingreso; " << fila[6];
				gotoxy(25, 11); cout << "Id Marca: " << fila[7];

				
				cout << ("\n\nProducto: ") << fila[1] << endl;
				cout << ("Desea modificarlo [s/n]: ");
				cin >> s;
				if ((s == 's') || (s == 'S')) {
					cout << "ingrese el nuevo Producto: \n";
					getline(cin, pro);
					string modificar = "update productos set Producto = '" + pro + "' where Id_Producto =" + ID + "";
					const char* m = modificar.c_str();
					q_estado = mysql_query(conectar, m);
				}
				cin.ignore();

				cout << ("\n\nDescripcion: ") << fila[2] << endl;
				cout << ("Desea modificarlo [s/n]: ");
				cin >> s;
				if ((s == 's') || (s == 'S')) {
					cin.ignore();

					cout << "ingrese el nueva descripcion: \n";
					getline(cin, desc);
					string modificar = "update productos set Descripcion = '" + desc + "' where Id_Producto =" + ID + "";
					const char* m = modificar.c_str();
					q_estado = mysql_query(conectar, m);
				}
				cin.ignore();

				cout << ("\n\nPrecio Costo: ") << fila[3] << endl;
				cout << ("Desea modificarlo [s/n]: ");
				cin >> s;
				if ((s == 's') || (s == 'S')) {
					cout << "ingrese el nuevo precio costo: \n";
					cin >> pcosto;
					string modificar = "update productos set Precio_costo = '" + pcosto + "' where Id_Producto =" + ID + "";
					const char* m = modificar.c_str();
					q_estado = mysql_query(conectar, m);
				}

				cout << ("\n\nPrecio Venta: ") << fila[4] << endl;
				cout << ("Desea modificarlo [s/n]: ");
				cin >> s;
				if ((s == 's') || (s == 'S')) {
					cout << "ingrese el nuevo precio venta: \n";
					cin >> pventa;
					string modificar = "update productos set Precio_venta = '" + pventa + "' where Id_Producto =" + ID + "";
					const char* m = modificar.c_str();
					q_estado = mysql_query(conectar, m);
				}
				
				cout << ("\n\nExistencia: ") << fila[5] << endl;
				cout << ("Desea modificarlo [s/n]: ");
				cin >> s;
				if ((s == 's') || (s == 'S')) {
					cout << "ingrese el nueva existencia: \n";
					cin >> exis;
					string modificar = "update productos set Existencia = '" + exis + "' where Id_Producto =" + ID + "";
					const char* m = modificar.c_str();
					q_estado = mysql_query(conectar, m);
				}

				cin.ignore();

				cout << ("\n\nFecha ingreso: ") << fila[6] << endl;
				cout << ("Desea modificarlo [s/n]: ");
				cin >> s;
				if ((s == 's') || (s == 'S')) {
					cout << "ingrese el nuevo precio costo: \n";
					cin >> fecha;
					string modificar = "update productos set Fecha_ingreso = '" +fecha + "' where Id_Producto =" + ID + "";
					const char* m = modificar.c_str();
					q_estado = mysql_query(conectar, m);
				}
				cout << ("\n\nId Marca: ") << fila[7] << endl;
				cout << ("Desea modificarlo [s/n]: ");
				cin >> s;
				if ((s == 's') || (s == 'S')) {
					cout << "ingrese nuevo Id Marca: \n";
					cin >> idmarc;
					string modificar = "update productos set Id_marca = '" + idmarc + "' where Id_Producto =" + ID + "";
					const char* m = modificar.c_str();
					q_estado = mysql_query(conectar, m);
				}
		}
		}
		else {
			cout << "\nError al modificar\n";
		}
	}
	else {
		cout << "\nError en la conexion\n";
	}
	cout << ("\n\n\n\n");
	system("pause");
}