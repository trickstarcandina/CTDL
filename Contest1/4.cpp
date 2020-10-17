#include <iostream>
using namespace std;
void khoitao(int a[], int n){
	for(int i = 0; i <n ; i++){
		a[i] = 0;
	}
}
void xuat(int a[], int n){
	for(int i = 0; i < n ;i++ )
		if(a[i]==0) cout <<"A";
        else cout<<"B";
    cout<<" ";
}
void day_ke_tiep(int a[], int n, int &stop){
	int  i = n - 1; 	
	while(i > -1 && a[i]){ 
		a[i] = 0;		
		i--;			
	}
	if(i == -1){
		stop = 1;
	} else{
		a[i] = 1;
	}
}
void xu_ly(int a[], int n, int &stop){
	while (!stop) {     
		xuat(a, n);
		day_ke_tiep(a, n, stop);
	}
}
int main(){
    int t; cin>>t;
    while(t--){
		int n; cin>>n;
        int a[n],stop=0;
        khoitao(a,n);
	    xu_ly(a, n,stop);
        cout<<endl;
    }
	return 0;
}