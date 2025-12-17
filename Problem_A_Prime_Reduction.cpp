// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

vector<long long> PRIMES;

// generate all primes
vector<long long> eratosthenes(long long n){
    bool *isMarked = new bool[n+1];
    memset(isMarked, 0, n+1);
    vector<long long> primes;
    
    long long i = 2;
    for(; i*i <= n; ++i)
        if (!isMarked[i]) {
            primes.push_back(i);
            for(long long j = i; j <= n; j += i)
                isMarked[j] = true;
        }
    for (; i <= n; i++)
        if (!isMarked[i])
            primes.push_back(i);
    return primes;
}

// check if x is prime
bool isPrime(long long x){
    return find(PRIMES.begin(), PRIMES.end(), x) != PRIMES.end();
}

// find x's prime factors
vector<long long> primeFactors(long long x){
    // x should be a composite number
    vector<long long> res;
    int i = 0, num = x;
    while(num > 1){
        if(num % PRIMES[i] == 0){
            res.push_back(PRIMES[i]);
            num /= PRIMES[i];
            i = 0;      // duplicate factors
        }
        else {
            ++i;
        }
        
    }
    return res;
}
// prime reduction


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // generate primes
    PRIMES = eratosthenes(100000);
    
    

    return 0;
}