#include <iostream>
#include<string>
#include <vector>
#include <map>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
	vector<int> matches;
	map<string, int> strings_sums;
	map<string, int>::iterator it;

	for(int i = 0; i < strings.size(); i++) {
		it = strings_sums.find(strings[i]);
		if(it == strings_sums.end()) {
			strings_sums.insert(pair<string, int>(strings[i], 1));
		} else {
			(*it).second = (*it).second + 1;
		}
	}

	for(int i = 0; i < queries.size(); i++) {
		it = strings_sums.find(queries[i]);
		if(it == strings_sums.end()) {
			matches.push_back(0);
		} else {
			matches.push_back((*it).second);
		}
	}

	return matches;
}

int main() {
	/*map<int, string> users;
	users.insert(pair<int, string>(1, "Umair"));
	cout << users.at(1) << "\n";*/
	vector<string> strings{"def", "de", "fgh"};
	vector<string> queries{"de", "lmn", "fgh"};
	vector<int> matches = matchingStrings(strings, queries);
	for(int i = 0; i < matches.size(); i++) {
		cout << matches[i] << "\n";
	}
	return 0;
}
