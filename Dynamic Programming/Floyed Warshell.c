#include<stdio.h>

int main(){
    int n,m,u,v,w;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&m);
    printf("Enter vertices (starting, ending, weight)\n");
    int graph[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                graph[i][j]=10000;
            }
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        graph[u][v]=w;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }  
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                printf("shortest distance from %d to %d is %d\n",i,j,graph[i][j]);
            }
        }
    }

    return 0;
}


/*
input:-
4
6
0 1 3
1 0 2
0 3 5
1 3 4
2 1 1
3 2 2

output:-
shortest distance from 0 to 1 is 3
shortest distance from 0 to 2 is 7
shortest distance from 0 to 3 is 5
shortest distance from 1 to 0 is 2
shortest distance from 1 to 2 is 6
shortest distance from 1 to 3 is 4
shortest distance from 2 to 0 is 3
shortest distance from 2 to 1 is 1
shortest distance from 2 to 3 is 5
shortest distance from 3 to 0 is 5
shortest distance from 3 to 1 is 3
shortest distance from 3 to 2 is 2
*/
