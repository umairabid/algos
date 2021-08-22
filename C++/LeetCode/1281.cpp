#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 

using namespace std;

int main() {
    int n = 4421;
    vector<int> digits;

    while(n > 9) {
        int d = n % 10;
        digits.push_back(d);
        n = n / 10;
    }

    digits.push_back(n);
    int sum = accumulate(digits.begin(), digits.end(), 0, [&](int a, int b) { return a + b; });
    int prod = accumulate(digits.begin(), digits.end(),1, [&](int a, int b) { return a * b; });
    cout << prod - sum;
    return 0;
}