#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria_movie.h"

int main()
{
    char seguir='s';
    int opcion=0;

    char out = "ok";
    char peliculaAEncontrar[30];

    while(seguir == 's')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("3- Buscar pelicula\n");
        printf("3- Generar link\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: //AGREGAR
                while(out == "ok")
                {
                  loadDatos(&m);
                  saveMovie(&m);
                  out = getChar("Ingresar una pelicula? ok/no ");
                }
                break;
            case 2: //BORRAR
                break;
            case 3: //MODIFICAR
               break;
            case 4: //BUSCAR

                getString("Ingrese un titulo a buscar en el archivo: ", peliculaAEncontrar);//recibe lo q queremos buscar

                struct Movie* mEncontrada = readMovie(peliculaAEncontrar); //luego llamo a readMovie enviandole el titulo q buscamos. mEncontrada es la estructura de la pelicula encontrada

                if(mEncontrada != NULL)
                {
                  printf("Se encontro: Titulo: %s | Genero: %s | Duracion: %d | Descripcion: %s | Puntaje: %d", mEncontrada -> titulo, mEncontrada -> genero, mEncontrada -> duracion, mEncontrada -> descripcion, mEncontrada -> puntaje);
                  free(mEncontrada); //una vez encontrada libero ese espacio
                }
                else
                  printf("El titulo ingresado no está en el archivo");

                return 0;

                break;
            case 5: //GENERA LINK
                break;
            case 6: //SALIR
              seguir = 'n';
              break;
        }
    }

    return 0;
}
