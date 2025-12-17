// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// It is not easy to construct the graph. Each node is a vector with multiple edges. Besides, circle exists.

bool compare(const vector<int> &breads, const vector<int> &sorted){
    for(int i = 0; i < breads.size(); ++i){
        if(breads[i] != sorted[i]){return false;}
    }
    return true;
}

// search in a graph. dfs
bool isPossible(vector<int> &breads, const vector<int> &sorted){
    if(compare(breads, sorted)){return true;}   // base case
    else{

    }  
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // get inputs
    int N;
    cin >> N;
    vector<int> breads(N), sorted(N);
    for(int i = 0; i < N; ++i){
        cin >> breads[i];
    }
    for(int i = 0; i < N; ++i){
        cin >> sorted[i];
    }

    if(isPossible(breads, sorted)) cout << "Possible";
    else cout << "Impossible";

    return 0;
}