//https://codeforces.com/problemset/problem/1110/B

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n,m,k;
    cin>>n>>m>>k;
    vector<long long int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    long long int ans = 0;
    int count = n;
    if(n==k){
        cout<<n<<endl;
        return 0;
    }
    priority_queue<pair<long long int,pair<int,int>>> pq;
    for(int i=0;i<n-1;i++){
        long long int diff = vec[i+1] -vec[i];
        pq.push({-diff,{i,i+1}});
    }
    vector<int> visited(n,0);
    while(count>k){
        long long int segmentLength = -pq.top().first;
        int index1 = pq.top().second.first;
        int index2 = pq.top().second.first;
        pq.pop();
        if(visited[index1]==1 or visited[index2]==1){
            ans = ans + segmentLength;
        }
        else ans = ans + segmentLength;
        visited[index1]=1;
        visited[index2]=1;
        //cout<<"The value of count is : "<<count<<" and the value of ans is : "<<ans<<endl;
        count--;
    }
    cout<<ans+k<<endl;
}