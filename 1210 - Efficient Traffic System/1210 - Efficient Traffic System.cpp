//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1210 - Efficient Traffic System
// Verdict: Accepted
//******************************************************************

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stack>

#define INF 1000111222
#define pb push_back
#define mp make_pair
#define DEBUG(x) cout << "#x = " << x << endl
#define sz size()
#define maxN 20000

using namespace std;

int n,m,id,scc;
stack<int> s;
vector<int> adj[maxN+5];
int low[maxN+5],ind[maxN+5],belong[maxN+5];
int in[maxN+5],out[maxN+5];
bool onStack[maxN+5],vis[maxN+5];

void Tarjan(int u)
{
    low[u] = ind[u] = id++;
    s.push(u);
    onStack[u] = true;
    
    int v;
    for(int i = 0 ; i < adj[u].sz ; i++)
    {
        v = adj[u][i];
        if(ind[v] == INF)
        {
            Tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(onStack[v])
            low[u] = min(low[u],ind[v]);
    }
    
    if(low[u] == ind[u])
    {
        //printf("SCC:");
        do
        {
            v = s.top();
            //printf(" %d",v);
            s.pop();
            belong[v] = scc;
            onStack[v] = false;
        }while(u != v);
        scc++;
        //printf("\n");
    }
}

inline void reset()
{
    id = scc = 0;
    while(!s.empty())
        s.pop();
    for(int i = 1 ; i <= n ; i++)
    {
        adj[i].clear();
        low[i] = ind[i] = INF;
        onStack[i] = vis[i] = false;
        in[i] = out[i] = 0;
    }
}

void DFS(int u)
{
    vis[u] = true;
    for(int i = 0 ; i < adj[u].sz ; i++)
    {
        int v = adj[u][i];
        if(belong[u] != belong[v])
        {
            in[belong[v]]++;
            out[belong[u]]++;
        }
        if(!vis[v])
            DFS(v);
    }
}

int main()
{
    freopen("1210 - Efficient Traffic System.INP","r",stdin);
    freopen("1210 - Efficient Traffic System.OUT","w",stdout);
    
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d %d ",&n,&m);
        reset();
        for(int i = 0 ; i < m ; i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            adj[u].pb(v);
        }
        
        for(int i = 1 ; i <= n ; i++)
            if(ind[i] == INF)
                Tarjan(i);
        
        for(int i = 1 ; i <= n ; i++)
            if(!vis[i])
                DFS(i);
        
        int mIn,mOut;
        mIn = mOut = 0;
        
        for(int i = 0 ; i < scc && scc > 1; i++)
        {
            if(!out[i])
                mOut++;
            if(!in[i])
                mIn++;
        }
        
        printf("Case %d: %d\n",t,max(mOut,mIn));
    }
    
    return 0;
}
