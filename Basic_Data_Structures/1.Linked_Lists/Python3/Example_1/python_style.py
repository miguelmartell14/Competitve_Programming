from numpy import cumsum
#from numpy.random import rand for testing with large sizes
def python_style(K,arr):
	return (cumsum(arr)[K-1:] - cumsum(([0] + arr[:len(arr)-K+1])))/K
if __name__== "__main__":
    result = python_style(5, [1, 3, 2, 6, -1, 4, 1, 8, 2])
    #result = python_style(10, rand(10000000)) for testing with large sizes
    print("Averages of subarrays of size K: " + str(result))