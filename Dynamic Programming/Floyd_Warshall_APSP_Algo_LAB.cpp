//Floyd_Warshall_APSP_Algo_LAB
#include <stdio.h>
#define INF 99999
#define MAX 10
int graph[MAX][MAX];
int n;
int RecursiveShortest(int i, int j, int k)
{
 if(k < 0){
 return graph[i][j];
 }
 int withoutK =
RecursiveShortest(i, j, k - 1);
 int left =
RecursiveShortest(i, k, k - 1);
 int right =
RecursiveShortest(k, j, k - 1);
 int withK;
 if(left == INF || right == INF){
 withK = INF;
 }
 else{
 withK = left + right;
 }
 if(withoutK < withK){
 return withoutK;
 }
 else{
 return withK;
 }
}
int main(){
 int dist[MAX][MAX];
 printf("Enter number of vertices: ");
scanf("%d", &n);
 printf("Enter adjacency matrix:\n");
 for(int i = 0; i < n; i++){
 for(int j = 0; j < n; j++){
 scanf("%d", &graph[i][j]);
 dist[i][j] = graph[i][j];
 }
 }

 // Floyd-Warshall Algorithm
for(int k = 0; k < n; k++){
 for(int i = 0; i < n; i++){
 for(int j = 0; j < n; j++){
 if(dist[i][k] != INF &&
 dist[k][j] != INF &&
 dist[i][k] + dist[k][j] < dist[i][j]){
 dist[i][j] = dist[i][k] + dist[k][j]; }
 }
   }
     }

 printf("\nShortest Path Matrix:\n");
 
 for(int i = 0; i < n; i++){
 for(int j = 0; j < n; j++){
 if(dist[i][j] == INF){
 printf("INF ");
 }
 else{
 printf("%3d ", dist[i][j]);
 }
 }
 printf("\n");
 }

 printf("\nRecursive shortest path from 0 to 3 = %d\n", RecursiveShortest(0, 3, n - 1));
 return 0;
}