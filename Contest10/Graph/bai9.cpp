#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,x,y,u,check[1005];
vector< vector<int> > a;
vector<int> dau,cuoi;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    check[u]=1;
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (int i=0;i<a[s].size();i++)
            if (check[a[s][i]]==0)
            {
                dau.push_back(s);
                cuoi.push_back(a[s][i]);
                q.push(a[s][i]);
                check[a[s][i]]=1;
            }
    }
}

void result()
{
    memset(check,0,sizeof(check));
    dau.clear();
    cuoi.clear();
    bfs(u);
    if (dau.size() == n-1)
    {
        for (int i=0;i<dau.size();i++)
            cout << dau[i] <<" " << cuoi[i] << endl;
    }
    else 
        cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> u;
        a.clear();
        a.resize(n+5);
        for (int i=0;i<m;i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        result();
    }
    return 0;
}
