def knapSack(W, wt, val, n):
	dp = [0 for i in range(W+1)]
	for i in range(1, n+1):
		for w in range(W, 0, -1):
			if wt[i-1] <= w:
				dp[w] = max(dp[w], dp[w-wt[i-1]]+val[i-1])
	return dp[W]

n,k=map(int,input().split())
wt=list(map(int,input().split()))
val=list(map(int,input().split()))
print(knapSack(k,wt,val,n))
