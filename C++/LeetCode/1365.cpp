#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> nums = { 6,5,4,8 };
    vector<int> sortedNums(nums);
    vector<int> output(nums.size());
    unordered_map<int, int> smallerNums;
    int maxIndex = nums.size() - 1;

    sort(sortedNums.begin(), sortedNums.end(), [&](int a, int b) { return a > b; });

    for(int i = 0; i <= maxIndex; i++) {
        int nextIndex = i + 1;
        if( nextIndex <= maxIndex && (sortedNums[i] != sortedNums[nextIndex] || i == maxIndex)) {
            smallerNums[sortedNums[i]] = maxIndex - i;
        }
    }

    for(int i = 0; i <= maxIndex; i++) {
        output[i] = smallerNums[nums[i]];
    }

    for(int i = 0; i <= maxIndex; i++) {
        cout << output[i] << "\t";
    }

    return 0;
}