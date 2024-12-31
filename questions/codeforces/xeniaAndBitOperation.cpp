// //https://codeforces.com/contest/339/problem/D

// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long int
// // Credits to HealthyUG for the inspiration.
// // Segment Tree with Point Updates and Range Queries
// // Supports multiple Segment Trees with just a change in the Node and Update
// // Very few changes required everytime

// template<typename Node, typename Update>
// struct SegTree {
// 	vector<Node> tree;
// 	vector<ll> arr; // type may change
// 	ll n;
// 	ll s;
// 	SegTree(int a_len, vector<ll> &a) { // change if type updated
// 		arr = a;
// 		n = a_len;
// 		s = 1;
// 		int cnt = 1;
// 		while(s < 2 * n){
// 			s = s << 1;
// 		}
// 		// cout<<"The value of s is : "<<s<<endl;
// 		// s = 1<<22;
// 		tree.resize(s); 
//         //fill(all(tree), Node());
//         for(int i=0;i<s;i++){
//             tree[i]=Node(arr[i]);
//         }
// 		build(0, n - 1, 1,true);
// 	}
// 	void build(int start, int end, int index,bool odd)  // Never change this
// 	{
// 		if (start == end)	{
// 			tree[index] = Node(arr[start]);
// 			return;
// 		}
// 		int mid = (start + end) / 2;
// 		build(start, mid, 2 * index,!odd);
// 		build(mid + 1, end, 2 * index + 1,!odd);
// 		tree[index].merge(tree[2 * index], tree[2 * index + 1],odd);
// 	}
// 	void update(int start, int end, int index, int query_index, Update &u,bool odd)  // Never Change this
// 	{
// 		if (start == end) {
// 			u.apply(tree[index]);
// 			return;
// 		}
// 		int mid = (start + end) / 2;
// 		if (mid >= query_index)
// 			update(start, mid, 2 * index, query_index, u,!odd);
// 		else
// 			update(mid + 1, end, 2 * index + 1, query_index, u,!odd);
// 		tree[index].merge(tree[2 * index], tree[2 * index + 1],odd);
// 	}
// 	Node query(int start, int end, int index, int left, int right,bool odd) { // Never change this
// 		if (start > right || end < left)
// 			return Node();
// 		if (start >= left && end <= right)
// 			return tree[index];
// 		int mid = (start + end) / 2;
// 		Node l, r, ans;
// 		l = query(start, mid, 2 * index, left, right,!odd);
// 		r = query(mid + 1, end, 2 * index + 1, left, right,!odd);
// 		ans.merge(l, r,odd);
// 		return ans;
// 	}
// 	void make_update(int index, ll val,bool odd) {  // pass in as many parameters as required
// 		Update new_update = Update(val); // may change
// 		update(0, n - 1, 1, index, new_update,odd);
// 	}
// 	Node make_query(int left, int right,bool odd) {
// 		return query(0, n - 1, 1, left, right,odd);
// 	}
// };

// struct Node{
// 	ll val; // may change
// 	Node() { // Identity element
// 		val =0;	// may change
// 	}
// 	Node(ll p1) {  // Actual Node
// 		val = p1; // may change
// 	}
// 	void merge(Node &l, Node &r,bool odd) { // Merge two child nodes
// 	if(odd==true)
// 		val = l.val ^ r.val;  // may change
//     else val = l.val | r.val;
// 	}
// };

// struct Update{
// 	ll val; // may change
// 	Update(ll p1) { // Actual Update
// 		val = p1; // may change
// 	}
// 	void apply(Node &a) { // apply update to given node
// 		a.val = val; // may change
// 	}
// };

// int main(){
//   ll n,q;
//   cin>>n>>q;
//   ll total=1;
//   bool odd = n%2==1;
//   while(n--) total = total<<1;
//   vector<ll> arr(total);
//   for(int i=0;i<total;i++) cin>>arr[i];
//   SegTree<Node,Update> s(total,arr);
  
//   for(int i=0;i<q;i++){
//     int x;
//     cin>>x;
//     x--;
//     ll val;cin>>val;
//     s.make_update(x,val,!odd);
//     cout<<s.make_query(0,total-1,!odd).val<<endl;
	
//   }

// }

#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)

typedef long long int LL;

int tree[1<<22];
int A[1<<18];
int N;

void build(int n,int b,int e,int l) {

	if(b == e) {
		tree[n] = A[b];
		return;
	}

	build(2*n, b, (b+e)/2, l+1);
	build(2*n+1, (b+e)/2+1, e, l+1);

	if((N-l)&1) {
		tree[n] = tree[2*n] | tree[2*n+1];
	} else {
		tree[n] = tree[2*n] ^ tree[2*n+1];
	}
}

void update(int n,int b,int e,int l,int x) {

	if(b == e) {
		tree[n] = A[b];
		return ;
	}

	if(x > (b+e)/2) {
		update(2*n+1, (b+e)/2+1, e, l+1, x);
	} else {
		update(2*n, b, (b+e)/2, l+1, x);
	}

	if((N-l)&1) {
		tree[n] = tree[2*n] | tree[2*n+1];
	} else {
		tree[n] = tree[2*n] ^ tree[2*n+1];
	}

}

using namespace std;
int main() {
	int n,m;
	S(n);S(m);
	N = n;
	rep(i,0,(1<<n)) S(A[i+1]);

	build(1,1,1<<n,0);


	while(m--) {
		int x,y;
		S(x);S(y);
		A[x] = y;
		update(1,1,(1<<n),0,x);
		P(tree[1]);
	}
	return 0;
}
