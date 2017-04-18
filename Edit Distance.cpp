#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll EditDistance(string s, string t) {
	vector<vector<ll>> dp( t.size(), vector<ll>(s.size()) );

	for(int j = 0; j < s.size(); j++)
		dp[0][j] = j;
	for(int i = 0; i < t.size(); i++)
		dp[i][0] = i;

	for(int i = 1; i < t.size(); i++) {
		for(int j = 1; j < s.size(); j++) {
			dp[i][j] = min(dp[i-1][j-1]+(s[j]!=t[i]), min(dp[i-1][j]+1, dp[i][j-1]+1));
		}
	}
	
	return dp[t.size()-1][s.size()-1];
}

int main() {
	
}