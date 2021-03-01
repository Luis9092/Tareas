#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include <string.h> 
#include <fstream>

using namespace std;

const char *nombe_archivo = "nuevo.dat";
const char *temp ="temporal11.dat";

struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	int telefono;
};

void ingresar_estudiante();
void abrir_estudiante();
void modificar_estudiante();

void control();
void Eliminar2();
void BAJA2();
void eliminar33();
void eliminar5();

int main (){

control();
}


void control(){
	int a, b,c;
do{
system("cls");

printf("° 1. Insertar  Datos\n");
printf("° 2. Ver Datos\n");
printf("° 3. Modificar datos\n");
printf("° 4. Eliminar datos\n");
printf("° 5. Salir\n\n");
printf("Ingrese opcion: ");
cin>>a;
switch(a){
case 1: system("cls");ingresar_estudiante();
break;	
case 2: system("cls");abrir_estudiante();
break;
case 3: system("cls");modificar_estudiante();
break;
case 4:system("cls"); eliminar5();
break;
	
}
}while(a!=5);
}
	

void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Estudiante estudiante;
	
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		
		do{
			
			if (estudiante.codigo == cod){
			pos = indice;
			}
	
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );

    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);
getch();
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );
	
	Estudiante estudiante;
	
    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"TELEFONO"<<" "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
		getch();
	}
	
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Estudiante estudiante;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);

}
void modificar_estudiante(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	Estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);

		system("PAUSE");
}
/*
void Eliminar2(){

system("cls");
 Estudiante estudiante;
int indice1=0,poso=0,cod2=0;
FILE* archivo = fopen(nombe_archivo, "r+b");
 
 int cod1; 
 char op; 
char elimina;

 cout << "\n\rEliminar elemento";
 if(archivo==NULL) {
 cout << "\n\n\n\rNo existe el archivo !!!";
 getch();
 return;
 }

cout << "\n\n\n\rId a borrar: "; cin >> cod1;
fread(&estudiante,sizeof(Estudiante),1,archivo);

while(!feof(archivo)) {
 if(cod1==estudiante.codigo)
estudiante.codigo=0;
strcpy(estudiante.nombre," ");
strcpy(estudiante.apellido," ");
estudiante.telefono=0;	
fwrite(&estudiante,sizeof(Estudiante),1,archivo);
cout << "\n\n\n\rRegistro eliminado !!!";
break;
}
fclose(archivo); 
cout << "\n\rNo se encuentra ese registro !!!";
getch();
return;
}
void eliminar33(){
   Estudiante estudiante;
     int id;
     char a;
FILE *archivo =fopen(nombe_archivo,"r+b");
FILE *temporal =fopen(temp, "wb");

	if (archivo==NULL || temporal == NULL){
    	cout<<"ERROR uno de los archivos no ha sido encontrado."<<endl;
	}
    cout<<"Ingrese codigo a eliminar:";
    cin>>id;
    	fread(&estudiante, sizeof(Estudiante),1, archivo);
    cout<<"Desea continuar con la eliminacion s/n";
    cin>>a;
    if (a == 'S' || a == 's'){
    	
while(!feof(archivo)){
	        if (id == estudiante.codigo)
	        	fwrite(&estudiante, sizeof(Estudiante), 1, temporal);
cout<<"Estudiante eliminado"<<endl;
	remove("casa11.dat");
	rename("temporal11.dat", "casa11.dat");
break;		
}		

	fclose(archivo);
	fclose(temporal);

	getch();
}
}

void BAJA2(){
Estudiante estudiante;
FILE *temporal;
 cout << "\n\rEliminar registro ";
 FILE *archivo=fopen("nuevo.dat","r+b");
 if(archivo==NULL) {
 cout << "\n\n\n\rNo existe el archivo !!!";
 getch();
 return;
 }
 temporal=fopen("TEMPORAL.dat","wb"); 
 fread(&estudiante,sizeof(estudiante),1,archivo);
 
 while(!feof(archivo)) {
 if(estudiante.codigo!=0)
 fwrite(&estudiante,sizeof(Estudiante),1,temporal);
 fread(&estudiante,sizeof(Estudiante),1,archivo);
 }
fclose(archivo);
 remove("nuevo.dat"); 
 rename("TEMPORAL.dat","nuevo.dat");
 cout << "Archivo eliminada";
 getch();
 return;
} 
*/
void eliminar5(){
Estudiante estudiante;
FILE *temporal33;
int cod1;
 cout << "\n\rEliminar registro ";
 FILE *archivo=fopen("nuevo.dat","r+b");
 if(archivo==NULL) {
 cout << "\n\n\n\rNo existe el archivo !!!";
 getch();
 return;
 }
 cout << "\n\n\n\rId a borrar: "; cin >> cod1;
fread(&estudiante,sizeof(Estudiante),1,archivo);
 temporal33=fopen("TEMPORAL2.dat","wb"); 
 fread(&estudiante,sizeof(estudiante),1,archivo);
 
 while(!feof(archivo)) {
 if(cod1==estudiante.codigo)
 fread(&estudiante,sizeof(Estudiante),1,archivo);

 fwrite(&estudiante,sizeof(Estudiante),1,temporal33);

 }
fclose(archivo);
 remove("nuevo.dat"); 
 rename("TEMPORAL2.dat","nuevo.dat");
 cout << "Archivo eliminado";

 getch();
 return;
} 
