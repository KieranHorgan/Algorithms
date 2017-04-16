#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
bool visited[100005];
vector<ll> AdjList[100005];

void dfs(ll u) {
	if(visited[u]) return;
	visited[u] = 1;

	cerr << u << endl;

	for(auto v: AdjList[u])
		dfs(v);
}


int main() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}

	dfs(0);
}