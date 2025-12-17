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

    int cases;
    cin >> cases;
    for(int i = 0; i < cases; ++i) {
        // inputs
        int x_size, y_size, x_start, y_start, b_size;
        vector<int> xb, yb;
        cin >> x_size >> y_size >> x_start >> y_start >> b_size;
        for(int j = 0; j < b_size; ++j){
            int x, y;
            cin >> x >> y;
            xb.push_back(x);
            yb.push_back(y);
        }
        sort(xb.begin(), xb.end());
        sort(yb.begin(), yb.end());
        // cout << xb[b_size-1] << " " << yb[b_size-1];

        // determine the relative position of Karel
    }

    return 0;
}