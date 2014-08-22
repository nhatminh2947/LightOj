//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1417 - Forwarding Emails
// Verdict: Accepted
//******************************************************************

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

#define mp make_pair
#define pb push_back
#define INF 1000111222
#define maxN 50000

using namespace std;

int adj[maxN+5],low[maxN+5],ind[maxN+5],cnt[maxN+5],SCC[maxN+5],node[maxN+5];
bool vis[maxN+5],onStack[maxN+5];
int n,scc,id,c;
stack<int> s;

void Tarjan(int u)
{
    low[u] = ind[u] = ++id;
    onStack[u] = true;
    s.push(u);
    
    int v = adj[u];
    if(ind[v] == INF)
    {
        Tarjan(v);
        low[u] = min(low[u],low[v]);
    }
    else if(onStack[v])
        low[u] = min(low[u],ind[v]);
    
    if(low[u] == ind[u])
    {
        ++scc;
        do
        {
            v = s.top();
            s.pop();
            onStack[v] = false;
            SCC[v] = scc;
            node[scc] = min(node[scc],v);
            cnt[scc]++;
        }while(u != v);
    }
}

void DFS(int u)
{
    c += cnt[SCC[u]];
    vis[SCC[u]] = true;
    int v = adj[u];
    if(!vis[SCC[v]])
        DFS(v);
}

inline void reset()
{
    id = scc = 0;
    while(!s.empty())
        s.pop();
    for(int i = 0 ; i <= n ; i++)
    {
        low[i] = ind[i] = node[i] = INF;
        onStack[i] = vis[i] = false;
        cnt[i] = 0;
    }
}

int main()
{
    freopen("1417 - Forwarding Emails.INP","r",stdin);
    freopen("1417 - Forwarding Emails.OUT","w",stdout);
    
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        
        reset();
        
        for(int i = 0 ; i < n ; i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            adj[u] = v;
        }
        
        for(int i = 1 ; i <= n ; i++)
            if(ind[i] == INF)
                Tarjan(i);
        //cout << "AAAAAAAAAAA" << endl;
        int m = -INF;
        int ans;
        for(int i = 1 ; i <= scc ; i++)
        {
            c = 0;
            for(int j = 1 ; j <= scc ; j++)
                vis[j] = false;
            DFS(node[i]);
                
            if(m < c)
            {
                m = c;
                ans = node[i];
            }
        }
            
        printf("Case %d: %d\n",t,ans);
    }
    
    return 0;
}
