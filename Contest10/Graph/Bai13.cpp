#include <bits/stdc++.h>
using namespace std;
int n,m,G[1005][1005];
int KiemtraCTAm(){
    int d[n+1],i,j,k;
    for(i=1;i<=n;i++) d[i] = 1e7;

    d[1] = 0;
    for(k=2;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(d[j]>d[i]+G[i][j])
                    d[j] = d[i]+G[i][j];

    int check = 0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            int x = d[i] + G[i][j];
            if(d[j] > x){
                check = 1;
                break;
            }
        }
    return check;
}
main() {
	int t,i,j,u,v,k;
	cin>>t;
	while(t--){
	    cin >> n >> m;
	    for(i=0;i<=n;i++)
	        for(j=0;j<=n;j++)
	            G[i][j] = 1e7;
	    for(i=1;i<=m;i++){
	        cin >> u >> v >> k;
	        G[u][v] = k;
	    }
	    cout<<KiemtraCTAm()<<endl;
	}
}
