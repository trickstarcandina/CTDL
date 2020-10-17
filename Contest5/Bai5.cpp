#include <bits/stdc++.h> 
using namespace std; 
int c[1005][1005],n,k;
int mod=1e9+7;
void xuly(){
    int i,j;
    for(i=0;i<=1000;i++)
        for(j=0;j<=i;j++){
            if(j==0 || j==i) c[i][j]=1;
            else c[i][j]=(c[i-1][j] + c[i-1][j-1]) %mod;
        }
}
int main() { 
	int t; 
    xuly();
    cin>>t;
	while (t--){
		cin>>n>>k;
        cout<<c[n][k]<<endl;
    }
	return 0; 
} 
