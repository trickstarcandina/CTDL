#include <bits/stdc++.h> 
using namespace std;
int main() {
    int t; cin>>t;
 	while(t--) {
        unsigned long long n;
		int dem;
        cin>>n;
        dem=0;
        if(n%2==1) cout<<0;
        else {
        	for (int i=1;i<=sqrt(n);i++){
        	if(n%i==0){
        		if (i%2==0) dem++;
        		if(i!=(n/i)){
					if ((n/i)%2==0) dem++;
        			}
        		}
        	}
        	cout<<dem;
		}
		cout<<endl;
    }
} 

