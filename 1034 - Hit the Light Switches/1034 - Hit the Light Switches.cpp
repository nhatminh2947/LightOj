//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1034 - Hit the Light Switches
// Verdict: Accepted
//******************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define maxN 10000
#define INF 1000111222

using namespace std;

vector<int> adj[maxN+5];
bool vis[maxN+5];
int n,m;

void DFS(int u)
{
    vis[u] = true;
    int sz = adj[u].size();
    for(int i = 0 ; i < sz ; i++)
        if(!vis[adj[u][i]])
            DFS(adj[u][i]);
}

int main()
{
    freopen("1034 - Hit the Light Switches.INP","r",stdin);
    freopen("1034 - Hit the Light Switches.OUT","w",stdout);
    
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d %d ",&n,&m);
        for(int i = 1 ; i <= n ; i++)
        {
            adj[i].clear();
            vis[i] = false;
        }
        
        for(int i = 0 ; i < m ; i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            adj[u].pb(v);
        }
        
        vector<int> u;
        for(int i = 1 ; i <= n ; i++)
            if(!vis[i])
            {
                //cout << "i = " << i << endl;
                DFS(i);
                u.pb(i);
            }
        
        for(int i = 1 ; i <= n ; i++)
            vis[i] = false;
        
        int cnt = 0;
        int sz = u.size();
        for(int i = sz-1 ; i >= 0 ; i--)
            if(!vis[u[i]])
            {
                //cout << "u[i] = " << u[i] << endl;
                DFS(u[i]);
                cnt++;
            }
        
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
