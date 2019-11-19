#include <iostream>
#include <vector> 

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int> > queries) {
	vector<vector<int> > sequences(n, vector<int>{});
	vector<int> answers;
	int lastAnswer = 0;
	
	for(int i = 0; i < queries.size(); i++) {
		int queriedIndex = (queries[i][1] ^ lastAnswer) % n;
		if(queries[i][0] == 1) {
			sequences[queriedIndex].push_back(queries[i][2]);
		}
		if(queries[i][0] == 2) {
			lastAnswer = sequences[queriedIndex][queries[i][2] % sequences[queriedIndex].size()];
			answers.push_back(lastAnswer);
		}
	}

	return answers;
}

int main() {
	vector<int> row1{1, 0 ,5};
	vector<int> row2{1, 1 ,7};
	vector<int> row3{1, 0 ,3};
	vector<int> row4{2, 1 ,0};
	vector<int> row5{2, 1 ,1};
	vector<vector<int>> matrix{row1, row2, row3, row4, row5};
	vector<int> answers = dynamicArray(2, matrix);
	for(int j = 0; j < answers.size(); j++) {
		cout << answers[j] << "\n";
	}
	return 0;
}
