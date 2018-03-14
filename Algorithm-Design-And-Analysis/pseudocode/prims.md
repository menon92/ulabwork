```py
process(u):
	taken[u] = true
	for j = 0; j < AdjList[j].size(); j++:
		ii = AdjList[u][j]
		if taken[ii.u] == false:
			pq.push(ii.u, ii.w)

prims():
	priority_queue pq
	process(0)
	while pq is not empty:
		ii = pq.top(), pq.pop()
		u = ii.u
		w = ii.w
		if taken[u] == false:
			mst_cost += w
			process(u)
```
