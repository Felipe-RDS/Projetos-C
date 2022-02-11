#include<stdio.h>
#include <stdlib.h>

int main(){

    int qtd;
    int *qtdpecas;
    float *sal;
    float somaSal = 0;
    float maiorSal = -1;
    char resp = 'p';

    do{
        printf("\nDigite a quantidade de funcionarios: ");
        scanf("%i", &qtd);

        if(qtd < 0 ){
            printf("\nDigite um valor maior que 0");
        }

    }while(qtd < 0);

    qtdpecas = (int *)malloc(qtd * sizeof(int)); // deixa lixo de memoria 
    sal = (float *)malloc(qtd * sizeof(float));
    // sal = (float *)calloc(qtd, sizeof(float)); limpa area de memoria 
    
    printf("\nEndereco da alocacao de quantidade de pecas: %p", qtdpecas);

    for(int i = 1 ; i <= qtd ; i++){
        do{
            printf("\nDigite a quantidade de pecas produzidas pelo funcionario: ");
            scanf("%i", qtdpecas);

            if (*qtdpecas < 0){
                printf("\nDigite um valor maior que 0");
            }
        }while (*qtdpecas < 0);

        if (*qtdpecas <= 200){
            *sal = *qtdpecas * 2 ;
        }else if(*qtdpecas <= 400){
            *sal = *qtdpecas * 2.30;
        }else {
            *sal = *qtdpecas * 2.50;
        }

        while (resp != 's' && resp != 'n'){
            printf("\nFuncionario estuda? (s/n) \n");
            scanf(" %c", &resp);
            //resp = toupper(resp); caractere maiusculo
           
        }

        if(resp == 's'){
            *sal *= 1.10;
        }

        if(*sal > maiorSal){
            maiorSal = *sal;
        }

        somaSal += *sal;

        qtdpecas++;
        sal++;
    }
    qtdpecas -= qtd;
    sal -= qtd;

    printf("\nQuantidade de funcionarios: %d", qtd);
   
    for(int y = 0; y < qtd; y++){
        printf("\nEndereco da alocacao de quantidade de pecas: %p  \nQuantidade de pecas do funcionario: %d", qtdpecas, *qtdpecas);
        printf("\nEndereco da alocacao de salarios %p \nValor do salario: %.2f", sal, *sal);

        qtdpecas++;
        sal++;
    }
    qtdpecas -= qtd;
    sal -= qtd;

    printf("\nSoma dos salarios: %.2f", somaSal);
    printf("\nMaior salario: %.2f", maiorSal);

    free(qtdpecas);
    free(sal);
}   