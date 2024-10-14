#include <stdio.h>
#include <stdlib.h>

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

int main()
{

    struct tiempo fecha1;
    fecha1.anio = 2024;
    fecha1.mes = 10;
    fecha1.dia = 13;
    fecha1.hora = 22;
    fecha1.minuto = 42;
    fecha1.segundo = 58;

    struct tiempo fecha2 = {2024, 10, 13, 22, 42, 57};
    struct tiempo fecha3 = {2023, 10, 13, 22, 42, 57};
    struct tiempo fecha4 = fecha2;

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

    return 0;
}