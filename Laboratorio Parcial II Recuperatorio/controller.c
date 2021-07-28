#include <stdio.h>
#include <stdlib.h>
#include "misFuncionesGet.h"
#include "parser.h"
#include "LinkedList.h"
#include "pais.h"
#include "controller.h"

int controller_cargarTexto(char* path,LinkedList* pLista)
{
    int error=1;
    char sobreescribe;
    FILE* f;

    if(path!=NULL && pLista!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL)
        {
            if(!ll_isEmpty(pLista))
            {
                if(!getDosChar("\nEl fichero ya tiene datos cargados. Desea sobreescribirlos?(S/N): ","\nERROR - Re-ingrese 's' o 'n'.",'n','s'))
                {
                    sobreescribe='n';
                }
                else
                {
                    sobreescribe='s';
                }
            }
            if(ll_isEmpty(pLista) || sobreescribe=='s')
            {
                ll_clear(pLista);
                parser_paisFromText(f,pLista);
                error=0;
            }
        }
    }
    fclose(f);

    return error;
}
int controller_guardarTexto(char* path,LinkedList* pLista)
{
    int error=1;
    FILE* f;
    ePais* auxPais=NULL;
    char confirma = 's';

    if(path!=NULL && pLista!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL)
        {
            if(!getDosChar("\nEl archivo ya tiene datos cargados, desea sobreescribirlos?(S/N): ","\nERROR - Ingrese S o N.",'s','n'))
            {
                confirma='s';
            }
            else
            {
                confirma='n';
            }
        }
        fclose(f);

        if(confirma=='s')
        {
            f=fopen(path,"w");
            if(f!=NULL)
            {
                fprintf(f,"Id,Nombre,HorasTrabajadas,Sueldo\n");
                for(int i=0;i<ll_len(pLista);i++)
                {
                    auxPais=(ePais*)ll_get(pLista,i);
                    if(auxPais!=NULL)
                    {
                        fprintf(f,"%d,%s,%d,%d,%d\n",auxPais->id,auxPais->nombre,auxPais->vac1dosis,auxPais->vac2dosis,auxPais->sinVacunar);
                        auxPais=NULL;
                        error=0;
                    }
                    else
                    {
                        printf("\nERROR con el FPRINTF");
                        error=1;
                        break;
                    }
                }
            }
        }
    }
    fclose(f);

    return error;
}
int controller_cargarBinario(char* path,LinkedList* pLista)
{
    int error=1;
    char sobreescribe;
    FILE* f;

    if(path!=NULL && pLista!=NULL)
    {
        f=fopen(path,"rb");
        if(f!=NULL)
        {
            if(!ll_isEmpty(pLista))
            {
                if(!getDosChar("\nEl fichero ya tiene datos cargados. Desea sobreescribirlos?(S/N): ","\nERROR - Re-ingrese 's' o 'n'.",'n','s'))
                {
                    sobreescribe='n';
                }
                else
                {
                    sobreescribe='s';
                }
            }
            if(ll_isEmpty(pLista) || sobreescribe=='s')
            {
                ll_clear(pLista);
                parser_paisFromBinary(f,pLista);
                error=0;
            }
        }
    }
    fclose(f);

    return error;
}
int controller_guardarBinario(char* path,LinkedList* pLista)
{
    int error=1;
    ePais* auxPais=NULL;
    FILE* f;
    char confirma='s';

    if(path!=NULL && pLista!=NULL)
    {
        f=fopen(path,"rb");
        if(f!=NULL)
        {
            if(!getDosChar("\nEl archivo ya tiene datos cargados, desea sobreescribirlos?(S/N): ","\nERROR - Ingrese S o N.",'s','n'))
            {
                confirma='s';
            }
            else
            {
                confirma='n';
            }
        }
        fclose(f);

        if(confirma=='s')
        {
            f=fopen(path,"wb");
            if(f!=NULL)
            {
                for(int i=0;i<ll_len(pLista);i++)
                {
                    auxPais=(ePais*)ll_get(pLista,i);
                    if(auxPais!=NULL)
                    {
                        if(fwrite(auxPais,sizeof(ePais),1,f)<1)
                        {
                            break;
                        }
                        else
                        {
                            error=0;
                        }
                    }
                }
            }
        }
    }
    fclose(f);

    return error;
}
int controller_mostrarPais(ePais* pais)
{
    int error=1;
    int id;
    char nombre[20];
    int dosis1;
    int dosis2;
    int sinVac;

    if(pais!=NULL)
    {

        if(pais_getId(pais,&id)==0
           &&pais_getNombre(pais,nombre)==0
           &&pais_getVac1(pais,&dosis1)==0
           &&pais_getVac2(pais,&dosis2)==0
           &&pais_getSinVac(pais,&sinVac)==0)
        {
            printf("\n%d  %s  %d  %d  %d\n",id,nombre,dosis1,dosis2,sinVac);
            error=0;
        }
    }

    return error;
}
int controller_mostrarPaises(LinkedList* lista)
{
    int error=1;
    int tam;
    ePais* auxPais=NULL;

    if(lista!=NULL)
    {
        tam=ll_len(lista);
        printf("\n|ID| |Pais| |1dosis| |2dosis| |sinVacunar|\n");
        for(int i=0;i<tam;i++)
        {
            auxPais=(ePais*)ll_get(lista,i);
            controller_mostrarPais(auxPais);
            error=0;
        }
    }

    return error;
}
