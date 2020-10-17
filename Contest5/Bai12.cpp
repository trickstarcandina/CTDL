#include <bits/stdc++.h> 
using namespace std; 
int c[1001][1001],n,k;
int mod=1e9+7;
long long xuly(int n,int k){
    long long result=1;
    for(int i=n;i>=n-k+1;i--)
        result=result*i%mod;
    return result;
}
int main() { 
	int t; cin>>t;
	while (t--){
		cin>>n>>k;
        cout<<xuly(n,k)<<endl;
    }
	return 0; 
} 
