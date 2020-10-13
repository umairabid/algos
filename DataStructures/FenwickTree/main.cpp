#include <iostream>
#include <vector>

using namespace std;

void update(vector<int> &arr, int index, int delta) {
    int idx = index + 1;
    while(idx <= arr.size()) {
        arr[idx - 1] = arr[idx - 1] + delta;
        idx = idx + (idx & -idx);
    }
}

int sum(vector<int> &arr, int index) {
    int idx = index + 1;
    int sum = 0;
    while(idx > 0) {
        sum += arr[idx - 1];
        idx = idx - (idx & -idx);
    }
    return sum;
}

int main() {
    vector<int> xs = {3, 0, 5, 6, 1, 2, 1, 3, 4, 6};
    vector<int> sums(xs.size());

    for(int i = 0; i < xs.size(); i++) {
        update(sums, i, xs[i]);
    }

    for(auto x : sums) {
        cout << x << endl;
    }

    cout << "----------------" << endl;

    cout << sum(sums, 9) << endl;

    return 0;
}