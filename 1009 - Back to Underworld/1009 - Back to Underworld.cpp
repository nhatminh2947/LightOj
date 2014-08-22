//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 1009 - Back to Underworld
// Verdict: Accepted
//******************************************************************

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>

#define mp make_pair
#define ff first
#define ss second
#define INF 1000111222
#define pb push_back
#define maxN 20000
using namespace std;

vector<int> adj[maxN+5];
bool vis[maxN+5];
int enc[maxN+5];
int n;
int cnt[5];

inline pair<int,int> BFS(int node, int st)
{
    queue< pair<int,int> > q;
    
    q.push(mp(node,st));
    pair<int,int> p;
    vector<int> vec;
    vec.pb(node);
    vis[node] = true;
    p.ff = p.ss = 0;
    while(!q.empty())
    {
        int u = q.front().ff;
        int stt = q.front().ss;
        if(stt == 1)
            p.ff++;
        else p.ss++;
        q.pop();
        
        int sz = adj[u].size();
        for(int i = 0 ; i < sz ; i++)
        {
            int v = adj[u][i];
            if(!vis[v])
            {
                vis[v] = true;
                vec.pb(v);
                q.push(mp(v,stt%2+1));
            }
        }
    }
    
    int sz = vec.size();
    for(int i = 0 ; i < sz && st == 1 ; i++)
        vis[vec[i]] = false;
    
    return p;
}

int main()
{
    freopen("1009 - Back to Underworld.INP","r",stdin);
    freopen("1009 - Back to Underworld.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        int m;
        scanf(" %d ",&m);
        
        for(int i = 1 ; i <= maxN ; i++)
        {
            vis[i] = false;
            adj[i].clear();
            enc[i] = 0;
        }
        
        int n = 0;
        cnt[1] = cnt[2] = 0;
        for(int i = 0 ; i < m ; i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            if(!enc[u])
                enc[u] = ++n;
            if(!enc[v])
                enc[v] = ++n;
            adj[enc[u]].pb(enc[v]);
            adj[enc[v]].pb(enc[u]);
        }
        
        cnt[1] = cnt[2] = 0;
        for(int i = 1 ; i <= n ; i++)
            if(!vis[i])
            {
                pair<int,int> p1,p2;
                p1 = BFS(i,1);
                p2 = BFS(i,2);
                cnt[1] += max(p1.ff,p2.ff);
                cnt[2] += max(p1.ss,p2.ss);
            }
        
        printf("Case %d: %d\n",t,max(cnt[1],cnt[2]));
    }
    return 0;
}
