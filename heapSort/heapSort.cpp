#include <iostream> 
  
using namespace std; 
  
void heapify(int arr[], int n, int i) // Função para gerar a subarvore enraizada no nó i
{ 
    int largest = i; // maior raíz
    int l = 2*i + 1; // nó da esquerda
    int r = 2*i + 2; // nó da direita
  
    if (l < n && arr[l] > arr[largest]) //Caso o filho da esquerda seja maior que a raíz
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) //Caso o filho da direita for o maior que todos
        largest = r; 
  
    if (largest != i) //Caso o maior não for a raíz
    { 
        swap(arr[i], arr[largest]); // Troca o i pelo maior
        heapify(arr, n, largest); // Chama novamente com a árvore enraizada
    } 
} 
  
void heapSort(int arr[], int n){ 

    for (int i = n / 2 - 1; i >= 0; i--) //Começa a reorganizar o array
        heapify(arr, n, i); 
  
    for (int i=n-1; i>=0; i--){ //Extrai os elementos do array
        swap(arr[0], arr[i]); //Troca a raíz de posição com o final
        heapify(arr, i, 0); 
    } 
} 
  
    void imprimirArray(int arr[], int n){ 
    
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 

    cout << "\n"; 
    } 
  
int main(){ 
    int quant;

    printf("Digite a QUANTIDADE de caracteres do vetor a ser ordenado: ");
    scanf("%d", &quant);

    int arr[quant];
    
    printf ("Digite os %d NUMEROS do vetor a ser ordenado:\n ", quant);
    for(int i = 0; i < quant; i++){   
       scanf("%d", &arr[i]);
    }

    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Array ordenado: \n"; 
    imprimirArray(arr, n); 
} 