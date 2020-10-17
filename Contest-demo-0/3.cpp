#include<bits/stdc++.h>
using namespace std;
int check(int n,int a[]){
    int x=0;
    int r=0;
    int l=n-1;
    while(r<l){
        if(a[r]==a[l]) {
            r++; l--;
        }
        else{
            x=1; break;
        }
    }
    if(x==1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        check(n,a);
	}
}

