#include<bits/stdc++.h>
using namespace std;
vector<int> List[20];
int color[20];
int n,m,d;

bool check(int u,int c){
	for(int i=0;i<List[u].size();i++)
		if(c==color[List[u][i]]) return false;
	return true;
}
bool Try(int u){
	if(u==n+1) return true;
	for(int c=1;c<=d;c++){
		if(check(u,c)){
			color[u]=c;
			if(Try(u+1)) return true;
			color[u]=0;
		}
	}
	return false;
}
main(){
	int t,i,u,v;
	cin>>t;
	while(t--){
        for(i=0;i<20;i++) List[i].clear();
        memset(color,0,sizeof(color));
		cin>>n>>m>>d;
        for(i=1;i<=m;i++){
            cin>>u>>v;
            List[u].push_back(v);
            List[v].push_back(u);
        }
        if(Try(1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
	}
}
