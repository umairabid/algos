#include <iostream>

using namespace std;

int reduceNumber(int num, int step) {
    cout << num << " : " << step << endl;
    if (num == 0) return step;
    if (num % 2 == 0) return reduceNumber(num / 2, ++step);
    else return reduceNumber(num - 1, ++step);
}

int main() {
    
    int num = 8;

    cout << reduceNumber(num, 0);

    return 0;
}