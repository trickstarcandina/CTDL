#include <bits/stdc++.h> 
using namespace std; 
int a[1005],c[1005];
int n;
int xuly() { 
	int i, j; int result=1; 
	for(i=1;i<=n;i++){
        c[i]=1;
        for(j=1;j<i;j++)
            if(a[j]<a[i]) c[i]= max(c[i],c[j]+1);
        result= max(result,c[i]);
    }
    return result;
} 
int main() { 
	int i; cin>>n;
    for(i=1;i<n;i++) 
        cin>>a[i];
    cout<<xuly()<<endl;
	return 0; 
} 
