#include <stdio.h>
#include <stdlib.h>

#include "misFuncionesGet.h"
#include "LinkedList.h"
#include "parser.h"
#include "pais.h"
#include "controller.h"

int main()
{
    int menuOpcion;
    char salir='n';
    char path[20];
    LinkedList* listaBicicletas=NULL;
    LinkedList* listaBicisPosiciones=NULL;

    listaBicicletas=ll_newLinkedList();
    if(listaBicicletas!=NULL)
    {
        do
        {
            if(!getNumero(&menuOpcion,
                "\n--- LABORATORIO PARCIAL II ---\n\n"
                "1) CARGAR de archivo de TEXTO.\n"
                "2) CARGAR de archivo BINARIO.\n"
                "3) MOSTRAR lista de bicicletas.\n"
                "4) ASIGNAR tiempos.\n"
                "5) FILTRAR por TIPO.\n"
                "6) MOSTRAR posiciones.\n"
                "7) GUARDAR lista del punto 6.\n"
                "8) GUARDAR en archivo de TEXTO.\n"
                "9) GUARDAR en archivo de BINARIO.\n"
                "10) SALIR.\n\n"
                "Ingrese una opcion(1-10): ",
                "\nERROR Ingrese entre 1 y 11.\n\n",1,10))
            {
                switch(menuOpcion)
                {
                case 1:
                    getPath("\n*** Bienvenido a la carga de archivo de TEXTO ***\nIngrese el nombre del archivo(bicicletas.csv): ",path);
                    if(!controller_cargarTexto(path,listaBicicletas))
                    {
                        printf("%d\n",ll_len(listaBicicletas));
                        printf("\n*** Archivo cargado con exito ***\n");
                    }
                    else
                    {
                        printf("\n*** ERROR al cargar el archivo ***\n");
                    }
                    break;
                case 2:
                    getPath("\n*** Bienvenido a la carga de archivo BINARIO ***\nIngrese el nombre del archivo(bicicletas.bin): ",path);
                    if(!controller_cargarBinario(path,listaBicicletas))
                    {
                        printf("\n*** Archivo cargado con exito ***\n");
                    }
                    else
                    {
                        printf("\n*** ERROR al cargar el archivo ***\n");
                    }
                    break;
                case 3:
                    controller_mostrarPaises(listaBicicletas);
                    break;
                case 4:
                    listaBicicletas=ll_map(listaBicicletas,randomTiempo);
                    break;
                case 5:
                    filtrarPorTipo(listaBicicletas);
                    break;
                case 6:
                    listaBicisPosiciones=ll_clone(listaBicicletas);
                    ll_sort(listaBicisPosiciones,comparaTipo,1);
                    controller_mostrarPaises(listaBicisPosiciones);
                    break;
                case 7:
                    getPath("\n*** Bienvenido al guardado en modo texto ***\nIngrese el nombre del archivo: ",path);
                    if(!controller_guardarTexto(path,listaBicisPosiciones))
                    {
                        printf("\nEl archivo se guardo con exito!");
                    }
                    else
                    {
                        printf("\nERROR al guardar el archivo.");
                    }
                    break;
                case 8:
                    getPath("\n*** Bienvenido al guardado en modo texto ***\nIngrese el nombre del archivo: ",path);
                    if(!controller_guardarTexto(path,listaBicicletas))
                    {
                        printf("\nEl archivo se guardo con exito!");
                    }
                    else
                    {
                        printf("\nERROR al guardar el archivo.");
                    }
                    break;
                case 9:
                    getPath("\n*** Bienvenido al guardado en modo binario ***\nIngrese el nombre del archivo: ",path);
                    if(!controller_guardarBinario(path,listaBicicletas))
                    {
                        printf("\nEl archivo se guardo con exito!");
                    }
                    else
                    {
                        printf("\nERROR al guardar el archivo.");
                    }
                    break;
                case 11:
                    if(!getDosChar("\nDesea salir del programa(S/N)?","\nERROR Ingrese S o N.\n",'s','n'))
                    {
                        salir='s';
                    }
                    break;
                }
            }
        }while(salir!='s');
    }

    return 0;
}
