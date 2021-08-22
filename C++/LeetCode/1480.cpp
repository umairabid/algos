#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


int main() {
    vector<int> a = {1, 2, 3, 4};

    partial_sum(a.begin(), a.end(), a.begin());
}