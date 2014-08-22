//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1049 - One Way Roads
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
#define maxN 100000

vii adj[105];
int dist[105][105];
bool vis[105];
int tcs,n;

int BFS(int st)
{
    fr(i,1,n) vis[i] = false;
    vis[st] = true;
    vis[1] = true;
    int cost = 0;
    queue<int> q;
    q.push(st);
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i].ff;
            int c = adj[u][i].ss;
            
            if(!vis[v])
            {
                vis[v] = true;
                q.push(v);
                cost += c;
            }
        }
    }
    
    return cost;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1049 - One Way Roads.INP","r",stdin);
    freopen("1049 - One Way Roads.OUT","w",stdout);
    #endif
    
    scanf("%d",&tcs);
    
    fr(t,1,tcs)
    {
        scanf("%d",&n);
        
        fr(i,1,n) adj[i].clear();
        
        fr(i,1,n)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            
            adj[u].pb(mp(v,0));
            adj[v].pb(mp(u,w));
            dist[u][v] = 0;
            dist[v][u] = w;
        }
        
        int u = adj[1][0].ff;
        int v = adj[1][1].ff;
        
        int c1 = dist[1][u] + BFS(u) + dist[v][1];
        int c2 = dist[1][v] + BFS(v) + dist[u][1];
        
        printf("Case %d: %d\n",t,min(c1,c2));
    }
    
    return 0;
}
