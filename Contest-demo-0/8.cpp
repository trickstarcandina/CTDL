#include <bits/stdc++.h> 
using namespace std; 
const int MAX = 100; 
void up(long long &a,long long &b){
    long long t=a;
    a=a+b;
    b=t;
}
void pro(int m, int n, long long a[][MAX]) { 
	long long val = 1; long long lav=0;
	int k = 0, l = 0; 
	while (k < m && l < n) { 
		for (int i = l; i < n; ++i) {
            a[k][i] = val; up(val,lav);
        }	
		k++; 
		for (int i = k; i < m; ++i) {
            a[i][n-1] = val; up(val,lav);
        }
		n--; 
		if (k < m) { 
			for (int i = n-1; i >= l; --i) {
                a[m-1][i] = val; up(val,lav);
            }		
			m--; 
		} 
		if (l < n) { 
			for (int i = m-1; i >= k; --i){
                a[i][l] = val; up(val,lav);
            } 	
			l++; 
		} 
	} 
} 
int main() { 
    int t; cin>>t;
    int x=t;
    while(t--){
        int m ,n;
        cin>>n; 
        m=n;
        long long a[MAX][MAX]; 
        cout<<"Test "<<x-t<<":"<<endl; 
	    pro(m, n, a); 
	    for (int i=0; i<m; i++) { 
	        for (int j=0; j<n; j++) 
		        cout << a[i][j] << " "; 
	        cout << endl; 
	    } 
    }
	return 0; 
} 
