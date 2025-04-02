//https://codeforces.com/problemset/problem/2072/D

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    vector<int> vec(n);
    
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    
    vector<int> inversion(n);
    vector<int> reverseInversion(n);
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=i+1;j<n;j++){
            if(vec[i]>vec[j]) count++;
        }
        inversion[i] = count;
        reverseInversion[i] = n - count - i - 1;
    }
    
    //for(auto it : inversion) cout<<it<<" ";cout<<endl;
    
    pair<int,int> p = {0,0};
    int maxi = 0;
    
    //for(auto it : inversion) cout<<it<<" ";cout<<endl;
    
    int index = 0;
    int l=0,r=0;
    
    for(int i=0;i<n;i++){
        int cnt_g=0,cnt_l=0;
        for(int j=i+1;j<n;j++){
            if(vec[i]<vec[j]) cnt_g++;
            if(vec[i]>vec[j]) cnt_l++;
            if(maxi>cnt_g-cnt_l){
            maxi = cnt_g-cnt_l;
            l = i;
            r = j;
           }
        }
        // if(maxi>cnt_g-cnt_l){
        //     maxi = cnt_g-cnt_l;
        //     l = i;
        //     r = j;
        // }
    }
//     2 7
// 2 4
// 1 8
// 4 6
// 1 2
// 1 4
// 1 3
// 2 3
// 5 5
    cout<<l+1<<" "<<r+1<<endl;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
