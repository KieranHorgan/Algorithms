#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m, ans;
vector<ll> AdjList[100005], AdjListTranspose[100005], postOrder;
ll visited[100005];

void getPostOrder(ll u) {
	if(visited[u]) return;
	visited[u] = 1;

	for(auto v: AdjList[u])
		if(!visited[v])
			getPostOrder(v);

	postOrder.push_back(u);
}

void dfs(ll u) {
	if(visited[u]) return;
	visited[u] = 1;

	for(auto v: AdjListTranspose[u])
		if(!visited[v])
			dfs(v);

}

void Kosaraju() {
	memset(visited, 0, sizeof(visited));
	for(int i = 1; i <= n; i++)
		if(!visited[i])
			getPostOrder(i);

	reverse(postOrder.begin(), postOrder.end());

	memset(visited, 0, sizeof(visited));
	for(auto u: postOrder) 
		if(!visited[u])
			ans++, dfs(u);
}

int main() {
	
}