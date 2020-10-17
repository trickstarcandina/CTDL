#include <bits/stdc++.h> 
using namespace std; 
int L[1001][1001];
int n,v;
int a[1001],c[1001];
void nhap(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
int tinh(){
    int i,j;
    memset(L,0,sizeof(L));
    for(i=1;i<=n;i++){
        for(j=1;j<=v;j++){
            if(j>=a[i] && L[i-1][j-a[i]]+c[i] > L[i-1][j])
                L[i][j]=L[i-1][j-a[i]]+c[i];
            else
                L[i][j]=L[i-1][j];   
        }
    }
    return L[n][v];
}
 
int main() { 
	int t; cin>>t;
	while (t--){
		cin>>n>>v;
        nhap(a,n); nhap(c,n); 
        cout<<tinh()<<endl;
	}
	return 0; 
} 
