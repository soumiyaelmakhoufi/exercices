#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct s_node {
    int val;
    struct s_node* next;
} node;
node* adj[MAX];
void add_edge(int x, int y) {
    node* t = (node*) malloc(sizeof(node));
    t->val = y;
    t->next = NULL;
    if (adj[x] == NULL) {
        adj[x] = t;
    } else {
        node* curr = adj[x];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = t;
    }
}
bool visited[MAX];
bool is_tree = true;
void dfs(int u, int p) {
    visited[u] = true;
    node* ptr = adj[u];
    while (ptr != NULL) {
        if (ptr->val != p) {
            if (visited[ptr->val]) {
                is_tree = false;
            } else {
                dfs(ptr->val, u);
            }
        }
        ptr = ptr->next;
    }
}
void bfs(int start) {
    int queue[MAX];
    int front = 0;
    int rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    while (front != rear) {
        int u = queue[front++];
        printf("%d ", u);
        node* ptr = adj[u];
        while (ptr != NULL) {
            int v = ptr->val;
            if (!visited[v]){
                visited[v] = true;
                queue[rear++] = v;
            }
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);
    for (int i = 0; i < edges; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
    dfs(1, -1);
    if (is_tree) {
        printf("This graph is a tree\n");
    } else {
        printf("This graph is not a tree\n");
    }
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
    printf("BFS traversal: ");
    bfs(2);
    for (int i = 0; i < MAX; i++) {
        node* ptr = adj[i];
        while (ptr != NULL) {
            node* next = ptr->next;
            free(ptr);
            ptr = next;
        }
        adj[i] = NULL;
    }
    return 0;
}
