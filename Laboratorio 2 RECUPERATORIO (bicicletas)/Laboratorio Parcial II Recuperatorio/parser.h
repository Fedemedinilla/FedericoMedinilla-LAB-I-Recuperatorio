#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_paisFromText(FILE* pFile,LinkedList* pLista);
int parser_paisFromBinary(FILE* pFile,LinkedList* pLista);

#endif // PARSER_H_INCLUDED
