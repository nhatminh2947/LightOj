//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1417 - Forwarding Emails
// Verdict: 
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

int adj[maxN+5];
bool vis[maxN+5];
int n,cnt;

void DFS(int u)
{
    cnt++;
    vis[u] = true;
    int v = adj[u];
    if(!vis[v])
        DFS(v);
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
        
        for(int i = 1 ; i <= n ; i++)
            vis[i] = false;
        
        for(int i = 0 ; i < n ; i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            adj[u] = v;
        }
        
        vector<int> store;
        for(int i = 1 ; i <= n ; i++)
            if(!vis[i])
            {
                DFS(i);
                store.pb(i);
            }
        
        for(int i = 1 ; i <= n ; i++)
            vis[i] = false;
        
        int sz = store.size();
        int ans;
        int m = -INF;
        for(int i = sz-1 ; i >= 0 ; i--)
            if(!vis[store[i]])
            {
                cnt = 0;
                DFS(store[i]);
                if(m <= cnt)
                {
                    ans = store[i];
                    m = cnt;
                }
            }
        
        printf("Case %d: %d\n",t,ans);
    }
    
    return 0;
}
