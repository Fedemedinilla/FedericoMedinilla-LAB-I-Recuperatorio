#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "pais.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_paisFromText(FILE* pFile,LinkedList* pLista)
{
    int error=0;
    char buffer[5][20];
    ePais* auxPais=NULL;

    if(pFile!=NULL && pLista!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4])==5)
            {
                auxPais=pais_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
                if(auxPais!=NULL)
                {
                    if(!ll_add(pLista,auxPais))
                    {
                        auxPais=NULL;
                        error=1;
                    }
                }
            }
        }
    }

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_paisFromBinary(FILE* pFile,LinkedList* pLista)
{
    int error=1;
    ePais* auxPais=NULL;

    if(pFile!=NULL && pLista!=NULL)
    {
        while(!feof(pFile))
        {
            auxPais=pais_new();
            if(auxPais!=NULL)
            {
                if(fread(auxPais,sizeof(ePais),1,pFile)==1)
                {
                    if(!ll_add(pLista,auxPais))
                    {
                        auxPais=NULL;
                        error=0;
                    }
                }
            }
        }
    }

    return error;
}
