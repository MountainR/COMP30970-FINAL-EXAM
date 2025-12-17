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
    int lhs = 0, rhs = 0;

    while(s1[lhs] == s2[lhs]){
        ++lhs;
        cout << lhs << " ";

    }
    while(*(s1.end()-rhs) == *(s2.end()-rhs)){
        ++rhs;
        cout << rhs << " ";
    }
    
    

    return 0;
}