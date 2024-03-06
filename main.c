#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// definim o structura pentru o muchie in graf.

struct Edge {
    int u, v, weight; // u si v sunt nodurile de start si sfarsit ale muchiei, weight este ponderea muchiei.
};

// functia pentru implementarea algoritmului Ford.

void alg_Ford(struct Edge edges[], int V, int E, int source, int destination) {
    int distance[V]; // vector pentru a stoca distanta minima de la sursa la fiecare nod
    int previous[V]; // vector pentru a stoca nodul anterior in calea optima de la sursa

    // initializam toate distantele ca fiind infinite si toate nodurile anterioare ca -1.

    for (int i = 0; i < V; ++i) {
        distance[i] = INT_MAX;
        previous[i] = -1;
    }

    // distanta de la sursa la ea insasi este intotdeauna 0.

    distance[source] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;

            // daca distanta la nodul de start al muchiei nu este infinita si distanta
            // prin aceasta muchie este mai mica decat distanta cunoscuta
            //anterior, atunci actualizam distanta si nodul anterior.

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                previous[v] = u;
            }
        }
    }

    // printam calea cea mai scurta de la sursa la destinatie.

    printf("Drumul minim de la nodul %d la nodul %d:\n", source, destination);
    while (destination != -1) {
        printf("%d ", destination);
        destination = previous[destination];
    }
    printf("\n");
}

//------------------------------------ main function ----------------------------------------

int main() {

    int V, E; // numarul de varfuri si muchii in graf.

    // cerem utilizatorului numarul de varfuri si muchii

    printf("Introduceti numarul de noduri si muchii: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E]; // vector de muchii.

    // cerem utilizatorului detaliile fiecarei muchii.

    printf("Introduceti muchiile (start, finish, ponderea):\n");
    for (int i = 0; i < E; ++i) {
        printf("Muchia %d:", i+1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    int source, destination; // citim nodurile distanta dintre care dorim sa aflam.

    // cerem utilizatorului nodurile sursa si destinatie.

    printf("Introduceti nodul pana la care doriti sa aflati drumul minim:  ");
    scanf("%d", &destination);

    // apelam functia alg_Ford.

    alg_Ford(edges, V, E, 1, destination);

    return 0;
}
