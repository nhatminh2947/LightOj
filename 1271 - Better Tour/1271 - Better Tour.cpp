//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1271 - Better Tour
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
#define maxN 50000

int n;
int a[maxN+5],track[maxN+5];
vi adj[maxN+5];
bool vis[maxN+5];

void BFS(int st, int ed)
{
    fr(i,1,50000)
    {
        track[i] = i;
        vis[i] = false;
        sort(all(adj[i]));
    }
    
    queue<int> q;
    q.push(st);
    vis[st] = true;
    
    while(!q.empty())
    {
        int u = q.front();
        
        if(u == ed) return;
        q.pop();
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i];
            
            if(!vis[v])
            {
                track[v] = u;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void printAns(int u)
{
    if(track[u] == u)
    {
        printf("%d",u);
        return;
    }
    printAns(track[u]);
    printf(" %d",u);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1271 - Better Tour.INP","r",stdin);
    freopen("1271 - Better Tour.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        
        fr(i,1,50000) adj[i].clear();
        
        fr(i,1,n) scanf(" %d ",&a[i]);
        
        fr(i,2,n)
        {
            adj[a[i-1]].pb( a[i] );
            adj[ a[i] ].pb(a[i-1]);
        }
        
        BFS(a[1],a[n]);
        
        printf("Case %d:\n",t);
        printAns(a[n]);
        puts("");
    }
    
    return 0;
}
