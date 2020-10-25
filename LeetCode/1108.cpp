#include <iostream>
#include <vector>

using namespace std;

int main() {
    string address = "255.100.50.0";

    string sub1 = ".";
    string sub2 = "[.]";
    std::size_t pos;
    int i = 0;
    while (address[i] != '\0') {
        cout << address[i] << " ";
        if (address[i] == '.') {
            address.replace(i, sub1.size(), sub2);
            i = i + sub2.size();
        } else {
            i++;
        }
        
    }
    cout << endl;
    cout << address;
    cout << endl;

    return 0;
}
