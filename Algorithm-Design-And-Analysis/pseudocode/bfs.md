```py
dfs(src):
	queue q
	visited[] = init all node as unvisited
	level[]

	q.push(src)
	visited[src] = true
	level[src] = 0

	while q is not empty:
		u = q.front()
		q.pop()
		for all edge from u to v:
			if visited[v] == false:
				visited[v] = true
				level[v] = level[u] + 1
				q.push(v)

```
