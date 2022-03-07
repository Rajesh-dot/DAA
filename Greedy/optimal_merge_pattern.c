#include<stdio.h>

void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    int t;
    if(l<n && arr[l]<arr[largest])
        largest=l;
    if(r<n && arr[r]<arr[largest])
        largest=r;
    if(largest!=i){
        t=arr[i];
        arr[i]=arr[largest];
        arr[largest]=t;
        heapify(arr, n, largest);
    }
}


int main(){
    int n,min1,min2;
    printf("Enter number of files: ");
    scanf("%d",&n);
    int f[n];
    printf("Enter size of files:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&f[i]);
    }
    for(int i=n/2-1;i>=0;i--){
        heapify(f,n,i);
    }
    int cost=0;
    for(int i=0;i<n-1;i++){
        min1=f[0];
        f[0]=1000;
        heapify(f,n,0);
        min2=f[0];
        f[0]=min1+min2;
        heapify(f,n,0);
        cost=cost+min1+min2;
        printf("merge %d and %d cost is = %d\n",min1,min2,min1+min2);
    }
    printf("minimum cost: %d\n",cost);
    return 0;
}
