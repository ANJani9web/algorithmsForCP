//https://codeforces.com/problemset/problem/1133/D

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>  a,b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        b.push_back(y);
    }
    
    map<pair<int,int>,int> mp;
    int zero = 0;
    for(int i=0;i<n;i++){
        // float bi = -1*(b[i] * 1.0);
        // float ai = a[i] * 1.0;
        
        if(a[i]==0 and b[i]!=0) continue;
        if(a[i]==0 and b[i]==0){
            zero++;
            continue;
        }
        int x = a[i];
        int y = b[i];
        int z = __gcd(abs(x),abs(y));
        if(x<0){
            x = x * (-1);
            y = y * (-1);
            x = x/z;
            y = y/z;
            mp[{x,y}]++;
        }
        else{
            x = x/z;
            y = y/z;
            mp[{x,y}]++;
        }
        // float ci = bi / ai;
        // mp[ci]++;
    }
    int count = 0;
    for(auto it = mp.begin();it!=mp.end();it++){
        int freq = it->second;
        count = max(count,freq);
    }
    cout<<count+zero<<endl;
    
}

int main() {
	// your code goes here
	int x = 2;
	float a = x*1.0;
	float b = 25.0;
	float c = a/b;
	//cout<<c<<endl;
    int t;
    t=1;
    while(t--){
        solve();
    }
}
