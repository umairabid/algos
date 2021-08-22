#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    
    string J = "z";

    string S = "ZZ";

    unordered_map<char, bool> jewels;

    int jewelsCount = 0;

    for_each(J.begin(), J.end(), [&](char j){ jewels[j] = true; });

    for_each(S.begin(), S.end(), [&](char s){ if (jewels[s]) jewelsCount++; });

    cout << jewelsCount;

    return 0;
}