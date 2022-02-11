#include <stdio.h>

int main(){
    
    int idade;
    
    int *pontIdade = &idade; 

   
    printf("\nEndereco de memoria da variavel idade: %p.", &idade);
    printf("\nEndereco de memoria da variavel pontIdade: %p.", &pontIdade);
    
    
    printf("\nO conteudo da variavel idade e: %i", idade);
    printf("\nO conteudo do ponteiro pontIdade e: %p", pontIdade);

    //Apontamento com scanf
    //printf("\nDigite a idade: ");
    //scanf("%d", pontIdade); // passando o conteudo do ponteiro (que no caso e o endereço da variavel idade)
                            // a fim de preencher o conteudo da variavel idade
    
    //Conteudo das variaveis
    
    idade = 5; // forma classica (direta)
    *pontIdade = 5; //forma indireta, acessando o conteudo da variavel apontada

    printf("\n\nO conteudo da variavel idade e %i", idade);
    printf("\n\nO conteudo da variavel pontIdade idade e %p", pontIdade);
    
    //imprimir conteudo da variavel idade
    printf("\n\nO conteudo da variavel idade e %i", idade);
    printf("\n\nO conteudo da variavel idade e %i", *pontIdade);

    idade = 9;

    printf("\nA variavel idade utiliza %li bytes na memoria", sizeof(idade));
    printf("\nA variavel idade utiliza %li bytes na memoria", sizeof(pontIdade));
}               
