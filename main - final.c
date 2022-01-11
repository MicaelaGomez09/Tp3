#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct {

    char titulo[30];
    char genero[30];
    float duracion;
    char descripcion[280];
    float puntaje;
    char linkImagen[50];
    int estado; /* Active (1) Inactivo(0) */
}Movie;


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
    continuar();
}

void cargar()
{
    crearArchivo();

    FILE *arch;
    arch=fopen("peliculas.dat","ab");
    if (arch==NULL)
        exit(1);
    Movie peli;
    printf("Ingrese el titulo de la pelicula: ");
    scanf("%s",&peli.titulo);
    fflush(stdin);

    printf("Ingrese el genero: ");
    gets(peli.genero);

    printf("Ingrese una duracion: ");
    scanf("%f",&peli.duracion);
/*
    printf("Ingrese una descripcion: ");
    gets(peli.descripcion);
*/
    printf("Ingrese una descripcion: ");
    scanf("%s",&peli.descripcion);

    printf("Ingrese una puntaje: ");
    scanf("%f",&peli.puntaje);

    fwrite(&peli, sizeof(Movie), 1, arch);
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
        printf("%s %s %0.2f %s %0.2f\n", peli.titulo, peli.genero, peli.duracion, peli.descripcion, peli.puntaje);
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
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    printf("Ingrese el titulo de una pelicula a modificar:");
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

           printf("Ingrese nuevo titulo:");
           scanf("%s",&peli.titulo);

           printf("Ingrese nuevo genero:");
           scanf("%s",&peli.genero);

           printf("Ingrese nuevo duracion:");
           scanf("%f",&peli.duracion);

           printf("Ingrese nuevo descripcion:");
           scanf("%s",&peli.descripcion);

           printf("Ingrese nuevo puntaje:");
           scanf("%f",&peli.puntaje);

           int pos=ftell(arch)-sizeof(Movie);
           fseek(arch,pos,SEEK_SET);
           fwrite(&peli, sizeof(Movie), 1, arch);
           printf("Se modifico el precio para dicha pelicula.\n");
           existe=1;
           break;
        }
        fread(&peli, sizeof(Movie), 1, arch);
    }
    if (existe==0)
        printf("No existe un pelicula con dicho dato\n");
    fclose(arch);
    continuar();
}

int main()
{
    int opcion;
    do {
        printf("1 - Agregar pelicula \"peliculas.dat\"\n");
        printf("2 - Carga de registros de tipo Movie\n");
        printf("3 - Listado completo de peliculas.\n");
        printf("4 - Consulta de una pel por su codigo.\n");
        printf("5 - Modificacion del precio de un producto. \n");
        printf("6 - Finalizar\n\n");
        printf("Ingrese su opcion:");
        //enviar en funcion menu

        scanf("%i",&opcion);
        switch (opcion) {
            case 1:
                   break;
            case 2:cargar();
                   break;
            case 3:listado();
                   break;
            case 4:consulta();
                   break;
            case 5:modificacion();
                   break;
        }
    } while (opcion!=6);
    return 0;
}
