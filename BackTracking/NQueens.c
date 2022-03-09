#include<stdio.h>
#include<stdlib.h>

int flag=0;

void printBoard(int ans[],int n){
    printf("Solution-%d:\n",flag);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ans[i]==j){
                printf("Q ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void NQueens(int ans[],int n,int curr){
    int f=0;
    for(int j=0;j<n;j++){
        f=0;
        for(int k=0;k<curr;k++){
            if(j==ans[k] || abs(curr-k)==abs(j-ans[k])){
                f=1;
                break;
            }
        }
        if(f==0){
            ans[curr]=j;
            if(curr==n-1){
                flag++;
                printBoard(ans,n);
            }
            else{
                NQueens(ans,n,curr+1);
            }
        }
    }
}


int main(){
    int n;
    printf("Enter size of the chess board: ");
    scanf("%d",&n);
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=-1;
    }
    NQueens(ans,n,0);
    if(flag==0){
        printf("There is no solution\n");
    }
}
