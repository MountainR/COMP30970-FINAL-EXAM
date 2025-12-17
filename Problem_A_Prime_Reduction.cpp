// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> PRIMES;

// generate all primes
vector<int> eratosthenes(int n){
    bool *isMarked = new bool[n+1];
    memset(isMarked, 0, n+1);
    vector<int> primes;
    
    int i = 2;
    for(; i*i <= n; ++i)
        if (!isMarked[i]) {
            primes.push_back(i);
            for(int j = i; j <= n; j += i)
                isMarked[j] = true;
        }
    for (; i <= n; i++)
        if (!isMarked[i])
            primes.push_back(i);
    return primes;
}

// check if x is prime
bool isPrime(int x){
    return find(PRIMES.begin(), PRIMES.end(), x) != PRIMES.end();
}
// find x's prime factors
// prime reduction


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    

    return 0;
}