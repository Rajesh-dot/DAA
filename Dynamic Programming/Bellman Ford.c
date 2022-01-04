#include<stdio.h>

int main(){
    int n,m,x,u,v,w;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&m);
    printf("Enter vertices (starting, ending, weight)\n");
    int edges[m][3];
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&edges[i][0],&edges[i][1],&edges[i][2]);
    }
    int dist[n];
    int parent[n];
    for(int i=0;i<n;i++){
        dist[i]=10000;
        parent[i]=i;
    }
    printf("Enter starting node: ");
    scanf("%d",&x);
    dist[x]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            u=edges[j][0];
            v=edges[j][1];
            w=edges[j][2];
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }
    for(int i=0;i<m;i++){
        u=edges[i][0];
        v=edges[i][1];
        w=edges[i][2];
        if(dist[v]!=10000 && dist[v]>dist[u]+w){
            printf("There exists a negative");
            return 0;
        }
    }
    printf("Shortest distances from %d are:\n",x);
    for(int i=0;i<n;i++){
        printf("%d ",dist[i]);
    }
    printf("\nParent nodes are:\n");
    for(int i=0;i<n;i++){
        printf("%d ",parent[i]);
    }
    printf("\n");

    return 0;
}


/*
input:-
7
10
0 1 6
0 2 5
0 3 5
1 4 -1
2 1 -2
3 2 -2
2 4 1
3 5 -1
4 6 3
5 6 3
0
*/
