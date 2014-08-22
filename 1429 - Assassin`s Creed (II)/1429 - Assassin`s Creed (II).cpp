//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1429 - Assassin`s Creed (II)
// Verdict: 
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

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
//int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
//int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

const int dx[] = {-1, 0, 0, 1};
const int dy[] = { 0,-1, 1, 0};

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1000

int n,m;
vi a[maxN+5], b[maxN+5], topoSort;
bool vis[maxN+5];
int rec[maxN+5], p[maxN+5];

//for Tarjan
int num[maxN+5], low[maxN+5], reg[maxN+5];
int idx, nreg;
stack<int> s;

void init()
{
    idx = nreg = 0;
    s = stack<int>();
    topoSort.clear();
    
    fr(i,1,n)
    {
        num[i] = low[i] = reg[i] = vis[i] = 0;
        rec[i] = -1;
        p[i] = i;
        a[i].clear();
        b[i].clear();
    }
}

void tarjan(int u)
{
    low[u] = num[u] = ++idx;
    
    rep(i,sz(a[u]))
    {
        int v = a[u][i];
        
        if(reg[v]) continue;
        
        if(!num[v])
        {
            tarjan(v);
            low[u] = min(low[v],low[u]);
        }
        else low[u] = min(low[u], num[v]);
    }
    
    if(low[u] == num[u])
    {
        ++nreg;
        int v;
        
        do
        {
            v = s.top();
            reg[v] = nreg;
            s.pop();
        }while(u != v);
    }
}

void topo(int u)
{
    vis[u] = true;
    
    rep(i,sz(b[u]))
    {
        int v = b[u][i];
        if(!vis[v])
            topo(v);
    }
    
    topoSort.pb(u);
}

int solve(int u)
{
    if(rec[u]) return rec[u];
    if(!sz(b[u])) return rec[u] = 1;
    
    rep(i,sz(b[u]))
    {
        int v = b[u][i];
        if(!rec[v])
        {
            p[v] = p[u];
            rec[u] += solve(v);
        }
        else
        {
            rec[u] += rec[v];
            p[u] = p[v];
        }
    }
    
    return rec[u];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1429 - Assassin`s Creed (II).INP","r",stdin);
    freopen("1429 - Assassin`s Creed (II).OUT","w",stdout);
    #endif
    
    read(tcs);
    
    fr(t,1,tcs)
    {
        read2(n,m);
        init();
        
        rep(i,m)
        {
            int u,v;
            read2(u,v);
            
            a[u].pb(v);
        }
        
        fr(i,1,n) if(!num[i]) tarjan(i);
        
        fr(u,1,n) rep(j,sz(a[u]))
        {
            int v = a[u][i];
            
            if(reg[u] != reg[v])
                b[reg[u]].pb(reg[v]);
        }
        
        rep(i,nreg)
        {
            if(!vis[i])
                topo(i);
        }
        
        reverse(all(topoSort));
        
        rep(i,sz(topoSort))
        {
            int u = topoSort[i];
            if(!rec[u]) solve(u);
        }
        
        int ans = 0;
        rep()
        {
            ans += ;
        }
        
        printf("Case %d: %d\n",t,ans);
    }
    
    return 0;
}

