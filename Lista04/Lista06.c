#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void menu();
float *clone( float *v, int n );
char *repetidor( char *s, int n );
float *mediaMaior(float *v, int n);
void *posENeg(int *v, int tam);
int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );

int main(){

    int opcao=-1;
    while (opcao!=0){
        menu();
        printf("Digite: ");
        scanf(" %d", &opcao);
        switch(opcao){
            case 0:
                break;
            case 1: 
                float *vet , *result;
                int qtd=0;
                printf("\nDigite a quantidade de termos: ");
                scanf(" %d", &qtd);
                vet = malloc(sizeof(float)*qtd);
                for(int i=0; i<qtd; i++){
                    scanf(" %f", &vet[i]);
                }
                result = clone(vet, qtd);
                for(int i=0; i<qtd; i++){
                    printf("%.2f ", result[i]);
                }
                break;
            case 2:
                char *palavra;
                char *repetido;
                int termos=0, repeticoes=0;
                printf("\nDigite a quantidade de termos: ");
                scanf(" %d", &termos);
                palavra = malloc(sizeof(char)*termos);
                scanf(" %s", palavra);
                printf("\nDigite a quantidade de repeticoes: ");
                scanf(" %d", &repeticoes);
                repetido = repetidor(palavra, repeticoes);
                printf("%s", repetido);

                break;
            case 3:
                float *vetor;
                int tamanho =0, tm=0;
                printf("\nDigite o tamanho: ");
                scanf(" %d", &tamanho);
                vetor = malloc(sizeof(float)*tamanho);
                for(int i=0 ; i<tamanho; i++){
                    scanf(" %f", &vetor[i]);
                }

                float *final;
                final = mediaMaior(vetor, tamanho);

                for(int i=0; i<tamanho; i++){
                    if(final[i]!=0){
                        tm++;
                    }
                }
                for(int i=0; i<tm; i++){
                    printf("[%d] = %.2f\n", i, final[i]);
                }
                break;
            case 4:
                int *vetors, tamo=0;
                printf("\nDigite o tamanho: ");
                scanf(" %d", &tamo);
                vetors = malloc(sizeof(int)*tamo);
                printf("\nDigite os termos: ");
                for(int i=0; i<tamo; i++){
                    scanf(" %d", &vetors[i]);
                }
                posENeg(vetors, tamo);
                break;
            case 5:
                int *arr1, *arr2, size1=0, size2=0, p3, *rslt;
                printf("\nDigite o tam do primeiro vetor e do segundo em seguida: ");
                printf("\n- ");
                scanf(" %d", &size1);
                printf("- ");
                scanf(" %d", &size2);
                arr1 = malloc(sizeof(int)*size1);
                arr2 = malloc(sizeof(int)*size2);
                printf("Digite os valores do primeiro vetor e em seguida do segundo: ");
                printf("\nPrimeiro:\n");
                for(int i=0; i< size1; i++){
                    scanf(" %d", &arr1[i]);
                }
                printf("\nSegundo:\n");
                for(int i=0; i< size2; i++){
                    scanf(" %d", &arr2[i]);
                }
                rslt = uniao(arr1,size1,arr2,size2, &p3);
                printf("\nUnião dos conjuntos:");
                for(int i=0; i< p3; i++){
                    printf(" %d", rslt[i]);
                }
                break;
            default:
                printf("\nValor inválido!");
        }
    }
    return 0;
}

void menu(){
    printf("\nSelecione o exercício:");
    printf("\n0 - Sair");
    printf("\n1 - Clone");
    printf("\n2 - Repetições");
    printf("\n3 - Maior que a média");
    printf("\n4 - Positivo e negativo");
    printf("\n5 - União de conjuntos\n");
}

//Faz com que o vetor "cl" seja igual ao v.
float *clone( float *v, int n ){
    float *cl;
    cl = v;
    return cl;
}

//repete n vezes a string s
char *repetidor( char *s, int n ){
    char *repetido;
    repetido = malloc(n*sizeof(char)*strlen(s));
    int j=0;
    for(int i=0;i<n*strlen(s); i++){
        repetido[i]= s[j]; 
        j++;
        if(j==3){
            j=0;
        }
    }
    return repetido;
}

//Faz uma matriz somente com os valores acima da média da matriz original
float *mediaMaior(float *v, int n){
    float *mediaMaior, media=0;
    int termosMaior=0;
    mediaMaior = malloc(0*sizeof(float));
    for(int i=0; i<n; i++){
        media += v[i];
    }
    media /= n;
    for(int i=0; i<=n; i++){
        if(v[i] >=media){
            termosMaior++;
            mediaMaior = realloc(mediaMaior, sizeof(float)*termosMaior);
            mediaMaior[termosMaior-1] = v[i];
        }   
    }
    return mediaMaior;
}
//Separa os valores positivos dos negativos, excluindo o zero
void *posENeg(int *v, int tam){
    int tamP=0, tamN=0, i=0;
    int *vp;
    int *vn;
    vp = malloc(sizeof(int)*tamP);
    vn = malloc(sizeof(int)*tamN);
    for(int i=0; i<tam; i++){
        if(v[i] >0){
            tamP++;
            vp = realloc(vp, sizeof(int)*tamP);
            printf("\n-%d-", tamP);
            vp[tamP-1] = v[i];
        }
        else if(v[i]<0){
            tamN++;
            vn = realloc(vn, sizeof(int)*tamN);
            vn[tamN-1] = v[i];
        }
    }
    printf("\nVetor original:");
    for(i=0; i<tam; i++){
        printf("\n[%d] - %d", i, v[i]);
    }
    printf("\nVetor positivo:");
    for(i=0; i<tamP; i++){
        printf("\n[%d] - %d", i, vp[i]);
    }
    printf("\nVetor negativo:");
    for(i=0; i<tamN; i++){
        printf("\n[%d] - %d", i, vn[i]);
    }
}
//Faz a união de dois conjuntos utilizando um Vetor de apoio, iguala a zero os termos iguais e depois coloca todos os valores diferetes de zero no vetor original.
int *uniao( int *v1, int n1, int *v2, int n2, int *p3 ){
    int *v3, *vAp, cont =0;
    vAp = malloc(sizeof(int)*(n1+n2));
    v3 = vAp;
    for(int i=0; i<n1; i++){
        vAp[i] = v1[i];
    }
    for(int i=n1; i<n1+n2; i++){
        vAp[i] = v2[cont];
        cont++;
    }
    for(int i=0; i<n1+n2; i++){
        for(int j=i+1; j<n1+n2; j++){
            if(vAp[i] == vAp[j]){
                vAp[j] = 0;
            }
        }
    }
    cont=0;
    for(int i =0; i< n1+n2; i++){
        if(vAp[i] != 0){
            v3[cont] = vAp[i];
            cont++;
        }
    }
    (*p3) = cont;
    v3 = realloc(v3, sizeof(int)*(*p3));
    return v3;
}