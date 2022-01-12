#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct {

    int codigo;
    char titulo[30];
    char genero[30];
    float duracion;
    char descripcion[280];
    float puntaje;
    char linkImagen[50];
    int estado; /* Active (1) Inactivo(0) */
}Movie;

void continuar();
void crearArchivo();
void cargar();
void listado();
void consulta();
void modificacion();
void printMenu();


#endif // MOVIE_H_INCLUDED
