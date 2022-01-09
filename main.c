#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

struct movie
{
    char titulo[30];
    char genero[30];
    int duracion;
    char descripcion[280];
    int puntaje;
    char linkImagen[50];
    int estado; /* Active (1) Inactivo(0) */
};

/** \brief Pide al usuario los datos y los guarda en la struct
 * \param struct movie* p puntero a struct donde se almacenan los datos ingresados
 * \return void
 */
void loadData(struct movie* p)
{
    getString("Ingrese el titulo:",p->titulo);
    getString("Ingrese el genero:",p->genero);
    p->duracion=getInt("Ingrese la duracion:");
    getString("Ingrese la descripcion:",p->descripcion);
    p->puntaje=getInt("Ingrese el puntaje:");
    getString("Ingrese el link:",p->linkImagen);
    p->estado=getInt("Ingrese el estado:");
}



/** \brief Guarda una struct al final de un archivo binario bin.dat
 * \param struct movie* p puntero a struct a ser escrita
 * \return 0: error, 1:OK
 */
int savePerson(struct movie* p)
{
    FILE* fp;
    fp=fopen("movie.dat","ab+"); // append binario, lo crea si no existe
    if(fp==NULL)
    {
        printf("Error opening file");
        return 0;
    }
    fwrite(p,sizeof(struct movie),1,fp); // escribo una struct al final

    fclose(fp);
    return 1;
}




/** \brief Busca en el archivo la struct con el apellido pasado como argumento y la devuelve
 * \param char* surname apellido
 * \return Puntero a struct que se leyo del archivo o NULL si no existe el apellido
 */
struct movie* readPerson(char* titulo)
{
    FILE* fp;
    fp=fopen("movie.dat","rb"); // lectura binaria
    if(fp==NULL)
    {
        printf("Error opening file");
        return NULL;
    }

    struct movie* pRet = malloc(sizeof(struct movie));
    int flagFound=0;
    while(fread(pRet,sizeof(struct movie),1,fp)!=0)
    {
        //printf("Leo %s %s %d\r\n",pRet->name,pRet->surname,pRet->age);
        if(strcmp(titulo,pRet->titulo)==0)
        {
            flagFound=1;
            break;
        }
    }
    fclose(fp);
    if(flagFound)
        return pRet;
    free(pRet);
    return NULL;
};

int main()
{
    struct movie p;
    char out='s';
    int op=0;
    char tituloToFind[64];
    while(op != 7)
    {
        system("cls");
        printMenu();
        scanf("%d", &op);
        switch(op)
        {
        case 1 :
            while(out=='s')
            {
                loadData(&p);
                savePerson(&p);
                //out = getChar("Ingresar uno nuevo? s/n:");
                system ("cls");
                break;
            }
        case 2: //BORRAr
             getString("Ingrese titulo a borrar en archivo:",tituloToFind);

            struct movie* pFound = readPerson(tituloToFind);

            if(pFound!=NULL)
            {
                // printf("Se encontro: nombre:%s apellido:%s edad:%d\r\n",pFound->name,pFound->surname,pFound->age);
                strcpy(pFound->titulo,"vacio");
                printf("Se borro correctamente el titulo ");
                system("pause");
                free(pFound);
            }
            else
                printf("el titulo ingresado no esta en el archivo");

            break;
        case 3: //MOSTRAR LISTA
            break;
        case 4: //MODIFICAR
            break;
        case 5:

            //char tituloToFind[64];
            getString("Ingrese titulo a buscar en archivo:",tituloToFind);

            struct movie* pBusca = readPerson(tituloToFind);

            if(pBusca!=NULL)
            {
                // printf("Se encontro: nombre:%s apellido:%s edad:%d\r\n",pFound->name,pFound->surname,pFound->age);
                printf("Se encontro: titulo:%s \r\n",pBusca->titulo);
                system("pause");
                free(pBusca);
            }
            else
                printf("el titulo ingresado no esta en el archivo");

            break;

        case 6://genera link
            case 7 :

            break;

        default:
            printf("Valor ingresado fuera de rango ");
            system("pause");

        }
    }
    return 0;
}
