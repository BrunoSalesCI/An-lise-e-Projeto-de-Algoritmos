#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void selectionSort(int list[], int elements){ //recebe um array e o número de elementos
	int i, j, aux, min, n;

	for(i=0; i<elements-1; i++){ //Percorre todo o array

		min = i; //Guarda o valor do menor índice para min
		
		for(j=i+1; j<elements; j++){ //percorre o resto do array, comparando com o i
			if(list[j] < list[min]) //compara o valor de j x min, caso j for menor, j é o novo min
				min = j;
				
				aux = list[i];		
				list[i] = list[min]; //atribui-se ao elemento de índice 'i' o valor mínimo
				list[min] = aux; //a variável em questão é designada ao elemento mínimo, para fazer outra comparação
		}
	}
	for(n=0; n < elements; n++)
	printf("#%d -> %d \n", n, list[n]);
}

int main(void){
	int elements;
	int i = 0;

    printf("Digite o numero de elementos da lista: \n");
    scanf("%d", &elements);

    int list[elements];

    printf("Digite os elementos da lista: \n");
    while(i < elements){
    	scanf("%d \n", &list[i]);
    	i++;
    }

	selectionSort(list, elements);

	return 0;
}