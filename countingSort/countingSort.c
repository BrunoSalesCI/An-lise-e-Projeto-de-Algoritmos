#include <stdio.h>
#include <stdlib.h>

int i = 0, j = 0;

int maiorValor(int *Vetor_A, int tam){
	int maior = 0;

	for (i =0; i < tam; i++){
		if (Vetor_A[i] > maior)
			maior = Vetor_A[i];
	}

	return maior;
}


void countingSort(int *A, int *B, int tam, int k){

	int C[k]; 

	for(i = 0; i <= k; i++) 
		C[i] = 0; 					// Preenche o vetor C com zero

	for(j = 0; j < tam; j++) 
		C[A[j]]= C[A[j]] + 1; 		// contagem cada elemento do intervalo

	for(i = 1; i <= k; i++) 
		C[i] = C[i] + C[i-1]; 		// complemento de casas de cada valor

	for(j = tam -1 ; j >= 0; j--){  // alocação dos valores no vetor ordenado
		int c = C[A[j]]; 			// recebe o valor do índice do vetor B
		B[c] = A[j]; 				// recebe o valor que ficará no índice
		C[A[j]] = C[A[j]] - 1;		// decrementando o valor do vetor C[A[j]]
	}
	
}


int main(){

	int n;

	printf("Digite a QUANTIDADE de caracteres do vetor a ser ordenado: ");
	scanf("%d", &n);

	int A[n];
    
    printf ("Digite os %d NUMEROS do vetor a ser ordenado: ", n);
    for(int i = 0; i < n; i++){   
       scanf("%d", &A[i]);
    }

	int k = 0, tam = 0;

	tam = sizeof(A) / sizeof(int); // cálculo do tamanho do vetor

	k = maiorValor(A,tam); // cálculo do intervalo k

	printf("\nVetor desordenado:\n");

	for(i = 0; i < tam; i++) 
		printf("%d, ", A[i]);

	int B[tam];

	countingSort(A, B, tam, k);

	printf("\n\n\nVetor ordenado:\n");

	for(i = 1; i <= tam; i++){
		A[i] = B[i];
		printf("%d, ", A[i]);
	}

	getchar();

	return 0;
}