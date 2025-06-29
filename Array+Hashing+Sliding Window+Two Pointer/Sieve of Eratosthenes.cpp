Given a positive integer n, calculate and return all prime numbers less than or equal 
to n using the Sieve of Eratosthenes algorithm.
A prime number is a natural number greater than 1 that has no positive divisors other
than 1 and itself.


class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<bool> prime(n+1,true);
        
        for(int p=2; p*p<=n; p++){
            if(prime[p]){
                
                for(int j=p*p; j<=n; j+=p){
                    prime[j]=false;
                }
                
            }
        }
        vector<int> ans;
        for(int i=2; i<=n; i++){
            if(prime[i]) ans.push_back(i);
        }
        return ans;
    }
};