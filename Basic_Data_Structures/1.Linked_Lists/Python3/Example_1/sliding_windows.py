#from numpy.random import rand 		for testing with large sizes
def sliding_window(K,arr):
	sliding_window,first_index =0.0,0
	result = []
	cumsum =0 
	for i,x in enumerate(arr):
		cumsum += x
		if i >= K-1:			
			result.append(cumsum/K)
			cumsum -= arr[first_index]
			first_index += 1 
	return result

if __name__== "__main__":
    result = sliding_window(5, [1, 3, 2, 6, -1, 4, 1, 8, 2])
    #result = sliding_window(10, rand(10000000))		for testing with large sizes
    print("Averages of subarrays of size K: " + str(result))
