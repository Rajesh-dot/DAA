#include<stdio.h>

int flag=0;

void print(int ans[],int n){
    flag++;
    printf("Solution-%d:\n",flag);
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}

void solve(int m,int values[], int ans[],int n,int curr, int pos){
    if(curr==m){
        print(ans,n);
    }
    if(curr>m || pos==n){
        return;
    }
    solve(m,values,ans,n,curr,pos+1);
    ans[pos]=1;
    solve(m,values,ans,n,curr+values[pos],pos+1);
    ans[pos]=0;
}

int main(){
    int n,m;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array values: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter value of m: ");
    scanf("%d",&m);
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    solve(m,a,ans,n,0,0);
    if(flag==0){
        printf("There is no solution\n");
    }
    return 0;
}
