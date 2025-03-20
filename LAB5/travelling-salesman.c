#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#define MAX 10 

int n;
int graph[MAX][MAX];
bool visited[MAX];
int minCost = INT_MAX;

void tsp(int city, int count, int cost, int start) {
    if (count == n && graph[city][start]) { 
        if (cost + graph[city][start] < minCost) {
            minCost = cost + graph[city][start]; 
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[city][i]) { 
            visited[i] = true;
            tsp(i, count + 1, cost + graph[city][i], start);
            visited[i] = false;
        }
    }
}

int main() {
    clock_t start_time, end_time;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Error: Maximum supported cities is %d.\n", MAX);
        return 1;
    }

    printf("Enter the distance matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    start_time = clock();

    for (int i = 0; i < n; i++) visited[i] = false;
    visited[0] = true;
    tsp(0, 1, 0, 0);
    printf("Minimum cost of travelling salesman tour: %d\n", minCost);
    end_time = clock();
    printf("Time executed: %f seconds\n", ((double)(end_time - start_time)) / CLOCKS_PER_SEC);

    return 0;
}
