#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_cargarTexto(char* path,LinkedList* pLista);
int controller_guardarTexto(char* path,LinkedList* pLista);
int controller_cargarBinario(char* path,LinkedList* pLista);
int controller_guardarBinario(char* path,LinkedList* pLista);
int controller_mostrarPais(eBicicleta* bici);
int controller_mostrarPaises(LinkedList* lista);

#endif // CONTROLLER_H_INCLUDED
