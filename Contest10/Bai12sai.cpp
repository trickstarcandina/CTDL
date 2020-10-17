#include <bits/stdc++.h> 
using namespace std;  
struct Edge { 
	int dau, cuoi, ts; 
}; 
struct Graph { 
	int V, E;  
	Edge* edge; 
}; 
struct subset { 
	int goc; 
  int rank; 
}; 
int find(struct subset subsets[], int i) { 
	if (subsets[i].goc != i) 
	subsets[i].goc = 
			find(subsets, subsets[i].goc); 

	return subsets[i].goc; 
} 
void Union(struct subset subsets[], int x, int y) 
{ 
	int xset = find(subsets, x); 
	int yset = find(subsets, y); 
	if (subsets[xset].rank < subsets[yset].rank) 
		subsets[xset].goc = yset; 
	else if (subsets[xset].rank > subsets[yset].rank) 
		subsets[yset].goc = xset; 
	else
	{ 
		subsets[yset].goc = xset; 
		subsets[xset].rank++; 
	} 
} 
void boruvkaMST(struct Graph* graph) { 
	int V = graph->V, E = graph->E; 
	Edge *edge = graph->edge; 
	struct subset subsets[V];
	int cheapest[V];  
	for (int v = 0; v < V; ++v) { 
		subsets[v].goc = v; 
		subsets[v].rank = 0; 
		cheapest[v] = -1; 
	} 
	int numTrees = V; 
	int MSTweight = 0; 
	while (numTrees > 1) { 
		for (int v = 0; v < V; ++v) { 
			cheapest[v] = -1; 
		} 
		for (int i=0; i<E; i++) { 
			int set1 = find(subsets, edge[i].dau); 
			int set2 = find(subsets, edge[i].cuoi); 
			if (set1 == set2) 
				continue; 
			else{ 
			if (cheapest[set1] == -1 || 
				edge[cheapest[set1]].ts > edge[i].ts) 
				cheapest[set1] = i; 

			if (cheapest[set2] == -1 || 
				edge[cheapest[set2]].ts > edge[i].ts) 
				cheapest[set2] = i; 
			} 
		} 
		for (int i=0; i<V; i++) { 
			if (cheapest[i] != -1) 
			{ 
				int set1 = find(subsets, edge[cheapest[i]].dau); 
				int set2 = find(subsets, edge[cheapest[i]].cuoi); 

				if (set1 == set2) 
					continue; 
				MSTweight += edge[cheapest[i]].ts;  
				Union(subsets, set1, set2); 
				numTrees--; 
			} 
		} 
	} 
  cout<<MSTweight<<endl;
	return; 
} 
struct Graph* createGraph(int V, int E) 
{ 
	Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 
	graph->edge = new Edge[E]; 
	return graph; 
} 
int main() { 
	int t; cin>>t;
  while (t--){
    int V,E;
    cin>>V>>E;
    struct Graph* graph = createGraph(V, E); 
	  for (int i=0; i<E; i++){
      int a,b,c;
      cin>>a>>b>>c;
      graph->edge[i].dau = a; 
	    graph->edge[i].cuoi = b; 
	    graph->edge[i].ts = c;
    }
    boruvkaMST(graph); 
  }
	return 0; 
} 
