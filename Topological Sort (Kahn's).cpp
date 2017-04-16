#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
bool visited[100005];
vector<ll> AdjList[100005];

vector<ll> topoSort;

void Kahn() {
	ll inDegree[100005];
	for(auto i: AdjList)
		for(auto j: i)
			inDegree[j]++;

	queue<ll> q;
	for(int i = 1; i <= n; i++)
		if(!inDegree[i])
			q.push(i);

	while(!q.empty()) {
		ll u = q.front(); q.pop();
		if(visited[u]) continue;
		visited[u]=1;

		topoSort.push_back(u);

		for(auto v: AdjList[u]) {
			inDegree[v]--;
			if(!inDegree[v]) {
				q.push(v);
			}
		}
	}

}

int main() {
	
}