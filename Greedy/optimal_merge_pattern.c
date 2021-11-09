#include<stdio.h>

int get_min(int a[],int n){
    int idx=-1;
    int m=1000;
    for(int i=0;i<n;i++){
        if(m>a[i]){
            idx=i;
            m=a[i];
        }
    }
    return idx;
}

int main(){
    int n,idx1,idx2,min1,min2;
    printf("Enter number of files: ");
    scanf("%d",&n);
    int f[n];
    printf("\nEnter size of files:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&f[i]);
    }
    int cost=0;
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        printf("f%d : %d  ",i,f[i]);
    }
    printf("\n");
    for(int i=0;i<n-1;i++){
        idx1=get_min(f,n);
        min1=f[idx1];
        f[idx1]=1000;
        idx2=get_min(f,n);
        min2=f[idx2];
        f[idx2]=min1+min2;
        cost=cost+min1+min2;
        if(parent[idx1]<0 && parent[idx2]<0){
            printf("t%d + t%d = t%d\n",-parent[idx1],-parent[idx2],i+1);
        }
        else if(parent[idx1]<0){
            printf("t%d + f%d = t%d\n",-parent[idx1],parent[idx2],i+1);
        }
        else if(parent[idx2]<0){
            printf("f%d + t%d = t%d\n",parent[idx1],-parent[idx2],i+1);
        }
        else{
            printf("f%d + f%d = t%d\n",parent[idx1],parent[idx2],i+1);
        }
        parent[idx2]=-(i+1);
    }
    printf("minimum cost: %d\n",cost);
    return 0;
}

