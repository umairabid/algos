#include <iostream>
#include <vector> 

using namespace std;

vector<int> reverseArray(vector<int> a) {
    vector<int> reversed;
    for(auto i = a.rbegin(); i != a.rend(); i++) {
        reversed.push_back(*i);
    }
    return reversed;
}


int main() {
	vector<int> a;
	for(int i = 1; i < 5; i++) {
		a.push_back(i);
	}
	vector<int> output = reverseArray(a);
	for(auto i = output.begin(); i != output.end(); i++) {
        cout << *i << "\t";
    }
    cout << "\n";
	return 0;
}