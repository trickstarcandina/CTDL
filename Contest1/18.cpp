#include<iostream>
#include<algorithm>
using namespace std;

int n, s, res = 99999999;
int a[100];

void Try(int i, int soBuoc, long long sum) {
	if (sum > s || soBuoc > res) return;
	if (i == n) {
		if (sum == s) res = min(res, soBuoc);
		return;
	}
	Try(i + 1, soBuoc, sum);
	Try(i + 1, soBuoc + 1, sum + a[i]);
}

int main() {
	int t; cin>>t;
	while (t--){
		cin >> n >> s;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		Try(0, 0, 0);
		if (res == 9999999) cout << "-1";
		else cout << res;
		cout<<endl;
	}
}