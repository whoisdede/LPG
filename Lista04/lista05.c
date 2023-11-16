#include <stdlib.h>
#include <stdio.h>

#define TAM 5

void menu();
void inc_dec (int *a, int *b);
void troca_valor(float *x, float *y);
void calcula_circulo(float raio, float *pPerimetro, float *pArea);
void calcula_hora(int totalMinutos, int *ph, int *pm);
void max_min(int vet[], int tam, int *pMin, int *pMax);
void max_vetor(float vet[], int tam, float *pMax, int *pIndice);
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);

int main(){
    int opcao=-1;
    while(opcao!= 0){
        menu();
        printf("Digite: ");
        scanf(" %d", &opcao);
        switch(opcao){
            case 0:
                break;
            case 1:
                int a,b;
                scanf(" %d %d", &a, &b);
                inc_dec(&a,&b);
                printf("%d %d\n", a,b);
                break;
            case 2:
                float x=0,y=0;
                scanf(" %f %f", &x, &y);
                troca_valor(&x,&y);
                printf("%.1f %.1f", x,y);
                break;
            case 3:
                float raio, perimetro=0, area=0;
                printf("Digite o raio: ");
                scanf(" %f", &raio);
                calcula_circulo(raio, &perimetro, &area);
                printf("Area: %.2f, Perimetro: %.2f", area, perimetro);
                break;
            case 4:
                int minutos=0, ph=0, pm=0;
                printf("Digite; ");
                scanf(" %d", &minutos);
                calcula_hora(minutos, &ph, &pm);
                printf("%d horas e %d minutos", ph, pm);
                break;
            case 5:
                int tamanho=TAM, pMin=0, pMax=0;
                int vetor[TAM];
                for(int i=0; i <TAM; i++){
                    scanf(" %d", &vetor[i]);
                }
                max_min(vetor, TAM, &pMin, &pMax);
                printf("Valor min: %d, valor max: %d", pMin, pMax);
                break;
            case 6:
                int tama=TAM, peIndice=0;
                float vetorr[TAM], peMax=0;
                for(int i=0; i<tama; i++){
                    scanf(" %f", &vetorr[i]);
                }
                max_vetor(vetorr, TAM, &peMax, &peIndice);
                printf("Valor max: %.2f, indice: %d", peMax, peIndice);
                break;
            case 7:
                float mat[3][4], peMin=0;
                int pI=0, pJ=0;
                for(int i=0;i<3;i++){
                    for(int j=0;j<4;j++){
                        scanf(" %f", &mat[i][j]);
                    }
                    printf("\n");
                }
                min_matriz(mat, &peMin, &pI, &pJ);
                printf("Valor min: %.2f;\nlinha : %d;\ncoluna: %d.", peMin, pI, pJ);
                break;
            default:
                printf("\nValor inválido!");
        }
    }
}

void menu(){
    printf("\nSelecione o exercício:");
    printf("\n0 - Sair");
    printf("\n1 - Incremento e Decremento");
    printf("\n2 - Troca valor");
    printf("\n3 - Calcula circunferencia");
    printf("\n4 - Minutos para hora");
    printf("\n5 - Minimo e Max vetor");
    printf("\n6 - Valor maximo e indice");
    printf("\n7 - Menor valor matrix 3x4\n");

}

void inc_dec (int *a, int *b){
    (*a)++;
    (*b)--;
}

void troca_valor(float *x, float *y){
    int temp=0;
    temp = (*x);
    (*x) = (*y);
    (*y) = temp;
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    double pi = 3.1415;
    (*pPerimetro) = 2*pi*raio;
    (*pArea) = pi*raio*raio;
}

void calcula_hora(int totalMinutos, int *ph, int *pm){
    (*ph) = totalMinutos/60;
    (*pm) = totalMinutos - (*ph)*60;
    if((*ph)>24){
        (*ph) /=24;
    }
}
void max_min(int vet[], int tam, int *pMin, int *pMax){
    (*pMin) = vet[0];
    (*pMax) = vet[0];
    for(int i=1; i<tam; i++){
        if(vet[i]<(*pMin)){
            (*pMin) = vet[i];
        }
        if(vet[i]>(*pMax)){
            (*pMax) = vet[i];
        }
    }
}
void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
    (*pMax) = vet[0];
    for(int i=1; i<tam; i++){
        if(vet[i]>(*pMax)){
            (*pMax) = vet[i];
            (*pIndice) = i;
        }
    }
}
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    (*pMin) = mat[0][0];
    for(int i=0; i<3; i++){
        for(int j=1;j<4;j++){
            if(mat[i][j]<(*pMin)){
                (*pMin) = mat[i][j];
                (*pI) = i;
                (*pJ) = j;
            }
        }
    }
}