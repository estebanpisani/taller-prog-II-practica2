#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tiempo
{
    int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct
{
    char *nombre;
    Tiempo ultima_mod;
} Archivo;

int compara_tiempos(Tiempo *t1, Tiempo *t2);
void imprime_tiempo(Tiempo t);
void ordena_alfa(Archivo *lista, int n);
void ordena_temporal(Archivo *lista, int n);

int compara_tiempos(Tiempo *t1, Tiempo *t2)
{

    if (t1->anio < t2->anio)
    {
        return 1;
    } else if (t1->anio > t2->anio){
        return -1;
    }

    if (t1->mes < t2->mes)
    {
        return 1;
    } else if (t1->mes > t2->mes){
        return -1;
    }
    if (t1->dia < t2->dia)
    {
        return 1;
    } else if (t1->dia > t2->dia){
        return -1;
    }
    if (t1->hora < t2->hora)
    {
        return 1;
    } else if (t1->hora > t2->hora){
        return -1;
    }
    if (t1->minuto < t2->minuto)
    {
        return 1;
    } else if (t1->minuto > t2->minuto){
        return -1;
    }
    if (t1->segundo < t2->segundo)
    {
        return 1;
    } else if (t1->segundo > t2->segundo){
        return -1;
    }

    return 0;
}

void imprime_tiempo(Tiempo t){
    printf("%d/%d/%d %d:%d:%d\n", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}

void ordena_alfa(Archivo *lista, int n){
    Archivo aux;
    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n-1; i++)
        {
            if(strcmp(lista[i].nombre, lista[i+1].nombre) > 0){
                aux = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = aux;            
            }
        }
    }
}

void ordena_temporal(Archivo *lista, int n){
    Archivo aux;
    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n-1; i++)
        {
            if(compara_tiempos(&(lista[i].ultima_mod), &(lista[i+1].ultima_mod)) < 0){
                aux = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = aux;            
            }
        }
    }
}

void imprimeLista(Archivo *lista, int n){
    for (int i = 0; i < n; i++)
    {
        printf("ARCHIVO %d", i+1);
        printf("nombre: %s\n", lista[i].nombre);
        printf("ultima_mod: ");
        imprime_tiempo(lista[i].ultima_mod);
    }
}

int main()
{

    Tiempo fecha1;
    fecha1.anio = 2024;
    fecha1.mes = 10;
    fecha1.dia = 13;
    fecha1.hora = 22;
    fecha1.minuto = 42;
    fecha1.segundo = 58;

    Tiempo fecha2 = {2024, 10, 13, 22, 42, 57};
    Tiempo fecha3 = {2023, 10, 13, 22, 42, 57};
    Tiempo fecha4 = fecha2;

    printf("Fecha 1: \n");
    imprime_tiempo(fecha1);
    printf("Fecha 2: \n");
    imprime_tiempo(fecha2);
    printf("Fecha 3: \n");
    imprime_tiempo(fecha3);
    printf("Fecha 4: \n");
    imprime_tiempo(fecha4);

    printf("Fecha 1 es anterior a Fecha 2?: %d\n", compara_tiempos(&fecha1, &fecha2));
    printf("Fecha 3 es anterior a Fecha 2?: %d\n", compara_tiempos(&fecha3, &fecha2));
    printf("Fecha 4 es igual a Fecha 2?: %d\n", compara_tiempos(&fecha4, &fecha2));

    Archivo archivo1 = {"Zapata", fecha1};
    Archivo archivo2 = {"Felipe", fecha2};
    Archivo archivo3 = {"Carlitos", fecha3};
    Archivo archivo4 = {"Abelardo", fecha4};

    Archivo lista[4] = {archivo1, archivo2, archivo3, archivo4};

    printf("LISTA ANTES DE ORDENAR ALFABETICAMENTE.\n");
    imprimeLista(lista, 4); 

    ordena_alfa(lista, 4);

    printf("LISTA DESPUES DE ORDENAR ALFABETICAMENTE.\n");
    imprimeLista(lista, 4);

    printf("LISTA ANTES DE ORDENAR TEMPORALMENTE.\n");
    imprimeLista(lista, 4); 

    ordena_temporal(lista, 4);

    printf("LISTA DESPUES DE ORDENAR TEMPORALMENTE.\n");
    imprimeLista(lista, 4);

    return 0;
}