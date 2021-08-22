#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> a = {2, 3, 5, 1, 3};
    vector<bool> b;
    b.resize(a.size());
    int extra = 3;
    int max = *max_element(a.begin(), a.end());

    transform(a.begin(), a.end(), b.begin(), [&](int x) { return (x + extra) >= max; });

    for(auto r: b) {
        cout << r;
    }

    return 0;
}