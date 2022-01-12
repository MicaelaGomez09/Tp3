#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "movie.h"
#define ACTIVO 1
#define BORRADO 0

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
