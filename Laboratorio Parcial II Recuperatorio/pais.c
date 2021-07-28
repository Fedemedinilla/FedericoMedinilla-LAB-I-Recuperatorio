#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"
#include "LinkedList.h"
#include "pais.h"

ePais* pais_new()
{
    ePais* auxPais;

    auxPais=(ePais*)malloc(sizeof(ePais));
    if(auxPais!=NULL)
    {
        auxPais->id=0;
        strcpy(auxPais->nombre," ");
        auxPais->vac1dosis=0;
        auxPais->vac2dosis=0;
        auxPais->sinVacunar=0;
    }

    return auxPais;
}
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1Str,char* vac2Str,char* sinVacStr)
{
    ePais* auxPais;
    auxPais=pais_new();

    if(auxPais!=NULL && idStr!=NULL && nombreStr!=NULL && vac1Str!=NULL && vac2Str!=NULL && sinVacStr!=NULL)
    {
		if(!(pais_setId(auxPais,atoi(idStr))==0
            &&pais_setNombre(auxPais,nombreStr)==0
            &&pais_setVac1(auxPais,atoi(vac1Str))==0
            &&pais_setVac2(auxPais,atoi(vac2Str))==0
            &&pais_setSinVac(auxPais,atoi(sinVacStr))==0))
		{
			free(auxPais);
			auxPais=NULL;
		}
    }

    return auxPais;
}
///SETTERS
int pais_setId(ePais* this,int id)
{
    int error=1;

    if(this!=NULL)
    {
        this->id=id;
        error=0;
    }

    return error;
}
int pais_setNombre(ePais* this,char* nombre)
{
	int error=1;

	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		error=0;
	}

	return error;
}
int pais_setVac1(ePais* this,int vac1dosis)
{
	int error=1;

	if(this!=NULL)
	{
		this->vac1dosis=vac1dosis;
		error=0;
	}

	return error;
}
int pais_setVac2(ePais* this,int vac2dosis)
{
	int error=1;

	if(this!=NULL)
	{
		this->vac2dosis=vac2dosis;
		error=0;
	}

	return error;
}
int pais_setSinVac(ePais* this,int sinVacunar)
{
	int error=1;

	if(this!=NULL)
	{
		this->sinVacunar=sinVacunar;
		error=0;
	}

	return error;
}
///GETTERS
int pais_getId(ePais* this,int* id)
{
	int error=1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		error=0;
	}

	return error;
}
int pais_getNombre(ePais* this,char* nombre)
{
	int error=1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		error=0;
	}

	return error;
}
int pais_getVac1(ePais* this,int* vac1dosis)
{
	int error=1;

	if(this!=NULL && vac1dosis!=NULL)
	{
		*vac1dosis=this->vac1dosis;
		error=0;
	}

	return error;
}
int pais_getVac2(ePais* this,int* vac2dosis)
{
	int error=1;

	if(this!=NULL && vac2dosis!=NULL)
	{
		*vac2dosis=this->vac2dosis;
		error=0;
	}

	return error;
}
int pais_getSinVac(ePais* this,int* sinVacunar)
{
	int error=1;

	if(this!=NULL && sinVacunar!=NULL)
	{
		*sinVacunar=this->sinVacunar;
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
int randomVac1(void* pais)
{
    int error=1;
    int resultado;
    int min=1;
    int max=60;

    ePais* pais1;
    if(pais!=NULL)
    {
        pais1=(ePais*)pais;
        resultado=numAleatorio(max,min);
        if(resultado>=min && resultado<=max)
        {
            pais1->vac1dosis=resultado;
            error=0;
        }
    }

    return error;
}
int randomVac2(void* pais)
{
    int error=1;
    int resultado;
    int min=1;
    int max=40;

    ePais* pais2;
    if(pais!=NULL)
    {
        pais2=(ePais*)pais;
        resultado=numAleatorio(max,min);
        if(resultado>=min && resultado<=max)
        {
            pais2->vac2dosis=resultado;
            error=0;
        }
    }

    return error;
}
int porcentajeSinVacunar(void* pais)
{
    int error=1;
    int vac1;
    int vac2;
    int resultado;

    ePais* pais1;
    if(pais!=NULL)
    {
        pais1=(ePais*)pais;
        vac1=pais1->vac1dosis;
        vac2=pais1->vac2dosis;
        resultado=100-(vac1+vac2);
        if(resultado>=0 && resultado<=100)
        {
            pais1->sinVacunar=resultado;
            error=0;
        }
    }

    return error;
}
///FILTRO PAISES EXITOSOS
int paisExitoso(void* pais)
{
    int error=1;
    int vac1;
    int vac2;

    ePais* pais1;
    if(pais!=NULL)
    {
        pais1=(ePais*)pais;
        vac1=pais1->vac1dosis;
        vac2=pais1->vac2dosis;
        if(vac1>=30 && vac2>=30)
        {
            error=0;
        }
    }
    return error;
}
///FILTRO PAISES AL HORNO
int paisAlHorno(void* pais)
{
    int error=1;
    int vac1;
    int vac2;
    int sinVac;

    ePais* pais1;
    if(pais!=NULL)
    {
        pais1=(ePais*)pais;
        vac1=pais1->vac1dosis;
        vac2=pais1->vac2dosis;
        sinVac=pais1->sinVacunar;
        if((vac1+vac2)<sinVac)
        {
            error=0;
        }
    }

    return error;
}
///ORDENAR POR 1DOSIS
int comparar1Dosis(void* pais1,void* pais2)
{
    int error=0;
    int vacPais1;
    int vacPais2;

    ePais* pais01;
    ePais* pais02;
    if(pais1!=NULL && pais2!=NULL)
    {
        pais01=(ePais*)pais1;
        pais02=(ePais*)pais2;

        vacPais1=pais01->vac1dosis;
        vacPais2=pais02->vac1dosis;

        if(vacPais1<vacPais2)
        {
            error=1;
        }
        else if(vacPais1>vacPais2)
        {
            error=-1;
        }
    }

    return error;
}
///MAS CASTIGADO
int compararMasCastigado(void* pais1,void* pais2)
{
    int error=1;
    int sinVac1;
    int sinVac2;

    ePais* pais01;
    ePais* pais02;
    if(pais1!=NULL && pais2!=NULL)
    {
        pais01=(ePais*)pais1;
        pais02=(ePais*)pais2;

        sinVac1=pais01->sinVacunar;
        sinVac2=pais02->sinVacunar;
        if(sinVac1>sinVac2)
        {
            error=1;
        }
        else if(sinVac1<sinVac2)
        {
            error=-1;
        }
    }

    return error;
}
int mostrarMasCastigados(LinkedList* this)
{
    int error=1;
    int masCastigado;
    int tam;

    ePais* auxPais1;
    ePais* auxPais2;
    if(this!=NULL)
    {
        auxPais1=ll_get(this,0);
        masCastigado=auxPais1->sinVacunar;
        tam=ll_len(this);
        printf("\n*** Los paises mas castigados ***\n");
        for(int i=0;i<tam;i++)
        {
            auxPais2=ll_get(this,i);
            if(auxPais2->sinVacunar==masCastigado)
            {
                controller_mostrarPais(auxPais2);
            }
        }
    }

    return error;
}
