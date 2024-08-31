#include <stdio.h>
#include <stdlib.h>
#define TAM 10

// procedimento para criar um vetor
int createVector(int **v){
    int tam = 0;
    
    do{
        printf("Insira o tamanho do vetor (valor entre 1 e %d):\n", TAM);
        scanf("%d", &tam);
        
    }while(tam < 1 || tam > TAM);
    
    *v = (int *) malloc(tam * sizeof(int));

    return tam;

    free(v);
}
// procedimento para inserir vetor
void insertVector(int v[], int tam){
    int i = 0;
    
    printf("Insira os valores para preencher o vetor:\n");
        for(i = 0; i < tam; i++){
            do{
                printf("Valor para v[%d]: ", i);
                scanf("%d", &v[i]);
                if (v[i] < 1){
                    printf("Valor inválido! O valor deve ser maior que 0. Tente novamente.\n");
            }
                
        }while(v[i] < 1);
    }
}
// procedimento para ordenar vetor
void insertionSort(int v[], int tam){
    for(int i = 0; i < tam; i++){
        
        int j = i;
        
        while (j > 0 && v[j] < v[j-1]) {
			int aux = v[j];
			v[j] = v[j - 1];
			v[j - 1] = aux;
			j -= 1;
		}
    }
}
// procedimento para imprimir vetor
void printVector(int v[], int qtd) {
    printf("[");
    if (qtd > 0) {
        printf("%d", v[0]);
    for (int i = 1; i < qtd; ++i) {
      printf(", %d", v[i]);
    }
  }
  printf("]\n");
}

int main()
{
    int *v, tam;
    
    
    tam = createVector(&v);
    insertVector(v, tam);
    
    printf("\nImpressão do vetor original\n");
    printf("V = ");
    printVector(v, tam);
    
    insertionSort(v, tam);
    
    printf("\nImpressão do vetor ordenado:\n");
    printf("V = ");
    printVector(v, tam);
    
    
    return 0;
}