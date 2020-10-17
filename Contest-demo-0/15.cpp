#include <bits/stdc++.h> 
using namespace std;
void nhap(int n,int a[]){
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
int pro(int n,int a[]){
    int c=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]==a[j]) {
                cout<<a[i]; 
                return 0;
                c=1;
            }
    if(c==0) cout<<"NO";
}
int main() {
    int t; cin>>t;
    while (t--){
        int n; cin>>n; 
        int a[n];
        nhap(n,a);
        pro(n,a);
        cout<<endl;
    }
    return 0;
}