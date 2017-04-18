#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, leftSet;
ll visited[100005], match[100005];
vector<ll> AdjList[100005];

ll MCBM(ll u) {
	if(visited[u]++) return 0;

	for(auto v: AdjList[u]) 
		if(match[v] == -1 || MCBM(match[v])) {
			match[v] = u;
			return 1;
		}

	return 0;
}


int main() {
	cin >> n >> leftSet;

	ll a, b;
	while(cin >> a && cin >> b) {
		AdjList[a].push_back(b);
		AdjList[b].push_back(a);
	}

	memset(match, -1, sizeof(match));
	
	ll max_matchings = 0;
	for(int i = 0; i < leftSet; i++) {
		memset(visited, 0, sizeof(visited));
		max_matchings += MCBM(i);
	}
	cout << max_matchings << endl;

	return 0;
}