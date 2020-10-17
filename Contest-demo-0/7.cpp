#include <bits/stdc++.h> 
using namespace std;
int a[10000][10000], b[10000][10000],c[10000][10000];
int main (){
    int z; cin>>z;
	int x; x=z;
	while(z--){
	    int n,m;
        int i,j,k,l,t=0;
	    cin>>m>>n;
	    for (i=1;i<=m;i++)
		    for (j=1;j<=n;j++)
                cin>>a[i][j];
	    for (i=1;i<=n;i++)
		    for(j=1;j<=m;j++)
			    b[i][j]=a[j][i];
	    for (i=1;i<=m;i++)
		    for (j=1;j<=m;j++){
			    for (k=1;k<=n;k++)
				    t=t+a[i][k]*b[k][j];
			c[i][j]=t;
			t=0;
		}
	    cout<<"Test "<<x-z<<":"<<endl; 
	    for (i=1;i<=m;i++){
	    	for (j=1;j<=m;j++)
                cout<<c[i][j]<<" ";
	    	cout<<endl;
	    }
	}
    return 0;
}

