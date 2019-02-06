#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void merge (int *vetor, int inicio, int meio, int fim){
	int *buff, list1, list2, tamanho, i, j, k;
	int final1 = 0;
	int final2 = 0;

	tamanho = fim - inicio + 1;
	list1 = inicio;							//Define o inicio da list1
	list2 = meio + 1;						//Define o inicio da list2

	buff = (int*) malloc(tamanho*sizeof(int));	//Define o tamanho do buff temporário que irá receber a junção
												// dos dois vetores (list1 e list2)

	if(buff != NULL){
		for(i=0; i<tamanho; i++){				//Percorre o vetor ordenando os valores
			if(!final1 && !final2){
				if(vetor[list1] < vetor[list2])	//Verificação de maior/menor valor, copia o valor e incrementa
					buff[i] = vetor[list1++];
				else 
					buff[i] = vetor[list2++];
				


				if(list1 > meio)				//Verifica se chegou no final das listas (list1 e list2)
					final1 = 1;
				if(list2 > fim)					//Caso um vetor já tenho terminado, é só copiar o restante do outro
					final2 = 1;
			

			}else{
				if(!final1)						//Copia o que está sobrando das lists
					buff[i] = vetor[list1++];
				else
					buff[i] = vetor[list2++];
			}



		}for(j = 0, k=inicio; j<tamanho; j++, k++)	//Copia os dados do buff que armazenou os dados temporários
			vetor[k] = buff[j];						//para o vetor original (vetor)
	}
	free(buff);									//Libera o espaço de memória do buff temporário
}


/*A função divide os dados do vetor, fazendo o uso da recursão. Na função merge
de fato, são ordenados os dados*/
void mergeSort (int *vetor, int inicio, int fim){
	int meio;

	if(inicio < fim){
		meio = floor((inicio + fim) /2);		// A função floor arredonda para baixo
		mergeSort(vetor, inicio, meio); 		// Chama recursivamente a função, dividindo
		mergeSort(vetor, meio+1, fim); 			//e ordenando item a item.
		merge(vetor, inicio, meio, fim);		// Função merge -> Junta as duas partes de forma ordenada
	}
}


void printArray(int array[], int elements) 
{ 
    int i; 
    for (i=0; i < elements; i++) 
        printf("ARRAY ORDENADO: #%d -> %d\n", i, array[i]);
}

int main(){
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

    mergeSort(array, 0, elements-1);
    printArray(array, elements);

	return 0;
}