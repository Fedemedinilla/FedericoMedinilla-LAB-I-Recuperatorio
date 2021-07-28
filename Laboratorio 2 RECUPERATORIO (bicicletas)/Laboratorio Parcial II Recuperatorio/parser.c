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
    char buffer[4][20];
    eBicicleta* auxBici=NULL;

    if(pFile!=NULL && pLista!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3])==4)
            {
                auxBici=pais_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if(auxBici!=NULL)
                {
                    if(!ll_add(pLista,auxBici))
                    {
                        auxBici=NULL;
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
    eBicicleta* auxBici=NULL;

    if(pFile!=NULL && pLista!=NULL)
    {
        while(!feof(pFile))
        {
            auxBici=pais_new();
            if(auxBici!=NULL)
            {
                if(fread(auxBici,sizeof(eBicicleta),1,pFile)==1)
                {
                    if(!ll_add(pLista,auxBici))
                    {
                        auxBici=NULL;
                        error=0;
                    }
                }
            }
        }
    }

    return error;
}
