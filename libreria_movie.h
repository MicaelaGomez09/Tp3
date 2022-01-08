#ifndef LIBRERIA_MOVIE_H_INCLUDED
#define LIBRERIA_MOVIE_H_INCLUDED

struct Movie
{
    char titulo[30];
    char genero[30];
    int duracion;
    char descripcion[280];
    int puntaje;
    char linkImagen[50];
    int estado; /* Active (1) Inactivo(0) */
}m;

void getString(char mensaje[], char input[]);
int getInt(char mensaje[]);
int getChar(char mensaje[]);

void loadDatos(struct Movie* m);
int saveMovie(struct Movie* m);
struct Movie* readMovie(char* titulo);

//void setStatus(Movie arrayProductos[], int arrayLongitud, int value);
//int findEmptyPlace(Movie arrayProductos[], int arrayLongitud);
//int findProductByCode(Movie arrayProductos[], int arrayLongitud, int code);
char* getDinamicStr(char* msg);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
//int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
//int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
//void generarPagina(EMovie lista[], char nombre[]);
#endif // LIBRERIA_MOVIE_H_INCLUDED
