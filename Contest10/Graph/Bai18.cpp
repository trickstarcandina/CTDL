#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define ii pair<int,int>


const int N = 500005;
const ll MAXD = 1e18;

struct data {
	int u;
	ll d;
	bool operator < (const data &o) const {
		return d > o.d;
	}
};

int n, m;
ll d[N], f[N];
vector<ii> dsk[N];
priority_queue<data> st;


void read() {
	cin >> n >> m;
	int u, v, l;
	for(int i=1;i<=m;i++) {
		cin >> u >> v >> l;
		dsk[u].push_back(ii(v, l));
		dsk[v].push_back(ii(u, l));
	}
}

void solve() {
	d[1] = 0;
	f[1] = 1;
	for(int i=2;i<=n;i++) d[i] = MAXD;
	
	data t;
	t.u=1;
	t.d=d[1];
	st.push(t);
	
	while (!st.empty()) {
		data t = st.top();
		st.pop();
		int u = t.u;
		if (d[u] < t.d) continue;
		
		for(int i=0;i<dsk[u].size();i++) {
			int v = dsk[u][i].fi, l = dsk[u][i].se;
			if (d[v] < d[u] + l) continue;
			if (d[v] > d[u] + l) {
				d[v] = d[u] + l;
				f[v] = f[u];
				
				data t;
				t.u=v;
				t.d=d[v];
				st.push(t);
			} else {
				f[v] += f[u];
			}
		}
	}

	cout << d[n] << " " << f[n];
}

int main() {
  	read();
  	solve();
    return 0;
}

