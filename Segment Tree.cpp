#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
vector<int> a, s;

int op(int l, int r) {
//	return l + r;										Range Sum
//	return l==-1?r:r==-1?l:a[l] > a[r] ? l : r;			Range Max
k	return l==-1?r:r==-1?l:a[l] < a[r] ? l : r;	//		Range Min
}

void build(int id = 1, int l = 0, int r = n) {
	if(l+1 == r) {
//		s[id] = a[l];									Range Sum
		s[id] = l;	//									Range Min/Max
		return;
	}
	int mid = (l+r)/2;
	build(id*2  , l, mid);
	build(id*2+1, mid, r);
	s[id] = op(s[id * 2], s[id * 2  + 1]);
}


void modify(int pos, int val, int id = 1, int l = 0, int r = n) {
	a[pos] = val;
	if(l+1 == r) {
//		s[id] = val;									Range Sum
		s[id] = l;	//									Range Min/<Max
		return;
	}

	int mid = (l+r)/2;
	if(pos < mid)
		modify(pos, val, id*2  , l, mid);
	else
		modify(pos, val, id*2+1, mid, r);
	s[id] = op(s[id*2], s[id*2+1]);
}


int query(int x, int y, int id = 1, int l = 0, int r = n) {
//	if(x >= r || y <= l) return 0;						Range Sum
	if(x >= r || y <= l) return -1; //					Range Min/Max
	if(x <= l && y >= r) return s[id];
	int mid = (r+l)/2;
	return op(query(x, y, id*2  , l, mid),
			  query(x, y, id*2+1, mid, r));
}

int main() {
	n = 10;
	a.assign(n,0);
	d.assign(n,-1);
	build();

	modify(2,13);
	modify(3,19);
	modify(4,15);
	modify(5,11);
	cout << query(2,5) << endl;
}