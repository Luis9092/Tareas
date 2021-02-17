#include "Personaj.cpp"
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>


using namespace std;

class Empleado : Personaj{

 private : string cod;

 public :
 Empleado(){

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 

 }

 Empleado(string nomb,string apell,string pues,float su, string n) : Personaj(nomb,apell,pues,su){ 
 cod = n;
 }


void mostrar(){
gotoxy(20,12);cout<<("******************************************************")<<endl;
gotoxy(20,14);cout<<cod<<", "<<nombres<<", "<<apellidos<<", "<<puesto<<", "<<sueldo<<endl;
}

};
