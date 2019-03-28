#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;


#define V 9
int vazio = 0;

int minDistance(int dist[], bool sptSet[])
{

   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}


int printSolution(int dist[], int n)
{
   cout << "O caminho mínimo obtido foi:\n" << endl;
   for (int i = 0; i < V; i++) {
        vazio += dist[i];
   }
   cout << vazio << endl;


}

