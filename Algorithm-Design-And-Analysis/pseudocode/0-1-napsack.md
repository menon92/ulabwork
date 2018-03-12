```py
dp[N][W]
cost[N]
weight[N]
CAP = MAX_CAP

func(i, w):
	if i == N + 1:
		return 0
	if dp[i][w] != -1:
		return dp[i][w]

	profit1 = profit2 = 0
	if w + weight[i] <= CAP:
		profit1 = cost[i] + func(i + 1, w + weight[i])
	else:
		profit2 = cost[i] + func(i + 1, w)

	dp[i][w] = max(profit1, profit2)
	return dp[i][w]
```
