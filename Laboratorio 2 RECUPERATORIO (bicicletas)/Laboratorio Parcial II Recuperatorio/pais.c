#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"
#include "LinkedList.h"
#include "pais.h"
#include "controller.h"

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
int filtrarPorTipo(LinkedList* this)
{
    int error=-1;
    int menuOpcion;

    LinkedList* resultado=NULL;
    resultado=ll_newLinkedList();

    if(this!=NULL)
    {
        if(!getNumero(&menuOpcion,
            "\nIngrese tipo\n 1-bmx\n 2-playera\n 3-mtb\n 4-paseo\n\n"
            "Ingrese una opcion(1-4): ",
            "\nERROR Ingrese entre 1 y 4.\n\n",1,4))
            {
                switch(menuOpcion)
                {
                case 1:
                    resultado=ll_filter(this,filtrarXtipoBMX);
                    controller_mostrarPaises(resultado);
                    break;
                case 2:
                    resultado=ll_filter(this,filtrarXtipoPLAYERA);
                    controller_mostrarPaises(resultado);
                    break;
                case 3:
                    resultado=ll_filter(this,filtrarXtipoMTB);
                    controller_mostrarPaises(resultado);
                    break;
                case 4:
                    resultado=ll_filter(this,filtrarXtipoPASEO);
                    controller_mostrarPaises(resultado);
                    break;
                }
            }
        error=0;
    }

    return error;
}
///FILTERS POR TIPO
int filtrarXtipoBMX(void* bici)
{
    int error=0;

    eBicicleta* auxBici;
    if(bici!=NULL)
    {
        auxBici=(eBicicleta*)bici;
        if(strcmp(auxBici->tipo,"BMX"))
        {
            error=1;
        }
    }

    return error;
}
int filtrarXtipoPASEO(void* bici)
{
    int error=0;

    eBicicleta* auxBici;
    if(bici!=NULL)
    {
        auxBici=(eBicicleta*)bici;
        if(strcmp(auxBici->tipo,"PASEO"))
        {
            error=1;
        }
    }

    return error;
}
int filtrarXtipoPLAYERA(void* bici)
{
    int error=0;

    eBicicleta* auxBici;
    if(bici!=NULL)
    {
        auxBici=(eBicicleta*)bici;
        if(strcmp(auxBici->tipo,"PLAYERA"))
        {
            error=1;
        }
    }

    return error;
}
int filtrarXtipoMTB(void* bici)
{
    int error=0;

    eBicicleta* auxBici;
    if(bici!=NULL)
    {
        auxBici=(eBicicleta*)bici;
        if(strcmp(auxBici->tipo,"MTB"))
        {
            error=1;
        }
    }

    return error;
}
///
int comparaTipo(void* bici1,void* bici2)
{
    int error=0;

    eBicicleta* auxBici1;
    eBicicleta* auxBici2;

    if(bici1!=NULL && bici2!=NULL)
    {
        auxBici1=(eBicicleta*) bici1;
        auxBici2=(eBicicleta*) bici2;

        if(strcmp(auxBici1->tipo,auxBici2->tipo)>0
        ||(strcmp(auxBici1->tipo,auxBici2->tipo)==0
        &&auxBici1->tiempo<    auxBici2->tiempo))
        {
            error=1;
        }
        else
        {
            if(strcmp(auxBici1->tipo,auxBici2->tipo)>0
            ||(strcmp(auxBici1->tipo,auxBici2->tipo)==0
            &&auxBici1->tiempo<auxBici2->tiempo))
            {
                error=-1;
            }
        }
    }
    return error;
}
