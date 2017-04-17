#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
vector<pair<ll,ll>> AdjList[100005];
ll dist[100005];

bool BellmanFord(ll s) {
	for(ll i = 0; i < 100005; i++) dist[i]=1<<30;
	dist[s] = 0;

	for(int i = 0; i < n-1; i++)
		for(int u = 0; u < n; u++)
			for(auto v: AdjList[u])
				dist[v.second] = min(dist[v.second], dist[u] + v.first);
}

int main() {
	
}