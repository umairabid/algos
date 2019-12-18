#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long number_of_nodes;
    long number_of_edges;
    long number_of_sets;
    long matrix_size;
    
    cin >> number_of_nodes;
    cin >> number_of_sets;
    number_of_edges = number_of_nodes - 1;
    matrix_size = number_of_nodes + 1;

    vector<vector<long>> matrix(matrix_size, vector<long>(matrix_size, INT16_MAX));
    vector<vector<long>> sets;

    int count = 0;
    while(count < number_of_edges) {
        long node1;
        long node2;
        cin >> node1;
        cin >> node2;
        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;
        count ++;
    }

    count = 0;
    while(count < number_of_sets) {
        long set_size;
        vector<long> set;
        cin >> set_size;
        for(long i = 0; i < set_size; i++) {
            long element;
            cin >> element;
            set.push_back(element);
        }
        sets.push_back(set);
        count++;
    }

    for(long j = 1; j < matrix_size; j++) {
        matrix[j][j] = 0;
    }

    /** Actual Solution Starts **/
    for(long k = 1; k < matrix_size; k++) {
        for(long i = 1; i < matrix_size; i++) {
            for(long j = 1; j < matrix_size; j++) {
                long prev = matrix[i][j];
                long next = matrix[i][k] + matrix[k][j];
                matrix[i][j] = prev < next ? prev : next;
            }
        }
    }

    for(long i = 0; i < sets.size(); i++) {
        if(sets[i].size() > 1) {
            long sum = 0;
            vector<pair<long, long>> pairs;
            for(long j = 0; j < sets[i].size() ; j++) {
                for(long k = j + 1; k < sets[i].size() ; k++) {
                    pairs.push_back(pair<long, long>{sets[i][j], sets[i][k]});
                }
            }
            for(long m = 0; m < pairs.size(); m++) {
                long dist = matrix[pairs[m].first][pairs[m].second];
                //cout << pairs[m].first << " " << pairs[m].second << " " << dist << "\n";
                //cout << sum << " + " << pairs[m].first * pairs[m].second * dist << "\n";
                sum = sum + ((pairs[m].first * pairs[m].second) * dist);
                //cout << "current sum: " << sum << endl;
            }
            cout << sum % 1000000007 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    /** Actual Solution Ends **/

    /* for(int i = 1; i < matrix_size; i++) {
        for(int j = 1; j < matrix_size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    } */


    /* for(int i = 0; i < sets.size(); i++) {
        for(int j = 0; j < sets[i].size() ; j++) {
            cout << sets[i][j] << " ";
        }
        cout << "\n";
    } */

    return 0;
}
