#include <bits/stdc++.h> 
using namespace std; 
void nhap(int n, int a[]){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void xuat(int n,int a[]){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main() { 
    int t; cin>>t;
    int x=t;
    while(t--){
        int m ,n,p;
        cin>>n>>m>>p; 
        int a[n]; 
        int b[m];
        int c[200];
        nhap(n,a);
        nhap(m,b);
        cout<<"Test "<<x-t<<":"<<endl; 
        int j=0;
        int k=0;
        for(int i=0;i<m+n;i++){
            if(p-1<i && i<p+m) { 
                c[i]=b[j]; j++;
            }
            else {
                c[i]=a[k]; k++; 
            }
            
        }
         xuat(n+m,c);   
    }
	return 0; 
} 
