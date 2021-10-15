/*
Problem:- Knapsack Problem (Greedy Approach)
Author:- The_King

Input Format:-

    .The input contains of 3 lines

    .The first line of input contains two integers n and w representing the number of items and max weight the bag can hold
    .The second line contains n space separated integers where i-th number represent the weight of the i-th bag
    .The third line contains n space separated integers where i-th number represent the value of the i-th bag

Output Format:-

    .The output contains of 2 lines

    .The first line contains a single Integer representing th maximum profit
    .The second line contains n space separated numbers where i-th number represent the amount of the i-th item taken

Sample input:-
    3 20
    18 15 10
    25 20 15

sample output:-
    28.888889
    1.000000 0.555556 0.000000

*/


//Code:-

#include<stdio.h>

int main(){
	int n,w;
	scanf("%d %d",&n,&w);
	float wts[n],r[n];
	int val[n];
	float max_profit = 0;
	float t;
	for(int i=0;i<n;i++){
		scanf("%f",&wts[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&val[i]);
	}
	for(int i=0;i<n;i++){
		r[i]=val[i]/wts[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(r[i]<r[j]){
				t=r[i];
				r[i]=r[j];
				r[j]=t;
				t=wts[i];
				wts[i]=wts[j];
				wts[j]=t;
				t=val[i];
				val[i]=val[j];
				val[j]=t;
			}
		}
	}
	float taken[n];
	for(int i=0;i<n;i++){
		taken[i]=0;
	}
	for(int i=0;i<n;i++){
		if(w>=wts[i]){
			max_profit=max_profit+val[i];
			w-=wts[i];
			taken[i]=1;
		}
		else{
			max_profit=max_profit+r[i]*w;
			taken[i]=w/wts[i];
			w=0;
			break;
		}
	}

	printf("%f\n",max_profit);
	for(int i=0;i<n;i++){
        printf("%f ",taken[i]);
	}
	printf("\n");

	return 0;
}

