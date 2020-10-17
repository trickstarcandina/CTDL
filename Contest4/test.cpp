#include <bits/stdc++.h>
using namespace std; 
void nhap(int a[],int n){
    for(int i=0;i<n;i++)
        cin>>a[i];
} 
int maxSubArraySum(int a[], int size) { 
    int kq = a[0]; 
    int sum = a[0]; 
    for (int i = 1; i < size; i++) { 
        sum = max(a[i], sum+a[i]); 
        kq = max(kq, sum); 
    } 
    return kq; 
} 
int main() { 
	int t; cin >> t; 
    while (t--) { 
        int n; cin>>n; 
        int a[n]; nhap(a,n); 
        cout<<maxSubArraySum(a, n);
		cout<<endl;
    }
} 
