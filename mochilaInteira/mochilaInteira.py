import sys
import timeit
import numpy as np

if len(sys.argv) != 2:
    arq = open("instancias/mochila01.txt.txt","r")				#Leitura do arquivo
else:
    arq = open("instancias/"+sys.argv[1],"r")
matriz = []
for j in arq:
	matriz.append(map(int,j.split()))




def Init_mat(lines,columns):							#Inicia uma matriz de tamanho linhas x colunas, com zeros
	mat = np.zeros((lines,columns),dtype=int)				#Seta as linhas e colunas com zeros, tipo = int
	return mat   								#Retorna a matriz 'mat'

def MaxMochila(matriz):
    mat = Init_mat(matriz[0][0]+1,matriz[0][1]+1)  				#Inicia a Matriz (nxM - Objetos x Capacidade) com 0
    for j in range(1,matriz[0][0]+1):						#Começa a percorrer a matriz
        for w in range(1,matriz[0][1]+1):					#w é a capacidade da mochila / j é o peso do item
            if(matriz[j][0] > w):  						#Verifica se o peso do item atual é maior que a capacidade da mochila
                mat[j][w] = mat[j-1][w] 					#Se entrar nessa condição, objeto não cabe na mochila. Então, põe o peso do item anterior
            else:
                col = [w-matriz[j][0] if w-matriz[j][0]>0 else 0]		#Coloca o item na mochila, subtraindo o seu peso pela capacidade da mochila
                mat[j][w] = max(mat[j-1][w] , mat[j-1][col] + matriz[j][1])
    return(mat)									#Retorna o valor dos itens na mochila


def GetMochila(mat,matriz):					#Função que percorre a matriz para ver os elementos que estão nela
    col = len(mat[0])-1						#Seta col como o tamanho da coluna da matriz mat[]
    elements = []						#Cria um array 'elements' para armazenar os elementos da matriz
    for row in range(len(mat)-1,-1,-1):				#Laço de percorrimento da matriz
        if(mat[row][col] != mat[row-1][col]):			#Se o elemento da linha[] e coluna[] for diferente da linha anterior significa que é um novo item dentro da mochila
            elements.append(row)				#Adiciona esse item no array 'elements'
            col = abs(col-matriz[row][0])			#Retorna o valor absoluto dessa func para 'col'
    return(elements)						#Retorna 'elements' com os valores dos elementos que estão na mochila (na matriz mat[])

mat = MaxMochila(matriz)					#mat = valor dos itens da mochila

print("Valor Arrecadado na Mochila:{}\nItens Escolhidos:{}".format(mat[-1][-1],GetMochila(mat,matriz))) #Printa a saída
