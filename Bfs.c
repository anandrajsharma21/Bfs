#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void resetQueue() {
    front = -1;
    rear = -1;
}

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

void BFS(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};

    resetQueue();

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void insertEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;   // Undirected graph
    printf("Edge inserted between %d and %d\n", u, v);
}

void searchEdge(int graph[MAX][MAX], int u, int v) {
    if (graph[u][v] == 1)
        printf("Edge exists between %d and %d\n", u, v);
    else
        printf("Edge does not exist between %d and %d\n", u, v);
}

void deleteEdge(int graph[MAX][MAX], int u, int v) {
    if (graph[u][v] == 1) {
        graph[u][v] = 0;
        graph[v][u] = 0;
        printf("Edge deleted between %d and %d\n", u, v);
    } else {
        printf("Edge not found\n");
    }
}

void displayGraph(int graph[MAX][MAX], int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, start, choice, u, v;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert Edge\n");
        printf("2. Search Edge\n");
        printf("3. Delete Edge\n");
        printf("4. BFS Traversal\n");
        printf("5. Display Graph\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two vertices: ");
                scanf("%d %d", &u, &v);
                insertEdge(graph, u, v);
                break;

            case 2:
                printf("Enter two vertices: ");
                scanf("%d %d", &u, &v);
                searchEdge(graph, u, v);
                break;

            case 3:
                printf("Enter two vertices: ");
                scanf("%d %d", &u, &v);
                deleteEdge(graph, u, v);
                break;

            case 4:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                BFS(graph, n, start);
                break;

            case 5:
                displayGraph(graph, n);
                break;

            case 6:
                printf("Exit...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}
