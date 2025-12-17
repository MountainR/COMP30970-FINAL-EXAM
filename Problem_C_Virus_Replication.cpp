// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    if(s1 == s2){
        cout << 0;
        exit(0);
    }

    int lhs = 0, rhs = 0;

    while(s1[lhs] == s2[lhs]){
        ++lhs;
        // cout << lhs << " ";

    }
    while(*(s1.end()-rhs) == *(s2.end()-rhs)){
        ++rhs;
        // cout << rhs << " ";
    }

    cout << s2.size() - lhs - rhs + 1;
    
    

    return 0;
}