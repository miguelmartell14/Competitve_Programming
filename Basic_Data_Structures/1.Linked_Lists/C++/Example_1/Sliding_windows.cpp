#include <iostream>
#include <vector>

using namespace std;

class AverageOfSubarrayOfSizeK {
	public:
	static vector<double> findAverages(int K,const vector<int>& arr) {
		vector<double> result(arr.size() - K + 1);
		double sliding =0;
		unsigned int sliding_int =0;
		for(unsigned int i =0;i <= arr.size() - 1; i++){
			sliding += arr[i];
			cout << sliding << endl;
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
  vector<double> result = AverageOfSubarrayOfSizeK::findAverages(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
  cout << "Averages of subarrays of size K: ";
  for (double d : result) {
    cout << d << " ";
  }
	  cout << endl;
}
