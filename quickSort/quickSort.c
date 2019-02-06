
#include <stdio.h> 
#include <stdlib.h>

  
// Função para trocar dois elementos 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* A função partition pega o último elemento do array e coloca como o pivô,
 e põe na posição correta. Os elementos menores que o pivô vão para a esq.,
 e os maiores para a direita. */

int partition (int array[], int menor, int maior){
    int pivo = array[maior];    // Define o pivô
    int i = (menor - 1);  // Índice do menor elemento
  
    for (int j = menor; j <= maior - 1; j++){ 
        if (array[j] <= pivo){     //Se o elemento [j] for menor ou igual que o pivô 
            i++;
            swap(&array[i], &array[j]);  // Troca de posição o elemento [i] com o elemento [j]
        }  
    }swap(&array[i + 1], &array[maior]);  //Troca de posição o elemento [i+1] com o elemento 
    return (i + 1); 
} 

void quickSort(int array[], int menor, int maior) 
{ 
    if (menor < maior) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(array, menor, maior); 
  
        // Separa os elementos de forma recursiva
        quickSort(array, menor, pi - 1); 
        quickSort(array, pi + 1, maior); 
    } 
} 

void printArray(int array[], int elements)                  //Printa os elementos ordenados
{ 
    int i; 
    for (i=0; i < elements; i++) 
        printf("ARRAY ORDENADO: #%d -> %d\n", i, array[i]);
}

int main(void){
    int elements;
    int i;
    int bag = 0;

    printf("Digite o numero de elementos da lista: \n");
    scanf("%d", &elements);

    int array[elements];

    printf("Digite os elementos da lista: \n");
    for(i=0; i < elements; i++){
        scanf("%d", &bag);
        array[i] = bag;
    }
    for(i=0; i < elements; i++)
        printf("ARRAY INSERIDO: #%d -> %d\n", i, array[i]);

    printf("\n");

    quickSort(array, 0, elements-1);
    printArray(array, elements); 

    return 0;
}