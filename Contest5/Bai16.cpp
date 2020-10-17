#include <bits/stdc++.h> 
using namespace std; 
int a[1005],c[1005];
int n;
int xuly() { 
	int i, j; int result=0; 
    for(i=1;i<=n;i++) 
        c[i]=a[i];
	for(i=1;i<=n;i++){
        for(j=1;j<i;j++)
            if(a[j]<a[i]) c[i]= max(c[i],c[j]+a[i]);
        result= max(result,c[i]);
    }
    return result;
} 
int main() { 
    int t; cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) 
            cin>>a[i];
        cout<<xuly()<<endl;
    }
	return 0; 
} 
