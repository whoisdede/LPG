#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//declaração de funções
void imprimeMenu();             
int fat(int n);                 
void harmonica();               
void somatorioLog();       
void calculaPi();
void calculaE();
void serieTaylor();
void senoDeX();
void cosDeX();

//função main
int main(){
    int select =-1;
    while (select !=0){
        imprimeMenu();
        printf("\nSelecione um caso para prosseguir: ");
        scanf(" %d", &select);
        switch (select)
        {
        case 0:
            break;
        case 1:
            harmonica();
            break;
        case 2:
            somatorioLog(); 
            break;
        case 3:
            calculaPi();
            break;
        case 4:
            calculaE();
            break;
        case 5:
            serieTaylor();
            break;
        case 6:
            senoDeX();
            break;
        case 7:
            cosDeX();
            break;
        default:
            printf("\n valor inválido");
            break;
        }
    }
}

//funções:

int fat(int n){
    double fat;
    if(n == 0 || n == 1){
        fat = 1;
    }   
    else{
        for (fat=1; n>1; n--){
        fat *= n;
        }   
    }
    return fat;  
}

void harmonica(){
    int k=0;
    float result=0;
    printf("digite um valor para k: ");
    scanf(" %d", &k);
    for(int i=1; i<=k; i++){
        float a =i;
        result += 1/a;
    }
    printf("\n Aqui está o resultado: %f", result);
}

void somatorioLog(){
    int k=0;
    float result=0;
    double pot=-1;
    printf("digite um valor para k: ");
    scanf(" %d", &k);
    for(int i=1; i<=k; i++){
        float a = i;
        pot *= -1;
        result += pot/a ;   
    }
    printf("\n Aqui está o resultado: %f", result);
}

void calculaPi(){
    int select =-1;
    while (select !=0){
        int k=0;
        float result = 0;
        printf("\nSelecione uma das formas de calcular: \n1 para Leibniz\n2 para Nilakantha\nOu 0 para sair\n");
        scanf(" %d", &select);
        switch(select)
        {
            case 0:
                break;
            case 1:
                printf("digite um valor para k: ");
                scanf(" %d", &k);
                int inverte = -1;
                for(int i=1; i<=k; i++){
                    float a=i;
                    inverte *= -1;
                    result += (4*inverte)/(2*a-1);
                }
                printf("\n Aqui está o resultado: %f", result);
                break;  
            case 2:
                printf("digite um valor para k: ");
                scanf(" %d", &k);
                int inverto = -1;
                float n = 2;
                for(int i=1; i<=k; i++){        
                    float a=i;
                    inverto *= -1;
                    result += ((4*inverto)/(n*(n+1)*(n+2)));
                    n +=2;
                }
                result += 3;
                printf("\n Aqui está o resultado: %f", result);
                break;
            default:
                printf("valor invalido,");
                break;
        }
    }
}

void calculaE(){
    int k=0; 
    float result=0;
    printf("digite um valor para k: ");
    scanf(" %d", &k);
    for(int i=0; i<=k; i++){
        double fato = fat(i);
        result += 1/fato;  
    }
    printf("\n Aqui está o resultado: %f", result);
}

void serieTaylor(){
    float x=0;
    int n=0,i,j;
    printf("Digite x e a quantidade de termos n: ");
    scanf(" %f %d", &x, &n);
    float e_x =0;
    for(i=0;i<=n;i++){
        double termo = 1;
        for(j=1;j<=i;j++){
            termo *= x/j;
        }
        e_x += termo;
    }
    printf("e elevado a %.3f = %.8f\n", x, e_x);
}

void senoDeX(){
    float result=0, x=0;
    int k=0;
    int inverto = 1;
    printf("Digite a quantidade de termos k: ");
    scanf(" %d", &k);
    printf("\nPois bem, agora digite um numero para x: ");
    scanf(" %f", &x);
    for(int i=1; i<=k; i++){
        inverto *= -1;
        float a=x;
        int n =(2*i)+1;
        for( int j=1; j<n;j++){
            a *= x;
        }
        result += (inverto*(a))/(fat(n));
    }
    result += x;
    printf("\n Aqui está o resultado: %f", result);
}

void cosDeX(){
    float result=0, x=0;
    int k=0;
    int inverto = 1;
    printf("Digite a quantidade de termos k: ");
    scanf(" %d", &k);
    printf("\nPois bem, agora digite um numero para x: ");
    scanf(" %f", &x);
    for(int i=1; i<=k; i++){
        inverto *= -1;
        float a=x;
        int n =(2*i);
        for( int j=1; j<n;j++){
            a *= x;
        }
        result += inverto*((a)/(fat(n)));
    }
    result += 1;
    printf("\n Aqui está o resultado: %f", result);
}

void imprimeMenu(){
    printf("\nEscolha uma opcao:");
    printf("\n0 - Sair");
    printf("\n1 - Série Harmônica");
    printf("\n2 - Somatorio de Log");
    printf("\n3 - Calcular Pi");
    printf("\n4 - calculaE");
    printf("\n5 - Serie de Taylor");
    printf("\n6 - Seno de X");
    printf("\n7 - Cosseno de X");
}
