#include <bits/stdc++.h> 
using namespace std; 
int C[101][101][101];
int xuly(string x,string y,string z,int m,int n,int p) { 
	int i, j,k;  
	for (i = 0; i <= m; i++) { 
		for (j = 0; j <= n; j++) { 
            for(k = 0; k <= p; k++)
		    if (i == 0 || j == 0 || k==0) 
		    	C[i][j][k] = 0; 
		    else if (x[i - 1] == y[j - 1] && y[j-1] == z[k-1]) 
		    	C[i][j][k] = C[i - 1][j - 1][k-1] + 1; 
		    else
		    	C[i][j][k] = max( max(C[i - 1][j][k], C[i][j - 1][k]), C[i][j][k-1] ); 
		} 
	} 
	return C[m][n][p]; 
} 
int main() { 
	int t; cin>>t;
	while (t--){
		string x,y,z; int m,n,p; cin>>m>>n>>p;
        cin>>x>>y>>z;
        cout<<xuly(x,y,z,m,n,p)<<endl;
	}
	return 0; 
} 
