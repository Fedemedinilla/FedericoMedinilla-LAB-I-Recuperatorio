#include <stdio.h>
#include <stdlib.h>

#include "misFuncionesGet.h"
#include "LinkedList.h"
#include "parser.h"
#include "pais.h"

int main()
{
    int menuOpcion;
    char salir='n';
    char path[20];
    LinkedList* listaPaises=NULL;
    LinkedList* listaPaisesExitosos=NULL;
    LinkedList* listaPaisesAlHorno=NULL;

    listaPaises=ll_newLinkedList();
    if(listaPaises!=NULL)
    {
        do
        {
            if(!getNumero(&menuOpcion,
                "\n--- LABORATORIO PARCIAL II ---\n\n"
                "1) CARGAR de archivo de TEXTO.\n"
                "2) CARGAR de archivo BINARIO.\n"
                "3) MOSTRAR lista de paises.\n"
                "4) ASIGNAR estadisticas.\n"
                "5) FILTRAR por paises EXITOSOS.\n"
                "6) FILTRAR por paises EN EL HORNO.\n"
                "7) ORDENAR por nivel de vacunacion.\n"
                "8) MOSTRAR paises mas castigados.\n"
                "9) GUARDAR en archivo de TEXTO.\n"
                "10) GUARDAR en archivo de BINARIO.\n"
                "11) SALIR.\n\n"
                "Ingrese una opcion(1-11): ",
                "\nERROR Ingrese entre 1 y 11.\n\n",1,11))
            {
                switch(menuOpcion)
                {
                case 1:
                    getPath("\n*** Bienvenido a la carga de archivo de TEXTO ***\nIngrese el nombre del archivo(vacunas.csv): ",path);
                    if(!controller_cargarTexto(path,listaPaises))
                    {
                        printf("%d\n",ll_len(listaPaises));
                        printf("\n*** Archivo cargado con exito ***\n");
                    }
                    else
                    {
                        printf("\n*** ERROR al cargar el archivo ***\n");
                    }
                    break;
                case 2:
                    getPath("\n*** Bienvenido a la carga de archivo BINARIO ***\nIngrese el nombre del archivo(vacunas.bin): ",path);
                    if(!controller_cargarBinario(path,listaPaises))
                    {
                        printf("\n*** Archivo cargado con exito ***\n");
                    }
                    else
                    {
                        printf("\n*** ERROR al cargar el archivo ***\n");
                    }
                    break;
                case 3:
                    controller_mostrarPaises(listaPaises);
                    break;
                case 4:
                    listaPaises=ll_map(listaPaises,randomVac1);
                    listaPaises=ll_map(listaPaises,randomVac2);
                    listaPaises=ll_map(listaPaises,porcentajeSinVacunar);
                    break;
                case 5:
                    listaPaisesExitosos=ll_newLinkedList();
                    if(listaPaisesExitosos!=NULL)
                    {
                        listaPaisesExitosos=ll_filter(listaPaises,paisExitoso);
                        controller_mostrarPaises(listaPaisesExitosos);
                    }
                    if(!getDosChar("\nGuardar esta lista en archivo:\nt)Texto\nb)Binario\nIngrese una opcion: ","\nERROR Ingrese 1 o 2.\n",'t','b'))
                    {
                        getPath("\n*** Bienvenido al guardado en modo texto ***\nIngrese el nombre del archivo: ",path);
                        if(!controller_guardarTexto(path,listaPaisesExitosos))
                        {
                            printf("\nEl archivo se guardo con exito!");
                        }
                        else
                        {
                            printf("\nERROR al guardar el archivo.");
                        }
                    }
                    else
                    {
                        getPath("\n*** Bienvenido al guardado en modo binario ***\nIngrese el nombre del archivo: ",path);
                        if(!controller_guardarBinario(path,listaPaises))
                        {
                            printf("\nEl archivo se guardo con exito!");
                        }
                        else
                        {
                            printf("\nERROR al guardar el archivo.");
                        }
                    }
                    break;
                case 6:
                    listaPaisesAlHorno=ll_newLinkedList();
                    if(listaPaisesAlHorno!=NULL)
                    {
                        listaPaisesAlHorno=ll_filter(listaPaises,paisAlHorno);
                        controller_mostrarPaises(listaPaisesAlHorno);
                    }
                    if(!getDosChar("\nGuardar esta lista en archivo:\nt)Texto\nb)Binario\nIngrese una opcion: ","\nERROR Ingrese 1 o 2.\n",'t','b'))
                    {
                        getPath("\n*** Bienvenido al guardado en modo texto ***\nIngrese el nombre del archivo: ",path);
                        if(!controller_guardarTexto(path,listaPaisesAlHorno))
                        {
                            printf("\nEl archivo se guardo con exito!");
                        }
                        else
                        {
                            printf("\nERROR al guardar el archivo.");
                        }
                    }
                    else
                    {
                        getPath("\n*** Bienvenido al guardado en modo binario ***\nIngrese el nombre del archivo: ",path);
                        if(!controller_guardarBinario(path,listaPaises))
                        {
                            printf("\nEl archivo se guardo con exito!");
                        }
                        else
                        {
                            printf("\nERROR al guardar el archivo.");
                        }
                    }
                    break;
                case 7:
                    ll_sort(listaPaises,comparar1Dosis,1);
                    controller_mostrarPaises(listaPaises);
                    break;
                case 8:
                    ll_sort(listaPaises,compararMasCastigado,0);
                    mostrarMasCastigados(listaPaises);
                    break;
                case 9:
                    getPath("\n*** Bienvenido al guardado en modo texto ***\nIngrese el nombre del archivo: ",path);
                    if(!controller_guardarTexto(path,listaPaises))
                    {
                        printf("\nEl archivo se guardo con exito!");
                    }
                    else
                    {
                        printf("\nERROR al guardar el archivo.");
                    }
                    break;
                case 10:
                    getPath("\n*** Bienvenido al guardado en modo binario ***\nIngrese el nombre del archivo: ",path);
                    if(!controller_guardarBinario(path,listaPaises))
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
