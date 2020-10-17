#include <bits/stdc++.h> 
using namespace std; 
int C[1001][1001];
int xuly(string x,string y) { 
    int m=x.length();
    int n=y.length();
	int i, j;  
	for (i = 0; i <= m; i++) { 
		for (j = 0; j <= n; j++) { 
		    if (i == 0 || j == 0) 
		    	C[i][j] = 0; 
		    else if (x[i - 1] == y[j - 1]) 
		    	C[i][j] = C[i - 1][j - 1] + 1; 
		    else
		    	C[i][j] = max(C[i - 1][j], C[i][j - 1]); 
		} 
	} 
	return C[m][n]; 
} 
int main() { 
	int t; cin>>t;
	while (t--){
		string s1,s2;
        cin>>s1>>s2;
        cout<<xuly(s1,s2)<<endl;
	}
	return 0; 
} 
