//https://codeforces.com/problemset/problem/1931/E

#include<bits/stdc++.h>
using namespace std;

int numberOfDigits(int n){
    int count = 0;
    while(n){
        count++;
        n = n/10;
    }
    return count;
}

int numberOfZeroesAtEnd(int n){
    int count = 0;
    while(n%10==0 and n>0){
       count++;
       n = n/10;
    }
    return count;
}

int main(){
    int t;cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int m;cin>>m;
        vector<int> vec(n,0);
        for(int i=0;i<n;i++) cin>>vec[i];

        int totalDigits=0;
        vector<int> numberOfZeroes(n,0);
        for(int i=0;i<n;i++){
            totalDigits += numberOfDigits(vec[i]);
            numberOfZeroes[i] = numberOfZeroesAtEnd(vec[i]);
        }

        sort(numberOfZeroes.begin(),numberOfZeroes.end());
        reverse(numberOfZeroes.begin(),numberOfZeroes.end());
        int numberOfRemovalDigits = 0;
        for(int i=0;i<n;i=i+2){
            numberOfRemovalDigits += numberOfZeroes[i];
        }
        //cout<<totalDigits<<" "<<numberOfRemovalDigits<<endl;
        totalDigits -= numberOfRemovalDigits;
        if(totalDigits>m){
           cout<<"Sasha\n";
        }
        else cout<<"Anna\n";
    }
    
}