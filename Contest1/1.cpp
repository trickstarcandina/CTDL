#include <iostream>
using namespace std;
void xuat(int a[], int n){
	for(int i = 0; i < n ;i++ )
		cout << a[i];
	cout << endl;
}
void day_ke_tiep(int a[], int n){
	int  i = n - 1; 
	while(i > -1 && a[i]){ 
		a[i] = 0;		
		i--;			
	}
		a[i] = 1;
}
void xu_ly(int a[], int n){
	int x=1;
	while (x--) {     
		day_ke_tiep(a, n);
		xuat(a, n);	
	}
}
int main(){
    int t; cin>>t;
    while(t--){
		string x; cin>>x;
		int n=x.length();
        int a[10000];
        for(int i = 0; i <x.length() ; i++){
			a[i] = x[i]-'0';
		}
	    xu_ly(a, n);
    }
	return 0;
}