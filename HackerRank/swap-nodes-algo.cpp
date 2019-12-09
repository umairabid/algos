#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;


vector<vector<int>> getNodesByLevel(vector<vector<int>> tree, int root) {
	int level = 1;
	vector<vector<int>> nodes;
	nodes.push_back(vector<int>{});
	nodes.push_back(vector<int>{root});

	while(nodes[level].size() > 0) {
		int nextLevel = level + 1;
		nodes.push_back(vector<int>{});
		for(int i = 0; i < nodes[level].size(); i++) {
			if(tree[nodes[level][i]][0] != -1) {
				nodes[nextLevel].push_back(tree[nodes[level][i]][0]);
			}
			if(tree[nodes[level][i]][1] != -1) {
				nodes[nextLevel].push_back(tree[nodes[level][i]][1]);
			}
		}
		level = nextLevel;
	}

	return nodes;
}

vector<int> getInorderTraversal(vector<vector<int>> tree, int root) {
	stack<int> s;
	vector<int> ordered;
	unordered_map<int, bool> visited;

	s.push(root);

	while(!s.empty()) {
		int node = s.top();
		visited[node] = true;
		

		bool is_left_visited = visited.find(tree[node][0]) != visited.end();
		bool has_left = tree[node][0] != -1;
		bool is_right_visited = visited.find(tree[node][1]) != visited.end();
		bool has_right = tree[node][1] != -1;
			/*cout << node << "\n";
			cout << "has_left && has_right: " << has_left << " - " << has_right << "\n";
			cout << "is_left_visited && is_right_visited: " << is_left_visited << " - " << is_right_visited << "\n";*/

		if(has_left && has_right) {
			
			if(!is_left_visited && !is_right_visited) {
				s.push(tree[node][0]);
			} else if(!is_right_visited && is_left_visited) {
				ordered.push_back(node);
				s.push(tree[node][1]);
			} else if(is_right_visited && !is_left_visited) {
				cout << "This shouldn't be called \n";
			} else if(is_left_visited && is_right_visited) {
				s.pop();
			}


		} else if(!has_left && has_right) {
			if(!is_right_visited) {
				ordered.push_back(node);
				s.push(tree[node][1]);
			} else {
				s.pop();
			}

		} else if(has_left && !has_right) {	

			if(!is_left_visited) {
				s.push(tree[node][0]);
			} else {
				ordered.push_back(node);
				s.pop();
			}

		} else if(!has_right && !has_left) {
			ordered.push_back(node);
			s.pop();
		}
	}

	return ordered;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
	indexes.insert(indexes.begin(), vector<int>{});
	vector<vector<int>> answers;
	int root = 1;
	vector<vector<int>> nodes = getNodesByLevel(indexes, root);
	cout << "levels count is: " << nodes.size() << endl;

	for(int i = 0; i < nodes.size(); i++) {
		for(int j = 0; j < nodes[i].size(); j++) {
			cout << nodes[i][j] << "\t";
		}
		cout << "\n";
	}

	for(int i = 0; i < queries.size(); i++) {
		int k = queries[i];
		int query = k;
		int multiple = 2;
		while(query < nodes.size()) {
			cout << "query is: " << query << "\n";
			for(int j = 0; j < nodes[query].size(); j++) {
				int node = nodes[query][j];
				int temp = indexes[node][0];
				indexes[node][0] = indexes[node][1];
				indexes[node][1] = temp;
			}
			query = multiple * k;
			multiple++;
			
		}
		vector<int> ordered = getInorderTraversal(indexes, root);
		/*for(int i = 0; i < ordered.size(); i++) {
			cout << ordered[i] << " ";
		}
		cout << "\n";*/
		answers.push_back(ordered);
	}
	cout << "answers count is: " << answers.size() << endl;
	for(int i = 0; i < answers.size(); i++) {
		cout << "answer number is " << (i + 1) << "\n";
		for(int j = 0; j < answers[i].size(); j++) {
			cout << answers[i][j] << " ";
		}
		cout << "\n";
	}
	return answers;
}

vector<int> explodeStringBySpace(string s) {
	stringstream ssin(s);
	vector<int> nodes;
	string node;
	while (ssin.good()){
		ssin >> node;
        nodes.push_back(stoi(node));
    }
    return nodes;
}


int main() {
	/*vector<int> nodes1{2, 3};
	vector<int> nodes2{4, -1};
	vector<int> nodes3{5, -1};
	vector<int> nodes4{6, -1};
	vector<int> nodes5{7, 8};
	vector<int> nodes6{-1, 9};
	vector<int> nodes7{-1, -1};
	vector<int> nodes8{10, 11};
	vector<int> nodes9{-1, -1};
	vector<int> nodes10{-1, -1};
	vector<int> nodes11{-1, -1};
	vector<vector<int>> indexes{nodes1, nodes2, nodes3, nodes4, nodes5, nodes6, nodes7, nodes8, nodes9, nodes10, nodes11};
	vector<int> queries{2, 4};*/
	vector<int> nodes1{2, 3};
	vector<int> nodes2{-1, -1};
	vector<int> nodes3{-1, -1};
	vector<vector<int>> indexes{nodes1, nodes2, nodes3};
	vector<int> queries{1, 1};	

	/*ifstream infile("input04.txt");
	string line;
	int line_count = 0;
	int nodes_count = 0;
	int queries_count = 0;

	vector<vector<int>> indexes;
	vector<int> queries;

	while(getline(infile, line)) {
		if(line_count == 0) {
			nodes_count = stoi(line);
		}

		if(line_count > 0 && line_count <= nodes_count) {
			indexes.push_back(explodeStringBySpace(line));
		}

		if(line_count > nodes_count) {
			if(line_count == (nodes_count + 1)) {
				queries_count = stoi(line);
			} else {
				queries.push_back(stoi(line));
			}
		}
		line_count++;
	}*/


	swapNodes(indexes, queries);
	return 0;
}