#include<bits/stdc++.h>
using namespace std;
int n, m,mat[25][25],ans = -1;
void re_new(){
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++)
            mat[i][j]=0;
    }
}
void dfs(int u, int tmp){
    ans = max(ans,tmp);
    for (int v = 0; v < n; v++){
        if (mat[u][v] == 1){
            mat[u][v] = 0;
            mat[v][u] = 0;
            dfs(v, tmp + 1);
            mat[u][v] = 1;
            mat[v][u] = 1;
        }
    }
}
void nhap(){
    cin>>n>>m; int x,y;
    for (int i = 0; i < m; i++){
        cin>>x>>y;
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
} 
void xuly(){
    ans = -1;
    for (int i = 0; i < n; i++) 
        dfs(i,0);
    cout << ans << endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        re_new();
        nhap(); 
        xuly();
    }
    return 0;
}