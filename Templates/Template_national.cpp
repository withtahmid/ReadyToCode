/**
 * 
 * Author: withtahmid
 * Created: 26-02-2023
 * 
 * */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
// #include <debug.h> 
#else
#define debug(...) 
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define sizeof(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
template <typename Type>
void operator>>(istream& istream, vector<Type>& v){for(auto& i:v){cin>>i;}}
void solve(int);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    // io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = not true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
class item{
public:
    ll hash_val;
    ll len;
    item(){}
    item(ll x, ll z){
        hash_val = x;
        len = z;
    }
};
const ll MAXN = 1e5 +10;
const ll p = 7, mod = LONG_MAX;
vector<item>TREE(MAXN * 4);
vector<ll> a,b;
ll power(ll x, ll y) 
 { 
     ll val = 1;

     while (y > 0)
     { 
         if (y % 2 != 0) {
             val = (val * x)%mod; 
         }
         y = y / 2; 
         x = (x * x) % mod;
     } 
     return val; 
 }
item relation(item a, item b){
    if(a.len != 0LL and b.len != 0LL){
        ll a_hash = a.hash_val;

        ll b_hash =(power(p, a.len) * b.hash_val) % mod;
        ll hash = (a_hash + b_hash) % mod;
        return item(hash, a.len + b.len);
    }
    if(a.len == 0){
        return b;
    }
    return a;  
}
void build(ll indx, ll l, ll r){
    if(l == r){
        TREE[indx] = item(a[l], 1);
        return;
    }
    ll mid = (l + r)/2;
    ll left = indx * 2;
    ll right = indx * 2 + 1;
    build(left, l, mid);
    build(right, mid+1, r);
    TREE[indx] = relation(TREE[left], TREE[right]);
}
item query(ll indx, ll l, ll r, ll range_l, ll range_r){
    if(range_l > range_r){
        return item(0LL,0LL);
    }
    if(l == range_l and r == range_r){
        return TREE[indx];
    }
    ll mid = (l + r) / 2;
    ll left = indx * 2;
    ll right = indx * 2 + 1;
    return relation(
        query(left,l, mid, range_l, min(mid, range_r)),
        query(right, mid + 1, r, max(mid+1, range_l), range_r)
    );
}
void update(ll indx, ll l, ll r, ll pos, ll val){
    if(l == r){
         TREE[indx] = item(val, 1);
        return;
    }
    ll mid = (l + r ) / 2;
    ll left = indx * 2;
    ll right = indx * 2 + 1;
    if(pos <= mid){
        update(left, l, mid, pos, val);
    }
    else{
        update(right, mid+1, r, pos, val);
    }
    TREE[indx] = relation(TREE[left], TREE[right]);

}
ll calculate_hash(vector<ll> v){
    ll res = 0, p_pow = 1;
    for(int i = 0; i < sizeof(v); ++i){
        res = ((v[i] * p_pow) % mod + res) % mod;
        p_pow = (p_pow * p) % mod;
    }
    return res;
}
void solve(int case_no){
    int n, m;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    cin >> a;
    cin >> b;
    int q;
    cin >> q;
    build(1, 0, n-1);
    ll hash_of_b = calculate_hash(b);
    // cerr << hash_of_b << " " << query(1, 0, n-1, 0, n-1).hash_val << endl;
    while(q--){
        int x, l, r;
        cin >> x >> l >> r;
        if(x^1){
            item res = query(1, 0, n-1, l-1, r-1);
            cout << (res.hash_val == hash_of_b ? "YES" : "NO") << endl;
        }
        else{
            update(1, 0, n-1, l-1, r);
        }
    }
}