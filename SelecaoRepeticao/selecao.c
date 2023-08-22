#include <stdlib.h>
#include <stdio.h>

//declarando funções
void imprimeMenu();
void coord();
void tipoTriangulo();
void horario();
void pares();
void medias();
void somaImpares();
void somaImpares2();

//main
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
            coord();
            break;
        case 2:
            tipoTriangulo();
            break;
        case 3:
            horario();
            break;
        case 4:
            pares();
            break;
        case 5:
            medias();
            break;
        case 6:
            somaImpares();
            break;
        case 7:
            somaImpares2();
            break;
        default:
            printf("\n valor inválido");
            break;
        }
    }
}

//funções
void imprimeMenu(){
    printf("\nEscolha uma opcao:");
    printf("\n0 - Sair");
    printf("\n1 - Calcula Quadrante");
    printf("\n2 - Tipo do Triângulo");
    printf("\n3 - Calcula Horario Jogo");
    printf("\n4 - Valores Pares/Impares/Negativos/Positivos");
    printf("\n5 - Média Ponderada");
    printf("\n6 - Soma de ímpares consecutivos");
    printf("\n7 - Soma de ímpares consecutivos 2");
}
void coord(){
    double x=0,y=0;
    printf("\ndigite o valor para x: ");
    scanf(" %lf", &x);
    printf("\ndigite o valor para y: ");
    scanf(" %lf", &y);
    if(x ==0 && y ==0){
        printf
        ("\nOrigem!");
    }
    else if(y==0){
        printf("\nEixo X");
    }
    else if(x==0){
        printf("\nEixo Y");
    }
    else if (x>0 && y>0){
        printf("\nQ1");
    }
    else if (x<0 && y>0){
        printf("\nQ2");
    }
    else if (x<0 && y<0){
        printf("\nQ3");
    }
    else if(x>0 && y<0){
        printf("\nQ4");
    }
    printf("\n");
}

void tipoTriangulo(){
    float A=0,B=0, C=0;
    printf("\ndigite o valor para A: ");
    scanf(" %f", &A);
    printf("\ndigite o valor para B: ");
    scanf(" %f", &B);
    printf("\ndigite o valor para C: ");
    scanf(" %f", &C);
    if(A>=B+C){
        printf("\nNão forma triângulo!");
    }
    if(A*A == B*B + C*C){
        printf("\nTriângulo retângulo");
    }
    if(A*A > B*B + C*C){
        printf("\nTriângulo obtusângulo");
    }
    if(A*A < B*B + C*C){
        printf("\nTriângulo acutângulo");
    }
    if(A == B && A == C && B==C){
        printf("\nTriângulo equilátero");
    }
    if((A == B && A != C && B!=C) || (A==C && B!=C && A !=B) || (B==C && A!=C && A!=B)){
        printf("\nTriângulo isósceles");
    }
    printf("\n");
}

void horario(){
    int x=0,y=0;
    printf("\nDigite um valor para x: ");
    scanf(" %d", &x);
    printf("\nDigite um valor para y: ");
    scanf(" %d", &y);
    if(x==y){
        printf("\nO jogo durou 24 horas");
    }
    else if(x<y){
        printf ("\nO jogo durou %d horas", y-x);
    }
    else if(x>y){
        printf("\nO jogo durou %d horas", 24-x+y);
    }
    printf("\n");
}

void pares(){
    int n=0, pares=0, impares=0, positivos=0, negativos=0;
    printf("\nDigite quantos valores quer colocar e em seguida os valores: ");
    scanf(" %d", &n);
    int loop = n;
    for(int i=0; i<loop; i++){
        if(n%2 == 0){
            pares++;
        }
        else{
            impares++;
        }
        if(n==0){
            pares++;
            impares--;
        }
        else if (n>0){
            positivos++;
        }
        else if (n<0){
            negativos++;
        }
        printf("-> ");
        scanf(" %d", &n);
    }
    printf("\n%d valores pares", pares);
    printf("\n%d valores impares", impares);
    printf("\n%d valores positivos", positivos);
    printf("\n%d valores negativos", negativos);
    printf("\n");
}

void medias(){
    int n=0;
    double x=0,y=0,z=0;
    double medias[100];
    printf("\nDigite quantos valores quer colocar: ");
    scanf(" %d", &n);
    for(int i=0; i<n; i++){
        printf("\ndigite os 3 valores: ");
        scanf(" %lf", &x);
        scanf(" %lf", &y);
        scanf(" %lf", &z);
        medias[i] = ((x*2)+(y*3)+(z*5))/10;
    }
    for(int i=0; i<n; i++){
        printf("\nmedia %d: %.1lf", i+1, medias[i]);
    }
    printf("\n");
}

void somaImpares(){
    int x=0, y=0;
    int soma=0;
    printf("\nDigite um valor para x: ");
    scanf(" %d", &x);
    printf("\nDigite um valor para y: ");
    scanf(" %d", &y);
    if(x>y){
        while(y<x){
            y++;
            x--;
            if(y%2 != 0){
                soma+=y;
            }
        }
    }
    else if(y>x){
        while(x<y){
            x++;
            y--;
            if(x%2 != 0){
                soma+=x;
            }
        }
    }
    else{
        printf("\nsão iguais");
    }
    printf("\n%d\n", soma);
}
void somaImpares2(){
    int n=0;
    int soma[100];
    printf("\nDigite um um valor para n:");
    scanf(" %d", &n);
    for(int i=0; i<n; i++){
        int x=0, y=0;
        printf("\nDigite um valor para x: ");
        scanf(" %d", &x);
        printf("\nDigite um valor para y: ");
        scanf(" %d", &y);
        if(x-y == 1 || y-x == 1){
            soma[i] += 0; 
        }
        else{
            if(x>y){
                while(x>y){
                    y++;
                    x--;
                    if(y%2 != 0){
                        soma[i]+=y;
                    }
                }
            }
            else if(y>x){
                while(y>x){
                    x++;
                    if(x%2 != 0){
                        soma[i]+=x;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("\n%d\n", soma[i]);
    }
}
