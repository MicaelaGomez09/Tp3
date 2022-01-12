#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "movie.h"
#define ACTIVO 1
#define BORRADO 0

/*typedef struct
{

    int codigo;
    char titulo[30];
    char genero[30];
    float duracion;
    char descripcion[280];
    float puntaje;
    char linkImagen[50];
    int estado; /* Active (1) Inactivo(0)
} Movie;*/


void continuar()
{
    printf("Presione una tecla para continuar\n\n");
    getch();
}

void crearArchivo()
{
    FILE *arch;
    arch=fopen("peliculas.dat","wb");
    if (arch==NULL)
        exit(1);
    fclose(arch);
}

/*void cargar()
{


    FILE *arch;
    arch=fopen("peliculas.dat","ab");
    if (arch==NULL)
        exit(1);
    Movie peli;

    printf("Ingrese el codigo de la pelicula:");
    scanf("%i",&peli.codigo);
    fflush(stdin);

    printf("Ingrese el titulo de la pelicula: ");
    scanf("%s",&peli.titulo);
    fflush(stdin);

    printf("Ingrese el genero: ");
    gets(peli.genero);

    printf("Ingrese una duracion: ");
    scanf("%f",&peli.duracion);

    printf("Ingrese una descripcion: ");
    scanf("%s",&peli.descripcion);

    printf("Ingrese una puntaje: ");
    scanf("%f",&peli.puntaje);

    // strcpy(peli.estado,"ACTIVO");

    fwrite(&peli, sizeof(Movie), 1, arch);
    fclose(arch);
    continuar();
}*/
void cargar()
{
    FILE *arch;
    arch=fopen("peliculas.dat","a+b");
    if (arch==NULL)
        exit(1);
    Movie peli;

    printf("Ingrese el titulo de la pelicula: ");
    scanf("%s",&peli.titulo);
    fflush(stdin);

    if(!getSoloLetras("Ingrese un genero: ", &peli.genero))
    {
        printf("El genero debe contener solo letras\n");
        return 0;
    }

    if(!getSoloNumeros("Ingrese una duracion en minutos: ", &peli.duracion))
    {
        printf("\nLa duracion debe contener solo numeros\n");
        return 0;
    }

    if(!getSoloLetras("Ingrese una descripcion: ", &peli.descripcion))
    {
        printf("La descripcion debe contener solo letras\n");
        return 0;
    }

    if(!getSoloNumeros("Ingrese un puntaje del 1 al 10: ", &peli.puntaje))
    {
        printf("\nEl puntaje debe contener solo numeros\n");
        return 0;
    }

    fwrite(&peli, sizeof(Movie), 1, arch);
    fclose(arch);

    printf("PELICULA GUARDADA CON EXITO");
}

void borrado()
{
    FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    printf("Ingrese el titulo de una pelicula a borrar:");
    char title;
    scanf("%s", &title);
    Movie peli;
    int existe=0;
    fread(&peli, sizeof(Movie), 1, arch);
    while(!feof(arch))
    {
        if (title==peli.titulo)
        {
            strcpy(peli.titulo,"BORRADO");
            strcpy(peli.genero,"BORRADO");
            peli.duracion=0;
            strcpy(peli.descripcion,"BORRADO");
            peli.puntaje=0;
            strcpy(peli.estado,"BORRADO");



            int pos=ftell(arch)-sizeof(Movie);
            fseek(arch,pos,SEEK_SET);
            fwrite(&peli, sizeof(Movie), 1, arch);
            printf("Se borro la pelicula correctamente.\n");
            existe=1;
            break;
        }
        fread(&peli, sizeof(Movie), 1, arch);
    }
    if (existe==0)
        printf("No existe una pelicula con dicho dato\n");
    fclose(arch);
    continuar();
}

void listado()
{
    FILE *arch;
    arch=fopen("peliculas.dat","rb");
    if (arch==NULL)
        exit(1);
    Movie peli;
    fread(&peli, sizeof(Movie), 1, arch);
    while(!feof(arch))
    {
        printf("%d %s %s %0.2f %s %0.2f\n",peli.codigo, peli.titulo, peli.genero, peli.duracion, peli.descripcion, peli.puntaje);
        fread(&peli, sizeof(Movie), 1, arch);
    }
    fclose(arch);
    continuar();
}

void consulta()
{
    FILE *arch;
    arch=fopen("productos.dat","rb");
    if (arch==NULL)
        exit(1);
    printf("Ingrese el titulo de pelicula a consultar:");
    char title;
    scanf("%s", &title);
    Movie peli;
    int existe=0;
    fread(&peli, sizeof(Movie), 1, arch);
    while(!feof(arch))
    {
        if (title==peli.titulo)
        {
            printf("%s %s %0.2f %s %0.2f\n", peli.titulo, peli.genero, peli.duracion, peli.descripcion, peli.puntaje);
            existe=1;
            break;
        }
        fread(&peli, sizeof(Movie), 1, arch);
    }
    if (existe==0)
        printf("No existe una pelicula con dicho titulo\n");
    fclose(arch);
    continuar();
}

void modificacion()
{
    FILE *arch;
    arch=fopen("peliculas.dat","r+b");
    if (arch==NULL)
        exit(1);
    printf("Ingrese el codigo de la pelicula a modificar:");
    int cod;
    scanf("%i", &cod);
    Movie peli;
    int existe=0;
    fread(&peli, sizeof(Movie), 1, arch);
    while(!feof(arch))
    {
        if (cod==peli.codigo)
        {
            printf("%i %s %0.2f\n", peli.codigo, peli.titulo, peli.duracion);

           printf("Ingrese nuevo titulo:");
           scanf("%i",&peli.titulo);
           int pos=ftell(arch)-sizeof(Movie);
           fseek(arch,pos,SEEK_SET);
           fwrite(&peli, sizeof(Movie), 1, arch);
           printf("Se modifico el titulo de dicha pelicula.\n");
           existe=1;
           break;
        }
        fread(&peli, sizeof(Movie), 1, arch);
    }
    if (existe==0)
        printf("No existe una pelicula con ese titulo\n");
    fclose(arch);
    continuar();
}
void printMenu()
{
    printf("\n                                           +---------------------------+\n");
    printf("                                           ¦      Menu de opciones     ¦\n");
    printf("                                           +---------------------------+\n");
    printf("                                           -----------------------------\n");
    printf("                                           ¦  1-AGREGAR PELICULA        ¦\n");
    printf("                                           ¦  2-BORRAR PELICULA         ¦\n");
    printf("                                           ¦  3-LISTA DE PELICULAS      ¦\n");
    printf("                                           ¦  4-MODIFICAR PELICULA      ¦\n");
    printf("                                           ¦  5-BUSCAR PELICULA         ¦\n");
    printf("                                           ¦  6-GENERAR LINK            ¦\n");
    printf("                                           ¦  7-SALIR                   ¦\n");
    printf("                                           -----------------------------\n");
    printf("                                           ELEGIR NUMERO DE OPERACION: ");
}

int main()
{
    crearArchivo();
    int opcion;
    do
    {
        printMenu();

        scanf("%i",&opcion);
        switch (opcion)
        {
        case 1:
            cargar();
            break;
        case 2:
            borrado();
            break;
        case 3:
            listado();
            break;
        case 4:
            modificacion();
            break;
        case 5:
            consulta();
            break;
        }
    }
    while (opcion!=6);
    return 0;
}
