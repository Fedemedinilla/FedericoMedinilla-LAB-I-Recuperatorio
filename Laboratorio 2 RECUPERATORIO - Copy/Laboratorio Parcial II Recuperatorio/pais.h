#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char tipo[20];
    int tiempo;
}eBicicleta;

eBicicleta* pais_new();
eBicicleta* pais_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr);

int numAleatorio(int a,int b);
int randomTiempo(void* eBicicleta);

int paisExitoso(void* pais);
int paisAlHorno(void* pais);

int comparar1Dosis(void* pais1,void* pais2);
int compararMasCastigado(void* pais1,void* pais2);
int mostrarMasCastigados(LinkedList* this);
#endif // PAIS_H_INCLUDED
