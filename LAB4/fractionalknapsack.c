#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
}

double fractionalKnapsack(int W, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    clock_t startTime, endTime;
    double executionTime;
  
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &W);
    printf("Enter item details (Weight, Value):\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    startTime = clock();
    double maxValue = fractionalKnapsack(W, items, n);
  
    printf("Maximum value in knapsack = %.2f\n", maxValue);
    endTime = clock();
    executionTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", executionTime);
    return 0;
}