#include<stdio.h>

int max=100;
int t=0;

void findAnsPlease(int graph[max][max],int curr,int ans[],int k,int n){
    if(curr==n){
        t++;
        printf("Solution-%d:\n",t);
        for(int i=0;i<n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=k;i++){
        int f=0;
        for(int j=0;j<n;j++){
            if(graph[curr][j]==1 && ans[j]==i){
                f=1;
            }
        }
        if(f==0){
            ans[curr]=i;
            findAnsPlease(graph,curr+1,ans,k,n);
            ans[curr]=-1;
        }
    }
}

int main(){
    int n,m,u,v,k;
    printf("Enter number of nodes:\n");
    scanf("%d",&n);
    printf("Enter number of edges:\n");
    scanf("%d",&m);
    int graph[max][max];
    printf("Enter edges (Start, End):\n");
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;
    }
    printf("Enter no.of colors:\n");
    scanf("%d",&k);
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=-1;
    }
    findAnsPlease(graph,0,ans,k,n);
    if(t==0){
        printf("Sorry kid there are no solutions\n");
    }
}
