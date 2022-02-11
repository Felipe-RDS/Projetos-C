//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//macros e constantes
#define RANDOM(x) rand() % (x)

//estrutura

typedef struct dadosListaDupla dadosListaDupla;
struct dadosListaDupla{
    int codigo;
    
    dadosListaDupla *anterior;
    dadosListaDupla *proximo;
};

//prototipos

dadosListaDupla* inserirInicio(dadosListaDupla *inicioLista);
void imprimeLista(dadosListaDupla *lista);
dadosListaDupla* inserirFim(dadosListaDupla *inicioLista);
void menu();
dadosListaDupla* buscar(dadosListaDupla *inicioLista, int cod);
int buscaCodigo();
void remover(dadosListaDupla *excluir, dadosListaDupla **inicioLista);