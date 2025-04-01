// https://codeforces.com/problemset/problem/2091/E

#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n,vector<int>& prime)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    // vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {


        if (prime[p] == true) {
            
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    // for (int p = 2; p <= n; p++)
    //     if (prime[p])
    //         cout << p << " ";
}

int main() {
    vector<int> prime(10000001,true);
    SieveOfEratosthenes(10000000,prime);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int ans = 0;
        for(int i=2;i<=n;i++){
            if(prime[i]) ans = ans + (n/i);
        }
        cout<<ans<<endl;
    }
	// your code goes here

}
