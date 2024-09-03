#include <stdio.h>
#define CAPAC 50

void insertVector(int[], int);

int main(){

    int tam = 0, v[CAPAC], r;

    do{
        printf("Enter the size of the vector (between 3 and %d):\n", CAPAC);
        scanf("%d", &tam);
    }while(tam < 3 || tam > CAPAC);

    do{
        printf("Enter values ​​to fill the entire vector: \n");
        insertVector(v, tam);
    }while(v < 0);


}

void insertVector(int v[], int tam){
    int i = 0;
    for(int i = 0; i < tam; i++){
        printf("[%d] = ", i+1);
        scanf("%d", &v[i]);
        do{
            printf("Invalid value. Only positive values. Try again.\n");
            printf("[%d] = ", i+1);
            scanf("%d", &v[i]);
        }while(v[i] < 0);
    }
}