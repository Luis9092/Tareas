#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include <cmath>

#define ARRIBA 'z'
#define ABAJO 'x'
#define ENTER 13
 
#define arriba 72
#define izquierda 75
#define derecha 77
#define abajo 80 

// CONTRASEÑA CAJERO  = hola    
using namespace std;

void ocultar(){
HANDLE hCon;
hCon=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cci;
cci.dwSize= 2;
cci.bVisible= FALSE;
SetConsoleCursorInfo(hCon,&cci);
}

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 
void cambiarcolor(int X){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),X);
}

void fondo(){
system("COLOR f3");
} 

void co(int,int);
void bla(int);
void control();
void suma();
void resta();
void multiplicacion();
void division();
void todo();
void control1();
void control2();
void control3();
void control4();
void control5();
void control6();
void control7();
void control8();
void control9();
void control10();
void control11();
void control12();
void control13();
void control14();
void control15();
void control16();
void control17();
void control18();
void control19();
void control20();
void central();
void km();
void mts();
void lb();
void marco();

char getch2 (){
	ocultar();
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
 ReadConsoleA (ih, &c, 1, &contador, NULL);
 
   if (c == 0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }
 
   SetConsoleMode (ih, modo);
   return c;
}
 

int gotoxy(USHORT x,USHORT y) {
   COORD cp = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
 }
 
 
int menu(const char *opciones[], int n);
void menu_principal();


void marco(){
for(int i=1; i <= 49;  i++){
	
gotoxy(120,i);co(1,242);
}
for(int i=1; i <= 49;  i++){
gotoxy(45,i);co(1,242);
}
for(int i=45; i <= 120;  i++){
gotoxy(i,0);co(1,242);
}
for(int i=45; i <= 120;  i++){
gotoxy(i,49);co(1,242);
}
}

 
int main(){
	ocultar();
   menu_principal();
 
   return 0;
}
 
void menu_principal(){
ocultar();
fondo();
bool repite = true;
int opcion;   
int d;
const char *opciones[] = {"Operaciones Basicas en dos Cantidades","Determinar si un Numero es Par o Impar","Convertir de km a Mi, Mts a Pulg,lb a  kl",
"Determinar si una Palabra es Palindromo","Conversion de Numeros Arabigos a Romanos","Numeros Enteros a Letras", "Numeros Decimales a Letras","Tabla de Multiplicar",
"10 Tablas de Multiplicar","Forma Grafica, Multiplicacion Manual","Conversion de Numeros Decimales a Binario","Numeros Decimales a Hexadecimales","Figuras Geometricas Basicas",
"Mover un Punto en la Pantalla","Cajero Automatico","Calcular la Hipotenusa","Goku SS fase 4","Orden ascendente y Descendente","Potenciacion al cuadrado y al cubo","Menu comida","Salir",};
int n = 21; 

do {
	
opcion = menu(opciones, n);

switch (opcion) {

case 1:control1();
break;

case 2:control2();
break;

case 3:control3();
break;

case 4:control4();
break;

case 5:control5();
break;

case 6:control6();
break;

case 7:control7();
break;
case 8:control8();
break;

case 9:control9();
break;

case 10:control10();
break; 

case 11:control11();
break; 

case 12:control12();
break;   

case 13:control13();
break;

case 14:control14();
break;

case 15:control15();
break;

case 16:control16();
break;

case 17:control17();
break;

case 18:control18();
break;

case 19:control19();
break;

case 20: control20();
break;

case 21:
exit(0);	
}
} while (repite);
}

void control1(){
int d;


do {
system("cls");

marco();
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°° O P E R A C I O N E S      B A S I C A S  (Dos cantidades) °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

gotoxy(60,10);cout<<("1)    SUMA");
gotoxy(60,12);cout<<("2)    RESTA");
gotoxy(60,14);cout<<("3)    MULTIPLICACION");
gotoxy(60,16);cout<<("4)    DIVISION");
gotoxy(60,18);cout<<("5)    Todo");
gotoxy(60,20);cout<<("6)    SALIR: ");
gotoxy(60,24);cout<<("Ingrese opcion: ");

cin>>d;


switch (d) {

case 1:suma();
break;

case 2:resta();
break;

case 3:multiplicacion();
break;

case 4:division();
break;

case 5:todo();
break;

}
} while (d!=6);
} 

 void suma(){
	system("cls");
	marco();
double a,b,c;
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°°°                        S U M A                       °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

gotoxy(60,10);cout<<("Ingrese Cantidad: ");
cin>>a;
gotoxy(60,12);cout<<("Ingrese Cantidad: ");
cin>>b;
c=a+b;
gotoxy(55,14);cout<<("-----------------------------------------------------------");
gotoxy(60,15);cout<<("La suma es : ")<<c;

getch();
} 

void resta(){
system("cls");
marco();
double a,b,c;
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°°°                        R E S T A                       °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(60,10);cout<<("Ingrese Cantidad: ");
cin>>a;
gotoxy(55,12);cout<<("Ingrese Cantidad: ");
cin>>b;
c=a-b;

gotoxy(55,14);cout<<("-----------------------------------------------------------");
gotoxy(60,15);cout<<("La resta es : ")<<c;

getch();
}

void multiplicacion(){
	system("cls");
marco();
double a,b,c;
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°°°             M U L T I P L I C A C I O N                °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(60,10);cout<<("Ingrese Cantidad: ");
cin>>a;
gotoxy(60,12);cout<<("Ingrese Cantidad: ");
cin>>b;
c=a*b;

gotoxy(55,14);cout<<("-----------------------------------------------------------");
gotoxy(60,15);cout<<("El resultado es : ")<<c;

getch();
}

void division(){
	system("cls");
marco();
double a,b,c;
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°°°                    D I V I S I O N                     °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(60,10);cout<<("Ingrese Cantidad: ");
cin>>a;
gotoxy(60,12);cout<<("Ingrese Cantidad: ");
cin>>b;
c=a/b;

gotoxy(55,14);cout<<("-----------------------------------------------------------");
gotoxy(60,15);cout<<("EL resultado es : ")<<c;

getch();
}

void todo(){
	system("cls");
marco();
double a,b,c,d,e,f;
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°°°        O P E R A C I O N E S     B A S I C A S           °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(60,10);cout<<("Ingrese Cantidad: ");
cin>>a;
gotoxy(60,12);cout<<("Ingrese Cantidad: ");
cin>>b;
c=a+b;

gotoxy(55,14);cout<<("-------------------------------------------------------------");
gotoxy(60,16);cout<<("LA SUMA ES : ")<<c;
d=a-b;
gotoxy(60,18);cout<<("LA RESTA ES : ")<<d;
e=a*b;
gotoxy(60,20);cout<<("LA MULTIPLICACION ES : ")<<e;
f=a/b;
gotoxy(60,22);cout<<("LA DIVISION ES : ")<<f;
getch();
}

void control2(){
system("cls");	
marco();
int a;
char b;
gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,3);cout<<("°°  C A L C U L A R     P A R   O     I M P A R  °°");
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

gotoxy(55,8);cout<<("Ingrese Cantidad: ");
cin>>a;
gotoxy(55,11);cout<<("---------------------------------------------------"); 		

   	if(a%2==0){
gotoxy(55,12);	cout<<("LA CANTIDAD ES PAR");	
	} else{
gotoxy(55,13);	cout<<("--- LA CANTIDAD ES IMPAR ---");
	}
gotoxy(55,15);cout<<("Desea volver a intentarlo [s/n]: ");
cin>>b;	
if (b=='s'){
control2();
}else{
menu_principal();
}		
}


void control3(){
int d;

do {
system("cls");
marco();
gotoxy(55,3);cout<<("1)  Km a millas");
gotoxy(55,4);cout<<("2) Metros a pulgadas");
gotoxy(55,5);cout<<("3) Libras a kilos");
gotoxy(55,8);cout<<("4) SALIR: ");
gotoxy(55,10);cout<<("Ingrese opcion: ");

cin>>d;
switch (d) {

case 1:km();break;

case 2:mts();break;

case 3:lb();break;

}
} while (d!=4);	
}


void km(){
int d;
double a,b,c;
double z=0.6213;
double y =1.60;
do {
system("cls");

gotoxy(55,3);cout<<("°°1. Km a millas");
gotoxy(55,4);cout<<("°°2. millas a km");
gotoxy(55,8);cout<<("°°3. SALIR: ");
gotoxy(55,10);cout<<("Ingrese opcion: ");
cin>>d;

switch (d) {

case 1:system("cls");
gotoxy(55,5);cout<<("Ingrese km: ");
	cin>>b;
	c=b*z;
gotoxy(55,7);cout<<("----------------------------");	
gotoxy(55,8);cout<<c<<(" millas");
		getch();
	break;

case 2:
	system("cls");
gotoxy(55,5);cout<<("Ingrese millas: ");
	cin>>b;
	c=b*y;
gotoxy(55,7);cout<<("--------------------------");	
gotoxy(55,8);cout<<c<<(" km");
	getch();

}
} while (d!=3);
}

void mts(){
int d;
double a,b,c;
double z=39.3701;
double y =0.0254;
do {
system("cls");

gotoxy(55,3);cout<<("°°1. Metros a Pulgadas");
gotoxy(55,4);cout<<("°°2. Pulgadas a Metros");
gotoxy(55,8);cout<<("°°3. Salir: ");
gotoxy(55,10);cout<<("Ingrese opcion: ");

cin>>d;

switch (d) {

case 1:system("cls");
gotoxy(55,5);cout<<("Ingrese metros: ");
	cin>>b;
	c=b*z;
gotoxy(55,7);cout<<("-----------------------------");	
gotoxy(55,8);cout<<c<<(" Pulgadas");
		getch();
	
break;
case 2:system("cls");
gotoxy(55,5),cout<<("Ingrese pulgadas: ");
	cin>>b;
	c=b*y;
gotoxy(55,7);cout<<("-----------------------------");	
gotoxy(55,8);cout<<c<<(" Metros");
		getch();
	

}
} while (d!=3);
}	
		
void lb(){
int d;
double a,b,c;
double z=0.453592;
double y =2.20462;
do {
system("cls");

gotoxy(55,3);cout<<("°°1. Libra a kilo");
gotoxy(55,4);cout<<("°°2. Kilo a Libra");
gotoxy(55,8);cout<<("°°3. Salir: ");
gotoxy(55,10);cout<<("Ingrese opcion: ");

cin>>d;

switch (d) {

case 1:	system("cls");
gotoxy(55,5);cout<<("Ingrese libras: ");
	cin>>b;
	c=b*z;
gotoxy(55,7);cout<<("---------------------------------");	
gotoxy(55,8);cout<<c<<(" Kilo");
		getch();
	break;

case 2:system("cls");
gotoxy(55,5);cout<<("Ingrese Kilo: ");
	cin>>b;
	c=b*y;
gotoxy(55,7);cout<<("---------------------------------");	
gotoxy(55,8);cout<<c<<(" Libras");
	getch();

}
} while (d!=3);
}	
 
bool pal(string cad){

int i = 0;
int j = cad.size()-1;
while(i<j){
if (cad[i]!= cad[j]) return false;
i++;
j--;
}
return true;
}

void control4(){
system("cls");
string cadena;
char a;
marco();
gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,3);cout<<("°°  D E T E R M I N A R     S I    E S    P A L I N D R O M O °°");
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,8);cout<<("Ingrese Palabra: ");
cin>>cadena;
gotoxy(55,8);cout<<("-----------------------------------------------------------------");
if (pal(cadena)==true){
gotoxy(55,12);cout<<("Es palindromo");
}else{

gotoxy(55,13);cout<<("No es palindromo");
}

gotoxy(55,16);cout<<(" Desea Volver a repetir [s/n] : ");
cin>>a;
if (a=='s'){
control4();

}else{
menu_principal();
}
}

void control5(){
system("cls");	
int num,uni,dec,cen, mill;
char b;
marco();
gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,3);cout<<("°° N U M E R O S    A R A B I G O S    A     N U M E R O S    R O M A N O S °°");
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

gotoxy(55,8);cout << "Ingresar cantidad: ";
		cin >> num;
		
		uni = num%10; num /= 10;
		dec = num%10; num /= 10;
		cen = num%10; num /= 10;
		mill = num%10; num /= 10;
		
switch(uni){
			
			case 1:gotoxy(70,10); cout<<("I"); 
			break;
			case 2:gotoxy(70,10); cout<<("II"); 
			break;
			case 3:gotoxy(70,10); cout<<("III"); 
			break;
			case 4:gotoxy(70,10); cout<<("IV"); 
			break;
			case 5:gotoxy(70,10); cout<<("V"); 
			break;
			case 6:gotoxy(70,10); cout<<("VI"); 
			break;
			case 7:gotoxy(70,10); cout<<("VII"); 
			break;
			case 8:gotoxy(70,10); cout<<("VIII"); 
			break;
			case 9:gotoxy(70,10);cout<<("IX"); 
			break;
}
		
switch(dec){
			
			case 1:gotoxy(67,10); cout<<("X"); 
			break;
			case 2:gotoxy(67,10); cout<<("XX"); 
			break;
			case 3:gotoxy(67,10); cout<<("XXX"); 
			break;
			case 4:gotoxy(67,10); cout<<("XL"); 
			break;
			case 5:gotoxy(67,10); cout<<("L"); 
			break;
			case 6:gotoxy(67,10); cout<<("LX"); 
			break;
			case 7:gotoxy(67,10); cout<<("LXX"); 
			break;
			case 8:gotoxy(67,10); cout<<("LXXX"); 
			break;
			case 9:gotoxy(67,10); cout<<("XC"); 
			break;
}
		
		switch(cen){
			case 1:gotoxy(64,10); cout<<("C"); 
			break;
			case 2:gotoxy(64,10); cout<<("CC"); 
			break;
			case 3:gotoxy(64,10); cout<<("CCC"); 
			break;
			case 4:gotoxy(64,10); cout<<("CD"); 
			break;
			case 5:gotoxy(64,10); cout<<("D"); 
			break;
			case 6:gotoxy(64,10); cout<<("DC"); 
			break;
			case 7:gotoxy(64,10); cout<<("DCC"); 
			break;
			case 8:gotoxy(64,10); cout<<("DCCC");
			 break;
			case 9:gotoxy(64,10); cout<<("CM"); 
			break;
		}
		
		switch(mill){
			case 1:gotoxy(60,10); cout<<("M"); 
			break;
			case 2:gotoxy(60,10); cout<<("MM"); 
			break;
			case 3:gotoxy(60,10); cout<<("MMM"); 
			break;
}
		
		
gotoxy(55,12);cout<<("Desea Volver a repetir [s/n]: ");
cin>>b;
if (b=='s'){
	
 control5();

}else{
menu_principal();
}
}
void control6(){
system("cls");
marco();
 char a;   int x;
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°°     N U M E R O S     E N T E R O S     A     L E T R A S     °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
 
gotoxy(55,10);cout<<("Ingrese cantidad: ");
    cin>>x;
gotoxy(55,15);cout<<("-------------------------------------------------------------------");
cout<<("\n\n\n");

if((x<1)||(x>1000))cout<<("\t\t\t\t\t\tIngrese Cantidad del  1 AL 1000");
else{
cout<<("\t\t\t\t\t\t\t\t");	
if(x==1000){
cout<<(" MIl ");               x=x-1000;  }
	
else if(x>=900)   {
cout<<("Novecientos ");       x=x-900;}
else if(x>=800){
cout<<("Ochocientos ");       x=x-800;}
else if(x>=700)   {
cout<<("Setecientos ");       x=x-700;}
else if(x>=600)   {
cout<<("Seiscientos ");      x=x-600;}
else if(x>=500){
cout<<("Quinientos ") ;      x=x-500;}
else if(x>=400){
cout<<("Cuatrocientos ");     x=x-400;}
else if(x>=300){
cout<<("Trescientos ");       x=x-300;}
else if(x>=200){
cout<<("Doscientos ");         x=x-200;}
else if(x>100){
cout<<("Ciento ");             x=x-100;}
else if(x==100){
cout<<("t\tCien ");              x=x-100;}
       
if(x>90){
cout<<(" Noventa y ");        x=x-90; }
 if(x==90){
 cout<<(" Noventa");          x=x-90; }  
 if(x>80){
 cout<<(" Ochenta y ");       x=x-80; }
if(x==80){
cout<<(" Ochenta" );          x=x-80; }
if(x>70){
cout<<(" Setenta y ");        x=x-70; }
if(x==70){
cout<<(" Setenta");           x=x-70; }
if(x>60){
cout<<(" Sesenta y ");        x=x-60; }
if(x==60){
cout<<(" Sesenta");           x=x-60; }
if(x>50){
cout<<(" Cincuenta y ");      x=x-50; }
if(x==50){
cout<<(" Cincuenta");         x=x-50; }
if(x>40){
cout<<(" Cuarenta y ");       x=x-40; }
if(x==40){
cout<<(" Cuarenta");          x=x-40; }
if(x>30){
cout<<(" Treinta y ");        x=x-30; }
if(x==30){
cout<<(" Treinta");           x=x-30; }
if(x>20){
cout<<(" Veinti");            x=x-20; }
if(x==20) {
cout<<(" Veinte");            x=x-20; }
if(x>=16){
cout<<(" Dieci");             x=x-10; }
else if(x==15){
cout<<(" Quince");            x=x-15; }
else if(x==14) {
cout<<(" catorce");           x=x-14; }
else if(x==13){
cout<<(" Trece");             x=x-13; } 
else if(x==12){
cout<<(" Doce");              x=x-12; }
else if(x==11){
cout<<(" Once");              x=x-11; }
else if(x==10){
cout<<(" Diez");              x=x-10; }      
if(x==9){
cout<<("nueve");             x=x-9;  }
if(x==8){
cout<<("ocho");              x=x-8;  }
if(x==7){
cout<<("siete");             x=x-7;  }
if(x==6){
cout<<("seis");              x=x-6;  }
else if(x==5){
cout<<("cinco");             x=x-5;  }
else if(x==4){
cout<<("cuatro");           x=x-4;  }
else if(x==3){
cout<<("tres");              x=x-3;  }
else if(x==2){
cout<<("dos");               x=x-2;  }
else if(x==1){
cout<<("uno");               x=x-1;  }
}

gotoxy(55,25);cout<<("Desea volver a intentarlo [s/n] :");
cin>>a;
if(a=='s'){
control6();	

}else{
menu_principal();
} 
}	
 
void control7(){
system("cls");
marco();
 char a;   int x, y;
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°°  N U M E R O S    D E C I M A L E S    A     L E T R A S  °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
 
gotoxy(55,10);cout<<("Ingrese cantidad entera: ");
cin>>x;
gotoxy(55,12);cout<<("Ingrese cantidad decimal: ");
cin>>y;
gotoxy(55,17);cout<<("--------------------------------------------------------------");
cout<<("\n\n\n");

if((x<1)||(x>1000)) cout<<("\t\t\t\t\t\tIngrese Cantidad entera del  1 AL 1000");
else{
cout<<("\t\t\t\t\t\t\t");  	
if(x==1000){
cout<<(" MIl ");               x=x-1000;  }
	
else if(x>=900)   {
cout<<(" Novecientos ");       x=x-900;}
else if(x>=800){
cout<<(" Ochocientos ");       x=x-800;}
else if(x>=700)   {
cout<<(" tetecientos ");       x=x-700;}
else if(x>=600)   {
cout<<(" Seiscientos ");      x=x-600;}
else if(x>=500){
cout<<(" Quinientos ") ;      x=x-500;}
else if(x>=400){
cout<<(" Cuatrocientos ");     x=x-400;}
else if(x>=300){
cout<<(" Trescientos ");       x=x-300;}
else if(x>=200){
cout<<(" Doscientos ");         x=x-200;}
else if(x>100){
cout<<(" Ciento ");             x=x-100;}
else if(x==100){
cout<<(" Cien ");              x=x-100;}
     
if(x>90){
cout<<(" Noventa y ");        x=x-90; }
 if(x==90){
 cout<<(" Noventa");          x=x-90; }  
 if(x>80){
 cout<<(" Ochenta y ");       x=x-80; }
if(x==80){
cout<<(" Ochenta" );          x=x-80; }
if(x>70){
cout<<(" Setenta y ");        x=x-70; }
if(x==70){
cout<<("  SETENTA");           x=x-70; }
if(x>60){
cout<<(" Sesenta y ");        x=x-60; }
if(x==60){
cout<<(" Sesenta");           x=x-60; }
if(x>50){
cout<<(" cincuenta y ");      x=x-50; }
if(x==50){
cout<<(" Cincuenta");         x=x-50; }
if(x>40){
cout<<(" Cuarenta y ");       x=x-40; }
if(x==40){
cout<<(" Cuarenta");          x=x-40; }
if(x>30){
cout<<(" Treinta y ");        x=x-30; }
if(x==30){
cout<<(" Treinta");           x=x-30; }
if(x>20){
cout<<(" Veinti");            x=x-20; }
if(x==20) {
cout<<("  Veinte");            x=x-20; }
if(x>=16){
cout<<(" Dieci");             x=x-10; }
else if(x==15){
cout<<(" Quince");            x=x-15; }
else if(x==14) {
cout<<(" catorce");           x=x-14; }
else if(x==13){
cout<<(" Trece");             x=x-13; } 
else if(x==12){
cout<<(" Doce");              x=x-12; }
else if(x==11){
cout<<(" Once");              x=x-11; }
else if(x==10){
cout<<(" Diez");              x=x-10; }      
if(x==9){
cout<<("nueve");             x=x-9;  }
if(x==8){
cout<<("ocho");              x=x-8;  }
if(x==7){
cout<<("siete");             x=x-7;  }
if(x==6){
cout<<("seis");              x=x-6;  }
else if(x==5){
cout<<("cinco");             x=x-5;  }
else if(x==4){
cout<<("cuatro");           x=x-4;  }
else if(x==3){
cout<<("tres");              x=x-3;  }
else if(x==2){
cout<<("dos");               x=x-2;  }
else if(x==1){
cout<<("uno");               x=x-1;  }
}
if((y<1)||(y>999)) cout<<("\t\t\t\t\t\tIngrese decimal del  1 AL 999");
else{	
cout<<(" punto ");
 if(y>=900)   {
cout<<(" novecientos ");       y=y-900;}
else if(y>=800){
cout<<(" Ochocientos ");       y=y-800;}
else if(y>=700)   {
cout<<(" setecientos ");       y=y-700;}
else if(y>=600)   {
cout<<("  seiscientos ");      y=y-600;}
else if(y>=500){
cout<<(" quinientos ") ;      y=y-500;}
else if(y>=400){
cout<<(" cuatrocientos ");     y=y-400;}
else if(y>=300){
cout<<(" trescientos ");       y=y-300;}
else if(y>=200){
cout<<(" doscientos ");         y=y-200;}
else if(y>100){
cout<<(" ciento ");             y=y-100;}
else if(y==100){
cout<<(" Cien ");              y=y-100;}
      
if(y>90){
cout<<(" Noventa y ");        y=y-90; }
 if(y==90){
 cout<<(" Noventa");          y=y-90; }  
 if(y>80){
 cout<<(" tOchenta y ");       y=y-80; }
if(y==80){
cout<<(" Ochenta" );          y=y-80; }
if(y>70){
cout<<(" setenta y ");        y=y-70; }
if(y==70){
cout<<(" SETENTA");           y=y-70; }
if(y>60){
cout<<(" Sesenta y ");        y=y-60; }
if(y==60){
cout<<(" sesenta");           y=y-60; }
if(y>50){
cout<<(" cincuenta y ");      y=y-50; }
if(y==50){
cout<<(" cincuenta");         y=y-50; }
if(y>40){
cout<<(" cuarenta y ");       y=y-40; }
if(y==40){
cout<<(" Cuarenta");          y=y-40; }
if(y>30){
cout<<(" treinta y ");        y=y-30; }
if(y==30){
cout<<(" treinta");           y=y-30; }
if(y>20){
cout<<(" veinti");            y=y-20; }
if(y==20) {
cout<<(" veinte");            y=y-20; }
if(y>=16){
cout<<(" dieci");             y=y-10; }
else if(y==15){
cout<<(" quince");            y=y-15; }
else if(y==14) {
cout<<(" catorce");           y=y-14; }
else if(y==13){
cout<<(" trece");             y=y-13; } 
else if(y==12){
cout<<(" doce");              y=y-12; }
else if(y==11){
cout<<(" once");              y=y-11; }
else if(y==10){
cout<<(" diez");              y=y-10; }      
if(y==9){
cout<<("nueve");             y=y-9;  }
if(y==8){
cout<<("ocho");              y=y-8;  }
if(y==7){
cout<<("siete");             y=y-7;  }
if(y==6){
cout<<("seis");              y=y-6;  }
else if(y==5){
cout<<("cinco");             y=y-5;  }
else if(y==4){
cout<<("cuatro");           y=y-4;  }
else if(y==3){
cout<<("tres");              y=y-3;  }
else if(y==2){
cout<<("dos");               y=y-2;  }
else if(y==1){
cout<<("uno");               y=y-1;  }
}


gotoxy(55,30);cout<<("Desea volver a intentarlo [s/n] :");
cin>>a;
if(a=='s'){
control7();	

}else{
menu_principal();
} 
}	
	
void control8(){
system("cls");
marco();
int a,b;
char c;
gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,3);cout<<("°°   T A B L A      D E      M U L T I P L I C A R   °°");
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
   
gotoxy(55,8);cout<<("Ingrese tabla:  ");
    cin>>a;

 cout<<("\n\n\n")<<endl;

for (int i=1; i<=12; i++) 
{

b=a*i;
cout<<("\t\t\t\t\t\t\t\t\t");cout<<a<<" * "<<i<<" =  "<<b<<endl;
}
gotoxy(55,30);cout<<(" Desea Volver a repetir s/n: ");
cin>>c;
if (c=='s'){
	
 control8();

}else{
menu_principal();
}
}

void control9(){
system("cls");
int b,c,e,f,g,h,j;
gotoxy(55,38);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,39);cout<<("°°        T A B L A S        D E       M U L T I P L I C A R        °°");
gotoxy(55,40);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");    
for (int z=1; z<=15; z++) {

b=1*z;
gotoxy(15,z);cout<<("|")<<1<<" * "<<z<<" =  "<<b<<endl;
}


for (int i=1; i<=15; i++) {
int d=2*i;
gotoxy(45,i);cout<<("|")<<2<<" * "<<i<<" =  "<<d<<endl;
}

for (int i=1; i<=15; i++) {
e=3 *i;
gotoxy(65,i);cout<<("|")<<3<<" * "<<i<<" =  "<<e<<endl;
}
for (int i=1; i<=15; i++) {
f=4*i;
gotoxy(85,i);cout<<("|")<<4<<" * "<<i<<" =  "<<f<<endl;
}
for (int i=1; i<=15; i++) {
 g=5*i;
gotoxy(105,i);cout<<("|")<<5<<" * "<<i<<" =  "<<g<<endl;
}
for (int i=1; i<=15; i++) {
 h=6*i;
gotoxy(135,i);cout<<("|")<<6<<" * "<<i<<" =  "<<h<<endl;
}

for (int m=1; m<=15;m++){
gotoxy(0,20);
for (int i=1; i<=15; i++) {

int j=7*i;
cout<<("\t\t\t\t")<<("|")<<7<<" * "<<i<<" =  "<<j<<endl;
}
}

for (int m=1; m<=15;m++){
gotoxy(0,20);

for (int i=1; i<=15; i++) {

int k=8*i;
cout<<("\t\t\t\t\t\t\t\t")<<("|")<<8<<" * "<<i<<" =  "<<k<<endl;
}
}

for (int m=1; m<=15;m++){
gotoxy(0,20);

for (int i=1; i<=15; i++) {

int l=9*i;
cout<<("\t\t\t\t\t\t");
cout<<("\t\t\t\t\t")<<("|")<<9<<" * "<<i<<" =  "<<l<<("\t\t")<<endl;
}
}

for (int m=1; m<=15;m++){
gotoxy(0,20);

for (int i=1; i<=15; i++) {

int p=10*i;
cout<<("\t\t\t\t\t\t\t");
cout<<("\t\t\t\t\t\t\t\t")<<("|")<<10<<" * "<<i<<" =  "<<p<<endl;
}
}
getch();
}

void control10(){
	system("cls");
	marco();
int x,a,b,c,d,e,f,p,g,cent1,cent2;
char z;
int uni,dec,uni1,dec1,uni2,dec2,uni3,dec3;
gotoxy(50,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(50,3);cout<<("°°  M U L T I P L I C A C I O N     M A N U A L (2 digitos)  °°");
gotoxy(50,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

gotoxy(50,8);cout<<("Ingrese Cantidad: ");
cin>>a;
gotoxy(50,10);cout<<("Ingrese Cantidad: ");
cin>>b;
int r=a*b;
gotoxy(80,15);cout<<a;
gotoxy(77,16);cout<<("X");gotoxy(80,16);cout<<b;
gotoxy(75,18);cout<<("_____________");

	uni = a%10; a /= 10;
	dec = a%10; a /= 10;
    uni1 = b%10; b /= 10;
	dec1 = b%10; b /= 10;

c=uni1*uni;
	uni2 = c%10; c /= 10;
	dec2 = c%10; c /= 10;
	cent1= c%10; c /= 10;
	
d=uni1*dec+dec2;
gotoxy(80,20);cout<<d<<uni2;

e=dec1*uni;
	uni3 = e%10; e /= 10;
	dec3 = e%10; e /= 10;
	
	cent2 = e%10; e /= 10;
	
f=dec1*dec+dec3;
gotoxy(79,21);cout<<f<<uni3;
gotoxy(75,22);cout<<("____________");
/*x=dec2+dec3;
p=dec2+dec+uni3;*/
gotoxy(79,24);cout<<r;

gotoxy(55,30);cout<<(" Desea Volver a repetir[s/n]: ");
cin>>z;
if (z=='s'){
 control10();

}else{
	menu_principal();
}
}

void control11(){
	
system("cls");
marco();
int a,b,c;
char d; 
int binario[50]; 
binario[0]=0;

gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"); 
gotoxy(55,3);cout<<("°°  N U M E R O S    E N T E R O S  A    B I N A R I O  °°");
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"); 


gotoxy(55,8);cout<<("Introduce cantidad a convertir: " ); 
cin>>c,"%1u";
cout<<("\n\n\n");
 
for (b=0;b<50;b++) { 
binario[b]=c%2; 
c=c/2; 
if(c==0) 
break; 
} 

for(a=b;a>=0;a--) { 
gotoxy(55,12);cout<<("----------------------------------------------------------");
gotoxy(80-a,14);cout<<("%d",binario[a]); 
gotoxy(55,16);cout<<("----------------------------------------------------------");

} 
getch();

gotoxy(60,25);cout<<("Desea Volver a repetir [s/n]: ");
cin>>d;
if (d=='s'){
	
 control11();

}else{
menu_principal();
}
} 

void control12(){
system("cls");	
marco();
 int can[20];
    int a,c,b; int i = 0;
char e;
gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");   
gotoxy(55,3);cout<<("°°   D E C I M A L E S      A     H E X A D E C I M A L E S   °°");
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");   

gotoxy(55,8);cout<<("Ingrese Cantidad: ");
    cin >> a;

    do{
        b = a % 16;
        c = a / 16;
        can[i] = b;
        a = c;
        i++;
    } while (c > 15);

    can[i] = c;
gotoxy(55,12);cout<<("----------------------------------------------------------------");
   cout<<("\n\t\t\t\t\t\t\t\t\t\t");

    for (int j = i; j >= 0; j--){
        if (can[j] == 10){
          cout<< (" A ");
        }
        else if (can[j] == 11){
     cout<<(" B ");
        }
        else if (can[j] == 12){
        cout<<("C");
        }
        else if (can[j] == 13){
          cout<<("D");
        }
        else if (can[j] == 14){
          cout<<("E");
        }
        else if (can[j] == 15){
          cout<<("F");
		  }
        else{
          cout<<can[j];
        }   
    }
    
    
gotoxy(60,20);cout<<("Desea Volver a repetir [s/n]:  ");
cin>>e;
if (e=='s'){
	
 control12();

}else{
menu_principal();
}
}

void control13(){
	system("cls");
	fondo();
	
int a= 242,b=241,g=246,f=244;
gotoxy(55,1);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,2);cout<<("°° F I G U R A S   G E O M E T R I C A S    B A S I C A S °°");
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(20,5);co(15,a);bla(20);co(30,b);
gotoxy(20,6);co(15,a);bla(20);co(30,b);
gotoxy(20,7);co(15,a);bla(20);co(30,b);
gotoxy(20,8);co(15,a);bla(20);co(30,b);
gotoxy(20,9);co(15,a);bla(20);co(30,b);
gotoxy(20,10);co(15,a);bla(20);co(30,b);
gotoxy(20,11);co(15,a);bla(20);co(30,b);
gotoxy(20,12);co(15,a);bla(20);co(30,b);
gotoxy(20,13);co(15,a);bla(20);co(30,b);
gotoxy(20,14);co(15,a);bla(20);co(30,b);
gotoxy(20,15);co(15,a);bla(20);co(30,b);
gotoxy(20,16);co(15,a);bla(20);co(30,b);
gotoxy(20,17);co(15,a);bla(20);co(30,b);
gotoxy(20,18);co(15,a);bla(20);co(30,b);
gotoxy(20,19);co(15,a);bla(20);co(30,b);
gotoxy(20,20);co(15,a);bla(20);co(30,b);
gotoxy(27,22);cout<<("|C U A D R A D O|");
gotoxy(110,22);cout<<("|R E C T A N G U L O|");
gotoxy(30,44);cout<<("|C I R C U L O|");	
gotoxy(110,44);cout<<("|T R I A N G U L O|");
gotoxy(20,25);bla(3);co(12,f);bla(3);bla(10);bla(20);co(1,g);bla(20);
gotoxy(20,26);bla(2);co(14,f);bla(2);bla(10);bla(19);co(3,g);bla(19);
gotoxy(20,27);bla(1);co(16,f);bla(1);bla(10);bla(18);co(5,g);bla(18);
gotoxy(20,28);co(18,f);bla(10);bla(17);co(7,g);bla(17);
gotoxy(20,29);co(18,f);bla(10);bla(16);co(9,g);bla(16);
gotoxy(20,30);co(18,f);bla(10);bla(15);co(11,g);bla(15);
gotoxy(20,31);co(18,f);bla(10);bla(14);co(13,g);bla(14);
gotoxy(20,32);co(18,f);bla(10);bla(13);co(15,g);bla(13);
gotoxy(20,33);co(18,f);bla(10);bla(12);co(17,g);bla(12);
gotoxy(20,34);co(18,f);bla(10);bla(11);co(19,g);bla(11);
gotoxy(20,35);co(18,f);bla(10);bla(10);co(21,g);bla(10);
gotoxy(20,36);co(18,f);bla(10);bla(9);co(23,g);bla(9);
gotoxy(20,37);co(18,f);bla(10);bla(8);co(25,g);bla(8);
gotoxy(20,38);co(18,f);bla(10);bla(7);co(27,g);bla(7);
gotoxy(20,39);co(18,f);bla(10);bla(6);co(29,g);bla(6);
gotoxy(20,40);bla(1);co(16,f);bla(1);bla(10);bla(5);co(31,g);bla(5);
gotoxy(20,41);bla(2);co(14,f);bla(2);bla(10);bla(4);co(33,g);bla(4);
gotoxy(20,42);bla(3);co(12,f);bla(3);bla(10);bla(3);co(35,g);bla(3);
getch();	
}	


void control14(){
system("cls");
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°°     M O V E R        U N         P U N TO     °°");	
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

gotoxy(55,7);cout<<("(Usar teclas direccionales)     | ENTER |  para salir");

char opcion;
int x=15, y=20;
ocultar();

while(opcion!=ENTER){
gotoxy(x,y);cout<<("*-*");
opcion=getch();

gotoxy(x,y);cout<<("   ");
switch(opcion){
case arriba: y--; break;
case abajo: y++; break;
case izquierda: x--; break;
case derecha: x++; break;
}
}		
}

void control15(){
system("cls");
char Id[20]="hola";
char correcto[20];
int fal=3; 	
int si =0; 
int i=0; 
marco();  
while (i++<fal && !si) {
system("cls");	
gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,3);cout<<("°°°                                LOGIN                                 °°°");
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

gotoxy(55,6);cout<<("Ingrese Id: ");	
cin>>correcto;
 if(strcmp(Id,correcto)==0){
central();
          si = 1;
}else{
gotoxy(55,9);cout<<("---------------------------------------------------------------");	
gotoxy(60,10);cout<<("Clave incorrecta, vuelva a intentarlo");   
getch();
}

}if (!si)
gotoxy(55,9);cout<<("---------------------------------------------------------------");	
gotoxy(60,10);cout <<("Ha realizado 3 intentos, por seguridad el programa se cerrara...")<<fal;
getch();
}

double saldo(double total){
	system("cls"); 

gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(55,3);cout<<("°°              I N G R E S A R            S A L D O                 °°");	
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	

gotoxy(55,7);cout<<("-------------------------------------------------------------------");
if (total==0){
gotoxy(60,15);cout<<("Su cuenta esta vacia");
}else{
gotoxy(60,15);cout<<("Su saldo es de: ")<<total;
}
return total;
}
 
double deposito(double total){
system("cls");
gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(55,3);cout<<("°°            C O N S U L T A R            S A L D O                 °°");	
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
    
double deposito1=0;
gotoxy(55,7);cout<<("--------------------------------------------------------------------");

do{
gotoxy(60,15);cout<<("Ingrese la cantidad que desea depositar: ");
cin>>deposito1;
if(deposito1>0){
total=total+deposito1;
gotoxy(60,17);cout<<("Su nuevo saldo es de: ")<<total;
}else{
gotoxy(60,17);cout<<("Ingrese una cantidad valida");
}   
}while (deposito1<=0);
return total;
}
 
double retiro(double total){
system("cls"); 	

gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(55,3);cout<<("°°              R E T I R A R               S A L D O                 °°");	
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
double sacar=0;
cout<<endl;

gotoxy(55,7);cout<<("---------------------------------------------------------------------");
if(total==0){
gotoxy(60,15);cout<<("Saldo vacio");
}else{
	
do{
gotoxy(60,12);cout<<("Ingrese la cantidad que desea retirar: ");
cin>>sacar;
if(sacar>0){

total=total-sacar;
gotoxy(60,15);cout<<("Su nuevo saldo es de: ")<<total;
}else{
gotoxy(60,12);cout<<("Ingrese una cantidad valida");

}
}while (sacar<=0);
return total;
}
}


void central(){
int a,b;
double total=0;
int opcion;
char c;
do{
marco();	
system("cls");

opcion=total;  

gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(55,3);cout<<("°°              C A J E R O                        BJ1                °°");	
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(60,7);cout<<("1. Depositar ");  
gotoxy(60,9);cout<<("2. Retirar");  
gotoxy(60,11);cout<<("3. Consultar Saldo");  
gotoxy(60,13);cout<<("4. Salir");  
gotoxy(60,15);cout<<("Ingrese Opcion: ");  
gotoxy(60,18);cout<<("Elija la transaccion que desea realizar: ");
cin>>opcion;
switch (opcion){
case 1:total=deposito(total);break;
case 2:total=retiro(total);break;
case 3:total=saldo(total);break;
case 4:
menu_principal(); 
}
opcion=(total);
total=(opcion,total);
do{
cout<<endl;
gotoxy(55,24);cout<<("Desea realizar alguna otra transaccion [s/n] : ");
cin>>c;
 a=0;
        switch(c){
case 's':
case 'S':a=2;
break;
case 'n':
case 'N':break;
} 
} while (a==1);
} while (a==2);    
}


void control16(){
system("cls");
marco();
double a, b ,c ,d,e,f;
char m;
gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°° C A L C U L A R     L A    H I P O T E N U S A °°");
gotoxy(55,6);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

gotoxy(60,10);cout<<("Ingrese Cantidad:");
cin>>a;
gotoxy(60,12);cout<<("Ingrese Cantidad: ");
cin>>b;
c=a*a;
d=b*b;
e=c+d;
f=sqrt(e);
gotoxy(60,15);cout<<("El valor de la Hipotenusa es: ")<<f;			
gotoxy(60,17);cout<<("Dese Volver a repetir s/n: ");
cin>>m;
if(m=='s'){
control16();	
}else{
menu_principal();
} 
}
void control17(){
system("cls");	

int n =240,r= 244,k=252, p=254, am=6, c=243,a=241;

bla(15);co(1,n);bla(2);co(3,n);bla(4);co(6,n);bla(33);co(19,a);    //3

cout<<("\n");
bla(14);co(3,n);bla(1);co(3,n);bla(3);co(6,n);bla(26);co(27,a);    //4

cout<<("\n");
bla(14);co(7,n);bla(2);co(6,n);bla(25);co(29,a);    //5
cout<<("\n");
bla(14);co(14,n);bla(24);co(31,a);    //6

cout<<("\n");
bla(14);co(16,n);bla(21);co(6,a);co(12,c);co(14,a);    //7

cout<<("\n");
bla(14);co(18,n);bla(18);co(4,a);co(4,c);bla(5);co(9,c);co(11,a);    //8


cout<<("\n");
bla(14);co(20,n);bla(14);co(4,a);co(3,c);bla(11);co(17,c);    //9

cout<<("\n");
bla(14);co(21,n);bla(12);co(3,a);co(3,c);bla(16);co(14,c);    //10

cout<<("\n");
bla(10);co(26,n);bla(10);co(2,a);co(3,c);bla(20);    //11

cout<<("\n");
bla(11);co(23,n);bla(11);co(2,a);co(2,c);bla(30);    //12

cout<<("\n");
bla(12);co(23,n);bla(9);co(2,a);co(2,c);bla(21);co(1,c);    //13

cout<<("\n");
bla(13);co(23,n);bla(7);co(2,a);co(1,c);bla(24);co(1,c);bla(10);   //|4

cout<<("\n");
bla(14);co(12,n);co(2,p);co(9,n);bla(6);co(2,c);bla(26);co(1,c);bla(10);    //15

cout<<("\n");
bla(16);co(9,n);co(5,p);co(4,n);bla(8);co(1,a);co(1,c);bla(26);co(1,c);bla(1);co(1,c);bla(10);    //16

cout<<("\n");
bla(15);co(11,n);co(5,p);co(3,n);bla(2);co(3,n);bla(3);co(2,c);bla(27);co(1,c);bla(1);co(1,c);bla(8);    //17

cout<<("\n");
bla(14);co(7,n);co(1,p);co(1,n);co(1,p);co(2,r);co(1,n);co(4,p);co(3,n);bla(2);co(1,n);co(2,p);co(1,n);bla(2);co(1,c);bla(10);    //18

cout<<("\n");
bla(13);co(8,n);co(3,p);co(1,r);bla(2);co(1,n);co(2,p);co(1,n);bla(2);co(1,n);bla(1);co(1,n);co(1,p);co(3,n);bla(1);co(1,a);co(1,c);    //19

cout<<("\n");
bla(15);co(6,n);co(1,p);co(4,n);bla(1);co(1,am);co(1,n);co(1,p);co(1,n);bla(4);co(1,n);co(1,p);co(1,n);bla(3);co(1,c); //20

cout<<("\n");
bla(14);co(8,n);co(4,r);co(9,n);co(1,r);co(1,p);co(1,n);bla(3);co(1,c);    //21

cout<<("\n");
bla(12);co(7,n);co(1,r);co(1,n);co(4,r);co(1,n);co(5,r);co(3,a);co(2,r);co(1,p);co(3,n);bla(1);co(1,c);bla(10);    //22

cout<<("\n");
bla(12);co(9,n);co(10,r);co(3,a);co(2,r);co(3,p);co(1,n);bla(1);co(1,c);bla(20);    //23

cout<<("\n");
bla(12);co(8,n);co(1,r);co(19,n);bla(1);co(1,c);bla(30);   //24

cout<<("\n");
bla(12);co(7,n);co(4,r);co(1,n);co(3,p);co(1,n);bla(2);co(4,n);co(1,r);co(1,p);co(3,n);bla(2);co(1,c);bla(20);    //25

cout<<("\n");
bla(12);co(1,n);bla(1);co(4,n);co(5,r);co(1,n);co(1,p);co(2,n);co(1,r);co(3,n);co(3,a);co(1,r);co(4,p);co(1,n);bla(1);co(1,c);    //26

cout<<("\n");
bla(14);co(4,n);co(4,r);co(1,n);co(1,p);co(1,n);co(6,r);co(2,a);co(2,n);co(2,p);co(2,n);bla(2);co(2,c);bla(10);    //27

cout<<("\n");
bla(15);co(4,n);co(2,r);co(6,n);co(5,r);co(1,n);bla(1);co(2,n);co(1,p);co(2,n);bla(2);co(1,a);co(1,c);bla(29);co(1,c);bla(1);co(1,c);    //28

cout<<("\n");
bla(16);co(10,n);bla(1);co(5,n);bla(3);co(2,n);co(2,p);co(1,n);bla(2);co(2,c);bla(27);co(1,c);bla(1);co(1,c);    //29

cout<<("\n");
bla(16);co(1,n);co(8,a);co(1,n);bla(10);co(3,n);bla(3);co(1,a);co(1,c);bla(26);co(1,c);bla(1);co(1,c);    //30

cout<<("\n");
bla(16);co(12,n);bla(15);co(2,c);bla(26);co(1,c);bla(5);    //31

cout<<("\n");
bla(15);co(3,n);co(2,am);co(4,n);co(4,am);co(2,n);bla(13);co(2,a);co(1,c);bla(24);co(1,c); //32

cout<<("\n");
bla(1);co(2,n);bla(10);co(4,n);co(4,am);co(2,n);co(7,am);co(1,n);bla(13);co(2,a);co(2,c);    //33

cout<<("\n");
co(1,n);co(2,r);co(1,n);bla(7);co(2,n);co(1,r);co(2,n);co(5,am);co(3,n);co(7,am);co(1,n);bla(13);co(2,a);co(2,c);    //34

cout<<("\n");
 co(1,n);co(3,r);co(1,n);bla(3);co(3,n);co(2,r);co(2,n);co(5,am);co(1,n);co(1,am);co(3,n);co(7,am);co(1,n);bla(13);co(2,a);co(3,c);    //35

cout<<("\n");
co(1,n);co(3,r);co(4,n);co(4,r);co(2,n);co(7,am);co(6,n);co(3,am);co(1,n);co(1,am);co(1,n);bla(14);co(3,a);co(3,c);bla(15);co(15,c);    //36

 cout<<("\n");
bla(1);co(1,n);co(9,r);co(3,n);co(7,am);co(1,n);bla(2);co(4,n);co(1,am);co(2,n);co(1,am);co(1,n);bla(15);co(4,a);co(3,c);bla(10);co(18,c);    //37

 cout<<("\n");
bla(2);co(2,n);co(4,r);co(3,n);co(1,a);co(2,n);co(5,am);co(2,n);bla(4);co(2,n);co(1,am);co(3,n);co(1,am);co(1,n);bla(17);co(4,a);co(4,c);bla(5);co(9,c);co(11,a);    //38
  
 cout<<("\n");
 bla(4);co(4,n);bla(2);co(1,n);co(1,a);co(8,n);bla(5);co(5,n);co(1,am);co(1,n);bla(19);co(6,a);co(12,c);co(14,a);    //39

 cout<<("\n");
bla(10);co(1,n);co(2,a);co(6,n);bla(7);co(5,n);bla(21);co(31,a);    //40

 cout<<("\n");
bla(9);co(3,n);co(2,a);co(3,n);bla(9);co(1,n);co(4,a);co(1,n);bla(22);co(29,a);    //41

 cout<<("\n");
bla(9);co(4,n);co(2,a);co(1,n);bla(10);co(1,n);co(4,a);co(1,n);bla(24);co(27,a); //42

 cout<<("\n");
bla(9);co(6,n);bla(11);co(6,n);bla(32);co(19,a);    //43

 cout<<("\n");
bla(9);co(6,n);bla(11);co(7,n);bla(30);   //44

 cout<<("\n");
bla(10);co(4,n);bla(12);co(8,n);bla(30);   //45

 cout<<("\n");
bla(26);co(8,n);bla(30);    //46

 cout<<("\n");
bla(27);co(7,n);bla(30);    //47

gotoxy(100,18);co(1,n);bla(2);co(1,n);bla(2);co(2,n);bla(2);co(1,n);bla(5);co(2,n);bla(4);co(2,n);bla(1);
gotoxy(100,19);co(1,n);bla(2);co(1,n);bla(1);co(1,n);bla(2);co(1,n);bla(1);co(1,n);bla(4);co(1,n);bla(2);co(1,n);bla(1);co(1,n);bla(2);co(1,n);
gotoxy(100,20);co(4,n);bla(1);co(1,n);bla(2);co(1,n);bla(1);co(1,n);bla(4);co(4,n);bla(3);co(1,n);bla(1);
gotoxy(100,21);co(1,n);bla(2);co(1,n);bla(1);co(1,n);bla(2);co(1,n);bla(1);co(1,n);bla(4);co(1,n);bla(2);co(1,n);bla(1);co(1,n);bla(2);co(1,n);
gotoxy(100,22);co(1,n);bla(2);co(1,n);bla(2);co(2,n);bla(2);co(4,n);bla(1);co(1,n);bla(2);co(1,n);bla(3);co(2,n);bla(1);

getch();
}
void control18(){
int a,b,c,e;

int d[50];
system("COLOR 2");
while(1){
int t;
system("cls");
gotoxy(55,2);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,3);cout<<("°°  O R D E N A M I E N T O     A S C E N D E N T E     Y     D E S C E N D E N T E    °°");
gotoxy(55,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(60,8);cout<<("1. Ordenar Numeros");
gotoxy(60,10);cout<<("3.  Salir");
gotoxy(60,12);cout<<("Ingrese opcion: ");
cin>>t;
switch(t){
case 1:
system("cls");
gotoxy(55,4);cout << "Ingrese la cantidad de numeros: ";
   
cin >> a;

for (b = 1; b <= a; b++) {
gotoxy(60,8+b);cout << " Cantidad No." << b << " :";
cin >> d[b];
}

for (b = 1; b <= a - 1; b++){
gotoxy(50-b,28);	
for (c = 1; c <= a - 1; c++) {
if (d[c] > d[c + 1]) {
e = d[c];
d[c] = d[c + 1];
d[c + 1] = e;
}
}
}
gotoxy(50,20);cout << "Ascendente: ";
for (b = 1; b <= a; b++) {
cout << "  " << d[b];
}

gotoxy(50,27);cout << "Decendente: ";
for (b = a; b >= 1; b--) {

cout << "  "<< d[b];
}
break;

case 2:
menu_principal();
}
getch();
}
}	
void control19(){
system("cls");
marco();
double a,b,c; 
char g;
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(55,4);cout<<("°°               P O T E N C I A C I O N              °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(60,8);cout <<"Ingresa cantidad: ";
cin >> a;

c = a * a;
b = a*a*a;
gotoxy(55,14);cout<<("--------------------------------------------------------");
gotoxy(60,15);cout<<"Elevado al cuadrado " << a << " es: " << c;	
gotoxy(55,19);cout<<("--------------------------------------------------------");
gotoxy(60,20);cout<<"Elevado al cubo " << a << " es: " << b;	
gotoxy(60,25);cout<<("Desea volver a intentarlo [s/n]:");	
cin>>g;
if(g=='s'){
control19();	
}else{
menu_principal();	
}
}
void control20(){
int z;	
float a,b,c,d;
float uno=45;
float dos=75;
float tres=90;
char p;
do{
system("cls");
marco();
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(55,4);cout<<("°°      R E S T A U R A N T E     E L       D E S P E R T A R    °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(60,10);cout<<("1)  Menu Desayuno ");	
gotoxy(60,12);cout<<("2)  Menu Almuerzo");	
gotoxy(60,14);cout<<("3)  Menu Familiar");	
gotoxy(60,16);cout<<("4)  Salir");	
gotoxy(60,20);cout<<("Ingrese opcion: ");	
cin>>z;
switch(z){
case 1:
system("cls");	
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(55,4);cout<<("°°            M E N U       D E S A Y U N O              °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(65,10);cout<<("[ Descripcion ]");
gotoxy(60,11);cout<<("1 vaso de cafe");	
gotoxy(60,12);cout<<("2 bollos ");	
gotoxy(60,13);cout<<("Huevos Estrellados,con frijol ");	
gotoxy(60,14);cout<<("Platanos fritos ");	
gotoxy(60,15);cout<<("Pecio:  Q.45");
gotoxy(60,20);cout<<("Desea Comprarlo: [s/n] : ");
cin>>p;
if(p=='s'){
gotoxy(60,22);cout<<("Cuantos menus necesita:");
cin>>c;
gotoxy(60,24);cout<<("Ingrese pago:");
cin>>a;
b=a-(uno*c);
gotoxy(60,26);cout<<("su vuelto es: ")<<b;	
getch();
}else{
gotoxy(60,3);cout<<("Gracias por visitarnos!!");	
control20();
}
break;
case 2:
system("cls");	
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(55,4);cout<<("°°                M E N U        A l M U E R Z O          °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(65,10);cout<<("[ Descripcion ]");
gotoxy(60,11);cout<<("Fresco de pina");	
gotoxy(60,12);cout<<("Tortillas");	
gotoxy(60,13);cout<<("Pepian ");	
gotoxy(60,14);cout<<("Flan");	
gotoxy(60,15);cout<<("Pecio:  Q.75");
gotoxy(60,20);cout<<("Desea Comprarlo: [s/n] : ");
cin>>p;
if(p=='s'){
gotoxy(60,22);cout<<("Cuantos menus necesita:");
cin>>c;
gotoxy(60,24);cout<<("Ingrese pago:");
cin>>a;
b=a-(dos*c);
gotoxy(60,26);cout<<("su vuelto es: ")<<b;	
getch();
}else{
gotoxy(60,20);cout<<("Gracias por visitarnos!!");	
control20();
}

break;
case 3:
system("cls");	
gotoxy(55,3);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(55,4);cout<<("°°            M E N U       F A M I L I A R	             °°");
gotoxy(55,5);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");	
gotoxy(65,10);cout<<("[ Descripcion ]");
gotoxy(60,11);cout<<("8 piezas de pollo tradicional");	
gotoxy(60,12);cout<<("4 papas fritas ");	
gotoxy(60,13);cout<<("1 Coca Cola 2.5 litros ");	
gotoxy(60,14);cout<<("Tortillas");
gotoxy(60,15);cout<<("3 flan");
gotoxy(60,16);cout<<("Precio:  Q.90");
gotoxy(60,20);cout<<("Desea Comprarlo: [s/n] : ");
cin>>p;
if(p=='s'){
gotoxy(60,22);cout<<("Cuantos menus necesita:");
cin>>c;
gotoxy(60,24);cout<<("Ingrese pago:");
cin>>a;
b=a-(tres*c);
gotoxy(60,26);cout<<("su vuelto es: ")<<b;	
getch();
}else{
gotoxy(60,20);cout<<("Gracias por visitarnos!!");	
control20();
}
break;	
}
}while(z!= 4);	
} 	


void co(int x, int c){
cambiarcolor(c);
int i;
for(i=1; i<=x; i++){
cout<<char(219)<<char(219);
}
}
void bla(int u){
int q;
for(q=1; q<=u; q++){
cout<<char(255)<<char(255);
}
}
 
int menu(const char *opciones[], int n){
ocultar();
int opcionSeleccionada = 1;  // Indica la opcionSeleccionada
int tecla;
bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER
do {
system("cls");

marco();
gotoxy(105, 9 + opcionSeleccionada);co(0,244);cout << "<---" << endl;
gotoxy(54, 9 + opcionSeleccionada);co(0,244);cout << "-->" << endl;
gotoxy(47,2);co(0,242);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(47,3);cout<<("°°°                 M E N U    D E    O P C I O N E S                 °°°");
gotoxy(47,4);cout<<("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
gotoxy(50,44);cout<<("[  Tecla |z|= Arriba        Tecla |x|= Abajo    Enter = Elegir  ]");     
for (int i = 0; i < n; ++i) {
co(0,241);	
gotoxy(60, 10 + i); cout << i + 1 << ") " << opciones[i];
}
 
do {
tecla = getch2();
} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
 
switch (tecla) {
 
case ARRIBA:   // En caso que se presione ARRIBA
opcionSeleccionada--;
 if (opcionSeleccionada < 1) {
opcionSeleccionada = n;
}
break;
 
case ABAJO:
opcionSeleccionada++;
 
if (opcionSeleccionada > n) {
opcionSeleccionada = 1;
}
break;
 
case ENTER:
repite = false;
break;
      }
 
   } while (repite);
 
   return opcionSeleccionada;
}
