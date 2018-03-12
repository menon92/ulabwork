```py
QuickSort(A, start, end):
	if start < end:
		pindex = partition(A, start, end)
		QuickSort(A, start, pindex - 1)
		QuickSort(A, pindex + 1, end)

partition(a, start, end):
	pivot = A[end]
	pindex = start

	for i = 0 to end - 1:
		if A[i] <= pivot:
			swap(A[i], A[pindex])
			pindex += 1
	swap(A[pindex], A[end])
	return pindex
```
