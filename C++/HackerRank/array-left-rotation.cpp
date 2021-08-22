#include <iostream>
#include <vector> 

using namespace std;

void rotateArrayRightByOne(vector<int> &a) {
	int lastReplaced = -1;	
	for(int i = 0; i < a.size(); i++) {
		if(lastReplaced > -1) {
			int temp = a[i];
			a[i] = lastReplaced;
			lastReplaced = temp;
		} else {
			lastReplaced = a[i];
			a[i] = a[a.size() - 1];
		}
		
	}
}

void rotateArrayLeftByOne(vector<int> &a) {
	int lastReplaced = -1;	
	for(int i = a.size() - 1; i >= 0; i--) {
		if(lastReplaced > -1) {
			int temp = a[i];
			a[i] = lastReplaced;
			lastReplaced = temp;
		} else {
			lastReplaced = a[i];
			a[i] = a[0];
		}
		
	}
}


vector<int> rotateArrayNTimes(int d, vector<int> a) {
	
	d = d > a.size() ? d & a.size() : d;
	vector<int> rotatedArray(a.size());
	for(int j = 0; j < a.size(); j++) {
		int shiftedIndex = j - d;
		shiftedIndex = shiftedIndex < 0 ? shiftedIndex + a.size() : shiftedIndex;
		rotatedArray[shiftedIndex] = a[j];
	}
	return rotatedArray;
}

int main() {
	vector<int> a{1, 2, 3, 4, 5};
	vector<int> answers = rotateArrayNTimes(4, a);
	for(int j = 0; j < answers.size(); j++) {
		cout << answers[j] << "\n";
	}
	return 0;
}