#include <bits/stdc++.h>

using namespace std;

#define ll long long

class FenwickTree {
private: 
	vector<ll> ft;
	ll N;

public:
	FenwickTree(ll n) {
		N = n;
		ft.resize(N+1);
	}

	void adjust(ll i, ll v) {
		while(i < N+1) {
			ft[i] += v;
			i += i&-i;
		}
	}
	ll getSum(ll i) {
		ll v = 0;
		while(i != 0) {
			v += ft[i];
			i -= i&-i;
		}
		return v;
	}
	ll rsq(ll i) { return getSum(i); }
	ll rsq(ll i, ll j) { return getSum(j) - getSum(i-1); }
};

int main() {
	
}