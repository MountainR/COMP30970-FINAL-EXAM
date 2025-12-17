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
        vector<int> x_cor, y_cor;
        cin >> x_size >> y_size >> x_start >> y_start >> b_size;
        for(int j = 0; j < b_size; ++j){
            int x, y;
            cin >> x >> y;
            x_cor.push_back(x);
            y_cor.push_back(y);
        }
        
        sort(x_cor.begin(), x_cor.end());
        sort(y_cor.begin(), y_cor.end());
        // cout << x_cor[b_size-1] << " " << yb[b_size-1];
        int x_min = x_cor[0], x_max = x_cor[b_size-1];
        int y_min = y_cor[0], y_max = y_cor[b_size-1];

        int dis = 0;
        // determine the relative position of Karel
        // If Karel is surrounded by beepers
        if(x_start > x_min && x_start < x_max && y_start > y_min && y_start < y_max){
            // cout << "in";
            dis = (x_max - x_min + y_max - y_min) * 2;
            // find min start direction
            int minStart = INT_MAX;
            vector<int> edgeDis = {x_start - x_min, x_max - x_start, y_start - y_min, y_max - y_start};
            sort(edgeDis.begin(), edgeDis.end());
            dis += edgeDis[0] * 2;
        }
        else{
            // add Karel to x_cor, y_cor
            x_cor.push_back(x_start);
            y_cor.push_back(y_start);
            sort(x_cor.begin(), x_cor.end());
            sort(y_cor.begin(), y_cor.end());
            // update min, max
            x_min = x_cor[0];
            x_max = x_cor[b_size];
            y_min = y_cor[0];
            y_max = y_cor[b_size];
            // cout << x_min << x_max << 
            dis = (x_max - x_min + y_max - y_min) * 2;

        }
        cout << dis;
        
    }

    return 0;
}