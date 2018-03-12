marge(array, array1, array2):
	array.clear()
	for i = 0, j = 0; i < array1.size() && j < array2.size():
		if array1[i] <= array2[j]:
			array.push_back(array[i])
			i++
		else if array[i] > array[j]:
			array.push_back(array[j])
			j++

	while i < array1.size():
		array.push_back(array1[i])
		i++

	while j < array2.size():
		array.push_back(array2[j])
		j++


marge_sort(array):
	if(array.size() > 1):
		array1 = array.begin() to array.begin() + array.size() / 2
		marge_sort(array1)
		
		array2 = array.begin() + array.size() / 2 to array.end()
		marge_sort(array2)

		marge(array, array1, array2)