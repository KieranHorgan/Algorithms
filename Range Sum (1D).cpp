#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll prefixSum[100005], n;

ll rsq(ll i, ll j) { return prefixSum[j] - prefixSum[i-1]; }

int main() {
	cin >> n;

	ll max1DRange = 0;

	for(int i = 1; i <= n; i++) {
		cin >> prefixSum[i];
		prefixSum[i] += prefixSum[i-1];
	}
}