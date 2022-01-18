#include <iostream>
#include <vector>
//needed to generate random numbers with a choosed distribution
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

class AverageOfSubarrayOfSizeK {
	public:
	static vector<double> findAverages(int K,const vector<int>& arr) {
		vector<double> result(arr.size() - K + 1);
		double sliding =0;
		unsigned int sliding_int =0;
		for(unsigned int i =0;i <= arr.size() - 1; i++){
			sliding += arr[i];
			if (i >= (unsigned int)(K -1)){
				result[sliding_int]=sliding/K;

				sliding -= arr[sliding_int];
				sliding_int +=1;
			}
		}
		return result;
	}
};

int main(int argc, char* argv[]) {
	
	/////Random Number Generator

	// First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist {1, 100};
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };
	vector<int> vec;
	if (argc >1){
		cout << "you add args:" << argv[1] << endl;
		size_t size = atoi(argv[1]);
		vec.resize(size);
		cout << vec.size()<< endl;
		generate(begin(vec), end(vec), gen);
	}
	else{
		vec.resize(9);
		vec[0] =1;
		vec[1] = 3;
		vec[2] = 2;
		vec[3] = 6;
		vec[4] = -1;
		vec[5] = 4;
		vec[6] = 1;
		vec[7] = 8;
		vec[8] = 2;

	}
    /////Random Number Generator
	vector<double> result = AverageOfSubarrayOfSizeK::findAverages(5, vec);
	cout << "Averages of subarrays of size K: ";
	for (double d : result) {
		cout << d << " ";
	}
	cout << endl;
}
