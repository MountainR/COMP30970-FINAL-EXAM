// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> PRIMES;
vector<int> PRIME_FACTORS_SUM;

// generate all primes
vector<int> eratosthenes(const int &n){
    // bool *isMarked = new bool[n+1];
    // memset(isMarked, 0, n+1);
    vector<bool> isMarked(n+1, 0);
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
vector<int> primeFactors(const int &x){
    // x should be a composite number
    vector<int> res;
    int i = 0, num = x;
    while(num > 1){
        if(num % PRIMES[i] == 0){
            res.push_back(PRIMES[i]);
            num /= PRIMES[i];
            // i = 0;      // duplicate factors. Keep current i.
        }
        else {
            ++i;
        } 
    }
    return res;
}
// prime reduction
pair<int, int> primeReduction(const int &x) {
    int counter = 1, num = x;

    while(!isPrime(num)){
        int sum = 0;
        if(PRIME_FACTORS_SUM[num] != 0){
            sum = PRIME_FACTORS_SUM[num];
        }
        else{
            vector<int> pf = primeFactors(num);
            // vector<int> pf = PRIME_FACTORS[num];
            for(int i = 0; i < pf.size(); ++i){
                sum += pf[i];
            }
            PRIME_FACTORS_SUM[num] = sum;
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
    vector<int> sequence;
    int num, max = 2;
    while(cin >> num){
        if(num != 4){
            sequence.push_back(num);
        }
        if(max < num){
            max = num;
        }
    }
    // cout << max;
    // generate primes and prime factors
    PRIMES = eratosthenes(max);
    PRIME_FACTORS_SUM.resize(max, 0);
    // for(int i = 0; i < max; ++i){
    //     PRIME_FACTORS.push_back(primeFactors(i));
    // }

    for(int i = 0; i < sequence.size(); ++i){
        pair<int, int> res = primeReduction(sequence[i]);
        cout << res.first << " " << res.second << "\n";
    }
    
    

    return 0;
}