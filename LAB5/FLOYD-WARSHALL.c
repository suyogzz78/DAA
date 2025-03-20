#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INF 99999 // Infinity for unreachable vertices

void floydWarshall(int graph[][100], int V) {
int dist[V][V];
for (int i = 0; i < V; i++)
for (int j = 0; j < V; j++)
dist[i][j] = graph[i][j];
for (int k = 0; k < V; k++) {
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
dist[i][j] = dist[i][k] + dist[k][j];
}
}
}
printf("Shortest distances between every pair of vertices:\n");
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (dist[i][j] == INF)
printf("%7s", "INF");
else
printf("%7d", dist[i][j]);
}
printf("\n");
}
}
int main() {
int V;
printf("Enter number of vertices in the graph: ");
scanf("%d", &V);
int graph[100][100]; // Assuming max size of graph is 100x100
printf("Enter the adjacency matrix of the graph (%d x %d):\n", V, V);
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
scanf("%d", &graph[i][j]);
if (i != j && graph[i][j] == 0)
graph[i][j] = INF; // Convert 0 to INF for non-self loops
}
}
clock_t start, end;
double cpu_time_used;

start = clock();
floydWarshall(graph, V);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("\nTime executed: %f seconds\n", cpu_time_used);
return 0;
}

