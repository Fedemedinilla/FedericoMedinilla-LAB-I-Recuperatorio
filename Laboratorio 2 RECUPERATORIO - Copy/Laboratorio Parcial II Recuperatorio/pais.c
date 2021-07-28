#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"
#include "LinkedList.h"
#include "pais.h"

eBicicleta* pais_new()
{
    eBicicleta* auxBici;

    auxBici=(eBicicleta*)malloc(sizeof(eBicicleta));
    if(auxBici!=NULL)
    {
        auxBici->id=0;
        strcpy(auxBici->nombre," ");
        strcpy(auxBici->tipo," ");
        auxBici->tiempo=0;
    }

    return auxBici;
}
eBicicleta* pais_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{
    eBicicleta* auxBici;
    auxBici=pais_new();

    if(auxBici!=NULL && idStr!=NULL && nombreStr!=NULL && tipoStr!=NULL && tiempoStr!=NULL)
    {
		if(!(pais_setId(auxBici,atoi(idStr))==0
            &&pais_setNombre(auxBici,nombreStr)==0
            &&pais_setTipo(auxBici,tipoStr)==0
            &&pais_setTiempo(auxBici,atoi(tiempoStr))==0))
		{
			free(auxBici);
			auxBici=NULL;
		}
    }

    return auxBici;
}
///SETTERS
int pais_setId(eBicicleta* this,int id)
{
    int error=1;

    if(this!=NULL)
    {
        this->id=id;
        error=0;
    }

    return error;
}
int pais_setNombre(eBicicleta* this,char* nombre)
{
	int error=1;

	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		error=0;
	}

	return error;
}
int pais_setTipo(eBicicleta* this,char* tipo)
{
	int error=1;

	if(this!=NULL)
	{
		strcpy(this->tipo,tipo);
		error=0;
	}

	return error;
}
int pais_setTiempo(eBicicleta* this,int tiempo)
{
	int error=1;

	if(this!=NULL)
	{
		this->tiempo=tiempo;
		error=0;
	}

	return error;
}
///GETTERS
int pais_getId(eBicicleta* this,int* id)
{
	int error=1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		error=0;
	}

	return error;
}
int pais_getNombre(eBicicleta* this,char* nombre)
{
	int error=1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		error=0;
	}

	return error;
}
int pais_getTipo(eBicicleta* this,char* tipo)
{
	int error=1;

	if(this!=NULL && tipo!=NULL)
	{
		strcpy(tipo,this->tipo);
		error=0;
	}

	return error;
}
int pais_getTiempo(eBicicleta* this,int* tiempo)
{
	int error=1;

	if(this!=NULL && tiempo!=NULL)
	{
		*tiempo=this->tiempo;
		error=0;
	}

	return error;
}
///
///MAP
int numAleatorio(int a,int b)
{
    int resultado;

    resultado=rand()%(a-b+1)+b;

    return resultado;
}
int randomTiempo(void* bicicleta)
{
    int error=1;
    int resultado;
    int min=50;
    int max=120;

    eBicicleta* bicicleta1;
    if(bicicleta!=NULL)
    {
        bicicleta1=(eBicicleta*)bicicleta;
        resultado=numAleatorio(max,min);
        if(resultado>=min && resultado<=max)
        {
            bicicleta1->tiempo=resultado;
            error=0;
        }
    }

    return error;
}
