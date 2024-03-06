#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int u, v, weight;
};

void alg_Ford(struct Edge edges[], int V, int E, int source, int destination) {
    int distance[V];
    int previous[V];

    for (int i = 0; i < V; ++i) {
        distance[i] = INT_MAX;
        previous[i] = -1;
    }

    distance[source] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                previous[v] = u;
            }
        }
    }

    printf("Drumul minim de la nodul %d la nodul %d:\n", source, destination);
    int current = destination;
    while (current != source && current != -1) {
        printf("%d ", current);
        current = previous[current];
    }
    printf("%d\n", source);
}

int main() {
    int V, E;

    printf("Introduceti numarul de noduri si muchii: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];

    printf("Introduceti muchiile (start, finish, ponderea):\n");
    for (int i = 0; i < E; ++i) {
        printf("Muchia %d:", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    int source, destination;
    printf("Introduceti nodul de start si nodul pana la care doriti sa aflati drumul minim: ");
    scanf("%d %d", &source, &destination);

    alg_Ford(edges, V, E, source, destination);

    return 0;
}
