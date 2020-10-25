#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums = {1,1,2,2};
    vector<int> pairs;
    int n = 2;

    for(int i = 0, j = n; i < n; i++, j++) {
        cout << i << " : " << j << endl;
        pairs.push_back(nums[i]);
        pairs.push_back(nums[j]);
    }

    for(int n : pairs) {
        cout << n << " " << endl;
    }
    
    return 0;
}
