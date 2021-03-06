#include<windows.h>
#include<stdio.h>
#include <string.h> 
#include<iostream>

using namespace std;

int main(){
int fila=1,columna=1,**pm_notas;
int *cod;
string *nombre;

cout<<"Cuantos Estudiantes Desea Ingresar: ";
cin>>fila;	
cout<<"Cuantas Notas Desea Ingresar: ";
cin>>columna;	
pm_notas = new  int *[fila];
cod = new  int [fila];
nombre=new  string[fila];

for (int i=0;i<fila;i++){
pm_notas[i] = new int[columna]; 	
}
cout<<"--------------Ingrese Notas--------------"<<endl;

for (int i=0;i<fila;i++){
cout<<("Ingrese Codigo: ");   // aqui inicia la magia crack
cin>>cod[i];
cin.ignore();
cout<<("Ingrese nombre: ");   // aqui inicia la magia crack
getline(cin,nombre[i]);
    	
    	

for (int ii=1;ii<=columna;ii++){
cout<<("Ingrese Nota ")<<ii<<": ";
cin>>*(*(pm_notas+i)+ii);
}
	cout<<"------------------------------------"<<endl;
}

cout<<"--------------Mostrar Notas--------------"<<endl;
for (int i=0;i<fila;i++){
cout<<("Codigo: ")<<cod[i]<<("   Estudiante: ")<<nombre[i]<<endl;   
	 //Aqui si imprime la magia crack
for (int ii=1;ii<=columna;ii++){

	cout<<("Nota [")<<ii<<("]: ");
	cout<<*(*(pm_notas+i)+ii)<<endl;
	}
	cout<<"------------------------------------"<<endl;
}
// Liberar el espacio reservado en memoria
for (int i=0;i<fila;i++){
	delete [] pm_notas[i];
}

delete [] pm_notas;

	system("PAUSE");
	return 0;	
	
}

