//https://codeforces.com/contest/2067/problem/C

#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;

bool is7present(long long int x){
    while(x){
        if(x%10==7) return true;
        x = x/10;
    }
    return false;
}

int maxElement(long long int x){
    int k = 0;
    while(x){
        int r = x%10;
        k = max(k,r);
        x = x/10;
    }
    return k;
}

void solve(){
    long long int n;
    cin>>n;
    if(is7present(n)) {
        cout<<0<<endl;
        return;
    }
    int steps  = INT_MAX;
    for(int k=1;k<=9;k++){
        long long int temp = n - k;
        int st = 7;
        while(temp){
            st = min(st,(mp[temp%10]));
            temp = temp/10;
        }
        if(st<=k){
            steps = min(steps,k);
        }
    }
    cout<<steps<<endl;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    mp[0]=7;
	    mp[1]=6;
	    mp[2]=5;
	    mp[3]=4;
	    mp[4]=3;
	    mp[5]=2;
	    mp[6]=1;
	    mp[7]=0;
	    mp[8]=9;
	    mp[9]=8;
	    solve();
	}

}
