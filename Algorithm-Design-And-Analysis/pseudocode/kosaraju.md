AdjList, AdjListT
visited[N]
vector S

kosaraju(u, pass):
	visited[u] = true
	if pass == 1:
		neighbor = AdjList[u]
	else:
		neighbor = AdjListT[u]
	for i = 0; i <= neighbor; i++:
		v = neighbor[i]
		if visited[v] == false:
			kosaraju(v, pass)
	S.push_back(u)

main():
	for all v in G:
		if visited[v] == false:
			kosaraju(v, 1)
	numSCC = 0
	set all node unvisited
	for i = S.size() - 1; i >= 0; i--:
		if visited[S[i]] == false:
			numSCC += 1
			kosaraju(S[i], 2)