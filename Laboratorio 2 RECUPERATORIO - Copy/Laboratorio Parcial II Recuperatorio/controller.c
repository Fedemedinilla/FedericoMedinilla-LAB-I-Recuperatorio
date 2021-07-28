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
    eBicicleta* auxBici=NULL;
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
                    auxBici=(eBicicleta*)ll_get(pLista,i);
                    if(auxBici!=NULL)
                    {
                        fprintf(f,"%d,%s,%s,%d\n",auxBici->id,auxBici->nombre,auxBici->tipo,auxBici->tiempo);
                        auxBici=NULL;
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
    eBicicleta* auxBici=NULL;
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
                    auxBici=(eBicicleta*)ll_get(pLista,i);
                    if(auxBici!=NULL)
                    {
                        if(fwrite(auxBici,sizeof(eBicicleta),1,f)<1)
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
int controller_mostrarPais(eBicicleta* bici)
{
    int error=1;
    int id;
    char nombre[20];
    char tipo[20];
    int tiempo;

    if(bici!=NULL)
    {

        if(pais_getId(bici,&id)==0
           &&pais_getNombre(bici,nombre)==0
           &&pais_getTipo(bici,tipo)==0
           &&pais_getTiempo(bici,&tiempo)==0)
        {
            printf("\n%d  %s  %s  %d\n",id,nombre,tipo,tiempo);
            error=0;
        }
    }

    return error;
}
int controller_mostrarPaises(LinkedList* lista)
{
    int error=1;
    int tam;
    eBicicleta* auxBici=NULL;

    if(lista!=NULL)
    {
        tam=ll_len(lista);
        printf("\n|ID| |Pais| |1dosis| |2dosis| |sinVacunar|\n");
        for(int i=0;i<tam;i++)
        {
            auxBici=(eBicicleta*)ll_get(lista,i);
            controller_mostrarPais(auxBici);
            error=0;
        }
    }

    return error;
}
