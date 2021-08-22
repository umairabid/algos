#include <iostream>
#include <vector>
#include <unordered_map> 

using namespace std;

int main() {
    vector<int> nums = {5,5,1,77,96,96,89,80,12,23,1,6,3,66,39,88,48,38,44,32,44,36,60,87,53,77,72,49,13,39,60,60,71,68,80,75,79,38,4,14,59,75,6,91,87,95,25,55,83,18,26,59,53,100,42,96,76,22,21,4,22,46,34,39,98,82,54,73,52,33,47,73,54,23,82,98,13,51,52,1,96,69,76};
    unordered_map<int, int> sums;
    int pairs = 0;

    for(int n : nums) {
        sums[n] += 1;
    }

    for(auto s: sums) {
        if (s.second > 1) {
            pairs += (s.second * (s.second - 1)) / 2;
        }
    }

    cout << pairs << endl;

    return 0;
}
