#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 50

typedef struct Graph_t{
    int v;
    bool adj[MAX_VERTICES][MAX_VERTICES];
}graph;

graph *Graph_Create(int v){
    graph *g=malloc(sizeof(graph));
    g->v=v;
    for (int i=0;i<v;i++){
        for (int j=0;j<v;j++){
            g->adj[i][j]=false;
        }
    }
    return g;
}

void Graph_destroy(graph * g){
    free(g);
}
void addEdge(graph *g,int v,int w){
    g->adj[v][w]=true;
}

void Graph_BFS(graph *g,int s){
    bool visited[MAX_VERTICES];
    for (int i=0;i<g->v;i++){
        visited[i]=false;
    }
    int queue[MAX_VERTICES];
    int front=0,rare=0;

    visited[s]=true;
    queue[rare++]=s;

    while (front !=rare){
        s=queue[front++];
        printf("%d",s);

        for (int adjacent=0;adjacent<g->v;adjacent++){
            if (g->adj[s][adjacent] && !visited[adjacent]){
                visited[adjacent]=true;
                queue[rare++]=adjacent;
            }
        }
    }
}

int main(){
    graph *g=Graph_Create(5);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,1,2);
    addEdge(g,1,3);
    addEdge(g,2,4);
    addEdge(g,3,4);
    printf("Following is Breadth First Traversal (starting from vertex 0) \n");
    Graph_BFS(g, 0);
    Graph_destroy(g);
    return 0;
}