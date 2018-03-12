```py
dfs(src):
	stack s
	visited[] = init all node as unvisited

	s.push(src)
	visited[src] = true

	while s is not empty:
		u = s.top()
		s.pop()
		for all edge from u to v:
			if visited[v] == false:
				visited[v] = true
				s.push(v)
```
