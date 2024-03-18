#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct fecha {
	int dia;
	int mes;
	int anio;
}fechaLibro;
struct cantidad{
	int canexi;
	int canped;
};
struct ficha{
	char titulo[40];
	char autor[30];
	struct fecha fcompra;
	char editorial[20];
	struct cantidad Cprod;
	float precio;
}libroN, aux;
struct ficha libreri[20];
char menuSeleccion(char*);
void opciones(char,char*);
void salir();
void Lectura(struct ficha *libreri, int pos){
	int a, b;
	printf("\nCuantos productos desea agregar: ");
	scanf("%d", &a);
	b=pos+a;
	a=1;
	system("cls");
	for( pos; pos<b; pos++){
	printf("Libro %d\n", a);
	printf("Dame el titulo del libro %d: ", a);
	fflush(stdin);
	scanf("%[^\n]", &libreri[pos].titulo);	
	printf("Dame el autor del libro %d: ", a);
	fflush(stdin);
	scanf("%[^\n]", &libreri[pos].autor);
	printf("Dame el ano de publicacion del libro %d: ", a);
	scanf("%d", &libreri[pos].fcompra.anio);
	printf("Dame la editorial del libro %d: ", a);
	fflush(stdin);
	scanf("%[^\n]", &libreri[pos].editorial);
	printf("Dame la cantidad en existencia del libro %d: ", a);
	scanf("%d", &libreri[pos].Cprod.canexi);
	printf("Dame la cantidad de pedidos del libro %d: ", a);
	scanf("%d", &libreri[pos].Cprod.canped);
	printf("Dame el precio del libro %d: ", a);
	scanf("%d", &libreri[pos].precio);
	a++;
	system("cls");
	}
	
}
void escri(struct ficha libreri[],int  b){
	int a=0;
	if(b>0){
    printf("No. Nombres \t Autores \t Editorial \t Existencia \t Pedidos \t Precio \t");
	for(a=0; a<b; a++){
	printf("%d  %s\t %s\t %s", a,libreri[a].titulo, libreri[a].autor, libreri[a].editorial);
	}
}
}

int main() {
	char selec,menu;
	printf("**Bienvenido al Inventario de la biblioteca De la FCC**");
	printf("\n\nQue desea realizar?");
	menu=menuSeleccion(&selec);
	opciones(menu,&selec);
	return 0;
}

char menuSeleccion(char* seleccion){
	char index;
	printf("\nA) Capturar un nuevo libro");
	printf("\nB) Desplegar informacion de un libro en especifico");
	printf("\nC) Borrar del inventario un libro en especifico");
	printf("\nD) Agregar la cantidad en existencia de un libro");
	printf("\nE) Solicitar la cantidad de pedido de un libro");
	printf("\nF) Actuaizar el precio de venta de un libro");
	printf("\nG) Reporte del inventario");
	printf("\nH) Salir del programa Inventario\n");
	fflush(stdin);
	scanf("%c",&index);
	if(index>=97 && index<=122){
		index=index-32;
	}
	return index;
}
void opciones(char menu, char* caracter){
	int i, j=0;
	while(i!=1){
	switch(menu){
	case 'A':
			printf("Usted seleccion la opcion Capturar un nuevo libro");
		//capturarLibro;
			i=1;
		break;
	case 'B':
			printf("Usted selecciono la opcion Desplegar informacion de un libro en especifico");
		//informacionLibro
			i=1;
		break;
	case 'C':
		printf("Usted selecciono la opcion Borrar del inventario un libro en especifico");
		system("cls");
		Lectura(&libreri, j);
		j=contador(libreri);
		escri(libreri, j);
		//borrarLibro
		i=1;
		break;
	case 'D':
		printf("Usted seleccion la opcion Agregar la cantidad en existencia de un libro");
		//existenciaLibro
		i=1;
		break;
	case 'E':
		printf("Usted selecciono la opcion Solicitar la cantidad de pedido de un libro");
		//cantidadLibro
		i=1;
		break;
	case 'F':
		printf("Usted selecciono la opcion Actuaizar el precio de venta de un libro");
		//precioLibro
		i=1;
		break;
	case 'G':
		printf("Usted selecciono la opcion Reporte del inventario");
		//reporteLibro
		i=1;
		break;
	case 'H':
		printf("Usted selecciono la opcion Salir del programa Inventario");
		salir();
		i=1;
		break;
	default:
		printf("Ingrese un caracter valido");
		menu=menuSeleccion(caracter);
	}
	}
}

int contador(struct ficha libreri[]){
	int a=0;
    while (libreri[a].fcompra.anio!=0){
    	a++;
	}
	printf("%d", a);
	return a;
}

void salir(){
	printf("\nGracias por utilizar el programa ^^");
}
