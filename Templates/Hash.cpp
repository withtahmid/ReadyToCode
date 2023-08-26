#include<bits/stdc++.h>
#include<debug.h>
using namespace std;
int_fast64_t hash(const string& str){
	const int p = 31;
	const int m = 1e9 + 9;
	int_fast64_t hash_val = 0LL;
	int_fast64_t p_pow = 1LL;
	for(const auto& i : str){
		hash_val = ( hash_val + (i - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_val;

}
vector<vector<int>> group (const vector<string>& v)
int main(){
	io();
}