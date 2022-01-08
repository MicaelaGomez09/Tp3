#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria_movie.h"

void getString(char mensaje[], char input[])
{
  printf("%s", mensaje);
  scanf("%s", input);
}
int getInt(char mensaje[])
{
    int aux; //variable int que contendr� el valor de mensaje
    printf("%s", mensaje);//solicita un string
    scanf("%d", &aux);//toma el string y lo guarda tido %d en la variable
    return aux;// retorna la variable con el dato guardado
}
int getChar(char mensaje[])
{
    float aux; //variable flotante que contendr� el valor de mensaje
    printf("%s", mensaje);//solicita un string
    fflush(stdin); // el estandar input puede contener algun residuo
    scanf("%c", &aux);//toma el string y lo guarda en la variable
    return aux;// retorna la variable con el dato guardado
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
//subfunciones de getSoloNumeros y getSoloLetras
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

/** Pide los datos y los guarda en la struct
 *
 *
 */
void loadDatos(struct Movie* m)
{
  getString("Ingrese el nombre: ", m -> titulo);
  getString("Ingrese el apellido: ", m -> genero);
  m ->duracion = getInt("Ingrese una duracion: ");
  getString("Ingrese una descripcion: ", m -> descripcion);
  getInt("Ingrese un puntaje: ");
}

/** Guarda una struct al final de un archivo binario.dat
 * \param struct Movie* m puntero a struct a ser escrita
 * \return 0:error, 1:OK
 */
int saveMovie(struct Movie* m) //recibe el puntero a estructura
{
    FILE* fm; //defino una variable para el puntero del archivo
    fm = fopen("bin.dat","ab+"); //append binario. ab: es para q sea binario, el + crea el archivo si no existe

    if(fp==NULL)
    {
        printf("Error opening archivo");
        return 0;
    }
    //fwrite hay q pasarle: el puntero, el tamaño del bloque que queremos escribir, la cantidad de bloques a escribir y el puntero donde vamos a escribir.
    fwrite(m, sizeof(struct Movie),1,fm); //para escribir la estructura al final del archivo

    fclose(fm);//cierra el file
    return 1;
}

/** Busca en el archivo la estruct con el nombre pasado como argumento y lo devuelve
 * \param struct Movie* m puntero a struct a ser escrita
 * \return 0:error, 1:OK
 */
struct Movie* readMovie(char* titulo)
{
    FILE* fm;
    fm=fopen("bin.dat","rb"); //abrimos el archivo en el modo rb(solo lectura)

    if()
    {
        printf("Error opening archivo");
        return NULL;
    }
    //Ahora creamos una estructura en forma dinamica donde guardaremos los datos leidos
    struct Movie* mRet = malloc(sizeof(struct Movie)); //en mRet guardamos el tamaño q representaesa estructura
    int flagEncontrado = 0;

    //freadfunciona con: puntero donde guardaremos los datos leidos, la cantidad de dytes del bloque q vamos a leer, cantidad de bloques q lee a la vez y el puntero al archivo.
    while(fread(mRet,sizeof(struct Movie),1,fm) != 0) //mientras se haya leido un bloque dará distinto de cero, entonces entra al while
    {
        if(strcmp(titulo, mRet -> titulo) == 0) //pregunta si el campo titulo es igual al la cad de char titulo q recibimos como argumento
        {
            flagEncontrado = 1; //si se cumple acusa OK
            break;
        }
    }
    fclose(fm);
    if(flagEncontrado)//si encontró el titulo entonces lo retorna
        return mRet;
    free(mRet); //si no lo encontró entonces liberamos ese espacio
    return NULL;
}

///////////////
/** Inicializa el array
\param arrayProductos es el array en el cual buscar
\param arrayLongitud indica el largo del array
\param value el valor que se asignara a estatus
*/
void setStatus(Movie arrayProductos[], int arrayLongitud, int value)
{
    int i;
    for(i=0; i < arrayLongitud; i++)
    {
        arrayProductos[i].status = value;
    }
}

/** Busca el primerlugar vacio en el array
\param arrayProductos: es el array en el cual buscar
\param arraylongitud: indica el largo del array
\return Si no hay lugares libres: (-1) y si lo hay indica la posicion del mismo:(i)
*/
int findEmptyPlace(Movie arrayProductos[], int arrayLongitud)
{
    int i;
    for(i=0; i < arrayLongitud; i++)
    {
        if(arrayProductos[i].status == 0)
        {
            return i;
        }
    }
}

/** Busca la primer coincidencia de un codigo
\param arrayProductos es el array en el q busca
\param arrayLongitud indica el largo del array
\param code es el valor que busca
\return Si no hya coincidencia: -1, si la hay: i
*/
int findProductByCode(Movie arrayProductos[], int arrayLongitud, int code)
{
    int i;
    for(i=0; i < arrayLongitud; i++)
    {
        //verifica q coincida el codigo y q el producto esté activo
        if(arrayProductos[i].code == code && arrayProductos[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}

/** Permite ingrear un texto y devuelve un puntero con la direccion de memoria
donde estara el texto ingresado.
\param char* msg. Mensaje a ser impreso
\return Puntero a cadena de caracteres con texto ingresado.
Una vez mostrado hay q liberar memoria con free(pName).
*/
char* getDinamicStr(char* msg) //recibe puntero cadena de char
{
    printf(msg); //imprime el msj q recibimos como argumento

    char* pData = (char*)malloc(sizeof(char)*1024); //luego construye un espacio de mem de 1k para usar en el scanf

    scanf("%1023s", pData); //el ingreso deberá ser inferior a 1023 letras

    int len = strlen(pData); //ahora veremos cuantas letras hay en ese ingreso

    pData = (char*)realloc(pData, sizeof(char)*(len+1)); //una vez q tenemos el espacio hacemos realloc para achicar el espacio de mem reservada. Entonces devolverá el espacio justo

    return pData; //retorna el dato
}

//
