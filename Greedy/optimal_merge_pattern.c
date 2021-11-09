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
    printf("Enter size of files:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&f[i]);
    }
    int cost=0;
    for(int i=0;i<n-1;i++){
        idx1=get_min(f,n);
        min1=f[idx1];
        f[idx1]=1000;
        idx2=get_min(f,n);
        min2=f[idx2];
        f[idx2]=min1+min2;
        cost=cost+min1+min2;
        printf("merge %d and %d cost is = %d\n",min1,min2,min1+min2);
    }
    printf("minimum cost: %d\n",cost);
    return 0;
}
