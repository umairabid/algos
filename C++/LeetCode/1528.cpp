#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s = "aaiougrt";
    vector<int> indices = {4,0,2,6,7,3,1,5};

    string output(s);

    for(int i = 0; i < indices.size(); i++) {
        output[indices[i]] = s[i];  
    }

    for(int i = 0; i < indices.size(); i++) {
        //cout << output[i];
    }

        
    cout << output;
    
}