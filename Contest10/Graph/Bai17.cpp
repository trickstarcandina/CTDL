#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define INF 1e9 

vector< vector<ii> > dsk;

int dist[105][105];
int V,E;

void xuLy(){
	
	for(int k=1;k<=V;k++){
	
		for(int h=1;h<=V;h++){
			dist[k][h]=INF;
		}
	
		priority_queue< ii,vector<ii>,greater<ii> > pq;
		pq.push(ii(0,k));
		dist[k][k]=0; 
	
		while(!pq.empty()){
			int u=pq.top().second;
			pq.pop();

			for(int i=0;i<dsk[u].size();i++){
				int v=dsk[u][i].first;
				int doDai=dsk[u][i].second;
			
				if(dist[k][v]>dist[k][u]+doDai){
					dist[k][v]=dist[k][u]+doDai;
					pq.push(ii(dist[k][v],v));
				}
			}
		}
	
	}
	
}

int main(){
	cin>>V>>E;
	dsk.resize(105);
	
	for(int i=1;i<=E;i++){
		int a,b,k;
		cin>>a>>b>>k;
		dsk[a].push_back(ii(b,k));
		dsk[b].push_back(ii(a,k));
	}
	xuLy();
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]<<endl;
	}
	return 0;
}
