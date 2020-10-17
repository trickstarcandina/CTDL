#include <bits/stdc++.h> 
using namespace std; 
int a[202];
int L[40004],n,s;
int check(int a[],int n){
    memset(L,0,sizeof(L));
    int i,j;
    L[0]=1;
    for(i=1;i<=n;i++)
        for(j=s;j>=a[i];j--){
            if(L[j]==0 && L[j-a[i]]==1) 
                L[j]=1;
        }
    return L[s];
}
int main() { 
	int t; cin>>t;
	while (t--){
		cin>>n>>s;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(check(a,n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
	}
	return 0; 
} 
