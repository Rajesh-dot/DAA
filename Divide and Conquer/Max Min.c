#include<stdio.h>

int get_max(int a[],int l,int r){
    int m=(l+r)/2;
    if(r==l){
        return a[l];
    }
    int x=get_max(a,l,m);
    int y=get_max(a,m+1,r);
    if(x>y){
        return x;
    }
    return y;
}

int get_min(int a[],int l,int r){
    int m=(l+r)/2;
    if(r==l){
        return a[l];
    }
    int x=get_min(a,l,m);
    int y=get_min(a,m+1,r);
    if(x>y){
        return y;
    }
    return x;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Max = %d and Min = %d\n",get_max(a,0,n-1),get_min(a,0,n-1));
    return 0;
}
