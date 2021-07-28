#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}ePais;

ePais* pais_new();
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1Str,char* vac2Str,char* sinVacStr);

int numAleatorio(int a,int b);
int randomVac1(void* pais);
int randomVac2(void* pais);
int porcentajeSinVacunar(void* pais);

int paisExitoso(void* pais);
int paisAlHorno(void* pais);

int comparar1Dosis(void* pais1,void* pais2);
int compararMasCastigado(void* pais1,void* pais2);
int mostrarMasCastigados(LinkedList* this);
#endif // PAIS_H_INCLUDED
