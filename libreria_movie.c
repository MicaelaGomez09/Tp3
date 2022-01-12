#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "movie.h"
#define ACTIVO 1
#define BORRADO 0

void getString(char mensaje[], char input[])
{
  printf("%s", mensaje);
  scanf("%s", input);
}
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
int getSoloLetras(char mensaje[], char input[])
{
  char datoIngresado[256];
  getString(mensaje, datoIngresado);//(placeholder, &duardado_en) /**/
  if(esSoloLetras(datoIngresado)) //si lo que ingresó el usuario son solo letras
  {
    strcpy(input, datoIngresado);//copiamos el dato ingresado en 'inpu'
    return 1;
  }
  return 0;
}
int getInt(char mensaje[])
{
    int aux; //variable int que contendr� el valor de mensaje
    printf("%s", mensaje);//solicita un string
    scanf("%d", &aux);//toma el string y lo guarda tido %d en la variable
    return aux;// retorna la variable con el dato guardado
}
float getFloat(char mensaje[])
{
    float aux; //variable flotante que contendr� el valor de mensaje
    printf("%s", mensaje);//solicita un string
    scanf("%f", &aux);//toma el string y lo guarda en la variable
    return aux;// retorna la variable con el dato guardado
}
int getSoloNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}
int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
int getChar(char mensaje[])
{
    float aux; //variable flotante que contendr� el valor de mensaje
    printf("%s", mensaje);//solicita un string
    fflush(stdin); // el estandar input puede contener algun residuo
    scanf("%c", &aux);//toma el string y lo guarda en la variable
    return aux;// retorna la variable con el dato guardado
}


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

void cargar()
{
    FILE *arch;
    arch=fopen("peliculas.dat","a+b");
    if (arch==NULL)
        exit(1);
    Movie peli;


    printf("Ingrese el codigo del producto:");
    scanf("%i",&peli.codigo);
    fflush(stdin);

    printf("Ingrese el titulo de la pelicula: ");
    scanf("%s",&peli.titulo);
    fflush(stdin);

    if(!getSoloLetras("Ingrese un genero: ", &peli.genero))
    {
        printf("El genero debe contener solo letras\n");
        return 0;
    }

    printf("Ingrese duracion: ");
    scanf("%f", &peli.duracion);

    if(!getSoloLetras("Ingrese una descripcion: ", &peli.descripcion))
    {
        printf("La descripcion debe contener solo letras\n");
        return 0;
    }

    printf("Ingrese puntuaje: ");
    scanf("%f",&peli.puntaje);
    fwrite(&peli, sizeof(Movie), 1, arch);
    fclose(arch);

    peli.estado=1;
    printf("estado : %d", peli.estado);

    printf("PELICULA GUARDADA CON EXITO");
}

void borrado()
{
FILE *arch;
    arch=fopen("peliculas.dat","r+b");
    if (arch==NULL)
        exit(1);
    printf("Ingrese el codigo de pelicula a borrar:");
    int cod;
    scanf("%d", &cod);
    Movie peli;
    int existe=0;
    fread(&peli, sizeof(Movie), 1, arch);
    while(!feof(arch))
    {
        if (cod==peli.codigo)
        {
           printf("%i %s %0.2f\n", peli.codigo, peli.titulo, peli.duracion);

           peli.estado=0;
           peli.duracion=0;
           printf("estado: %d", peli.estado);
           printf("duracion: %0.2f", peli.duracion);
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
        printf("%d %s %s %0.2f %s %0.2f %d \n",peli.codigo, peli.titulo, peli.genero, peli.duracion, peli.descripcion, peli.puntaje, peli.estado);
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
        if (title == peli.titulo)
        {
            printf("%d %s %s %0.2f %s %0.2f\n",peli.codigo, peli.titulo, peli.genero, peli.duracion, peli.descripcion, peli.puntaje);
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
    printf("Ingrese el codigo de pelicula a modificar:");
    int cod;
    scanf("%d", &cod);
    Movie peli;
    int existe=0;
    fread(&peli, sizeof(Movie), 1, arch);
    while(!feof(arch))
    {
        if (cod==peli.codigo)
        {
           printf("%i %s %0.2f\n", peli.codigo, peli.titulo, peli.duracion);
           printf("Ingrese nuevo titulo:");
           scanf("%s",&peli.titulo);
           int pos=ftell(arch)-sizeof(Movie);
           fseek(arch,pos,SEEK_SET);
           fwrite(&peli, sizeof(Movie), 1, arch);
           printf("Se modifico el titulo para dicha pelicula.\n");
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
