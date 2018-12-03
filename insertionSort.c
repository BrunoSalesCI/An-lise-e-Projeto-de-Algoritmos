#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void InsertionSort (int list[], int elements){
	int i, x, y;
	int n;

	for(i=1; i<elements; i++){				//designa os índices para X e Y
		x = list[i];
		y = i-1;

		while(y >= 0 && list[y] > x){			//Se o número correspondente ao indice
			list[y+1] = list[y];				//de Y for maior que o do índice X, executa o while: [o valor Y vai para 
			y = y-1;							//valor do proximo indice, no caso o X]
		}
		list[y+1] = x;							//A posição inicial do Y agora recebe o valor de X
	}
	for(n=0; n < elements; n++)
		printf("#%d -> %d \n", n, list[n]);
}

int main(void){
	int elements;
	int i;

    printf("Digite o numero de elementos da lista: \n");
    scanf("%d", &elements);

    int list[elements];

    printf("Digite os elementos da lista: \n");
    for(i=0; i < elements; i++)
    	scanf("%d \n", &list[i]);

	InsertionSort(list, elements);

	return 0;
}