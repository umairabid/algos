#include <iostream>
#include <vector> 

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int maxSum = INT_MIN;
    int currentSum = INT_MIN;
    for(int i = 0; i < arr.size() - 2; i++) {
    	vector<int> row = arr[i];
    	for(int j = 0; j < row.size() - 2; j++) {
    		currentSum = arr[i][j] +
	    			arr[i][j + 1] +
	    			arr[i][j + 2] +
	    			arr[i + 1][j + 1] +
	    			arr[i + 2][j] +
	    			arr[i + 2][j + 1] +
	    			arr[i + 2][j + 2];
    		if(currentSum > maxSum) {
    			maxSum = currentSum;
    		}
    	}
    }
    return maxSum;
}

int main() {
	vector<int> row1{1, 2 ,3 ,4 ,5};
	vector<int> row2{1, 2 ,3 ,4 ,5};
	vector<int> row3{1, 2 ,3 ,4 ,5};
	vector<int> row4{1, 2 ,3 ,4 ,5};
	vector<int> row5{1, 2 ,3 ,4 ,5};
	vector<vector<int>> matrix{row1, row2, row3, row4, row5};
	cout << hourglassSum(matrix);
	cout << "\n";
	return 0;
}