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

int comparaTipo(void* bici1, void* bici2);

int filtrarXtipoBMX(void* bici);
int filtrarXtipoPASEO(void* bici);
int filtrarXtipoPLAYERA(void* bici);
int filtrarXtipoMTB(void* bici);

int pais_setId(eBicicleta* this,int id);
int pais_setNombre(eBicicleta* this,char* nombre);
int pais_setTipo(eBicicleta* this,char* tipo);
int pais_setTiempo(eBicicleta* this,int tiempo);

int pais_getId(eBicicleta* this,int* id);
int pais_getNombre(eBicicleta* this,char* nombre);
int pais_getTipo(eBicicleta* this,char* tipo);
int pais_getTiempo(eBicicleta* this,int* tiempo);

int filtrarPorTipo(LinkedList* this);

#endif // PAIS_H_INCLUDED
