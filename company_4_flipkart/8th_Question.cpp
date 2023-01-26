/*question details
name: closest-prime-numbers-in-range
link: https://leetcode.com/problems/closest-prime-numbers-in-range/
submission link: https://leetcode.com/problems/closest-prime-numbers-in-range/submissions/885467855/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPrime(int num){
        if(num == 1) return false;

        for(int i=2; i<=sqrt(num); i++){
            if(num % i == 0) return false;  
        }

        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for(int i=left; i<=right; i++){
            if(isPrime(i)) primes.push_back(i);
        }

        // for(int x: primes) cout<<x<<" ";

        vector<int> ans (2, -1);
        int val = INT_MAX;

        if(primes.size() <= 1) return ans;

        for(int i=0; i<primes.size()-1; i++){
            if(primes[i+1] - primes[i] < val){
                val = primes[i+1] - primes[i];
                ans[0] = primes[i];
                ans[1] = primes[i+1];
            }
        }
        return ans;
    }
};