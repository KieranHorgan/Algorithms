#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll LIS[100005], a[100005], n;

int main() {
	cin >> n;

	ll Longest = 0;

	cin >> a[0];
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		LIS[i] = LIS[i-1]+1;
		if(a[i] <= a[i-1]) LIS[i] = 1;
		Longest = max(Longest, LIS[i]);
	}
}