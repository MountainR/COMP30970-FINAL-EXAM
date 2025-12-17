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
    long long i = 0, num = x;
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
pair<long long, long long> primeReduction(const long long &x) {
    long long counter = 1, num = x;
    while(!isPrime(num)){
        vector<long long> pf = primeFactors(num);
        int sum = 0;
        for(int i = 0; i < pf.size(); ++i){
            sum += pf[i];
        }
        num = sum;
        ++counter;
    }
    pair<int, int> res = {num, counter};
    return res;
}

// main logic
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // inputs
    vector<long long> sequence;
    long long num, max = 2;
    while(cin >> num){
        if(num != 4){
            sequence.push_back(num);
        }
        if(max < num){
            max = num;
        }
    }
    // cout << max;
    // generate primes
    PRIMES = eratosthenes(max);

    for(int i = 0; i < sequence.size(); ++i){
        pair<long long, long long> res = primeReduction(sequence[i]);
        cout << res.first << " " << res.second << "\n";
    }
    
    

    return 0;
}