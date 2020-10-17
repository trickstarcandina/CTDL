#include<bits/stdc++.h>
using namespace std;
int n,m,check;
vector<int> List[20];
bool chuaxet[20];
void Hamiton(int u,int count){
	if(count==n) {
        check = 1;  return;
	}
	for(int i=0;i<List[u].size();i++){
        int v = List[u][i];
		if(chuaxet[v]){
			chuaxet[v]=false;
			Hamiton(v,count+1);
			chuaxet[v]=true;
		}
	}
}
main(){
	int t,i,u,v; cin>>t;
	while(t--){
		for(i=0;i<20;i++) List[i].clear();
		memset(chuaxet,true,sizeof(chuaxet));
		cin>>n>>m;
		for(i=1;i<=m;i++){
			cin>>u>>v;
			List[u].push_back(v);
			List[v].push_back(u);
		}
		check=0;
		for(i=1;i<=n;i++){
			chuaxet[i]=false;
            Hamiton(i,1);
            chuaxet[i] = true;
		}
		cout<<check<<endl;
	}
}
