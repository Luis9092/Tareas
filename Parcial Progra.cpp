// Luis Fernando Paxel Cojolon        Carne: 1290-20-388   Pacial 1
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#define s 40
using namespace std;
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void cambiarcolor(int X)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
}
void fondo()
{
    system("COLOR f3");
}

void co(int, int);
const char *nombe_archivo = "parcial.dat";
const char *nom_temporal = "tempo10.dat";

struct Datos
{
    int Codigo_empleado;
    char Nombre[s];
    char Apellido[s];
    char Puesto[s];
    double sueldo_base;
    double Bonificacion;
    double total;
};
void Eliminar_registro();
void ingresar_registro();
void mostrar_Registro();
void control();
void modificar_Registro();
void buscar();

int main()
{
    control();
}

void control()
{
    int a, b, c;
    do
    {
        fondo();
        system("cls");
        co(0, 241);
        gotoxy(35,2);cout<<("|**********************************************************|");
        gotoxy(35,3);cout<<("|**      M E N U          D E        O P C I O N E S     **|");
        gotoxy(35,4);cout<<("|**********************************************************|");
        gotoxy(50, 8);
        cout << (" 1. Insertar  Registro");
        gotoxy(50, 9);
        cout << (" 2. Mostrar Registro");
        gotoxy(50, 10);
        cout << (" 3. Eliminar Registro");
        gotoxy(50, 11);
        cout << (" 4. Buscar Registro");
        gotoxy(50, 12);
        cout << (" 5. Modificar Registro");
        gotoxy(50, 13);
        cout << (" 6. Salir");
        gotoxy(50, 18);
        cout << ("Ingrese opcion: ");
        cin >> a;
        switch (a)
        {
        case 1:
            system("cls");
            ingresar_registro();
            break;
        case 2:
            system("cls");
            mostrar_Registro();
            break;
        case 3:
            system("cls");
            Eliminar_registro();
            break;
        case 4:
            system("cls");
            buscar();
            break;

        case 5:
            system("cls");
            modificar_Registro();
            break;
        }
    } while (a != 6);
}

void ingresar_registro()
{
    char continuar;
    FILE *archivo = fopen(nombe_archivo, "ab"); // ab
    Datos persona;
        string Nombre,Apellido, Puesto;
    do
    {
        system("cls");
        fflush(stdin);
        persona.Codigo_empleado = 0;
        persona.Codigo_empleado = persona.Codigo_empleado + 1;
        gotoxy(20, 5);
        cout << "Ingrese Nombres: ";
        getline(cin, Nombre);
        strcpy(persona.Nombre, Nombre.c_str());

        gotoxy(20, 7);
        cout << "Ingrese Apellidos: ";
        getline(cin, Apellido);
        strcpy(persona.Apellido, Apellido.c_str());

        gotoxy(20, 9);
        cout << "Ingrese Puesto: ";
        getline(cin, Puesto);
        strcpy(persona.Puesto, Puesto.c_str());

        gotoxy(20, 11);
        cout << "sueldo Base :  Q.";
        cin >> persona.sueldo_base;
        cin.ignore();

        gotoxy(20, 13);
        cout << "Bonificacion:  Q.";
        cin >> persona.Bonificacion;
        cin.ignore();
        persona.total = persona.sueldo_base + persona.Bonificacion;

        fwrite(&persona, sizeof(Datos), 1, archivo);

        gotoxy(20, 20);
        cout << "Desea Agregar otro registro [s/n] : ";
        cin >> continuar;
    } while ((continuar == 's') || (continuar == 'S'));
    fclose(archivo);
    system("cls");
}

void modificar_Registro()
{
    FILE *archivo = fopen(nombe_archivo, "r+b");
    int id;
    char respuesta[s];
    string Nombre, Apellido, Puesto;
    Datos persona;
gotoxy(40,3);cout<<("*******************************************************");
gotoxy(40,4);cout<<("**    M O D I F I C A R        R E G I S T R O      ***");
gotoxy(40,5);cout<<("*******************************************************");
gotoxy(50,8);cout << "Ingrese el ID que Desea Modificar: ";

    cin >> id;
    fseek(archivo, id * sizeof(Datos), SEEK_SET); // esto es lo que permite modificar en la pocision
    fread(&persona, sizeof(Datos), 1, archivo);

    gotoxy(50, 12);
    cout << ("------------   Registros Encontrados  -------------");
    gotoxy(50, 13);
    cout << ("Nombres:  ") << persona.Nombre;
    gotoxy(50, 14);
    cout << ("Apellidos:  ") << persona.Apellido;
    gotoxy(50, 15);
    cout << ("Puesto:  ") << persona.Puesto;

    gotoxy(50, 16);
    cout << ("Sueldo Base:  ") << persona.sueldo_base;
    gotoxy(50, 17);
    cout << ("Bonificacion ") << persona.Bonificacion;

    gotoxy(50, 18);
    cout << ("---------------------------------------------");

    co(0, 242);
    cout << "<\n\n Nombres: " << persona.Nombre << endl;
    cout << ("¿Desea modificar el nombre? [s/n]: ");
    cin >> respuesta, s;

    if (strcmp(respuesta, "s") == 0)
    {

        fseek(archivo, id * sizeof(Datos), SEEK_SET);
        cin.ignore();
        cout << ("Nuevo Nombre : ");
        getline(cin, Nombre);
        strcpy(persona.Nombre, Nombre.c_str());
        fwrite(&persona, sizeof(Datos), 1, archivo);
    }

    co(0, 242);
    cout << "\n\nApellido: " << persona.Apellido << endl;
    cout << ("¿Desea modificar la Apellido? [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Datos), SEEK_SET);
        cin.ignore();
        cout << "Ingrese nuevo Apellido: ";
        getline(cin, Apellido);
        strcpy(persona.Apellido, Apellido.c_str());
        fwrite(&persona, sizeof(Datos), 1, archivo);
    }

    co(0, 242);
    cout << "\n\nPuesto: " << persona.Puesto << endl;
    cout << ("¿Desea modificar el Puesto? [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Datos), SEEK_SET);
        cin.ignore();

        cout << "Ingrese nuevo Puesto: ";
        getline(cin, Puesto);
        strcpy(persona.Puesto, Puesto.c_str());
        fwrite(&persona, sizeof(Datos), 1, archivo);
    }

    co(0, 242);
    cout << "\n\nSueldo Base: " << persona.sueldo_base << endl;
    cout << ("¿Desea modificar el sueldo? [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Datos), SEEK_SET);
        cin.ignore();

        cout << "Ingrese nuevo sueldo_base: ";
        cin >> persona.sueldo_base;
        fwrite(&persona, sizeof(Datos), 1, archivo);
  
    }

    co(0, 242);
    cout << "\n\nBonificion: " << persona.Bonificacion << endl;
    cout << ("¿Desea modificar la bonificacion? [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0){
        fseek(archivo, id * sizeof(Datos), SEEK_SET);
        cin.ignore();

        cout << "Ingrese nueva Bonificacion: ";
        cin >> persona.Bonificacion;
        fwrite(&persona, sizeof(Datos), 1, archivo);

    }
    fseek(archivo, id * sizeof(Datos), SEEK_SET);
    persona.total=persona.sueldo_base+persona.Bonificacion;
    fwrite(&persona, sizeof(Datos), 1, archivo);
    gotoxy(20, 55);
    cout << ("Datos actualizados!!");
    fclose(archivo);
    getch();
    mostrar_Registro();
}

void mostrar_Registro()
{
    system("cls");
    FILE *archivo = fopen(nombe_archivo, "rb");
    if (!archivo)
    {
        archivo = fopen(nombe_archivo, "w+b");
    }

    Datos persona;
    int registro = 0;
    fread(&persona, sizeof(Datos), 1, archivo);
   gotoxy(30,2); cout<<("*********    R E G I S T R O      D E     E M P L E A D O S   *********");
   gotoxy(30,3); cout<<("-----------------------------------------------------------------------\n");
    cout << "_____________________________________________________________________________________________________________" << endl;
    cout << "Codigo|"
         << "Nombre\t\t|"
         << "Apellido\t|"
         <<"Puesto\t\t\t|"
         << "Sueldo\t\t|"
         << "Bonificacion\t|"
         << "Sueldo Total " << endl;

    do{

        cout << "_____________________________________________________________________________________________________________" << endl;
        cout << registro <<"     |"<<persona.Nombre<< "\t|" << persona.Apellido << "\t|" << persona.Puesto << " \t"<<"|  Q." << persona.sueldo_base << "\t|    Q." << persona.Bonificacion << "\t|  Q." << persona.total << endl;

        fread(&persona, sizeof(Datos), 1, archivo);
        registro += 1;

    } while (feof(archivo) == 0);

    cout << endl;

    fclose(archivo);
    getch();
}

void buscar()
{

   FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
    gotoxy(40,3);cout<<("******************************************************");
    gotoxy(40,4);cout<<("***       B U S C A R         R E G I S T R O     ****");
	gotoxy(40,5);cout<<("******************************************************");
   
    gotoxy(45,8);cout<<"Que registro desea ver: ";
	cin>>pos;
	
	fseek ( archivo,pos * sizeof(Datos), SEEK_SET );
	
	Datos persona;
    
    fread(&persona, sizeof(Datos), 1, archivo);
    
gotoxy(50,12);    cout << "Codigo_Empleado: " <<pos;
gotoxy(50,13);    cout << "Nombre:   " << persona.Nombre;
gotoxy(50,14);    cout << "Apellido:  " << persona.Apellido;
gotoxy(50,15);    cout << "Puesto:  " << persona.Puesto;
gotoxy(50,16);    cout << "Sueldo Base:  Q." << persona.sueldo_base;
gotoxy(50,17);    cout << "Bonificacion:  Q." << persona.Bonificacion;
gotoxy(50,18);    cout << "Total Sueldo:  Q." << persona.total;
    
    fclose(archivo);
    getch();
}
void co(int x, int c)
{
    cambiarcolor(c);
    int i;
    for (i = 1; i <= x; i++)
    {
        cout << char(219) << char(219);
    }
}

void Eliminar_registro()
{
    Datos persona;
    FILE *temporal = fopen(nom_temporal, "w+b");
    FILE *archivo = fopen(nombe_archivo, "r+b");
    int eliminar;
    cout << "Ingrese el Codigo del registro que desea eliminar: ";
    cin >> eliminar;
    fseek(archivo, eliminar * sizeof(Datos), SEEK_SET);
    persona.Codigo_empleado = -1;
    fwrite(&persona, sizeof(Datos), 1, archivo);
    fclose(archivo);

    archivo = fopen(nombe_archivo, "r+b");

    fread(&persona, sizeof(Datos), 1, archivo);
    temporal = fopen(nom_temporal, "a+b");
    do
    {
        if (persona.Codigo_empleado == -1)
        {
            cout << "Registro Eliminado";
        }
        if (persona.Codigo_empleado >= 0)
        {
            fwrite(&persona, sizeof(Datos), 1, temporal);
        }
        fread(&persona, sizeof(Datos), 1, archivo);
    } while (feof(archivo) == 0);
    fclose(temporal);
    fclose(archivo);

    archivo = fopen(nombe_archivo, "w");
    fclose(archivo);

    temporal = fopen(nom_temporal, "r+b");

    fread(&persona, sizeof(Datos), 1, temporal);
    archivo = fopen(nombe_archivo, "a+b");
    do
    {
        fwrite(&persona, sizeof(Datos), 1, archivo);
        fread(&persona, sizeof(Datos), 1, temporal);
    } while (feof(temporal) == 0);
    fclose(archivo);
    fclose(temporal);


    mostrar_Registro();
}

