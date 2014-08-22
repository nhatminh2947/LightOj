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
stack<int> s;
int ind[maxN+5],low[maxN+5],scc[maxN+5];
bool onStack[maxN+5],vis[maxN+5];
int n,m,cnt,comp;

void Tarjan(int u)
{
    ind[u] = low[u] = cnt++;
    s.push(u);
    onStack[u] = true;
    int sz = adj[u].size();
    int v;
    for(int i = 0 ; i < sz ; i++)
    {
        v = adj[u][i];
        if(ind[v] == INF)
        {
            Tarjan(v);
            low[u] = min(low[v],low[u]);
        }
        else if(onStack[v])
            low[u] = min(low[u],ind[v]);
    }
    
    if(low[u] == ind[u])
    {
        //printf("SCC: ");
        do
        {
            v = s.top();
            //printf(" %d",v);
            onStack[v] = false;
            s.pop();
            scc[v] = comp;
        }while(u != v);
        //printf("\n");
        comp++;
    }
}

void init()
{
    for(int i = 0 ; i <= n ; i++)
    {
        adj[i].clear();
        ind[i] = low[i] = INF;
        onStack[i] = vis[i] = false;
    }
    while(!s.empty())
        s.pop();
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
        init();
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
        
        cnt = comp = 0;
        
        for(int i = 1 ; i <= n ; i++)
            if(ind[i] == INF)
                Tarjan(i);
        
        //cout << "comp = " << comp << endl;
        for(int u = 1 ; u <= n ; u++)
        {
            int sz = adj[u].size();
            for(int i = 0 ; i < sz ; i++)
            {
                int v = adj[u][i];
                if(scc[u] != scc[v] && !vis[scc[v]])
                {
                    //cout << "u = " << u << endl;
                    //cout << "v = " << v << endl;
                    vis[scc[v]] = true;
                    comp--;
                }
            }
        }
        
        printf("Case %d: %d\n",t,comp);
    }
    return 0;
}
