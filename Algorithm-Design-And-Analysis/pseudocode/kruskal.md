kruskal(G):
	T = 0
	for each v in G:
		make_set(v)
	for each (u, v) ordered by weight(u, v) increasing:
		if find_set(u) is not find_set(v):
			T = T U {u, v}
			union(u, v)
	return T