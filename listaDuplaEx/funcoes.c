#include "biblioteca.h"

void menu(){
    char op;
    int cod;
    dadosListaDupla *listaDupla = NULL; 
    dadosListaDupla *busca = NULL; 
    
    do{
        printf("\nA - Insercao pelo inicio da lista"
                "\nB - Insercao pelo final da lista"
                "\nC - Pesquisar"
                "\nD - Remover"
                "\nE - Imprimir"
                "\nF - Finalizar"
                "\nDigite sua escolha: ");
        scanf(" %c", &op);
        op = toupper(op);
        
        switch (op) {
            case 'A' :
            	listaDupla = inserirInicio(listaDupla);
                break;
            case 'B':
            	inserirFim(listaDupla);
                break;
            case 'C':
                cod = buscaCodigo();
                busca = buscar(listaDupla, cod);
                if (busca == NULL) {
                    printf("\nRegistro nao encontrado."); 
                } else {
                    printf("\nAnterior %p %i - %p %i - Proximo %p %i", 
                                        busca->anterior, 
                                        ((busca->anterior) ? busca->anterior->codigo : 0), 
                                        busca, busca->codigo,
                                        busca->proximo, 
                                        ((busca->proximo) ? busca->proximo->codigo: 0));
                }
                break;
                
            case 'D':
                cod = buscaCodigo();
                busca = buscar(listaDupla, cod);
                if (!busca) {
                    printf("\nRegistro nao encontrado."); 
                } else {
                    remover(busca, &listaDupla);
                }
                break;
            case 'E':
            	imprimeLista(listaDupla);
                break;
            case 'F':
                printf("\nPrograma finalizado. ");
                break;
            default:
                printf("\nAlternativa invalida, tente novamente! ");
                break;
        }

    } while (op != 'F');        
}

dadosListaDupla* inserirInicio(dadosListaDupla *inicioLista) {

	dadosListaDupla *novo = (dadosListaDupla*) malloc (sizeof(dadosListaDupla));
	
	novo->codigo = RANDOM(500);
	
	novo->anterior = NULL; 
	novo->proximo = inicioLista; 
	
	if (inicioLista != NULL) { 
		inicioLista->anterior = novo;   
	}
	return novo; 	
}

dadosListaDupla* inserirFim(dadosListaDupla *inicioLista){
	
	dadosListaDupla *novo = (dadosListaDupla*) malloc (sizeof(dadosListaDupla));
	
	novo->codigo = RANDOM(500);
    novo->proximo = NULL; 
	
	if (inicioLista == NULL) { 
		novo->anterior = NULL;
		return novo;	
	} else {
		dadosListaDupla *listaTmp = inicioLista; 
		while (listaTmp->proximo != NULL) { 
			listaTmp = listaTmp->proximo;
		}
		
		listaTmp->proximo = novo; 
		novo->anterior = listaTmp; 
		
		return inicioLista;
	}
	
}

int buscaCodigo(){
    int valor;
    do{
        printf("\nDigite o codigo a ser procurado: ");
        scanf("%i", &valor);
        if (valor < 0){
            printf("\nInvalido.");
        }
    } while (valor < 0);
    return valor;
}

dadosListaDupla* buscar(dadosListaDupla *inicioLista, int codigo){
    if (!inicioLista) {
        return NULL;
    } else if (inicioLista->codigo == codigo){
        return inicioLista;
    } else {
        return buscar(inicioLista->proximo, codigo);
    }
}

void remover(dadosListaDupla *excluir, dadosListaDupla **inicioLista) {
  
    if (!excluir->anterior) { 
        
        (*inicioLista) = (*inicioLista)->proximo; 
        if ((*inicioLista) != NULL) { 
            (*inicioLista)->anterior = NULL; 
        }
        
    } else {
        
        excluir->anterior->proximo = excluir->proximo;
        if (excluir->proximo != NULL) {
            excluir->proximo->anterior = excluir->anterior;
        }    
    }
    
    
    free(excluir); 
}


void imprimeLista(dadosListaDupla *lista) {
    if (lista != NULL) {  
        printf("\nAnterior %p - %p - %i - Proximo %p", 
				lista->anterior, lista, lista->codigo, lista->proximo);
        imprimeLista(lista->proximo);
    }
}