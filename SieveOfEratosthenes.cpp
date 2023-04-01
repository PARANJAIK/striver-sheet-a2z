// Q) Count number of primes less than n -> https://leetcode.com/problems/count-primes/description/

    // Ans) 

    // i) Sieve of Eratosthenes:  O(NloglogN) time complexity

    int countPrimes(int n) {
        vector<bool> prime(n,true);
        if(n == 0 || n==1) return 0;
        prime[0] = prime[1] = false;
        int ans = 0;
        for(int i=2;i<n;i++){
            if(prime[i] == true){
                ans++;
                for(int j=2*i;j<n;j+=i){
                    prime[j] = false;
                }
            }
        }
        return ans;
    }
