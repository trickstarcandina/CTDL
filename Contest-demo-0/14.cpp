#include <bits/stdc++.h> 
using namespace std;
void nhap(int &n,int a[]){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
int ln(int n,int a[]){
	int max=a[0];
	for(int i=0;i<=n;i++)
		if(a[i]>max) max=a[i];
	for(int i=0;i<=n;i++)
		if(a[i]==max) {
			return i;
			break;
		}
}
int main(){
	int t; cin>>t;
	while(t--){
		int n,a[100001],b[100001];
		nhap(n,a);
		int i,j,k;
		for(i=1;i<=n;i++)
			if(a[i]==0) b[0]=b[0]+1;
		for(i=1;i<n;i++)
			if(a[i]!=0){
				int d=1;
				for(j=i+1;j<=n;j++)
					if(a[j]==a[i]){
						d=d+1;
						a[j]=0;
					}
				b[i]=d;
			}
		for(j=1;j<=n;j++){
			if(ln(n,b)>=0){
				for(i=1;i<=b[ln(n,b)];i++)
					cout<<a[ln(n,b)]<<" ";
				b[ln(n,b)]=-1;
			}
		}
		cout<<endl;
	}
	return 0;
}
