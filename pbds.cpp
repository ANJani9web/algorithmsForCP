// ordered_set:

// -> A specialized data structure from PBDS that supports:
//    1) Order Statistics:
//         order_of_key(x): Returns the number of elements strictly smaller than x.
//    2) Find by Order:
//         find_by_order(k): Returns the k-th smallest element in the set.
//     It works like a balanced binary search tree and supports operations in O(log⁡n)
// -> And we have to use the following format for that

// For more reference: https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
int t, n;
 
vector<pair<int, int>> arr;
 
long long ans;
 
ordered_set st;
 
void solve(){
    cin >> n;
 
    arr.assign(n, {});
 
    for(auto &p : arr) cin >> p.second >> p.first;
 
    sort(arr.begin(), arr.end());
 
    ans = 0;
    st.clear();
 
    for(auto p : arr){
        ans += st.size() - st.order_of_key(p.second);
 
        st.insert(p.second);
    }
 
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    cin >> t;
 
    while(t--){
        solve();
    }
}