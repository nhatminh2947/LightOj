//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1257 - Farthest Nodes in a Tree (II)
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) (int)s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 30000

int dist[maxN+5],dU[maxN+5];
vii adj[maxN+5];
int n;

int BFS(int st)
{
    rep(i,n) dist[i] = INF;
    
    queue<int> q;
    dist[st] = 0;
    q.push(st);
    
    int farthest = st;
    int maxDist = 0;
    
    while(!q.empty())
    {
        int u = q.front();
        //DEBUG(u);
        q.pop();
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i].ff;
            int w = adj[u][i].ss;
            
            if(dist[v] == INF)
            {
                dist[v] = dist[u] + w;
                if(maxDist < dist[v])
                {
                    maxDist = dist[v];
                    farthest = v;
                }
                q.push(v);
            }
        }
    }
    
    return farthest;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1257 - Farthest Nodes in a Tree (II).INP","r",stdin);
    freopen("1257 - Farthest Nodes in a Tree (II).OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        printf("Case %d:\n",t);
        scanf(" %d ",&n);
        
        rep(i,n) adj[i].clear();
        
        rep(i,n-1)
        {
            int u,v,w;
            scanf(" %d %d %d ",&u,&v,&w);
            
            adj[u].pb(mp(v,w));
            adj[v].pb(mp(u,w));
        }
        
        int u = BFS(BFS(0));
        rep(i,n) dU[i] = dist[i];
        BFS(u);
        
        rep(i,n) printf("%d\n",max(dist[i],dU[i]));
    }
    
    return 0;
}
