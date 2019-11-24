#include <iostream>
#include <vector>

using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
	int start = 0;
	vector<long> d(n + 1);
	vector<long> ps(n + 1);
	long max = 0;

	for(int i = 0; i < queries.size(); i++) {
		int p = queries[i][0];
		int q = queries[i][1];
		int x = queries[i][2];

		if(p == 1) {
			start += x;
		} else {
			d[p - 1] += x;
		}


		if(q < n)
			d[q] -= x;
	}

	ps[1] = start;
	for(int i = 1; i < n; i++) {
		ps[i+1] = ps[i] + d[i];
	}

	for(int i =1; i <= n; i++) {
		if(ps[i] > max)
			max = ps[i];
	}

	return max;

}

int main() {
	vector<int> query_one{1, 2, 1};
	vector<int> query_two{2, 3, 3};
	vector<int> query_three{1, 3, 3};
	vector<vector<int>> queries{query_one, query_two, query_three};
	cout << arrayManipulation(3, queries) << "\n";
}

