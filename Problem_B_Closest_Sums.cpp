// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int closestSum(const int &query, const vector<int> &numbers){
    int minDistance = INT_MAX;
    int sum;
    for(int i = 0; i < numbers.size(); ++i){
        for(int j = i + 1; j < numbers.size(); ++j){
            if(abs(query - numbers[i] - numbers[j]) < minDistance){
                minDistance = abs(query - numbers[i] - numbers[j]);
                sum = numbers[i] + numbers[j];
            }
        }
    }

    return sum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, counter=1;

    while(cin >> n){
        // get inputs
        vector<int> numbers(n);
        for(int i = 0; i < n; ++i){cin >> numbers[i];}
        cin >> m;
        vector<int> queries(m);
        for(int i = 0; i < m; ++i){cin >> queries[i];}

        // sort numbers
        sort(numbers.begin(), numbers.end());

        // result
        cout << "Case " << counter << ": \n";
        // Closest sum
        for(int i = 0; i < m; ++i){
            cout << "Closest sum to " << queries[i] << " is " << closestSum(queries[i], numbers) << ".\n"; 
        }


        ++counter;
    }

    return 0;
}