#include<bits/stdc++.h>
using namespace std;

#define ii pair<double,double>
#define fi first
#define se second

struct doThi{
	ii u,v;
	double doDai;
};

int N;
vector<ii> dinh;
vector<doThi> dsc;
vector<doThi> tree;
map< ii,vector<ii> > dsk;
map<ii,bool> visited;

bool BFS(ii u){
	map<ii,ii> parent;
	for(int i=0;i<dinh.size();i++) parent[dinh[i]]=ii(-1,-1);
	queue<ii> q;
	q.push(u);
	visited[u]=true;
	while(!q.empty()){
		ii s=q.front();
		q.pop();
		for(int i=0;i<dsk[s].size();i++){
			if(!visited[dsk[s][i]]){
				visited[dsk[s][i]]=true;
				q.push(dsk[s][i]);
				parent[dsk[s][i]]=s;
			}
			else if(parent[s]!=dsk[s][i]) return true;
		}		
	}
	return false;
}

bool ktChuTrinh(doThi dt){
	for(int i=0;i<dinh.size();i++) visited[dinh[i]]=false;
	dsk[dt.u].push_back(dt.v);
	dsk[dt.v].push_back(dt.u);
	for(int i=0;i<dinh.size();i++){
		if(!visited[dinh[i]]){
			if(BFS(dinh[i])) return true;
		}
	}
	return false;
}

double trongSo(ii x,ii y){
	return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se));
}

bool comp(doThi x,doThi y){
	return x.doDai<y.doDai;
}

void xuLy(){
	double res=0;

	sort(dsc.begin(),dsc.end(),comp);
	queue<doThi> que;
	for(int i=0;i<dsc.size();i++){
		que.push(dsc[i]);
	}
	while(tree.size()<dinh.size()-1 && !que.empty()){
		doThi t=que.front();
		que.pop();
		if(!ktChuTrinh(t)){
			tree.push_back(t);
			res+=t.doDai;
		}
		else{
			dsk[t.u].pop_back();
			dsk[t.v].pop_back();
		} 
		
	}
	printf("%.6lf\n",res);
}


int main(){
	int t;
	cin>>t;
	while(t--){
		dsk.clear();
		dsc.clear();
		tree.clear();
		dinh.clear();
		cin>>N;
		for(int i=0;i<N;i++){
			double a,b;
			cin>>a>>b;
			dinh.push_back(ii(a,b));
		}
		
		for(int i=0;i<dinh.size();i++){
			for(int j=i+1;j<dinh.size();j++){
				doThi tmp;
				tmp.u=dinh[i];
				tmp.v=dinh[j];
				tmp.doDai=trongSo(dinh[i],dinh[j]);
				dsc.push_back(tmp);
			}
		}
		
		xuLy();
		
	}
	return 0;
}
